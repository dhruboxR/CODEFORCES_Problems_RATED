// https://codeforces.com/problemset/problem/1359/B

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
    Each row can be processed independently 
        - it's always optimal to use 1*1 tiles if two (1*1) tiles are cheaper than one (1*2) tiles 
*/

void solve() {
    int n, m, x, y; cin >> n >> m >> x >> y; 
    vector<string> strip(n); 

    int cost = 0; 

    for(int i = 0; i < n; i++) {
        cin >> strip[ i ]; 

        // process the blocks ....**...*...
        for(int l = 0; l <  m; ++l) {
            if(strip[i][l] == '*') continue; 

            int r = l; 
            while(r+1 < m && strip[i][r+1] == '.') ++r; 
            
            int len = r - l + 1; 

            if(2*x <= y) cost += (len*x); 
            else cost += ((len/2)*y + (len%2)*x); 

            l = r; 
        }
    }

    cout << cost << endl; 
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