#include <iostream>
#include <vector>
using namespace std;

// MERGE(A, p, q, r)
// n1=q-p+1
// n2 = r -q
// let L[1..n, + 1] and R[1 .. 2 + 1] be new arrays
// for i = 1 to n1
// [i] = A[p + i - 1]
// for j = 1 to nz
// R[i] = A[g + j]
// [Ins + 1] = ∞
// R[n2 + 1] = ∞
// i = 1
// j = 1
// for k = p to r
//  if L[i]<= R[j]
//    A[k] = [i]
//    i=i+l
//  else A[k] = R[j]
//    j= j+1

// MERGE-SORT(A, p,r)
  // if p<r

  // q = [(p + r)/2]

  // MERGE-SORT(A, p,q)

  // MERGE-SORT(A, q + 1, r)

  // MERGE(A, p, q,r)



// Merge function: merges two sorted subarrays into a single sorted subarray
void Merge(int *A, int p, int q, int r)
{
  // Calculate the sizes of the two subarrays
  int n1 = q - p + 1; // Size of left subarray
  int n2 = r - q;     // Size of right subarray

  // Create temporary arrays to hold the subarrays
  int *L = new int[n1];
  int *R = new int[n2];

  // Copy data from the main array 'A' into the temporary left and right subarrays
  for (int i = 0; i < n1; i++)
  {
    L[i] = A[p + i];
  }

  for (int j = 0; j < n2; j++)
  {
    R[j] = A[q + 1 + j];
  }

  // Merge the two subarrays back into the main array 'A'
  int i = 0; // Initial index of the left subarray
  int j = 0; // Initial index of the right subarray
  int k = p; // Initial index of the merged subarray

  // Compare elements from both subarrays and merge them in sorted order
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      A[k] = L[i];
      i++;
    }
    else
    {
      A[k] = R[j];
      j++;
    }
    k++;
  }

  // Copy any remaining elements from the left subarray, if any
  while (i < n1)
  {
    A[k] = L[i];
    i++;
    k++;
  }

  // Copy any remaining elements from the right subarray, if any
  while (j < n2)
  {
    A[k] = R[j];
    j++;
    k++;
  }

  // Clean up: delete temporary arrays to avoid memory leaks
  delete[] L;
  delete[] R;
}

// Merge sort function: recursively divides and sorts the array
void mergeSort(int *A, int p, int r)
{
  if (p < r)
  {
    // Calculate the midpoint of the array
    int q = (p + r) / 2;

    // Recursively sort the left and right halves of the array
    mergeSort(A, p, q);
    mergeSort(A, q + 1, r);

    // Merge the sorted subarrays back together
    Merge(A, p, q, r);
  }
}




///Merge function 
// time complexity: o(n) where 'n' is the total number of elements being merged 
//                 (n = n1 + n2). This is because the while loop inside the Merge 
//                  function iterates through all elements of the left and right subarrays once.
// Merge Sort function
//Time complexity: O(n log n) as function recursively 
              // divides the array into halves until it reaches subarrays of size 1, 
              // and then merges them back together. 
              // The merge operation takes O(n) time, and the recursion depth is log(n).

//
int main()
{
  int n;
  cin >> n;
  int *elements = new int[n];

  // Input elements into the array
  for (int i = 0; i < n; i++)
  {
    cin >> elements[i];
  }

  // Perform merge sort on the array
  mergeSort(elements, 0, n - 1);

  // Output the sorted array
  for (int i = 0; i < n; i++)
  {
    cout << elements[i];

    // Add a semicolon separator for all elements except the last one
    if (i < n - 1)
    {
      cout << ";";
    }
  }

  // Print a semicolon after the sorted array
  cout << ";";

  // Clean up: release memory allocated for the array
  delete[] elements;

  return 0;
}