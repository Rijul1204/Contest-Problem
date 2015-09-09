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
#define maxm 100010
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

dd mind(dd a, dd b){ if (a < b) return a;  return b; }
dd maxd(dd a, dd b){ if (a > b) return a;  return b; }

struct node{
	double x, p;
	int ind, c;
	int last1, last2;
	node(){
		last1 = -1, last2 = -1;
	}
	node(int _ind){
		ind = _ind;
		c = 0;
		x = p = 0;
		last1 = -1, last2 = -1;
	}

};

bool operator < (const node &a, const node &b){
	if (iseq(a.x, b.x)){
		return a.ind > b.ind;
	}
	return a.x > b.x;
}

priority_queue<node>pq;
int p, n, ans[maxm];

int main(){

	int i, j, k, l, test, t = 1;

	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);	

	scanf("%d %d", &n, &k);

	for (int i = 1; i <= k; i++){
		node now = node(i);
		pq.push(now);
	}

	for (int i = 1; i <= n; i++){

		scanf("%d", &p);

		node now = pq.top(); pq.pop();
		ans[i] = now.ind;

		if (now.last1 == -1){
			now.last1 = p;
			now.p = now.last1;
		}
		else if (now.last2 == -1){
			now.last2 = p;
			now.p = now.last1 + now.last2;
			now.p *= .5;
		}
		else{
			now.last1 = now.last2;
			now.last2 = p;
			now.p = now.last1 + now.last2;
			now.p *= .5;
		}
		now.c++;
		now.x = (double)now.c*now.p;

		pq.push(now);
	}

	for (int i = 1; i <= n; i++){
		if (i > 1) printf(" ");
		printf("%d", ans[i]);
	}
	puts("");

	return 0;
}