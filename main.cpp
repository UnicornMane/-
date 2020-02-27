#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <iomanip>
//#include <rpcndr.h>
#include <string>
#include <set>

using namespace std;

constexpr long long INF = 1e9;
constexpr long long MOD1 = 1e9 + 9;
constexpr long long P1 = 113;
constexpr long long MOD2 = 1e9 + 7;
constexpr long long P2 = 101;
constexpr int MAX = 2000005;

long long power1[MAX], power2[MAX];
long long prefix1[MAX], prefix2[MAX], prefix3[MAX], prefix4[MAX];

void pre_calc(string &f, string &s)
{
    for (int i = 0; i < f.size(); i++)
    {
        power1[i + 1] = power1[i] * P1 % MOD1;
        prefix1[i + 1] = (prefix1[i] * P1 + f[i]) % MOD1;

        power2[i + 1] = power2[i] * P2 % MOD2;
        prefix2[i + 1] = (prefix2[i] * P2 + f[i]) % MOD2;
    }

    for (int i = 0; i < s.size(); i++)
    {
        prefix3[i + 1] = (prefix3[i] * P1 + s[i]) % MOD1;
        prefix4[i + 1] = (prefix4[i] * P2 + s[i]) % MOD2;
    }
}

int subhash1(int i, int j)
{
    return ((prefix1[j] - prefix1[i] * power1[j - i]) % MOD1 + MOD1) % MOD1;
}

int subhash2(int i, int j)
{
    return ((prefix2[j] - prefix2[i] * power2[j - i]) % MOD2 + MOD2) % MOD2;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    string s;
    cin >> s;

    int b = 0;
    for (auto &c : s)
    {
        if (c == '(')
        {
            b++;
        }
        else
        {
            b--;
        }
        if (b < 0)
        {
            cout << "NO";
            return 0;
        }
    }
    if (b)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES";
}