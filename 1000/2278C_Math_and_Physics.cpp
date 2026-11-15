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
        2 1 1 1 2   middle elements all 1 -> totalSum - s[0] - s[n-1] == n-2
            # Answer : totalSum - (n-2) - 1  
        
        1 1 2 1  element > 1 exists in the middle 
        1 2 2 
        2 3 
        4 
            # Answer : totalSum - 1 
*/

void solve() {
    int n, idx = -1; cin >> n; vector<int> source(n);
    for(auto &val : source) cin >> val; 

    // any element from 2 till n-2 must be > 1 for traversing without value loss : choose that and expand outwards  
    // if edge elements is > 1 then we have to choose that : value loss = (number of steps moved) 
    
    int totalSum = accumulate(whole(source), 0ll); 
    if(totalSum == n) {negative; return;}   // all elements are 1 

    // check if all middle elements are 1 
    if(totalSum - source.front() - source.back() == n - 2) {
        // edge case if n == 2 
        if(n == 2) {
            cout << totalSum - 1 << endl; 
        }
        else cout << totalSum - (n-2) - 1 << endl; 
    } else cout << totalSum - 1 << endl; 
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