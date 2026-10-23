// https://codeforces.com/contest/1469/problem/B

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
    Exploring all interleavings: 
        - By branching into dp_calc(i+1, j) and dp_calc(i, j+1), 
        - the recursion explores every valid way to interleave the elements of a and b.

    Covering all prefixes: 
        - Because the recursion starts at (0, 0) and explores all paths down to (n, m), 
        - it tests virtually every possible prefix configuration,
        - and max({mx, s1, s2}) keeps track of the peak sum achieved anywhere along those paths.
*/

int dp[105][105]; 
int a[105];
int b[105]; 

int dp_calc(int i, int j, int n, int m) {
    int mx = 0, s1 = 0, s2 = 0; 

    if(i >= n && j >= m) return 0; 
    if(dp[i][j] != -1) return dp[i][j]; 

    if(i < n) s1 = a[i] + dp_calc(i+1, j, n, m);   // inlcude elements from a if available 
    if(j < m) s2 = b[j] + dp_calc(i, j+1, n, m);   // include elements from b if available 

    mx = max({mx, s1, s2});  

    dp[i][j] = mx; 
    
    return dp[i][j]; 
}

void solve() {
    int n;  cin >> n;   for(int i = 0; i < n; i++) cin >> a[i]; 
    int m;  cin >> m;   for(int i = 0; i < m; i++) cin >> b[i]; 

    memset(dp, -1, sizeof(dp)); 
    
    // Start recursion from the beginning (0 elements used from a, 0 from b)
    int result = dp_calc(0, 0, n, m);  
    
    cout << result << endl; 
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