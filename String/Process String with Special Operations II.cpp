/*
Leetcode Link: https://leetcode.com/problems/process-string-with-special-operations-ii/

Approach: Reverse Simulation

Intuition:
The resulting string can grow exponentially because of the '#' operation
(duplicate the current string). Therefore, explicitly constructing the
final string is infeasible.

Instead, we only track the length of the string after processing each
character. Once the final length is known, we traverse the operations
backwards and map the target index k to the index it originated from.

Forward Simulation (length only):
---------------------------------
letter : length += 1
'*'    : length = max(0, length - 1)
'#'    : length *= 2
'%'    : length remains unchanged

Reverse Simulation:
-------------------
Let 'length' represent the size of the string before processing s[i+1].

1. Letter:
   - This character was appended at position (length - 1).
   - If k == length - 1, this is the answer.
   - Otherwise, remove it from consideration:
         length--

2. '#': duplicate current string
   Before operation:
         A
   After operation:
         A + A

   If k belongs to the second half, it originated from the first half:
         if (k >= length / 2)
             k -= length / 2

   Restore previous length:
         length /= 2

3. '*': remove last character
   Before operation length = L + 1
   After operation length = L

   While reversing, simply restore the removed position:
         length++

4. '%': reverse string
   Reversal does not change length.

   If the string length is L, index k before reversal becomes:
         k = L - 1 - k

Complexity:
-----------
Time Complexity  : O(n)
Space Complexity : O(1)

We never construct the actual string; we only maintain its length and
continuously remap k while traversing the operations in reverse.
*/


class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;
        int n = s.length();

        for(char c : s){
            if(c=='*'){
                if(len>0){
                    len--;
                }
            }
                else if(c == '#'){
                    len *= 2;
                }
                else if(c == '%')continue;
                else len++;
            
        }

        if(k>=len) return '.';


        for(int i=n-1 ; i>=0 ;i--){
            if(s[i]=='*'){
                len++;
            }
            else if(s[i]=='#'){
                len = len/2;
                if(k>=len){
                    k = k-len;
                }
            }
            else if(s[i]=='%'){
                k = len-k-1;
            }
            else{
                len--;
            }
            if(k==len){
                return s[i];
            }
        }
        return '.';

    }
};