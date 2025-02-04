class Solution {
public:
    bool isVowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c=='u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c=='U'){
            return true;
        }
        return false;
    }
    string reverseVowels(string str) {
        int i = 0, j = str.size()-1;
        while(i < j ){
            while ( i < j && !isVowel(str[i])){
                i++;
            }
            while(i < j  && !isVowel(str[j])){
                j--;
            }
            if(i < j){
                swap(str[i], str[j]);
                i++;
                j--;
            }
            
        }
        return str;
    }
};