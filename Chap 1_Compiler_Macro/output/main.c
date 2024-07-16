#include <stdio.h>
#include <stdarg.h>

#define sum(a,b) a+b

int sum(int a, int b){
    return a+b; 
}

int main(int argc, char const *argv[]) 
{
    printf("%d\n", sum(2,3));

    return 0;
}