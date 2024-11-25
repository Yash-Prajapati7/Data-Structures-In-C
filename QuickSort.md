## C
```c
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int nums[], int low, int high) {
    int pivot = nums[low];
    int i = low, j = high;
    
    while(i < j) {
        while(i <= high - 1 && nums[i] <= pivot) i++;
        while(j >= low + 1 && nums[j] > pivot) j--;
        
        if(i < j) swap(&nums[i], &nums[j]);
    }
    
    swap(&nums[low], &nums[j]);
    return j;
}

void quickSort(int nums[], int low, int high) {
    if(low >= high) {
        return;
    }
    int next = partition(nums, low, high);
    quickSort(nums, low, next - 1);
    quickSort(nums, next + 1, high);
}

int main() {
    printf("Enter the number of elements\n");
    int n = 0;
    scanf("%d", &n);
    int nums[n];
    printf("Enter the elements\n");
    
    for(int i = 0; i < n; i++) scanf("%d", &nums[i]);
    quickSort(nums, 0, n - 1);
    
    printf("After sorting\n");
    for(int i = 0; i < n; i++) printf("%d   ", nums[i]);
    

    return 0;
}
```
