/*
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1e6 + 100;

class Node{
public:	
	int a, b;
};
Node a[MAXN], b[MAXN], c[MAXN];
int ansA, ansB, ansC;

bool mCmpA(Node tempA, Node tempB)
{
	return tempA.a < tempB.a;
}

bool mCmpB(Node tempA, Node tempB)
{
	return tempA.b < tempB.b;
}

int getA(int n)
{
	cout<<"A"<<endl;
	for (int i = 0; i < n; i++) cout<<a[i].a<<"  "<<a[i].b<<endl;

	ansA = 0;
	int len = 0;
	sort(a, a + n, mCmpA);
	int st = 0, pos = 0;
	for (int i = 0; i <= n; i++){
		if ( a[st].a == a[i].a ){
			pos = i + 1;
			continue;
		}
		i--;

		bool flag = true;
		for (int j = st; j < pos; j++){
			if ( a[st].b != a[j].b ){
				flag = false;
				ansA++;
				break;
			}
		}
		if ( flag ){
			for (int j = st; j < pos; j++) b[len++] = a[j];
		}
		st = pos;
	}

	return len;
}

int getB(int n)
{
	cout<<"B"<<endl;
	for (int i = 0; i < n; i++) cout<<b[i].a<<"  "<<b[i].b<<endl;

	ansB = 0;
	int len = 0;
	sort(b, b + n, mCmpB);
	int st = 0, pos = 0;
	for (int i = 0; i <= n; i++){
		if ( b[st].b == b[i].b ){
			pos = i + 1;
			continue;
		}
		i--;

		bool flag = true;
		for (int j = st; j < pos; j++){
			if ( b[st].a != b[j].a ){
				flag = false;
				ansB++;
				break;
			}
		}
		if ( flag ){
			for (int j = st; j < pos; j++) c[len++] = b[j];
		}
		st = pos;
	}

	return len;
}

void getC(int n)
{
	cout<<"C"<<endl;
	for (int i = 0; i < n; i++) cout<<c[i].a<<"  "<<c[i].b<<endl;
	
	ansC = 0;
	for (int i = 0; i < n; i++){
		if ( c[i].b != c[i+1].b ) ansC++;
	}
}

int main()
{

	freopen("in.txt", "r", stdin);
	int T;
	cin>>T;
	int t = 1;
	while ( T-- )
	{
		int n;
		cin>>n;
		memset(a, -1, (n + 10) * sizeof a[0]);
		memset(b, -1, (n + 10) * sizeof b[0]);
		memset(c, -1, (n + 10) * sizeof c[0]);
		for (int i = 0; i < n; i++){
			scanf("%d %d", &a[i].a, &a[i].b);
		}

		int len = 0;
		len = getA(n);
		len = getB(len);
		getC(len);

		printf("Case #%d: %d %d %d\n", t++, ansA, ansB, ansC);
	}

	return 0;
}*/