#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>  //sending rand stuff
using namespace std;

// Function to partition the array A[p...r]
int Randomized_Partition(vector<int> &A, int p, int r) {
    // Generate a random index i between p and r
    int i = rand() % (r - p + 1) + p; // Time Complexity: O(1), generating a random number.

    // Swap A[r] and A[i] to use A[i] as the pivot
    swap(A[r], A[i]); // Time Complexity: O(1), swapping two elements. makes sure pivot at end

    int pivot = A[r];
    int i_less = p - 1;  // Index of the last element less than the pivot

    // Iterate through the subarray and rearrange elements
    for (int j = p; j < r; j++) {
        if (A[j] <= pivot) {
            i_less++;
            swap(A[i_less], A[j]); // Time Complexity: O(1), swapping two elements.
        }
    }

    // Place the pivot in its correct position
    swap(A[i_less + 1], A[r]); // Time Complexity: O(1), swapping two elements.

    return i_less + 1;
}

// Randomized QuickSort algorithm
void Randomized_QuickSort(vector<int> &A, int p, int r) {
    if (p < r) { //makes sure more than one element in sub is sorted
        int q = Randomized_Partition(A, p, r); // Time Complexity: O(r - p)

        // Recursively sort the two subarrays
        Randomized_QuickSort(A, p, q - 1); // Time Complexity: T(n/2) left
        Randomized_QuickSort(A, q + 1, r); // Time Complexity: T(n/2) right
    }
}

int main() {
    int numbers;
    cin >> numbers;

    vector<int> A(numbers);

    // Seed the random number generator
    srand(time(0));

    // Input elements into the array
    for (int i = 0; i < numbers; i++) {
        cin >> A[i];
    }

    // Sort the array using Randomized QuickSort
    Randomized_QuickSort(A, 0, numbers - 1); // Time Complexity: T(n)

    // Print the sorted array
    for (int i = 0; i < numbers; i++) {
        cout << A[i] << ";";
    }

    return 0;
}
