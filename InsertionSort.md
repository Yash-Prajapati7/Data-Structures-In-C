## C
```c
#include <stdio.h>

void print(int nums[], int n) {
  int i = 0;
  for (i = 0; i < n; i++) {
    printf("%d  ", nums[i]);
  }
}

void insertionSort(int nums[], int n) {
  int i = 1, j = 0, temp = 0;
  for (i = 1; i < n; i++) {
    temp = nums[i];
    j = i - 1;

    while (j >= 0 && nums[j] > temp) {
      nums[j + 1] = nums[j];
      j--;
    }

    nums[j + 1] = temp;
  }

  print(nums, n);
}

int main() {
  int n;
  printf("Enter size of the array: ");
  scanf("%d", &n);

  int nums[n];
  printf("Enter the values in array:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &nums[i]);
  }

  insertionSort(nums, n);
  return 0;
}
```
