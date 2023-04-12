#include <stdio.h>

int main()
{
    int num1, num2, result;
    char operator;

    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter operator (+, -, *, /, %%): ");
    scanf(" %c", &operator);
    printf("Enter second number: ");
    scanf("%d", &num2);

    switch (operator)
    {
    case '+':
        result = num1 + num2;
        printf("%d + %d = %d\n", num1, num2, result);
        break;
    case '-':
        result = num1 - num2;
        printf("%d - %d = %d\n", num1, num2, result);
        break;
    case '*':
        result = num1 * num2;
        printf("%d * %d = %d\n", num1, num2, result);
        break;
    case '/':
        result = num1 / num2;
        printf("%d / %d = %d\n", num1, num2, result);
        break;
    case '%':
        result = num1 % num2;
        printf("%d %% %d = %d\n", num1, num2, result);
        break;
    default:
        printf("Invalid operator\n");
    }

    return 0;
}
