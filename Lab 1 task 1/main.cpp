#include <iostream>

// Function to calculate the summation of elements in the array
int summation(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum;
}

// Function to find the maximum element in the array
int maximum(int arr[], int n) {
    int maxElement = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    return maxElement;
}

int main() {
    // Obtain the length of the array from the user
    int n;
    std::cout << "Enter the length of the array: ";
    std::cin >> n;

    // Declare an array of length n
    int arr[n];

    // Allow the user to enter n integers and store them in the array
    std::cout << "Enter " << n << " integers:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter integer #" << (i + 1) << ": ";
        std::cin >> arr[i];
    }

    // Call the summation function and display its output
    int sum = summation(arr, n);
    std::cout << "Summation of the array: " << sum << std::endl;

    // Call the maximum function and display its output
    int max = maximum(arr, n);
    std::cout << "Maximum element in the array: " << max << std::endl;

    return 0;
}



