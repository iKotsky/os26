section .data
    arr1 dd 10, 20, 30, 40, 50
    arr2 dd 5, 15, 25, 35, 45
    size dd 5
    
    fmt1 db "Arr1[%d] = %d", 10, 0
    fmt2 db "Arr2[%d] = %d", 10, 0
    fmt3 db "Result[%d] = %d", 10, 0

section .bss
    arr_res resd 5

section .text
    global _start
    extern printf

_start:
    ; 1. Цикл сложения (один проход по условию)
    xor ecx, ecx
.loop_sum:
    cmp ecx, [size]
    je .print_all
    mov eax, [arr1 + ecx*4]
    add eax, [arr2 + ecx*4]
    mov [arr_res + ecx*4], eax
    inc ecx
    jmp .loop_sum

    ; 2. Печать результатов напрямую через системный printf
.print_all:
    xor esi, esi       ; Использовать esi как индекс для вывода
.loop_p:
    cmp esi, [size]
    je .exit_program

    ; Печать элемента 1-го массива
    push dword [arr1 + esi*4]
    push esi
    push fmt1
    call printf
    add esp, 12

    ; Печать элемента 2-го массива
    push dword [arr2 + esi*4]
    push esi
    push fmt2
    call printf
    add esp, 12

    ; Печать результата сложения
    push dword [arr_res + esi*4]
    push esi
    push fmt3
    call printf
    add esp, 12

    inc esi
    jmp .loop_p

.exit_program:
    mov eax, 1         ; sys_exit
    xor ebx, ebx       ; exit code 0
    int 0x80
