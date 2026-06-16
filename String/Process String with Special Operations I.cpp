/*Leetcode Link : https://leetcode.com/problems/process-string-with-special-operations-i/ */
// Approach 1: Simulate the described operations while traversing the string

// Time Complexity: O(n) where n is the length of the input string s
// Space Complexity: O(1)

// C++ implementation

class Solution {
public:
    string processStr(string s) {
        string res = "";
        for(char c : s){
            if(c=='#'){
                res = res+res;
            }
            else if(c=='%'){
                reverse(res.begin(),res.end());
            }
            else if(c=='*'){
                if(!res.empty()){
                    res.pop_back();
                }
            }
            else{
                res = res+c;
            }
        }
        return res;
    }
};