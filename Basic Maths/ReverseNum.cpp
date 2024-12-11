class Solution {
public:
    int reverse(int x) {
        long n = 0;
        long p = x;

        int flag = 0;
        if(p<0)
        {
            p = abs(p);
            flag = 1;
        }

        while(p>0)
        {
            int r = p%10;

            n = (n*10) + r;
            p = p/10;
        }

        if(flag == 1){
            n = -n;
        }

        if(n>INT_MAX || n<INT_MIN) return 0;

        return int(n);
    }
};