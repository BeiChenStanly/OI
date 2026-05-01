#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500;
int n,w[MAXN];
unsigned long long dp[MAXN][MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n + 1; i++)
        cin >> w[i];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = i==j?0:UINT64_MAX;
        }
    }
    for(int len = 2; len <= n; len++){
        for(int i = 1; i + len - 1 <= n; i++){
            int j = i + len -1;
            for(int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + (unsigned long long)w[i] * w[k+1] * w[j+1]);
            }
        }
    }
    cout << dp[1][n];
}