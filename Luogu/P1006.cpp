#include <bits/stdc++.h>
using namespace std;
int dp[51][51][51][51];
int a[51][51];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n;
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            for(int k = i+1; k <= m; k++){
                for(int l = 1; l <= j-1; l++){
                    dp[i][j][k][l] = max(
                        max(dp[i][j-1][k][l-1],dp[i][j-1][k-1][l]),
                        max(dp[i-1][j][k][l-1],dp[i-1][j][k-1][l])
                    ) + a[i][j] + a[k][l];
                }
            }
        }
    }
    cout << dp[m-1][n][m][n-1] << endl;
    return 0;
}