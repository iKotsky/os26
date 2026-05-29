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
    unsigned long sp=(unsigned long)stack_ptr();
    void* brk0 = sbrk(0);
    unsigned long tmp = sp - (unsigned long)brk0;
    printf("\nHEAP брейк0-адрес\t\t\t%Xh\n", brk0);
    printf("Полный размер HEAP \t%lu байт = %lu Мб\n\n",tmp,tmp/1024/1024);

    // 1. Вызначэнне памеру масіва (напрыклад, 5 элементаў)
    int n = 5;

    // 2. Выдзяленне памяці пад другі дынамічны масіў типа int
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Памылка выдзялення памяці!\n");
        return 1;
    }

    // 3. Запаўненне масіва дадзенымі (напрыклад, квадратамі індэксаў)
    for(int i = 0; i < n; i++) {
        arr[i] = (i + 1) * 10; // Вынікі: 10, 20, 30, 40, 50
    }

    // 4. Вывад значэнняў масіва на экран
    printf("Значэнні другога дынамічнага масіва:\n");
    for(int i = 0; i < n; i++) {
        printf("arr[%d] = %d (адрас: %p)\n", i, arr[i], &arr[i]);
    }

    // 5. Абавязковае вызваленне памяці
    free(arr);

    return 0;
}
