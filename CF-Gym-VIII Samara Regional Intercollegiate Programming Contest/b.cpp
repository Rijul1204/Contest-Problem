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

int p, n, x;

int find_ans(int p, int n, int x){

	int ans = 0;

	int total_col = (n / p) + 1;

	int no_of_col = (x / p) + 1;

	if (no_of_col < total_col){

		int ans1 = (x / p) + (x%p);
		int ans2 = (x / p) + 1 + (p - (x%p));
		ans = min(ans1, ans2);
	}
	else{
		ans = (x / p);
		int rem = x%p;
		int back_rem = ((n%p) - rem);
		ans += (min(rem, back_rem + 1));
	}

	return ans;
}


int find_ans2(int n, int p){

	int ret = 0;

	ret = min((n / p) + n%p, ((n / p) + 1) + (p - (n%p)));

	return ret;
}

int main(){

	int i, j, k, l, test, t = 1;

	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while (scanf("%d %d %d", &p, &n, &x) == 3){

		int ans = find_ans(p, n, x);

		// from n - to x 
		int ans1 = find_ans(p, n, n);
		int rem = (n - x);

		int ans2 = find_ans2(rem, p);

		ans1 += ans2;

		ans = min(ans, ans1);

		printf("%d\n", ans);
	}

	return 0;
}