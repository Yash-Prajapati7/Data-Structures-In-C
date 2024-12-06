## C
```c
#include <stdio.h>
#include <math.h>

int min(int x, int y) {
    return x <= y ? x : y;
}

// Function to calculate the nth Fibonacci number
int fib(int n) {
    double phi = (1 + sqrt(5)) / 2;
    return round(pow(phi, n) / sqrt(5));
}

int fibSearch(int nums[], int n, int x) {
    // Find the smallest Fibonacci number greater than or equal to n
    int k = 0;
    while (fib(k) < n) {
        k++;
    }

    int offset = -1;

    while (k > 1) {
        int i = min(offset + fib(k - 2), n - 1);
        if (nums[i] < x) {
            offset = i;
        }
        else if (nums[i] > x) {
            k -= 2;
        }
        else {
            return i;
        }
    }

    // Compare the last element
    if (k == 1 && nums[offset + 1] == x) {
        return offset + 1;
    }

    return -1; // Element not found
}

int main() {
    int n = 6;
    int nums[] = {0, 2, 5, 12, 42, 76};
    int x = 42;

    int index = fibSearch(nums, n, x);
    if (index != -1) {
        printf("Element found at index: %d\n", index);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
```
