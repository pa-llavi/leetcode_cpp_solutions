/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> StoT, TtoS;
        
        for(int i=0; i<s.size(); i++) {
            // if mapping dosen't exist in either of the maps
            if(StoT.find(s[i]) == StoT.end() && TtoS.find(t[i]) == TtoS.end()) {
                StoT[s[i]] = t[i];
                TtoS[t[i]] = s[i];
            } 
            // if mapping dosen't exist in one of the maps or mapping exist but dosen't match
            else if(!(StoT[s[i]] == t[i] && TtoS[t[i]] == s[i])) {
                return false;
            }
        }
        return true;
    }
};
