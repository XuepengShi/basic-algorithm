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
#define offset 18750000
#define MOD 100007

typedef long long LL;

int squ(int x)
{
    return x * x * x;
}


int hashtable[MOD];

void insert_hash(int num)
{
    int id = num % MOD;
    while (hashtable[id] != -1)
        id = (id + 1) % MOD;
    hashtable[id] = num;
}

int find_hash(int num)
{
    int id = num % MOD;
    int ans = 0;
    while (hashtable[id] != -1)
    {
        if (hashtable[id] == num)
            ans++;
        id = (id + 1) % MOD;
    }
    return ans;
}


int main()
{
    int a[5];
    for (int i = 0; i < 5; i++)
        cin >> a[i];
    memset(hashtable, -1, sizeof(hashtable));
    for (int i = -50; i <= 50; i++)
        for (int j = -50; j <= 50; j++)
            if (i * j)
            {
                int num = -a[0] * squ(i) - a[1] * squ(j) + offset;
                insert_hash(num);
            }
    LL res = 0;
    for (int i = -50; i <= 50; i++)
        for (int j = -50; j <= 50; j++)
            for (int k = -50; k <= 50; k++)
                if (i * j * k)
                {
                    int num = a[2] * squ(i) + a[3] * squ(j) + a[4] * squ(k) + offset;
                    res += find_hash(num);
                }
    cout << res << endl;
    return 0;
}
