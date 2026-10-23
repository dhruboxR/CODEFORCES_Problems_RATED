// https://atcoder.jp/contests/dp/tasks/dp_b

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

const int N = 1e5 + 10; 
int h[N], dp[N]; 
int k; 

int costFor_i(int i) {
    int cost = LLONG_MAX; 

    if(i == 0) return 0; 
    if(dp[i] != -1) return dp[i]; 

    // We can come here in K ways 
    for(int j = 1; j <= k; j++) {
        if(i - j >= 0) 
            cost = min(cost, costFor_i(i-j) + abs(h[i] - h[i-j]));
    }

    dp[i] = cost; 
    
    return cost; 
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp)); 

    int n;   cin >> n >> k; 
    for(int i = 0; i < n; i++) cin >> h[ i ]; 

    cout << costFor_i(n-1) << endl; 

    return 0;
}