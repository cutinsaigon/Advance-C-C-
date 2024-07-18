#include <stdio.h>

// void swap(int *a, int *b)
// {
//     int temp;
//     temp = *a;
//     *a = *b;
//     *b = temp;
// }

int sum(int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}

int mul(int a, int b)
{
    return a*b;
}

int div(int a, int b)
{
    return (double)a/b;
}
//con trỏ hàm được gọi trong hàm
void domath(int(*math)(int, int), int a, int b)
{
    printf("Value: %d", math(a,b));
}
int main()
{
    // char array[] = "Hello"; 
    // void *ptr;
    // int value = 5;
    // double test = 5.123;
    // char letter = 'A';
    /*
     : char *array = "Hello"

     array[i+1] = *(array[i] + 1*sizeof(char))

    */
    // int a = 5;
    // int b = 6;
    
    // swap(&a,&b);
    // printf("a = %d \nb = %d", a, b);

    // void *ptr = &value;
    // printf("%d\n", *(int *)(ptr));

    // void *ptr = &test;
    // printf("%f\n", *(double *)(ptr));


    // void *ptr = &sum;
    // VD con trỏ hàm   

    // int(*math[])(int, int) = {&sum, &sub, &mul, &div};

    // for(int i=0; i<4;i++)
    // {
    //     printf("Value: %.d\n", math[i](7,4));
    // }

    // domath(&sum, 1,2);
    
    // return 0;

    char array[] = "Hello";
    int value = 5;
    double test = 15.7;
    char letter = 'A';

    void *ptr = &value;
    printf("value is: %d\n", *(int *)(ptr));

    ptr = &test;
    printf("value is: %f\n", *(double *)(ptr));

    ptr = &letter;
    printf("value is: %c\n", *(char *)(ptr));

    ptr = sum;
    printf("sum: %d\n", ((int (*)(int, int))ptr)(5, 6));

    void *ptr1[] = {&value, &test, &letter, sum, array};

    printf("value: %d\n", *(int *)ptr1[0]);

    printf("value: %c\n", *((char *)ptr1[4] + 1));

    return 0;
}