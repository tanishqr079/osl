#include <stdio.h>

// Function to calculate the average of the array
float calculate_average(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (float)sum / size;
}

// Function to find the maximum element in the array
int find_maximum(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int n;

    // Input array size
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Input array elements
    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate average and maximum
    float average = calculate_average(arr, n);
    int maximum = find_maximum(arr, n);

    // Display results
    printf("The average of the array elements is: %.2f\n", average);
    printf("The maximum element in the array is: %d\n", maximum);

    return 0;
}
