#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int stack_ptr()
{__asm__
    (   ".code32\n"
        ".intel_syntax noprefix\n"
        "mov    eax,    esp\n"
    );
}

int main(int argc, char *argv[])
{   
    unsigned long sp = (unsigned long)stack_ptr();
    
    // --- ПЕРШЫ МАСІЎ ---
    void* brk0 = sbrk(0);
    int *arr1 = (int*)malloc(100000 * sizeof(int)); // выдзяляем шмат памяці
    void* brk1 = sbrk(0);
    
    // --- ДРУГІ МАСІЎ (без free для першага!) ---
    int *arr2 = (int*)malloc(100000 * sizeof(int));
    void* brk2 = sbrk(0);

    unsigned long tmp = sp - (unsigned long)brk2;
    
    printf("\nПачатковы брэйк-адрас: %Xh\n", brk0);
    printf("Брэйк пасля 1-га масіва: %Xh\n", brk1);
    printf("Брэйк пасля 2-га масіва: %Xh\n", brk2);
    printf("Засталося вольнай памяці: %lu байт\n", tmp);

    // Каманды free(arr1) і free(arr2) наўмысна адсутнічаюць — ствараем уцечку

    return 0;
}
