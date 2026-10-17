// https://codeforces.com/contest/2269/problem/C

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
    vector<int> source(n+1);  for(int i = 1; i <= n; i++) cin >> source[ i ]; 

    vector<int> remains;    int sum = 0; 
    // elements from k to n - k + 1 will get deleted anyway 
    for(int i = 1; i <= n; i++) {
        if(i >= k && i <= n - k + 1) sum += source[ i ]; 
        else remains.push_back( source[ i ] ); 
    }

    // how many elements can you remove after this 
    int rem = remains.size() - k + 1; 
    
    for(int i = 0; i < rem; i++) {
        sum += max(remains[i], remains[remains.size()-i-1]); 
    }
    cout << sum << endl; 
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