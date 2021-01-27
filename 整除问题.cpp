// passed

/* 
查看该blog
https://blog.csdn.net/LYKXHTP/article/details/88430444

*/
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool mark[1001];
int prime[1001];
int primeSize;

void init()
{ //筛选出0到1000范围内的所有素数
    primeSize = 0;
    for (int i = 2; i <= 1000; i++)
    {
        if (mark[i] == true)
            continue;
        mark[i] = true;
        prime[primeSize++] = i;
        for (int j = i * i; j <= 1000; j += i)
        {
            mark[j] = true;
        }
    }
}

int cnt[1001];
//cnt[i]用来表示prime[i]所保存的素数在n!中的因子数
//即!分解素因数后素因子prime[i]所对应的幂指数，可能为0

int cnt2[1001];
//cnt2[i]用来表示prime[i]所保存的素数在a中的因子数

int main()
{
    init();
    int n, a;
    while (cin >> n >> a)
    { //成功读取的个数
        for (int i = 0; i < primeSize; i++)
        {
            cnt[i] = 0;
            cnt2[i] = 0;
            //将两个计数器清零，为新的一次分解做准备
        }
        for (int i = 0; i < primeSize; i++)
        {
            //对n!分解质因数，遍历0到1000的每个素数
            int t = n; //用临时变量t保存n的值
            while (t)
            {
                cnt[i] += t / prime[i];
                t = t / prime[i];
            } //依次计算t/(prime[i]^k),累加其值，直到t/(prime[i]^k)变为0
        }
        int ans = 123123123; //答案初始值为一个大整数，为取最小值做准备
        for (int i = 0; i < primeSize; i++)
        {
            //对a分解素因数
            while (a % prime[i] == 0)
            {
                cnt2[i]++;
                a /= prime[i];
            } //计算a中素因数prime[i]对应的幂指数
            if (cnt2[i] == 0)
                continue;
            //若该素数不能从a中分解到，即其对应幂指数为0
            //则其不影响整除性，跳过

            if (cnt[i] / cnt2[i] < ans)
            {
                //计算素数prime[i]在两个数中因子数的商
                ans = cnt[i] / cnt2[i]; //统计这些商的最小值
            }
        }
        cout << ans << endl;
    }
    return 0;
}
