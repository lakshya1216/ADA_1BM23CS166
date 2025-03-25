#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000

void quicksort(int[], int, int);
int partition(int[], int, int);

int main() {
    int i, n, a[MAX], ch = 1;
    clock_t start, end;

    while (ch == 1) {
        printf("\nEnter the number of elements: ");
        scanf("%d", &n);

        if (n > MAX) {
            printf("Error: Maximum array size exceeded.\n");
            continue;
        }

        srand(time(NULL));
        for (i = 0; i < n; i++) {
            a[i] = rand() % 200;
        }

        printf("The randomly generated array is:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");

        start = clock();
        quicksort(a, 0, n - 1);
        end = clock();

        printf("\nThe sorted array elements are:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }

        printf("\nTime taken = %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

        printf("\nDo you wish to continue? (0 = No, 1 = Yes): ");
        scanf("%d", &ch);
    }

    return 0;
}

void quicksort(int a[], int low, int high) {
    int mid;
    if (low < high) {
        mid = partition(a, low, high);
        quicksort(a, low, mid - 1);
        quicksort(a, mid + 1, high);
    }
}

int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1, j = high, temp;

    while (i <= j) {
        while (i <= high && a[i] <= pivot) i++;
        while (a[j] > pivot) j--;

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}
