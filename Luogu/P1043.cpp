#include <bits/stdc++.h>
using namespace std;
const int MAXN = 51;
const int MAXM = 11;
int n,m,a[MAXN],s[MAXN];
int dp[MAXN][MAXM],pd[MAXN][MAXM];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    if(m == 1){
        s[n] = (s[n]% 10 + 10)% 10;
        cout << s[n] << endl << s[n] << endl;
        return 0;
    }
    int maans = 0,mians = INT32_MAX;
    for(int i = 1; i <= n; i++){
        memset(dp,0,sizeof(dp));
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= m; k++){
                pd[j][k] = INT32_MAX;
            }
        }
        int temp = s[1];
        for(int j = 1; j < n; j++)
            s[j] = s[j + 1] - temp;
        for(int j = 1; j <= n; j++){
            dp[j][1] = pd[j][1] = (s[j] % 10 + 10) % 10;
        }
        for(int j = 2; j <= n; j++){
            for(int k = 2; k <= m; k++){
                for(int l = k - 1; l < j; l++){
                    dp[j][k] = max(dp[j][k],dp[l][k-1] * (((s[j] - s[l])%10 + 10) % 10));
                    pd[j][k] = min(pd[j][k],pd[l][k-1] * (((s[j] - s[l])%10 + 10) % 10));
                }
            }
        }
        maans = max(maans,dp[n][m]);
        mians = min(mians,pd[n][m]);
    }
    cout << mians << endl << maans << endl;
}