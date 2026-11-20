// https://codeforces.com/problemset/problem/1133/C
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
    int n;  cin >> n;   vector<int> source(n);
    for(auto &v : source) cin >> v; sort(whole(source)); 

    // the team difference must not be > 5 
    int mx = LLONG_MIN; 
    for(int i = 0; i < n; i++) {
        int tar = source[i] + 5; 
        int lidx = upper_bound(whole(source), tar) - source.begin();    

        mx = max(mx, lidx - i);
    }
    cout << mx << endl; 
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve(); 

    return 0;
}