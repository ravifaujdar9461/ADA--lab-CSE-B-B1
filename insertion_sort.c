#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function for insertion sort
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to generate random array elements
void generateRandomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000; // random values between 0 and 99999
    }
}

// Main function
int main()
{
    srand(time(NULL));
    int n;

    printf("Enter the array size: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Generate random numbers
    generateRandomArray(arr, n);

    // Start time
    clock_t start = clock();

    // Perform insertion sort
    insertionSort(arr, n);

    // End time
    clock_t end = clock();

    // Calculate total time taken
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to sort %d elements: %f seconds\n", n, time_taken);

    // Free allocated memory
    free(arr);

    return 0;
}
