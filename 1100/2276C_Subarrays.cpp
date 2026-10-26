// https://codeforces.com/problemset/problem/2276/C
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

void solve() {
    int n, k;   cin >> n >> k; 
    vector<int> source(n), pref(n+1, 0); 

    for(int i = 0; i < n; i++) {cin >> source[i]; pref[i+1] = (pref[i] + source[i]) % k;}

    int answer = 0; 
    vector<int> freq(n+1, 0); // store the moded freq 

    // we are updating the ferquency in the gap of k 
    for(int i = k+1;  i <= n; i++) {
        if(i-k-1 >= 0) freq[ pref[i-k-1] ]++; 

        answer += freq[pref[i]];     // can pair up with freq[pref[i]] subarrays 
    }

    cout << answer << endl; 
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