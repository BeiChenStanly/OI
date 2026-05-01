#include <bits/stdc++.h>
using namespace std;
string wds[7];
int sum[205][205];
int dp[205][51];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int p, k;
    cin >> p >> k;
    string str = "0";
    for(int i = 0; i < p; i++){
        string s;
        cin >> s;
        str += s;
    }
    int n = str.size() - 1;
    int s;
    cin >> s;
    for(int i = 0; i < s; i++){
        cin >> wds[i];
    }
    for(int j = 1; j <= n; j++){
        for(int i = j; i >= 1; i--){
            sum[i][j] = sum[i+1][j];
            for(int k = 0; k < s; k++){
                if(j - i + 1 < wds[k].size()) continue;
                bool flag = true;
                for(int l = i; l < i + wds[k].size(); l++){
                    if(str[l] != wds[k][l - i]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    sum[i][j]++;
                    break;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        dp[i][1] = sum[1][i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 2; j <= k; j++){
            for(int l = j - 1; l < i; l++){
                dp[i][j] = max(dp[i][j], dp[l][j - 1] + sum[l + 1][i]);
            }
        }
    }
    cout << dp[n][k] << "\n";
    return 0;
}