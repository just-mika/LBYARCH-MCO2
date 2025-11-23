section .text
bits 64
default rel 

global dot_product_asm

; ==========================================
; float dot_product_asm(const float* A, const float* B, int n)
;
; Arguments (Windows x64 Calling Convention):
; RCX = A (pointer to vector A)
; RDX = B (pointer to vector B)
; R8  = n (integer length of vectors)
;
; Return Value:
; XMM0 = Result (float)
; ==========================================

dot_product_asm:
    ; 1. Initialize Sum to 0.0
    ; XORPS is the most efficient way to clear an XMM register
    xorps xmm0, xmm0    
    
    ; 2. Safety Check: If n <= 0, return 0.0 immediately
    cmp r8d, 0       ; Check if R8D (the 32-bit int n) is 0
    jle end           ; If n <= 0, jump to end

loop_start:
    ; 3. Load A[i] into XMM1
    movss xmm1, [rcx]
    
    ; 4. Load B[i] into XMM2
    movss xmm2, [rdx]
    
    ; 5. Multiply: XMM1 = A[i] * B[i]
    mulss xmm1, xmm2
    
    ; 6. Accumulate: XMM0 = XMM0 + XMM1
    addss xmm0, xmm1
    
    ; 7. Move pointers forward
    add rcx, 4          ; Move A pointer by 4 bytes (size of float)
    add rdx, 4          ; Move B pointer by 4 bytes (size of float)
    
    ; 8. Decrement loop counter and jump
    dec r8d                  ; Decrease n
    jnz loop_start           ; If n is not zero, jump back to .loop

end:
    ret                 ; Return value is already in XMM0
