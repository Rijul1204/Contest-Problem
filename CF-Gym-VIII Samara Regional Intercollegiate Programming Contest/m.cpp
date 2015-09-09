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
#define maxm 1000010
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

int dp[maxm], n, q;

int find_ans(int n, int k, int l){

	int ret = 0;
	int kl = k + l;

	ret = ((n / kl) * 2);

	if (n%kl >= k) ret++;

	return ret;
}

int main(){

	int i, j, k, l, test, t = 1;

	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d", &n, &q);

	bool space = false;

	while (q--){

		//memset(dp, 0, sizeof(dp));

		scanf("%d %d", &k, &l);

		/*

		for (int i = 1; i <= n; i++){
		for (int j = k; j <= l; j++){
		if (i - j < 0) break;
		if (dp[i - j] == 0){
		dp[i] = 1;
		break;
		}
		}
		}

		for (int i = 0; i <= n; i++){
		printf("%d : %d\n", i, dp[i]);
		}
		while (scanf("%d", &n) == 1){
		printf("%d\n", find_ans(n, k, l));
		}

		*/

		if (space) printf(" ");
		space = true;
		printf("%d", find_ans(n, k, l));
	}
	puts("");



	return 0;
}