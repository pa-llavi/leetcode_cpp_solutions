class Solution {
public:
    static bool compare(const pair<int,int> &a , const pair<int,int> &b){
        if(a.first==b.first)
        {
            return a.second>b.second;
        }
        else
        {
            return a.first<b.first;
        }
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        
        vector<pair<int, int>> v;
        for(auto i = mp.begin(); i!=mp.end(); i++){
            v.push_back(make_pair(i->second, i->first));
        }
        sort(v.begin(), v.end(), compare);
        
        vector<int> res;
        for(int i=0;i<v.size();i++)
        {
            while(v[i].first>0)
            {
                res.push_back(v[i].second);
                v[i].first--;
            }
        }
        return res;
    }
};
