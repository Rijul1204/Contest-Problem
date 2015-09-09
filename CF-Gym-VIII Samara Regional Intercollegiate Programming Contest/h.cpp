/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
Created on  : 2014-08-19
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include <ctime>
using namespace std;

#define maxm 1010
#define maxn ((1<<maxm)+10)
#define inf (1000000001)
#define dd double
#define ii int

#define pi  acos(-1.0)
#define eps 1e-9
#define iseq(a,b) (fabs(a-b)<eps)
#define eq(a,b) (fabs(a-b)<eps)

#define pii pair<int,int>
#define mp  make_pair
#define uu first
#define vv second

ii on(ii n, ii k){ return (n | (1 << k)); }
ii off(ii n, ii k){ return (n - (n&(1 << k))); }
bool chck(ii n, ii k){ return (n&(1 << k)); }

dd mind(dd a, dd b){ if (a<b) return a;  return b; }
dd maxd(dd a, dd b){ if (a>b) return a;  return b; }

int n;
int a[maxm], b[maxm], c[maxm];


int main(){

	int i, j, k, l, test, t = 1;

	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d", &n);

	int mx_a = 0;
	for (i = 0; i < n; i++){
		scanf("%d", &a[i]);
		mx_a = max(mx_a, a[i]);
	}

	for (i = 0; i < n; i++){
		scanf("%d", &b[i]);
	}

	scanf("%d", &k);
	int ans = 0;
	for (i = 0; i < k; i++){
		scanf("%d", &c[i]);
		ans += c[i];
	}

	ans += (k*mx_a);

	printf("%d\n", ans);


	return 0;
}