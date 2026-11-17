// https://codeforces.com/problemset/problem/2274/B
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
            3    -5    1    -4    2
    value   3    -8   -4    -13   
    prefix  3    -5   -9    -22
*/

void solve() {
    int n;  cin >> n;   vector<int> source(n); 
    for(auto &v : source) cin >> v; 

    // we try to make the sum as high as possible and also as low as possible 
    int value_low = source.front(), value_high = source.front();

    int answer = LLONG_MIN; 
    for(int i = 1; i < n; i++) {
        int cmax = max({source[i], source[i] - value_low, source[i] + value_high}); 
        answer = max(answer, cmax); 

        // update the values 
        value_low = min({value_low+source[i]+value_low,
                        value_low+source[i]-value_low,
                        value_low+source[i]}); 
        
        value_high = max({value_high+source[i]+value_high, 
                          value_high+source[i]-value_high,
                          value_high+source[i]});
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