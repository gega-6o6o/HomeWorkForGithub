#include <stdio.h>

#define MODE 1

#ifndef MODE
#error "Необходимо определить MODE"
#endif


int add(int a, int b) {return a + b;}

int main()
{
#if MODE == 0
    printf("Работаю в режиме тренировки\n");
#elif MODE == 1
    printf("Работаю в боевом режиме\n");
    
    int num1, num2;
    printf("Введите число 1: ");
    scanf("%d", &num1);
    printf("Введите число 2: ");
    scanf("%d", &num2);
    
    int result = add(num1, num2);
    printf("Результат сложения: %d\n", result);
#else
    printf("Неизвестный режим. Завершение работы\n");
#endif

    return 0;
}
