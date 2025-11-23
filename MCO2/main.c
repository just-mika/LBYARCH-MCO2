#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define NUM_ITERATIONS 20
extern float sdot;

/**
 * @brief Calculates the dot product of two single-precision float vectors.
 * @param A Pointer to the first float vector.
 * @param B Pointer to the second float vector.
 * @param n The length (number of elements) of both vectors.
 * @return float The resulting dot product (scalar sum).
 */
float dot_product_c(const float* A, const float* B, int n) {
    float sum = 0.0f;
    // Iterate through the vectors and accumulate the product of corresponding elements
    for (int i = 0; i < n; i++) {
        sum += A[i] * B[i];
    }
    return sum;
}

// Function prototype for the Assembly implementation (To be linked with your NASM code)
extern float dot_product_asm(const float* A, const float* B, int n);


// --- Timing Function ---
// This function measures the execution time of any dot product function pointer
void time_function(float (*func)(const float*, const float*, int), const float* A, const float* B, int n, const char* name) {
    LARGE_INTEGER start, end, frequency;
    double total_time_ms = 0.0; // Accumulator for the average

    // Get the high-resolution clock frequency
    QueryPerformanceFrequency(&frequency);

    printf("\n--- %s Performance per test ---\n", name);

    // 1. Warm-up run (ensures CPU caches are primed, not timed)
    printf("Running warm-up...\n");
    float verification_result = func(A, B, n); // Run once to cache
    printf("----------------------------------------\n");

    // 2. Run and time each iteration individually
    for (int i = 0; i < NUM_ITERATIONS; i++) {

       // float run_result;

        // Start timer for this single run
        QueryPerformanceCounter(&start);

        // Run the function and get its result
        sdot = func(A, B, n); //Store result in sdot

        // Stop timer
        QueryPerformanceCounter(&end);

        // Calculate time for this single run
        double run_time_ms = (double)(end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;

        // Add to the total accumulator
        total_time_ms += run_time_ms;

        // Print the result and time for this specific run
        printf("  Run %2d: Result = %.2f, Time = %.6f ms\n", i + 1, sdot, run_time_ms);
    }

    // 3. Print the final summary and average
    double average_time_ms = total_time_ms / NUM_ITERATIONS;

    printf("----------------------------------------\n");
    printf("Result (Verification): %.2f\n", verification_result);
    printf("Average Time (%d runs): %.6f milliseconds\n", NUM_ITERATIONS, average_time_ms);
}

int main() {

    // Array of sizes: 2^20, 2^24, 2^30
    // Note: 1 << 20 means "1 shifted left 20 times", which is 2^20
    const int sizes[] = { 1 << 20, 1 << 24, 1 << 30 };
    const int num_sizes = 3;

    for (int s = 0; s < num_sizes; s++) {
        int n = sizes[s];

        printf("\n\n==============================================\n");
        printf("Running Benchmarks for Size 2^%d (n = %d)\n", (s == 0 ? 20 : (s == 1 ? 24 : 30)), n);
        printf("==============================================\n");

        printf("Allocating memory...\n");

        // IMPORTANT: We cast n to (size_t) to prevent overflow when calculating 4GB+ sizes
        float* vector_A = (float*)malloc((size_t)n * sizeof(float));
        float* vector_B = (float*)malloc((size_t)n * sizeof(float));

        if (vector_A == NULL || vector_B == NULL) {
            printf("CRITICAL ERROR: Failed to allocate memory for 2^%d.\n", (s == 0 ? 20 : (s == 1 ? 24 : 30)));
            printf("You likely ran out of RAM or are running in 32-bit mode.\n");
            // If A was allocated but B failed, free A before exiting
            if (vector_A) free(vector_A);
            break; // Stop the loop
        }

        // Initialize Vectors
        // Using simpler initialization for speed on massive arrays
        printf("Initializing vectors...\n");
        for (int i = 0; i < n; i++) {
            vector_A[i] = 1.0f;
            vector_B[i] = 2.0f;
        }

        // Time C Version
        time_function(dot_product_c, vector_A, vector_B, n, "C Scalar");

        // Time Assembly Version
        time_function(dot_product_asm, vector_A, vector_B, n, "x64 Assembly");

        // Cleanup
        free(vector_A);
        free(vector_B);
    }

    printf("\nBenchmark Complete.\n");
    return 0;
}