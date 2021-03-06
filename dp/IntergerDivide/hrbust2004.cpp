#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bitset>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <map>
#include <set>
#include <stdexcept>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <numeric>

using namespace std;

#define eps 1e-10
#define N 1010

typedef long long LL;

int dp[N][N];
int res[N];

int main()
{
    int n = 100;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = dp[i - j][j] + dp[i - 1][j - 1];
            res[i] += dp[i][j];
        }


    while (cin >> n)
    {
        cout << res[n] << endl;
    }
    return 0;
}
