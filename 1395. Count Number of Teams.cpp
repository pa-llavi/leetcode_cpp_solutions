/*
There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

 

Example 1:

Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 
Example 2:

Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.
*/


class Solution {
public:
    int numTeams(vector<int>& rating) {
        
        int n = rating.size(), cnt=0;
        
        for(int i=1; i<n-1; i++) {
            int rightSmall=0, rightLarge=0;
            int leftSmall=0, leftLarge=0;
            
            for(int j=0; j<i; j++) {
                if(rating[i] > rating[j]) {
                    leftSmall++;
                }
                if(rating[i] <rating[j]) {
                    leftLarge++;
                }
            }
            
            for(int j=i+1; j<n; j++) {
                if(rating[i] > rating[j]) {
                    rightSmall++;
                }
                if(rating[i] <rating[j]) {
                    rightLarge++;
                }
            }
            cnt += leftSmall*rightLarge + leftLarge*rightSmall;
        }
        return cnt;
    }
};
