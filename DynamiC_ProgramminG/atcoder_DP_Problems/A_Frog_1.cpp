// https://atcoder.jp/contests/dp/tasks/dp_a

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
    We can either jump to i+1 or i+2 cost is abs(hj - hi) 
        - find the minimum cost for reaching the n'th stone 

    To reach the n'th stone we can either come from n-1'th stone or n-2'th stone 
*/

const int N = 1e5 + 10; 
int h[N], dp[N]; 

int costFor_i(int i) {
    int cost = LLONG_MAX; 

    if(i == 0) return 0; 
    if(dp[i] != -1) return dp[i]; 

    // way 1 : come from i-1'th stone 
    cost = min(cost, costFor_i(i-1) + abs(h[i] - h[i-1])); 
    // way 2 : come from i-2'th stone 
    if(i > 1) cost = min(cost, costFor_i(i-2) + abs(h[i] - h[i-2])); 

    dp[i] = cost; 

    return cost; 
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp)); 

    int n;  cin >> n;  for(int i = 0; i < n; i++) cin >> h[i]; 
    cout << costFor_i(n-1) << endl; 

    return 0;
}