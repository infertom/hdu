#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <set>
#include <string>
#include <map>
#include <cmath>
//#include <bits/stdc++.h>
#include <queue>

using namespace std;
typedef long long ll;

const int MAXN = (1<<10) + 10;
const int MOD = 1e9 + 7;
const int MO[88] = {3,6,12,24,48,96,192,384,768,
15,27,30,51,54,60,99,102,108,120,195,198,204,216,240,387,390,396,408,432,480,771,774,780,792,816,864,960,
63,111,123,126,207,219,222,243,246,252,399,411,414,435,438,444,483,486,492,504,783,795,798,819,822,828,867,870,876,888,963,966,972,984,1008,
255,447,495,507,510,831,879,891,894,975,987,990,1011,1014,1020,
1023};

int n, m, c, d;
int maxn;
int f[110][MAXN][30], p[110];

void printBinary(int x)
{
    int len = m;
    while ( len-- )
    {
        cout<<(x&1);
        x >>= 1;
    }
}

int lowBit(int x)
{
    return x&(-x);
}

int getN(int sig, int nSig)
{
    int num = 0;
    sig ^= nSig;
    while ( sig ) num++, sig -= lowBit(sig);

    return num;
}

void upF(int k)
{
	for (int i = d; i >= 0; i--){
		for (int sig = maxn; sig >= 0; sig--){
			if ( (sig|p[k]) != sig ) continue;
			for (int j = 0; j < 88; j++){
				if ( (sig|MO[j]) == sig ) f[k][sig][i] = (f[k][sig][i] + f[k][sig^MO[j]][i]) % MOD;
			}
		}
	}
	for (int i = d; i >= 0; i--){
		for (int sig = maxn; sig >= 0; sig--){
			if ( (sig|p[k]) != sig ) continue;
// 			for (int fSig = 0; fSig <= maxn; fSig++){
// 				if ( (sig|fSig) != sig ) continue;
// 				int num = getN(sig, fSig);
// 				if ( num <= i && num > 0 ) f[k][sig][i] = (f[k][sig][i] + f[k][fSig][i-num]) % MOD;
// 			}
			for (int fSig = 1; fSig <= sig; fSig++){
				if ( fSig&p[k] ) continue;
				f[k][sig][i]
			}
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

    while ( scanf("%d%d%d%d", &n, &m, &c, &d) != EOF )
    {
        memset(f, 0, sizeof f);
        memset(p, 0, sizeof p);
        maxn = (1<<m) - 1;
        char temp[20], len;
        for (int i = 0; i < n; i++){
            scanf("%s", temp);
            len = strlen(temp);
            for (int j = 0; j < len; j++){
                p[i] <<= 1;
                if ( temp[j] == '0' ) p[i]++;
            }
            //printBinary(p[i]);
            //cout<<endl;
        }
        p[n] = maxn;

        f[0][p[0]][0] = 1;
        for (int i = 0; i < n; i++){
            upF(i);
            for (int j = 0; j <= d; j++){
				for (int sig = 0; sig <= maxn; sig++){
					if ( (sig|p[i]) != sig ) continue;
					int cSig = (maxn^sig);
					if ( !(cSig&p[i+1]) ) f[i+1][cSig|p[i+1]][j] = (f[i+1][cSig|p[i+1]][j] + f[i][sig][j]);
				}
			}
        }


//         for (int i = 0; i <= maxn; i++){
//             for (int j = c; j <= d; j++){
//                 cout<<"sig:";
//                 printBinary(i);
//                 cout<<"   "<<"d:"<<j<<"  f:"<<f[0][i][j]<<endl;
//             }
//         }


        int ans = 0;
        for (int i = c; i <= d; i++){
            ans = (ans + f[n-1][maxn][i]) % MOD;
        }
        printf("%d\n", ans);
    }

    return 0;
}