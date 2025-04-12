class Solution {
public:
    int fib(int n) {
        int a=0, b=1, c=0;
        if(n==0) {
            return a;
        } else if(n==1) {
            return b;
        }
        for(int i=2;i<=n;i++) {
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
};