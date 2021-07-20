class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> mx(k);
        vector<int> ans;
        
        // for first k elements
        for(int i=0; i<k; i++) {
            while(!mx.empty() && nums[i] > nums[mx.back()])
                mx.pop_back();
            mx.push_back(i);
        }
        
        // sliding window
        for(int i=k; i<nums.size(); i++) {
            
            // cout<<nums[i]<<" "<<nums[mx.back()]<<endl;
            
            ans.push_back(nums[mx.front()]);
            
            // delete out of scope elemnts of window
            while(!mx.empty() && mx.front()<=i-k) {
                mx.pop_front();
            }
            
            // delete smaller elements than cur added element
            while(!mx.empty() && nums[i]>=nums[mx.back()]) {
                mx.pop_back();
            }
            
            // add cur ele
            mx.push_back(i);
        }
        ans.push_back(nums[mx.front()]);
        return ans;
    }
};
