//upgrade bubblesort

#include <stdio.h>

void bubblesort(int *array, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(*(array + i) > *(array + j))
            {
                int temp = *(array + i);
                *(array + i) = *(array + j);
                *(array + j) = temp;
            }
        }
    }

}

int main()
{
    // int array[3] = {5,4,1};
    // printf("Input the array: ")
    // scanf("%d", &array);
    int *a;
    int n; //size of array
    printf("Enter size of array: ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));

    printf("Enter the array:");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", a+i);
    }
    // int n = sizeof(array)/sizeof(array[0]);
    //bubble(a,n) not bubble(&a, n) due to a is transferred into an array.
    bubblesort(a, n);
    printf("Array after sorted: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    free(a);
    return 0;
}


