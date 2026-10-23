// CALCULATE THE n'th fibonacci using dynamic programming 

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
    fibonacci series : 0 1 2 3 5 8 13 21 ..... n'th fib

        ### [ RECURSION IMPLEMENTATION ] n'th fibonacci number 

            1. In every stage function call gets double 
            2. Time complexity 2^n : exponential 
*/

int fib_recursion(int n) {
    if(n == 0) return 0; 
    if(n == 1) return 1; 

    return fib_recursion(n-1) + fib_recursion(n-2);
}

/*
    [ DYNAMIC PROGRAMMING IMPLEMENTATION ]  : TOP DOWN APPORACH 
        1. Store the values that we calculate in the process 
        2. Time complexity O(n)
*/

const int N = 1e5+10; 
int dp[N]; 

int fib_dp(int n) {
    // set all the values of the store array to -1 
    memset(dp, -1, sizeof(dp)); 

    if(n == 0) return 0; 
    if(n == 1) return 1; 
    
    if(dp[n] != -1) return dp[n];   // already calculate 

    dp[n] = fib_dp(n-1) + fib_dp(n-2); // store the value 
    
    return dp[n]; 
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;  cin >> n; 
    cout << fib_dp(n) << endl; 

    return 0;
}