//O(n3)

// #include <bits/stdc++.h>
// using namespace std;

// int main() {

//     int t;
//     cin >> t;

//     while (t--) {

//         int n;
//         cin >> n;

//         vector<int> a(n);

//         for (int i = 0; i < n; i++)
//             cin >> a[i];

//         bool ok = false;

//         for (int left = 0; left <= n - 3 && !ok; left++) {

//             int one = 0, two = 0, three = 0;

//             // Count LEFT
//             for (int i = 0; i <= left; i++) {
//                 if (a[i] == 1) one++;
//                 else if (a[i] == 2) two++;
//                 else three++;
//             }

//             if (one < two + three)
//                 continue;

//             for (int mid = left + 1; mid <= n - 2 && !ok; mid++) {

//                 one = two = three = 0;

//                 // Count MIDDLE
//                 for (int i = left + 1; i <= mid; i++) {
//                     if (a[i] == 1) one++;
//                     else if (a[i] == 2) two++;
//                     else three++;
//                 }

//                 if (one + two >= three)
//                     ok = true;
//             }
//         }

//         cout << (ok ? "YES" : "NO") << '\n';
//     }
// }



// O(n2)

// #include <bits/stdc++.h>
// using namespace std;

// int main() {

//     int t;
//     cin >> t;

//     while (t--) {

//         int n;
//         cin >> n;

//         vector<int> a(n);

//         vector<int> p1(n + 1, 0);
//         vector<int> p2(n + 1, 0);
//         vector<int> p3(n + 1, 0);

//         for (int i = 0; i < n; i++) {

//             cin >> a[i];

//             p1[i + 1] = p1[i];
//             p2[i + 1] = p2[i];
//             p3[i + 1] = p3[i];

//             if (a[i] == 1)
//                 p1[i + 1]++;
//             else if (a[i] == 2)
//                 p2[i + 1]++;
//             else
//                 p3[i + 1]++;
//         }

//         bool ok = false;

//         for (int left = 0; left <= n - 3 && !ok; left++) {

//             int one = p1[left + 1];
//             int two = p2[left + 1];
//             int three = p3[left + 1];

//             if (one < two + three)
//                 continue;

//             for (int mid = left + 1; mid <= n - 2 && !ok; mid++) {

//                 one = p1[mid + 1] - p1[left + 1];
//                 two = p2[mid + 1] - p2[left + 1];
//                 three = p3[mid + 1] - p3[left + 1];

//                 if (one + two >= three)
//                     ok = true;
//             }
//         }

//         cout << (ok ? "YES" : "NO") << '\n';
//     }
// }

// O(n)

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve() {

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> pref1(n + 1, 0);
    vector<int> pref2(n + 1, 0);

    for (int i = 0; i < n; i++) {

        if (a[i] == 1)
            pref1[i + 1] = pref1[i] + 1;
        else
            pref1[i + 1] = pref1[i] - 1;

        if (a[i] == 3)
            pref2[i + 1] = pref2[i] - 1;
        else
            pref2[i + 1] = pref2[i] + 1;
    }

    int mn = INF;

    for (int i = 1; i < n; i++) {

        if (pref2[i] >= mn) {
            cout << "YES\n";
            return;
        }

        if (pref1[i] >= 0)
            mn = min(mn, pref2[i]);
    }

    cout << "NO\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();
}