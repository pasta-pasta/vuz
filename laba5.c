#include<stdio.h>
#include<stdlib.h>
//В массиве из 10 целых чисел обнулить те N соседних элементов массива,
//которые имеют минимальную сумму.

int* createArray(int n)
{
    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    return a;
}

void getMin(int* a, int i, int* minSum, int* minIndex){
    if (i == 9)
    {
        return;
    }
    if (a[i] + a[i + 1] < *minSum)
    {
        *minSum = a[i] + a[i + 1];
        *minIndex = i;
    }
    return getMin(a, i + 1, minSum, minIndex);

}

int main()
{
    int* a = createArray(10);
    int i = 0;
    int minIndex = 0;
    int minSum = a[0] + a[1];
    getMin(a, i, &minSum, &minIndex);

    a[minIndex] = 0;
    a[minIndex + 1] = 0;
    for (i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    free(a);
    return 0;
}