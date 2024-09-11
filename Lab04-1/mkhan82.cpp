#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Function to get the index of the left child of a node in the heap
int Left(int i) {
    return 2 * i + 1;
}

// Function to get the index of the right child of a node in the heap
int Right(int i) {
    return 2 * i + 2;
}

// Function to maintain the max-heap property starting from a given node
// Time Complexity: O(log n), where n is the number of nodes in the subtree rooted at 'i'.
void Max_Heapify(vector<int> &A, int i, int heapSize) {
    int left = Left(i);
    int right = Right(i);
    int largest = i;

    // Check if the left child exists and is greater than the current largest
    if (left < heapSize && A[left] > A[largest]) {
        largest = left;
    }

    // Check if the right child exists and is greater than the current largest
    if (right < heapSize && A[right] > A[largest]) {
        largest = right;
    }

    // If the largest element is not the current node, swap and continue heapifying recursion
    if (largest != i) {
        swap(A[i], A[largest]);
        Max_Heapify(A, largest, heapSize);
    }
}

// Function to build a max-heap from an array
// Time Complexity: O(n), where n is the number of elements in the array.
void Build_Max_Heap(vector<int> &A) {
    int heapSize = A.size();

    // Start from the last non-leaf node and perform Max_Heapify for each node
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        Max_Heapify(A, i, heapSize);
    }
}

// Function to perform Heap Sort on an array
// Time Complexity: O(n log n), where n is the number of elements in the array.
void Heap_Sort(vector<int> &A) {
    int heapSize = A.size();
    Build_Max_Heap(A);
    //Start from the end of the array and move the maximum element
    // Move the maximum element to the end of the array and reduce heap size
    for (int i = heapSize - 1; i >= 1; i--) {
        swap(A[0], A[i]);
        heapSize--;
        Max_Heapify(A, 0, heapSize);
    }
}

int main() {
    int numbers;
    cin >> numbers;

    vector<int> A(numbers);

    // Input elements into the array
    for (int i = 0; i < numbers; i++) {
        cin >> A[i];
    }
    int heapSize = A.size();

    // Build a max-heap from the given array
    Heap_Sort(A);

    // Print the sorted array
    for (int i = 0; i < heapSize; i++) {
        cout << A[i] << ";";
    }

    return 0;
}
