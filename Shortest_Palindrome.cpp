//214 leetcode Shortest Palindrome 
//Optimised for c++ .. use substr in other languages
TC is O(n^2)
class Solution {
public:
    string shortestPalindrome(string s) {
        //brute force optimised for c++ using memcmp
        string rev = s;
        reverse(begin(rev), end(rev));
        int n = s.length();
        for(int i =0;i<n;i++){
            if(!memcmp(s.c_str(),rev.c_str()+i, n-i )){
                return rev.substr(0,i) +s;
            }
        }
        return rev +s;
    }
};
