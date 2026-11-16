// https://codeforces.com/problemset/problem/2278/D

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

/*          2  1  3   ->   1  2  3   

    Let, vector<int>(b) be the sorted version of the initial array. 
            To make all elements equal We must reduce the gap between b[i+1] - b[i]     

    ## OPTIMAL : Whenever we are closing a gap 
        - We must shift the entire group of elements on one side of the gap as a rigid block. 

        2   1   3   ->  1   2   3     
                                    lock_idx(1), unlocked_idx(2, 3), decreament : cost = 1, operation = 1
        1   2   3   ->  1   1   2   
                                    lock_idx(3), unlocked_idx(1, 2), increament : cost = 1, operation = 1
        1   1   2   ->  2   2   2
                                    all equal values : cost = 2, operation = 2
*/

void solve() {
    int n;  cin >> n; vector<int>a(n), b(n); 
    for(int i = 0; i < n; i++) {cin >> a[i]; b[i] = a[i];}

    sort(whole(b)); 
    int pre_inc = 0, pre_dec = 0, cost = 0, operation = 0; 

    for(int i = 1; i < n; i++) {
        b[i] += (pre_inc - pre_dec);    // update the value first 

        if(b[i] != b[i-1]) {
            int diff = b[i] - b[i-1];
            int left_cost = (diff * i), right_cost = (diff * (n-i)); 

            if(left_cost < right_cost) {
                cost += left_cost;  pre_dec += diff; 
                b[i] -= diff; 
            } else {
                cost += right_cost; pre_inc += diff; 
                b[i] += diff; 
            }
            operation += diff; 
        }
    }
    cout << cost << " " << operation << endl; 
}

// problem was great !! enjoyed figuring out the solution :)

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case; cin >> test_case;
    while (test_case--) {
        solve();
    }

    return 0;
}