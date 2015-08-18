#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;

const int MAXN = 100 + 10;

int n, m;
int maze[MAXN][MAXN];
int x, y, k, sum;

int main()
{
	freopen("in.txt", "r", stdin);
	while ( scanf("%d%d", &n, &m) != EOF )
	{
		sum = 0;
		k = 10000 + 100;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				scanf("%d", &maze[i][j]);
				if( ((i + j)&1) && (maze[i][j] < k) ) k = maze[i][j], x = i, y = j;
				sum += maze[i][j];
			}
		}

		if ( (n&1) || (m&1) ) {
			printf("%d\n", sum);
			if ( n&1 ) {
				for (int i = 0; i < n; i++){
					for (int j = 0; j < m - 1; j++){
						printf("%c", (i&1)? 'L':'R');
					}
					if ( !(i == n - 1) ) printf("D");
				}
			}
			else{
				for (int i = 0; i < m; i++){
					for (int j = 0; j < n - 1; j++){
						printf("%c", (i&1)? 'U':'D');
					}
					if ( !(i == m - 1) ) printf("R");
				}
			}
			printf("\n");
			continue;
		}

		printf("%d\n", sum - k);
		if ( x == 0 ){
			for (int i = 0; i < y; i++) printf("%s", (i&1)? "UR":"DR");
			for (int i = y + 1; i < m; i++) printf("%s", (i&1)? "RD":"RU");
			if ( !(n - 1 - x == 1) ) printf("D");
			for (int i = 0; i < n - 2; i++){
				for (int j = 0; j < m - 1; j++){
					printf("%c", (i&1)? 'R':'L');
				}
				if ( !(i == n - 3) ) printf("D");
			}
		}
		else if ( y&1 ){
			for(int i = 0; i < y - 1; i++){
				for (int j = 0; j < n - 1; j++){
					printf("%c", (i&1)? 'U':'D');
				}
				printf("R");
			}
			for (int i = 0; i < x; i++) printf("%s", (i&1)? "LD":"RD");
			for (int i = x + 1; i < n; i++) printf("%s", (i&1)? "DR":"DL");
			if ( !(m - 1 - y == 0) ) printf("R");
			for(int i = y + 1; i < m; i++){
				for (int j = 0; j < n - 1; j++){
					printf("%c", (i&1)? 'D':'U');
				}
				if ( !(i == m - 1) ) printf("R");
			}
		}
		else{
			for(int i = 0; i < y; i++){
				for (int j = 0; j < n - 1; j++){
					printf("%c", (i&1)? 'U':'D');
				}
				printf("R");
			}
			for (int i = 0; i < x; i++) printf("%s", (i&1)? "LD":"RD");
			for (int i = x + 1; i < n; i++) printf("%s", (i&1)? "DR":"DL");
			if ( !(m - y == 1) ) printf("R");
			for(int i = y + 2; i < m; i++){
				for (int j = 0; j < n - 1; j++){
					printf("%c", (i&1)? 'D':'U');
				}
				if ( !(i == m - 1) ) printf("R");
			}
		}
		printf("\n");
	}

	return 0;
}