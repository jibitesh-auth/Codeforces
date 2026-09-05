#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> c(n + 1, 0);

    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && a[j] == a[i])
            j++;

        c[j - i]++;
        i = j;
    }

    long long ans = 0;
    long long s1 = 0;
    long long s2 = 0;

    for (int i = n; i >= 1; i--) {
        s1 += c[i];
        s2 += s1;

        if (c[i] && k >= s2 && (k - s2) % s1 == 0)
            ans++;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}