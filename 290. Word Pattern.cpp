/*
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", s = "dog dog dog dog"
Output: false
 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lower-case English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> StoP; 
        unordered_map<string, char> PtoS;
        
        stringstream sss(s); // Used for breaking words
        string word; // To store individual words
        
        // if length of both pattern and s is diff then return false
        int count = 0;
        while (sss >> word)
            count++;
        if(count != pattern.length())
            return false;
        
        int i=0;
        stringstream ss(s); 
        string Word;
        while(ss >> Word) {
            // cout<<Word<<" "<<pattern[i]<<endl;
            
            // if mapping dosen't exist in either of the maps
            if(StoP.find(pattern[i]) == StoP.end() && PtoS.find(Word) == PtoS.end()) {
                StoP[pattern[i]] = Word;
                PtoS[Word] = pattern[i];
            } 
            // if mapping dosen't exist in one of the maps or mapping exist but dosen't match
            else if(!(StoP[pattern[i]] == Word && PtoS[Word] == pattern[i])) {
                return false;
            }
            i++;
        }
        return true;
    }
};
