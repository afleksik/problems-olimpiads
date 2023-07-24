#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void merge(int *A, int *B, int l, int r, int c) {
    int i, j, k;

    for (i = l, j = c + 1, k = l; i <= c && j <= r;) {
        if (A[i] <= A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    while (i <= c)
        B[k++] = A[i++];
    while ( j <= r)
        B[k++] = A[j++];

    for (k = l; k <= r; k++)
        A[k] = B[k];

    return;
}

void merge_sort_r(int *A, int *B, int l, int r) {
    if (r <= l)
        return;
    int c = (l + r) / 2;
    merge_sort_r(A, B, l, c);
    merge_sort_r(A, B, c + 1, r);
    merge(A, B, l, r, c);
}

void merge_sort(int *A, int N) {
    int l = 0, r = N - 1;
    int *B = (int *) malloc(N * sizeof(int));
    merge_sort_r(A, B, l, r);
    free(B);
}

int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {
    int count = 0;
    merge_sort(arr2, arr2Size);
   
    for (int i = 0; i < arr1Size; i++) {
        int l = 0, r = arr2Size - 1;
        while(l <= r){
            int c = (l + r) / 2;
            if (abs(arr1[i] - arr2[c]) <= d) {
                count++;
                break;
            }
            if (arr1[i] > arr2[c])
                l = c + 1;
            else
                r = c - 1;
        }
    }
    return arr1Size - count;
}


int main(){
    int arr1Size, arr2Size, d, x;
    scanf("%d", &arr1Size);
    scanf("%d", &arr2Size);
    scanf("%d", &d);
    int *arr1 = (int*)malloc(arr1Size * sizeof(int));
    int *arr2 = (int*)malloc(arr2Size * sizeof(int));
    for (int i = 0; i < arr1Size; ++i){
        scanf("%d", &x);
        arr1[i] = x;
    }
    for (int i = 0; i < arr2Size; ++i){
        scanf("%d", &x);
        arr2[i] = x;
    }

    printf("%d", findTheDistanceValue(arr1, arr1Size, arr2, arr2Size, d));
    return 0;
}