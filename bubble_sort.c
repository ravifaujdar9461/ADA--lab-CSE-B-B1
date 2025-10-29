#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bubble sort function
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0; // Optimization: check if already sorted
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break; // if no swapping happened, array already sorted
    }
}

// Function to generate random array
void generateRandomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000; // values between 0–99999
    }
}

int main()
{
    srand(time(NULL));
    int n;

    printf("Enter the array size: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    generateRandomArray(arr, n);

    clock_t start = clock();
    bubbleSort(arr, n);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements (Bubble Sort): %f seconds\n", n, time_taken);

    free(arr);
    return 0;
}
