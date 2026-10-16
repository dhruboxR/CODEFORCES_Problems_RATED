// https://codeforces.com/problemset/problem/2269/B

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
    We will apply replace operation exactly 100 times to each number. 
        - At that point every number will be on it's eventual cycle 
    
    Two numbers are in TUNE, 
        - if and only if their values after those 100 transformations are equal 
*/

int replace(int val) { 
    int sq = 0; 
    while(val > 0) {
        sq += (val % 10) * (val % 10); 
        val /= 10;
    }
    return sq; 
}

void solve() {
    int n;  cin >> n;  vector<int> source(n); 
    for(auto &val : source) cin >> val; 

    map<int, int> freq; 
    for(int i = 0; i < n; i++) {
        int temp = source[ i ]; 

        // Move each number 100 steps ahead 
        for(int j = 0; j < 100; j++) temp = replace(temp); 

        freq[ temp ]++; 
    }
    /*
        Unique pairs that can be formed using X numbers 
            Formula : (c 2) = (c * (c-1)) / 2
    */
    int answer = 0; 
    for(auto [val, count] : freq) {
        answer += (count * (count-1)) / 2; 
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