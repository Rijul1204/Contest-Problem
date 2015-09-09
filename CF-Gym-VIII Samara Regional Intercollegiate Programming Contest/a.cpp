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

#define mx_cn 201
#define maxm 10010
#define maxn 920
#define inf (1000000009)
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

int n, m;

int p[maxm], w[maxm], d[maxm];
int dp[maxm][maxn][3];

ii cal(int ind, int rem_w, int taken){

	if (taken < 0) return -inf;
	if (rem_w < -200) return -inf;

	if (ind <= 0 && rem_w >= 0){
		return 0;
	}
	if (ind <= 0){
		return -inf;
	}

	if (dp[ind][rem_w + mx_cn][taken] != -1) return dp[ind][rem_w + mx_cn][taken];

	ii ret = max(cal(ind - 1, rem_w, taken),
		max(cal(ind - 1, rem_w - w[ind], taken), cal(ind - 1, rem_w - w[ind] + d[ind], taken - 1)) + p[ind]);

	return dp[ind][rem_w + mx_cn][taken] = ret;
}

int main(){

	int i, j, k, l, test, t = 1;

	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	memset(dp, -1, sizeof(dp));

	scanf("%d %d", &n, &m);

	for (i = 1; i <= n; i++){
		scanf("%d %d %d", &p[i], &w[i], &d[i]);
	}

	ii ans = cal(n, m, 2);

	printf("%d\n", ans);

	return 0;
}