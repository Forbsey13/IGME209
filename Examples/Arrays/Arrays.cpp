#include <stdio.h>
#include <string>

int main()
{
    // Array
    int array1[10];
    for (int i = 0; i < 10; i++) {
        array1[i] = i * 3;
    }
    //Print array1
    printf("array1:");
    for (int i = 0; i < 10; i++) {
        printf(" %d", array1[i]);
    }
    printf("\n");

    int array2[] = { 1,3,5,7,9,2,4,6,8,10 };
    //Print array2
    printf("array2:");
    for (int i = 0; i < 10; i++) {
        printf(" %d", array2[i]);
    }
    printf("\n");

    int array3[3];
    for (int i = 0; i < 3; i++) {
        printf("Please enter the element (%d/3): ", i + 1);
        scanf_s("%d", &array3[i]);
        // scanf_s() function is more secure than scanf() function 
        // as it provides an additional parameter to specify the buffer size that can avoid buffer overflow.
        // Receive input from the user. & means address. &array3[i] is the adress of array3[i] in the memory
    }
    //Print array3
    printf("array3:");
    for (int i = 0; i < 3; i++) {
        printf(" %d", array3[i]);
    }
    printf("\n");

    int array2D[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
    printf("array2D:\n");
    //Print array2D
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", array2D[i][j]);
        }
        printf("\n");
    }

    // String
    std::string s = "This is a string.";
    printf("String: %s\n", s.c_str());

    char s2[] = "Second string.";
    printf("String2: %s\n", s2);

    return 0;
}