#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

// index, N, NA
bitset<2501> dp[40][41][1601];

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,K; cin >> n >> K;
    string s; cin >> s;
    if (s[0] == 'w') {
        dp[0][1][0].set(0);
    }
    else if (s[0] != '?') {
        dp[0][0][0].set(0);
    }
    else {
        dp[0][0][0].set(0);
        dp[0][1][0].set(0);
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            for (int k = 0; k < 1601; ++k) {
                if (s[i] == 'w') {
                    dp[i][j+1][k] |= dp[i-1][j][k];
                } else if (s[i] == 'm') {
                    if (k+j < 1601) dp[i][j][k+j] |= dp[i-1][j][k];
                } else if (s[i] == 'y') {
                    dp[i][j][k] |= (dp[i-1][j][k] << k);
                } else if (s[i] != '?') {
                    dp[i][j][k] |= dp[i-1][j][k];
                } else {
                    dp[i][j+1][k] |= dp[i-1][j][k];
                    if (k+j < 1601) dp[i][j][k+j] |= dp[i-1][j][k];
                    dp[i][j][k] |= (dp[i-1][j][k] << k);
                    dp[i][j][k] |= dp[i-1][j][k];
                }
            }
        }
    }
    int nn = -1, na = -1, nac = K;
    for (int i = 0; i < 41; ++i) {
        for (int j = 0; j < 1601; ++j) {
            if (dp[n-1][i][j][K]) {
                nn = i, na = j;
            }
        }
    }
    if (nn == -1) {
        cout << -1 << endl;
        return 0;
    }
    string res;
    for (int i = n-1; i >= 0; --i) {
        if (i == 0) {
            if (nn == 1) res += 'w';
            else {
                if (s[0] == '?') res += 'm';
                else res += s[0];
            }
            continue;
        }
        // C
        if (s[i] == 'y' or s[i] == '?') {
            if (0 <= nac-na and dp[i-1][nn][na][nac-na]) {
                res += 'y';
                nac -= na;
                continue;
            }
        }
        // A
        if (s[i] == 'm' or s[i] == '?') {
            if (0 <= na-nn and dp[i-1][nn][na-nn][nac]) {
                res += 'm';
                na -= nn;
                continue;
            }
        }
        // N
        if (s[i] == 'w' or s[i] == '?') {
            if (nn and dp[i-1][nn-1][na][nac]) {
                res += 'w';
                nn -= 1;
                continue;
            }
        }
        // それ以外
        {
            if (s[i] == '?') res += 'z';
            else res += s[i];
        }
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
}