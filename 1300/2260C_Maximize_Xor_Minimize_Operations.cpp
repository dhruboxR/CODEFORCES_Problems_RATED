// https://codeforces.com/problemset/problem/2260/C

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
    the maximum sum can be atmost (a+b), WE SET UNIQUE BITS AS SET BITS IN BOTH NUMBERS 

            - for minimum operations we move from the MSB->LSB
*/ 

void solve() {
    int a, b;   cin >> a >> b; 
    int answer = a+b; 

    int a_prime = 0; 
    for(int i = 29; i >= 0; i--) {
        if( (answer>>i)&1 ) {
            // if setting this bit makes our candidate less than a 
            if( (a_prime | (1ll << i)) <= a ) {
                a_prime |= (1ll << i); 
            }
        }
    }
    cout << answer << " " << (a - a_prime) << endl;
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