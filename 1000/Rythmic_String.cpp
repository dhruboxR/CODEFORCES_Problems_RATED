// https://codeforces.com/contest/2283/problem/B

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
    muiltiple numbers can only maintain the RYTHM if and only if their GCD is same 
        n <= 5000 (n2 solution is acceptable)

    - find the number with maximum number of multiples present in the array 
    - remove the rest 
*/

void solve() {
    int n;  cin >> n;   vector<int> source(n); 
    for(auto &v : source) cin >> v; 
    
    int mxMultiple = 0; 

    for(int i = 0; i < n; i++) {
        int div = source[i], mul = 0;  
        for(int j = 0; j < n; j++) {
            mul += (source[j] % div == 0); 
        }
        mxMultiple = max(mul, mxMultiple);
    }

    cout << n - mxMultiple << endl; 
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
