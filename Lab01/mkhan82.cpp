#include <iostream>
using namespace std;


// INSERTION-SORT(A)
// 1 for j = 2 to A.length
// 2
// key = A[i]
// 3// Insert A [j] into the sorted sequence A[1.. j - 1].
// 4 i = j-1
// 5 whilA i > kee i > 0 and y
// 6 A[i + 1] = A[i]
// 7 i = i - 1
// 8 A[i + 1] = key

//average: o(n^2)
//Big pog: o(n) when nothing to shift
//worst: decending order: ex: [7,6,5,4,3,2,1,0]
void insertionSort(int arr[], int numbers)
{
  for (int i = 1; i < numbers; i++) //we start from second element which helps us shift
  {
    int key = arr[i];
    int j = i - 1; // j will be set to sorted sub array
    // SHIFT elements in the arr[????] greater than key
    // by one pos ahead of their current pos
    while (j >= 0 && arr[j] > key) //intention to start comparing key with elements here; shift if bigger
    {
      arr[j + 1] = arr[j]; //This portion/loop inside the for makes it o(n^2) as its responsible for shifting no elements to be shifted = o(n) time
      j--;
    }
    arr[j + 1] = key;

    for (int k = 0; k <= i; k++) //printing
    {
      cout << arr[k];
      if (k < i) 
        cout << ";";
    }
    cout << ";"; //sad print added at end to ende with ;
    cout << endl;
  }
}

int main()
{
  int numbers; //undefined int numbers
  cin >>  numbers; //user input

  int arr[numbers]; // create array of user input size
  for (int i = 0; i < numbers; i++) //for size of array put numbers into array
  {
    cin >> arr[i];
  }

  insertionSort(arr,numbers); //call insertion sort (above)

  return 0;
}
