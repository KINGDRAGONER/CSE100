#include <iostream>
#include <vector>
#include <limits>
using namespace std;
// FIND-MAX-CROSSING-SUBARRAY (A, low, mid, high)
// 1 left-sum
// -00
// 2 sum = 0
// 3 for i = mid downto low
// 4
// sum = sum + Alil
// 5
// if sum > left-sum
// 6
// left-sum = sum
// 7
// max-left = i
// 8 right-sum = -00
// 9 sum = 0
// 10 for j = mid + 1 to high
// 11
// sum = sum + Alil
// 12
// if sum > right-sum
// 13
// right-sum = sum
// 14
// max-right = j
// 15 return (max-left, max-right, left-sum + right-sum)



// FIND-MAXIMUM-SUBARRAY(A, low, high)
//  if high == low
// return (low, high, A[low])
// / base case: only one element
//   else mid = L(low + high) /2]
// (left-low, left-high, left-sum) =
// FIND-MAXIMUM-SUBARRAY (A, low, mid)
// (right-low, right-high, right-sum) =
// FIND-MAXIMUM-SUBARRAY (A, mid + 1, high)
// (cross-low, cross-high, cross-sum) =
// FIND-MAX-CROSSING-SUBARRAY (A, low, mid, high)
// if left-sum ≥ right-sum and left-sum ≥ cross-sum
// return (left-low, left-high, left-sum)
// elseif right-sum ≥ left-sum and right-sum ≥ cross-sum
// return (right-low, right-high, right-sum
// else return (cross-low cross_hich cross_sum
void findMaxCrossingSubarray(vector<int> &A, int low, int mid, int high, int &maxLeft, int &maxRight, int &maxSum)
{
    int leftMaxSum = numeric_limits<int>::min();
    int leftSum = 0;
    maxLeft = mid;

    for (int i = mid; i >= low; i--)
    {
        leftSum += A[i];
        if (leftSum > leftMaxSum)
        {
            leftMaxSum = leftSum; // change the left maximum sum and index if needed
            maxLeft = i;
        }
    }

    int rightMaxSum = numeric_limits<int>::min();
    int rightSum = 0;
    maxRight = mid + 1;

    for (int i = mid + 1; i <= high; i++)
    {
        rightSum += A[i];
        if (rightSum > rightMaxSum)
        {
            rightMaxSum = rightSum;
            maxRight = i;
        }
    }

    maxSum = leftMaxSum + rightMaxSum;
}

void findMaxSubarray(vector<int> &A, int low, int high, int &maxLeft, int &maxRight, int &maxSum)
{
    if (low == high)//Base case: If there's only one element in the array
    {
        maxLeft = low;
        maxRight = high;
        maxSum = A[low];
        return;
    }

    int mid = (low + high) / 2; //we need a mid bruh

    int leftMaxLeft, leftMaxRight, leftMaxSum;
    findMaxSubarray(A, low, mid, leftMaxLeft, leftMaxRight, leftMaxSum);

    int rightMaxLeft, rightMaxRight, rightMaxSum;
    findMaxSubarray(A, mid + 1, high, rightMaxLeft, rightMaxRight, rightMaxSum);

    int crossMaxLeft, crossMaxRight, crossMaxSum;
    findMaxCrossingSubarray(A, low, mid, high, crossMaxLeft, crossMaxRight, crossMaxSum);
// we check here from the left and right and crossing subs
    if (leftMaxSum >= rightMaxSum && leftMaxSum >= crossMaxSum)
    {
        maxLeft = leftMaxLeft;
        maxRight = leftMaxRight;
        maxSum = leftMaxSum;
    }
    else if (rightMaxSum >= leftMaxSum && rightMaxSum >= crossMaxSum)
    {
        maxLeft = rightMaxLeft;
        maxRight = rightMaxRight;
        maxSum = rightMaxSum;
    }
    else
    {
        maxLeft = crossMaxLeft;
        maxRight = crossMaxRight;
        maxSum = crossMaxSum;
    }
}

int main()
{
    int numbers;
    cin >> numbers;

    vector<int> A(numbers);

    for (int i = 0; i < numbers; i++)
    {
        cin >> A[i];
    }

    int maxLeft = 0;
    int maxRight = 0;
    int maxSum = A[0];

    findMaxSubarray(A, 0, numbers - 1, maxLeft, maxRight, maxSum);

    cout << maxSum;

    return 0;
}
// Time Complexity:
// The findMaxCrossingSubarray function works in linear time O(n) because it iterates through the array once.
//total o(nlogn)
// Space Complexity: o(n) probally not too important for me
// The recursion relation for the findMaxSubarray function is:

// T(n) = 2T(n/2) + O(n)