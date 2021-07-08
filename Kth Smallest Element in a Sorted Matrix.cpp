/*
Given an n x n matrix where each of the rows and columns are sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5
 

Constraints:

n == matrix.length
n == matrix[i].length
1 <= n <= 300
-109 <= matrix[i][j] <= 109
All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
1 <= k <= n2
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> tmp;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[i].size(); j++) {
                tmp.push_back(matrix[i][j]);
            }
        }
        
        sort(tmp.begin(), tmp.end());
        
        return tmp[k-1];
    }
};

/***************** Binary search ************************

Since each row and column of the matrix is sorted, is it possible to use Binary Search to find the Kth smallest number?

The biggest problem to use Binary Search in this case is that we don’t have a straightforward sorted array, instead we have a matrix. As we remember, in Binary Search, we calculate the middle index of the search space (‘1’ to ‘N’) and see if our required number is pointed out by the middle index; if not we either search in the lower half or the upper half. In a sorted matrix, we can’t really find a middle. Even if we do consider some index as middle, it is not straightforward to find the search space containing numbers bigger or smaller than the number pointed out by the middle index.

An alternate could be to apply the Binary Search on the “number range” instead of the “index range”. As we know that the smallest number of our matrix is at the top left corner and the biggest number is at the bottom lower corner. These two number can represent the “range” i.e., the start and the end for the Binary Search. Here is how our algorithm will work:

Start the Binary Search with start = matrix[0][0] and end = matrix[n-1][n-1].
Find middle of the start and the end. This middle number is NOT necessarily an element in the matrix.
Count all the numbers smaller than or equal to middle in the matrix. As the matrix is sorted, we can do this in O(N).
While counting, we can keep track of the “smallest number greater than the middle” (let’s call it n1) and at the same time the “biggest number less than or equal to the middle” (let’s call it n2). These two numbers will be used to adjust the "number range" for the Binary Search in the next iteration.
If the count is equal to ‘K’, n1 will be our required number as it is the “biggest number less than or equal to the middle”, and is definitely present in the matrix.
If the count is less than ‘K’, we can update start = n2 to search in the higher part of the matrix and if the count is greater than ‘K’, we can update end = n1 to search in the lower part of the matrix in the next iteration.

*/
class KthSmallestInSortedMatrix {
 public:
  static int findKthSmallest(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();
    int start = matrix[0][0], end = matrix[n - 1][n - 1];
    while (start < end) {
      int mid = start + (end - start) / 2;
      // first number is the smallest and the second number is the largest
      pair<int, int> smallLargePair = {matrix[0][0], matrix[n - 1][n - 1]};
      int count = countLessEqual(matrix, mid, smallLargePair);
      if (count == k) {
        return smallLargePair.first;
      }

      if (count < k) {
        start = smallLargePair.second;  // search higher
      } else {
        end = smallLargePair.first;  // search lower
      }
    }

    return start;
  }

 private:
  static int countLessEqual(vector<vector<int>> &matrix, int mid, pair<int, int> &smallLargePair) {
    int count = 0;
    int n = matrix.size(), row = n - 1, col = 0;
    while (row >= 0 && col < n) {
      if (matrix[row][col] > mid) {
        // as matrix[row][col] is bigger than the mid, let's keep track of the
        // smallest number greater than the mid
        smallLargePair.second = min(smallLargePair.second, matrix[row][col]);
        row--;
      } else {
        // as matrix[row][col] is less than or equal to the mid, let's keep track of the
        // biggest number less than or equal to the mid
        smallLargePair.first = max(smallLargePair.first, matrix[row][col]);
        count += row + 1;
        col++;
      }
    }
    return count;
  }
};
