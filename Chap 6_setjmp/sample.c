#include <stdio.h>
#include <setjmp.h>
// int check;
jmp_buf buf;
int code;
#define TRY if(check == 0)
#define CATCH(x) else if (check == x)
#define THROW(x) longjmp(buf, (x))



double divide(int a, int b)
{
    if(b==0)
    {
        THROW(1); // MÃ LỖI 1
    }
    return a/(double)b;
}

int main()
{
    int x = 10;
    int y = 0;

    TRY
    {
        double result = divide(x, y);
        printf("divide: %f \n", result);
    }
    CATCH(1)
    {
        printf("ERROR!!");
    }

    return 0;
}