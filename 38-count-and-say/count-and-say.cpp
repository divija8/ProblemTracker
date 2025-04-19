class Solution {
public:
    string countAndSay(int n) {

        if(n==1) return "1";
        if(n==2) return "11";
        int c=1;
       string str="11";

       for(int i=3;i<=n;i++){
        string res="";
        int j=1;  
        str+="$";  
        while(j<str.length()){
            if(str[j]!=str[j-1]){
                res+=c+'0';
                res+=str[j-1];
                c=1;
            }
            else{
                c++;
            }
            j++;
        }
        str=res;
       }

      return str;
      
    }
};