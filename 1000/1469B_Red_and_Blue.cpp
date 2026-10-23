// https://codeforces.com/problemset/problem/1469/B

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
/*
    summation of (max_prefixSum from a && max_prefixSum from b)
*/
void solve() {
    int n;  cin >> n; vector<int>a(n), pre_a(n+1, 0); 
    for(int i = 0; i < n; i++) {cin >> a[i]; pre_a[i+1] = a[i] + pre_a[i];}

    int m;  cin >> m; vector<int>b(m), pre_b(m+1, 0); 
    for(int i = 0; i < m; i++) {cin >> b[i]; pre_b[i+1] = b[i] + pre_b[i];}

    int first = *max_element(whole(pre_a)), second = *max_element(whole(pre_b));

    cout << max(0ll, first+second) << endl; 
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