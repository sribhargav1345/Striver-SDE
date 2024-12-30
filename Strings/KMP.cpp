#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void computelps(string& pattern,vector<int>& lps)
{
    int length = 0;
    lps[0] = 0;

    int n = pattern.size();
    int i = 1;

    while(i<n)
    {
        if(pattern[i] == pattern[length]){
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            if(length != 0){
                length = lps[length-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string& text, string& pattern)
{
    int n = text.size();
    int m = pattern.size();

    vector<int> lps(m); // LPS array to store longest prefix suffix values
    computeLPSArray(pattern, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }


}

int main()
{
    string text = "ABABDABABDABB";
    string pattern = "BABD";

    KMPSearch(text,pattern);
}