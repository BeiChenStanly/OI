#include <bits/stdc++.h>
using namespace std;
using ll = __int128;
void out(ll x){
    if(x > 9) out(x / 10);
    putchar(x%10+'0');
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    ll dp[82][82];
    int a[82];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        memset(dp,0,sizeof(dp));
        for(int j = 0; j < m;j++){
            cin >> a[j];
            dp[j][j] = 2 * a[j];
        }
        for(int l = 2; l <= m; l++){
            for(int k = 0; k + l - 1 < m; k++){
                int o = k + l - 1;
                dp[k][o] = max(dp[k+1][o] + a[k], dp[k][o-1] + a[o]) * 2;
            }
        }
        ans += dp[0][m-1];
    }
    out(ans);
    return 0;
}