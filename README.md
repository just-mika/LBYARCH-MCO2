## LBYARCH MCO2 - x86-to-C interface programming project
- Amon, Mikaela Nicole
- Filipino, Eunice Marble

### I.) Comparative execution time and short analysis of the performance of the kernels
The following table summarizes the average execution times for the two kernels across all tested sizes and build modes.
| Vector Size (n)  |     C (Debug)    |    C (Release)     | x86-64 Assembly (Debug) | x86-64 Assembly (Release) |
|:----------------:|:----------------:|:------------------:|:-----------------------:|:-------------------------:|
| 2<sup>20</sup>   |    2.423585 ms   |    0.732075 ms     |       0.533070 ms       |         0.520290 ms       |
| 2<sup>24</sup>   |   31.434300 ms   |    9.008700 ms     |       9.786205 ms       |        9.572425 ms        |
| 2<sup>30</sup>   | 5854.377045 ms   | 1540.179305 ms     |    2542.689880 ms       |       578.570510 ms       |

These results indicate that across the three vector sizes, the x86-64 assembly implementation generally outperforms the C implementation of the scalar dot product function in terms of speed. This is expected because of assembly being low-level, which allows explicit control over registers, memory access, and instruction sequence. The implementation uses scalar SIMD registers and instructions directly, which allows the program to run faster. In contrast, the C implementation depends on the compiler to translate high-level code to machine instructions, in which it may not always use the most efficient instructions especially when optimizations are disabled.

However, the amount of improvement in performance also depends on the build mode the program used. For the Debug Build, the difference between the performance of both implementations is the largest, as the C implementation runs significantly slower due to the compiler having no optimizations in this mode. The assembly implementation runs mostly similar across both build modes, but its performance gap becomes notable as the vector sizes increase to a very large amount.

For the Release Build, both implementations are faster compared to their performance using the Debug build mode. The C implementation is significantly faster because the release build mode compiler has optimizations that help the program run as fast as the assembly version, or even outperforms it at times. This suggests that the compiler, on release mode, has the ability to generate optimal code that is close to the handwritten assembly version. However, for n = 2<sup>30</sup>, the x86-64 assembly implementation still outperforms the other tests. Thus, for extremely large inputs, x86-64 assembly is still recommended to ensure fast execution times.

### II.) Screenshot of the program output with the correctness check (C).
- **DEBUG MODE**
    * 2<sup>20</sup>

    ![alt text](https://github.com/just-mika/LBYARCH-MCO2/blob/master/docu%20files/db%20mode/img/2_20%20C.png)
    * 2<sup>24</sup>

   ![alt text](https://github.com/just-mika/LBYARCH-MCO2/blob/master/docu%20files/db%20mode/img/2_24%20C.png)
    * 2<sup>30</sup>

   ![alt text](https://github.com/just-mika/LBYARCH-MCO2/blob/master/docu%20files/db%20mode/img/2_30%20C.png)
  
- **RELEASE MODE**
    * 2<sup>20</sup>

    ![alt text](https://github.com/just-mika/LBYARCH-MCO2/blob/master/docu%20files/rl%20mode/img/2_20%20C.png)
    * 2<sup>24</sup>

   ![alt text](https://github.com/just-mika/LBYARCH-MCO2/blob/master/docu%20files/rl%20mode/img/2_24%20C.png)
    * 2<sup>30</sup>

   ![alt text](https://github.com/just-mika/LBYARCH-MCO2/blob/master/docu%20files/rl%20mode/img/2_30%20C.png)


### III.) Screenshot of the program output, including the correctness check (x86-64).
- **DEBUG MODE**
    * 2<sup>20</sup>

    ![alt text](https://github.com/just-mika/LBYARCH-MCO2/blob/master/docu%20files/db%20mode/img/2_20%20ASM.png)
    * 2<sup>24</sup>

   ![alt text](https://github.com/just-mika/LBYARCH-MCO2/blob/master/docu%20files/db%20mode/img/2_24%20ASM.png)
    * 2<sup>30</sup>

   ![alt text](https://github.com/just-mika/LBYARCH-MCO2/blob/master/docu%20files/db%20mode/img/2_30%20ASM.png)

- **RELEASE MODE**
    * 2<sup>20</sup>

    ![alt text](https://github.com/just-mika/LBYARCH-MCO2/blob/master/docu%20files/rl%20mode/img/2_20%20ASM.png)
    * 2<sup>24</sup>

   ![alt text](https://github.com/just-mika/LBYARCH-MCO2/blob/master/docu%20files/rl%20mode/img/2_24%20ASM.png)
    * 2<sup>30</sup>

   ![alt text](https://github.com/just-mika/LBYARCH-MCO2/blob/master/docu%20files/rl%20mode/img/2_30%20ASM.png)

### IV.) Short videos (5-10mins) showing your source code, compilation, and execution of the C and x86-64
- to be added
