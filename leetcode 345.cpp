class Solution {
public:
   bool isVowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || 
            c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
  
  
    string reverseVowels(string s) {
        int i = 0, j = s.length()-1;
        while(i<j) {
            while(i<j && !isVowel(s[i])) i++;
            while(i<j && !isVowel(s[j])) j--;
            if(i<j) swap(s[i++], s[j--]);
        }
        return s;
    }
   
};