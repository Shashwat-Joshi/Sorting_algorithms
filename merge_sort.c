#include <stdio.h>
void Merge(int A[], int Left, int mid, int Right)               // to merge the individual array into a sorted array
{
    int n1 = mid - Left + 1;
    int n2 = Right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = A[Left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = A[mid + 1 + j];
    }
    int i = 0, j = 0, k = Left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}
void MergeSort(int A[], int Left, int Right)                // split the array into left and write until they become individual elements
{
    if (Left < Right)
    {
        int mid = Left + (Right - Left) / 2;

        MergeSort(A, Left, mid);
        MergeSort(A, mid + 1, Right);

        Merge(A, Left, mid, Right);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int ar[n];
    for (int i = 0; i < n; i++)
        scanf("%d", ar + i);

    MergeSort(ar, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", ar[i]);
    return 0;
}
