// https://codeforces.com/problemset/problem/2278/B

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

bool is_pal(string s, int n) {
    for(int i = 0; i <= n/2; i++) {
        if(s[i] != s[n-i-1]) return false;
    }
    return true; 
}

// just beat the move that appears maximum number of times 
// paper beats rock 
// scissors beats paper 
// rock beats scissors 

void solve() {
    int x, y, z;    cin >> x >> y >> z; 
    // rock, scissors, paper
    if(max({x, y, z}) == x) {
        string xx(x+y+z, 'P'); cout << xx << endl;
    }
    else if(max({x, y, z}) == y) {
        string yy(x+y+z, 'R'); cout << yy << endl;
    } else {
        string zz(x+y+z, 'S'); cout << zz << endl; 
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