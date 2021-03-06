#include <bits/stdc++.h>
typedef IOS
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
using namespace std;

typedef ll long long typedef lli long long int typedef pp pair<int, int> typedef pp1 pair<pp, pp>

    pp get24hr(string s, string ap)
{
    int h1 = (int)s[0] - '0';
    int h2 = (int)s[1] - '0';
    int hh = h1 * 10 + h2;

    if (ap[0] == 'P' && hh != 12)
        hh += 12;

    if (ap[0] == 'A' && hh == 12)
        hh = 0;

    int m1 = (int)s[3] - '0';
    int m2 = (int)s[4] - '0';

    int mm = m1 * 10 + m2;

    return make_pair(hh, mm);
}

int getMin(pp time)
{
    return time.first * 60 + time.second;
}

int main()
{
    IOS int t;
    cin >> t;

    while (t--)
    {
        string s1;
        string ap1;
        cin >> s1 >> ap1;
        auto t1 = getMin(get24hr(s1, ap1));
        int n;
        cin >> n;
        for (int cnt = 1; cnt <= n; cnt++)
        {
            string s2;
            string ap2;
            cin >> s2 >> ap2;
            auto t2 = getMin(get24hr(s2, ap2));
            cin >> s2 >> ap2;
            auto t3 = getMin(get24hr(s2, ap2));
            if (t1 >= t2 && t1 <= t3)
                cout << "1";
            else
                cout << "0";
        }
        cout << "\n";
    }
    return 0;
}
