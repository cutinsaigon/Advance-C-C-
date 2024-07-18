#include <stdio.h>
#include <stdarg.h>


void display(int count, ...)
{
    va_list args;          // <=> typedef *char va_list
    va_start(args, count); // so sánh giá trị count nếu bằng giá trị count trong function 
                           // display thì mới bắt đầu chuỗi

    for(int i = 0; i < count ; i++)
    {
        printf("Value at %d: %d \n", i, va_arg(args, int));
    }

    va_end(args);
}

int sum(int count , ...)
{
    va_list args;
    va_start(args, count);
    int result = 0;
    for(int i = 0; i < count; i++)
    {
        result += va_arg(args, int);
    }

    va_end(args);

    return result;
}

typedef struct
{
    int x;
    double y;
}Data;

void display1(int count, ...)
{
    va_list args;
    va_start(args, count);

    for(int i = 0; i < count; i++)
    {
        Data temp = va_arg(args, Data);
        printf("Data.x at %d is: %d\n",i, temp.x);
        printf("Data.y at %d is: %.4f\n",i, temp.y); 
    }

    va_end(args);

}

int main()
{
    display(3,1,4,2); 
    
    printf("Sum = %d\n", sum(3,1,2,3));

    display1(1, (Data){1, 2.232});
    return 0;
}