#include <stdio.h>

int maiorValor(int *a, int *b)
{
    if (*a > *b)
    {
        return *a;
    }
    else
    {
        return *b;
    }
}

int main()
{
    int num1, num2;
    printf("Digite dois numeros: ");
    scanf("%d %d", &num1, &num2);

    printf("%d", maiorValor(&num1, &num2));
}