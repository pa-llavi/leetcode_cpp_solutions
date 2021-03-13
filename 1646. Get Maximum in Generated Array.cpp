class Solution {
public:
    int getMaximumGenerated(int n) {
        //edge case
        if(n == 0 || n == 1) {
            return n;
        } 
        
        int mx = 0;
        vector<int> v;
        v.push_back(0);
        v.push_back(1);
        
        for(int i=2; i<=n; i++) {
            if(i%2 == 0) {
                v.push_back(v[i/2]);    
            } else {
                v.push_back(v[i/2] + v[i/2 + 1]);
            }
            mx = max(mx, v.back());
        }
        return mx;
    }
};
