#include <bits/stdc++.h>
using namespace std;

string gett(int k) {

    int place = min(6,k); // maximum number of digits that will be grater than 1
    int have = pow(9,place);    // This is the max product

    int summ = place*9 + (k-place);     // Max sum which can be obtained

    while(have>=sum){
        have /= 9;
        summ -= 9;
        summ += 1;
    }

    have *= 9;      // Because here, have<sum
    summ += (9 - 1);

    string s(k,'1');

    int have2 = have;
    int i = 0;

    while(have2 >= 9){
        s[i] = '9';
        have2 /= 9;
        i++;
    }

    i = 0;
    int sum2 = summ;

    while(s[i] == '9'){
        int dig = 9;
        for (int j = 1; j <= 9; j++) {
            have2 = (have/9) * j;
            sum2 = summ - 9 + j;

            if (have2 >= sum2) {
                have = have2;
                summ = sum2;
                dig = j;
                break;
            }
        }
        s[i] = dig + '0';
        i++;
    }

    sort(s.begin(),s.end());
    return s;

}

int main() {
    int k;
    cin>>k;

    cout<<gett(k)<<endl;
    return 0;
}