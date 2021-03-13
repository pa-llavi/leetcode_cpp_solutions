class Solution {
public:
    int minOperations(string s) {
        int odd=0, even=0;
        for(int i=0; i<s.size(); i++) {
            //for even place of 0's i.e. starting with 0
            if((i%2 == 0 && s[i] == '1') || (i%2 != 0 && s[i] == '0')) {
                even++;
            }
            
            //for odd place of 0's i.e. starting with 1
            if((i%2 == 0 && s[i] == '0') || (i%2 != 0 && s[i] == '1')) {
                odd++;
            }
        }
        
        return min(odd, even);
    }
};
