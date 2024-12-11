#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

// Function to calculate power of a number modulo mod
int power(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        n = n >> 1;
    }
    return ans;
}

struct pairing {
    int a;
    int b;
};

// Comparator function to sort pairings based on 'a' and then 'b'
bool sort_on_basis_of_a(pairing p1, pairing p2) {
    if (p1.a != p2.a) {
        return (p1.a < p2.a);
    } else {
        return (p1.b < p2.b);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pairing> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].a;
    }

    for (int i = 0; i < n; i++) {
        cin >> p[i].b;
    }

    // Sort pairings based on 'a' and then 'b'
    sort(p.begin(), p.end(), sort_on_basis_of_a);

    vector<int> lis; // Vector to store LIS
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(lis.begin(), lis.end(), p[i].b) - lis.begin();
        if (pos == lis.size()) {
            lis.push_back(p[i].b); // Add to LIS if it's larger than any element in LIS
        } else {
            lis[pos] = p[i].b; // Replace element in LIS
        }
    }

    cout << lis.size() << endl; // Output the length of LIS

    return 0;
}
