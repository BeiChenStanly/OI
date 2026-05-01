#include <bits/stdc++.h>
using namespace std;
struct BigInt
{
    string s;
    BigInt() : s("0") {}
    BigInt(const string &s) : s(s)
    {
        while (this->s.size() > 1 && this->s[0] == '0')
            this->s.erase(this->s.begin());
    }
    BigInt(char c) : s(1, c) {}
    BigInt(int x) : s(to_string(x)) {}
    BigInt operator+(const BigInt &b) const
    {
        string a = s, c = b.s;
        reverse(a.begin(), a.end());
        reverse(c.begin(), c.end());
        string res;
        int carry = 0;
        for (size_t i = 0; i < max(a.size(), c.size()) || carry; i++)
        {
            int x = carry;
            if (i < a.size())
                x += a[i] - '0';
            if (i < c.size())
                x += c[i] - '0';
            res.push_back(x % 10 + '0');
            carry = x / 10;
        }
        reverse(res.begin(), res.end());
        return {res};
    }
    BigInt operator*(const BigInt &b) const
    {
        string a = s, c = b.s;
        reverse(a.begin(), a.end());
        reverse(c.begin(), c.end());
        vector<int> res(a.size() + c.size(), 0);
        for (size_t i = 0; i < a.size(); ++i)
            for (size_t j = 0; j < c.size(); ++j)
                res[i + j] += (a[i] - '0') * (c[j] - '0');
        for (size_t i = 0; i < res.size() - 1; ++i)
        {
            res[i + 1] += res[i] / 10;
            res[i] %= 10;
        }
        while (res.size() > 1 && res.back() == 0)
            res.pop_back();
        string result;
        for (int x : res)
            result.push_back(x + '0');
        reverse(result.begin(), result.end());
        return {result};
    }
    bool operator<(const BigInt &b) const
    {
        if (s.size() != b.s.size())
            return s.size() < b.s.size();
        return s < b.s;
    }
};
BigInt num[41][41];
BigInt dp[41][41];//表示前i个数字插入j个乘号的最大值
int main()
{
    int n, k;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++)
    {
        num[i][i] = s[i - 1];
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            num[i][j] = num[i][j - 1] * 10 + num[j][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = num[1][i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= min(i, k); j++)
        {
            for (int l = j; l < i; l++)
            {
                dp[i][j] = max(dp[i][j], dp[l][j - 1] * num[l + 1][i]);
            }
        }
    }
    cout << dp[n][k].s << endl;
    return 0;
}