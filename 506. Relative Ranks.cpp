class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        map<int, int> scores;
        int sze = nums.size();
        for(int i=0;i<sze;i++) scores.insert({nums[i], i});
        sort(nums.begin(), nums.end());
        vector<string> ans(sze);
        if (sze >= 1) ans[scores[nums[sze-1]]] = "Gold Medal";
        if (sze >= 2) ans[scores[nums[sze-2]]] = "Silver Medal";
        if (sze >= 3) ans[scores[nums[sze-3]]] = "Bronze Medal";
        for(int i=0;i<sze-3;i++) {
            ans[scores[nums[i]]] = to_string(sze - i);
        }
        return ans;
    }
};
