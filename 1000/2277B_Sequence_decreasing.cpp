// https://codeforces.com/contest/2272/problem/A

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
    int n;  cin >> n; vector<int> source(n); 
    for(auto &val : source) cin >> val; 

    cout << (*min_element(whole(source)) < n ? n : 0) << endl; 
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

/*

3 2 1 0 3 4 5
2 0 0 0 2 3 4
1 0 0 0 1 2 3

3 2 2
2 1 

for a particular length subarray and element equals to length-1 must be preesnt at that subarray for that subarray to be valid 

comes down to -> if any element less than n is present then the whole array is valid 
*/