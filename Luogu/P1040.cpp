#include <bits/stdc++.h>
using namespace std;
const int MAXN = 51;
unsigned int n, dp[MAXN][MAXN], bestk[MAXN][MAXN];
void output(int l, int r){
    if(l > r) return;
    if(l == r){ cout << l << ' '; return;}
    int k = bestk[l][r];
    cout << k << ' ';
    output(l,k-1);
    output(k+1,r);
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        cin >> dp[i][i];
    }
    for(int len = 2; len <= n; len++){
        for(int i = 1; i + len - 1 <= n; i++){
            int j = i + len - 1;
            for(int k = i; k <= j; k++){
                unsigned int ans = dp[i][k-1] * dp[k+1][j] + dp[k][k];
                if(ans > dp[i][j]){
                    dp[i][j] = ans;
                    bestk[i][j] = k;
                }
            }
        }
    }
    cout << dp[1][n] << '\n';
    output(1,n);
}