#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int code;


#define TRY if((code = setjmp(buf)) == 0)
#define CATCH(x) else if (code == (x))
#define THROW(x,y) longjmp(buf, (x)) 


double divide(int a, int b)
{
    if(b == 0)
    {
        THROW(1, "Error of 0 division!\n");
    }
    return (double)a/b;
}


int main()
{
    int a = 1;
    int b = 1;
    double result ;
    TRY
    {
        result = divide(a,b);
        printf("Result: %f\n", result);
    }
    CATCH(1)
    {
        printf("ERROR\n");
    }

    return 0;
}