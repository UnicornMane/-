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
