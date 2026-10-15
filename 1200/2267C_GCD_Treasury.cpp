// https://codeforces.com/contest/2267/problem/C

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

const int N = 1e7+5;
vector<int> primes;     vector<bool> mark_prime(N, true);

void generate_primes() {
    mark_prime[0] = mark_prime[1] = false;
    for(int i = 2; i < N; ++i) {
        if(mark_prime[i]) {
            primes.push_back(i);
            for(int j = i * i; j < N; j += i) mark_prime[j] = false;
        }
    }
}

void solve() {
    int n, x;   cin >> n >> x; 
    vector<int> factor_x; 

// prime factorize x 

    for(auto v : primes) {
        if(v * v > x) break; 

        if(x%v == 0) {
            factor_x.push_back(v); 
            while(x % v == 0) x /= v; 
        }
    }
    
    if(x > 1) factor_x.push_back(x); 

    map<int, int> total; 
    for(int i = 0; i < n; i++) {
        int value;  cin >> value; 

        for(auto &div : factor_x) {
            if(value % div == 0) {
                total[ div ] += value; 
            }
        }
    }
    int answer = 0; 
    for(auto &it : total) answer = max(answer, it.second); 
    
    cout << answer << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    generate_primes(); 

    int test_case; cin >> test_case;
    while (test_case--) {
        solve();
    }

    return 0;
}

