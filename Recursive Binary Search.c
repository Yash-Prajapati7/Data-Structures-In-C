#include<stdio.h>
#include<conio.h>
int binarySearch(int arr[], int n, int target, int left, int right) {
    int mid = left + (right - left) / 2;

    if(arr[mid] == target) {
        return mid;
    }
    if(right < left) {
        return -1;
    }
    if(arr[mid] > target) {
        binarySearch(arr, n, target, left, mid - 1);
    }
    else {
        binarySearch(arr, n, target, mid + 1, right);
    }
}

// Incase if the array provided isn't sorted (You can use other advanceed sorting methods like MergeSort, QuickSort, etc)
void bubbleSort(int arr[], int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void main() {
    int arr[] = { 10, 20, 30, 40, 50, 60, 70 };
    int n = 7;
    int target = 30;
    printf("%d", binarySearch(arr, n, target, 0, n - 1));
}
