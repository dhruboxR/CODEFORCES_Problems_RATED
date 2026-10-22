// https://codeforces.com/problemset/problem/2261/C

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ull unsigned long long
#define ld long double
#define whole(vect) (vect).begin(), (vect).end()
#define rwhole(vect) (vect).rbegin(), (vect).rend()
#define print_yes (cout << "YES" << endl)
#define print_no (cout << "NO" << endl)
#define print_zero (cout << "0" << endl)
#define negative (cout << "-1" << endl)

// so many edge cases to handle -_-

void solve() {
    int n;  cin >> n; vector<int> source(n);  
    int sum = 0, odd = 0, even = 0; 

    for(auto &v : source) {
        cin >> v;   sum += v; 
        if(v&1) ++odd;  else ++even; 
    }

    if(n == 1 || sum % 2 == 0) {cout << "moggity" << endl; return;}

    // only odd elements 
    if(odd && !even) {
        cout << (odd == 3 ? "larpity" : "moggity") << endl;  
    } else {
        // odd even both exists and the sum is not even 
        cout << (n == 2 ? "larpity" : "moggity") << endl; 
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case; cin >> test_case;
    while (test_case--) {
        solve();
    }

    return 0;
}