#include <stdio.h>
int partition(int ar[], int start, int end)
{
    int pivot = ar[end], temp;
    int partition_index = start;
    for (int i = start; i < end; i++)
    {
        if (ar[i] <= pivot)
        {
            temp = ar[i];
            ar[i] = ar[partition_index];
            ar[partition_index] = temp;
            partition_index++;
        }
    }
    temp = ar[end];
    ar[end] = ar[partition_index];
    ar[partition_index] = temp;
    return partition_index;
}
void quicksort(int ar[], int start, int end)
{
    if (start < end)
    {
        int part_index = partition(ar, start, end);
        quicksort(ar, start, part_index - 1);
        quicksort(ar, part_index + 1, end);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int ar[n];
    for (int i = 0; i < n; i++)
        scanf("%d", ar + i);
    quicksort(ar, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", *(ar + i));
    return 0;
}