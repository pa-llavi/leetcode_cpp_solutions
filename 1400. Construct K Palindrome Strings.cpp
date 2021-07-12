class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        // edge case 
        if(k > n)
            return false;
        if(k == n)
            return true;
        
        unordered_map<char, int> freq;
        for(int i=0; i<n; i++) {
            freq[s[i]]++;
        }
        
        // counting how many char appears odd # times
        int odd = 0;
        for(auto f : freq) {
            if(f.second % 2 != 0) 
                odd++;
        }
        
        // if char apearing odd times is greater than k then we cannot divide it into palindrome
        if(odd > k)
            return false;
        return true;
    }
};
