#include <bits/stdc++.h>
using namespace std;
typedef ll long long int main()
{

#ifdef ONLINE_JUDGE
    //getting input from the input.txt
    freopen("intput.txt", "r", stdin);

    //writing output into output.txt
    freopen("output.txt", "w", stdout);

#endif

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        ll a[n + 1];
        for (ll i = 1; i <= n; i++)
            cin >> a[i];
        ll cnt = 0;
        ll i = 1;
        while (i <= n)
        {
            while (a[i] == a[i + 1] && i < n)
            {
                i++;
            }
            cnt++;
            i++;
        }
        while (q--)
        {
            ll x, y;
            cin >> x >> y;
            if (x == 1)
            {
                if (x + 1 <= n && a[x] == a[x + 1] && y != a[x + 1])
                {
                    cnt++;
                }
                else if (x + 1 <= n && a[x] != a[x + 1] && y == a[x + 1])
                {
                    cnt--;
                }
            }
            else if (x == n)
            {
                if (x - 1 >= 1 && a[x] == a[x - 1] && y != a[x - 1])
                {
                    cnt++;
                }
                else if (x - 1 >= 1 && a[x] != a[x - 1] && y == a[x - 1])
                {
                    cnt--;
                }
            }
            else
            {
                if (a[x] == a[x - 1] && a[x] == a[x + 1] && y != a[x])
                    cnt += 2;
                else if (a[x] == a[x - 1] && y != a[x - 1] && y != a[x + 1])
                    cnt += 1;
                else if (a[x] == a[x + 1] && y != a[x + 1] && y != a[x - 1])
                    cnt += 1;
                else if (a[x] != a[x - 1] && a[x] != a[x + 1])
                {
                    if (a[x - 1] == a[x + 1])
                    {
                        if (y == a[x - 1])
                            cnt -= 2;
                    }
                    else if (a[x - 1] != a[x + 1])
                    {
                        if (y == a[x - 1])
                            cnt--;
                        if (y == a[x + 1])
                            cnt--;
                    }
                }
            }
            a[x] = y;
            cout << cnt << '\n';
        }
    }
}
