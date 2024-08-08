#include <bits/stdc++.h>

using namespace std;

bitset<2367> f[41][41][401];

signed main() {
    int n, m; scanf("%d%d", &n, &m);
    if (m > 2366) {
        puts("-1");
        return 0;
    }
    string s; cin >> s;
    s = ' ' + s;
    f[0][0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            for (int k = 0; k <= (i / 2) * ((i + 1) / 2); ++k) {
                if (s[i + 1] != 'w' && s[i + 1] != 'm' && s[i + 1] != 'y') {
                    f[i + 1][j][k] |= f[i][j][k];
                }
                if (s[i + 1] == 'w' || s[i + 1] == '?') {
                    f[i + 1][j + 1][k] |= f[i][j][k];
                }
                if (s[i + 1] == 'm' || s[i + 1] == '?') {
                    f[i + 1][j][k + j] |= f[i][j][k];
                }
                if (s[i + 1] == 'y' || s[i + 1] == '?') {
                    f[i + 1][j][k] |= f[i][j][k] << k;
                }
            }
        }
    }
    int ti = -1, tj = -1, tk = m;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n / 2 * ((n + 1) / 2); ++j) {
            if (f[n][i][j][m]) {
                ti = i, tj = j;
            }
        }
    }
    if (!~ti && !~tj) {
        puts("-1");
        return 0;
    }
    for (int i = n; i >= 1; --i) {
        if (s[i] != 'w' && s[i] != 'm' && s[i] != 'y' && f[i - 1][ti][tj][tk]) {
            s[i] = (s[i] == '?' ? 'a' : s[i]);
        } else if ((s[i] == 'w' || s[i] == '?') && ti && f[i - 1][ti - 1][tj][tk]) {
            s[i] = 'w', --ti;
        } else if ((s[i] == 'm' || s[i] == '?') && tj >= ti && f[i - 1][ti][tj - ti][tk]) {
            s[i] = 'm', tj -= ti;
        } else if ((s[i] == 'y' || s[i] == '?') && tk >= tj && f[i - 1][ti][tj][tk - tj]) {
            s[i] = 'y', tk -= tj;
        } else {
            puts("# ERROR!");
            exit(0);
        }
    }
    puts(s.substr(1).c_str());
    return 0;
}