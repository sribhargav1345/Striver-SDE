class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;

        long n = 0;
        long p = x;
        while(p>0)
        {
            int r = p%10;
            n = n*10 + r;

            p = p/10;
        }

        return (x==n);
    }
};