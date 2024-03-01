#include <stdio.h>


void If_Statement() {
    // if Statement 
    int a = -3;
    if (a > 3) {
        printf("a is larger than 3\n");
    }
    else {
        printf("a is not larger than 3\n");
    }
}

void Switch_Statement() {
    // The Conditional Operator(?:)
    int a = -3;
    int b = a > 0 ? a : -a;//if a > 0, b = a, else b = -a.
    printf("b = %d\n", b);

    // The switch Statement
    switch (b) {
    case 1:
        printf("b is 1\n");
        break;
    case 2:
        printf("b is 2\n");
        break;
    case 3:
        printf("b is 3\n");
        break;
    default:
        printf("b is not 1, 2, or 3\n");
    }
}

void While_Loop() {
    // while and do/while Loop
    int c = 4;
    while (c < 4) {
        c *= 2;
    }

    int d = 4;
    do {
        d *= 2;//execute at least once
    } while (d < 4);

    printf("c = %d, d = %d\n", c, d);
}

void For_Loop() {
    // for Loop
    for (int i = 0; i < 5; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < 3; i++) //Nested Loops
    {
        for (int j = 0; j < 3; j++)
        {
            printf("(%d %d) ", i, j);
        }
        printf("\n");
    }
}

int sum(int value1, int value2) {
    return value1 + value2;
}

void SumFunction() {
    // function
    int a = 2, b = 3;
    printf("%d + %d = %d\n", a, b, sum(a, b));
}

void ShortcutOperator() {
    // ++a & a++
    int count = 0;
    printf("count++ = %d, count = %d\n", count++, count);
    count = 0;
    printf("++count = %d, count = %d\n", ++count, count);
}

int main()
{
    ShortcutOperator();

    // function
    SumFunction();

    // statement
    If_Statement();
    Switch_Statement();

    While_Loop();
    For_Loop();

    return 0;
}