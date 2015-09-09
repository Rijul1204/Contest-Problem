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

dd mind(dd a, dd b){ if (a<b) return a;  return b; }
dd maxd(dd a, dd b){ if (a>b) return a;  return b; }

struct node{
	char s[100];
	int x, y;
};

node nodes[maxm];

int n, m, K;
int a[maxm], b[maxm];

vector< vector<int> > res;

void find_res(int a[], int b[]){

	int pn = 1;

	for (int i = 1; i <= n;){

		while (b[pn] != a[i]){
			pn++;
		}
		int k = K;
		vector<int>now;
		while (k--){
			if (a[i] != b[pn]) break;
			now.push_back(i);
			i++; pn++;
			if (i > n) break;
		}
		res.push_back(now);
	}

}

int main(){

	int i, j, k, l, test, t = 1;

	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);	

	scanf("%d %d %d", &n, &m, &K);

	for (i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	for (i = 1; i <= m; i++){
		scanf("%d", &b[i]);
	}

	find_res(a, b);

	printf("%d\n", res.size());

	for (i = 0; i < res.size(); i++){
		printf("%d", res[i].size());
		for (j = 0; j < res[i].size(); j++){
			printf(" %d", res[i][j]);
		}
		puts("");
	}

	return 0;
}