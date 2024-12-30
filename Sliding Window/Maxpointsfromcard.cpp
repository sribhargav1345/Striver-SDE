class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        int n = cards.size();
        int i = 0,j = 0;

        int tot = accumulate(cards.begin(),cards.end(),0);

        int sum = 0,mini = INT_MAX;
        while(j<n)
        {
            sum += cards[j];
            
            while(j-i+1 > n-k)
            {
                sum -= cards[i];
                i++;
            }

            if(n-k == j-i+1)
            {
                mini = min(mini,sum);
            }
            j++;
        }
        return tot-mini;
    }
};