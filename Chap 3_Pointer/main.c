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


int main()
{
    char array[] = "Hello"; 
    void *ptr;
    int value = 5;
    double test = 5.123;
    char letter = 'A';
    /*
     : char *array = "Hello"

     array[i+1] = *(array[i] + 1*sizeof(char))

    */
    // int a = 5;
    // int b = 6;
    
    // swap(&a,&b);
    // printf("a = %d \nb = %d", a, b);

    void *ptr = &value;
    printf("%d\n", *(int *)(ptr));

    void *ptr = &test;
    printf("%f\n", *(double *)(ptr));


    void *ptr = &sum;
    return 0; 
}