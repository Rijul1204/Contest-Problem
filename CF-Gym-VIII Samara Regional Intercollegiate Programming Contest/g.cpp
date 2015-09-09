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

#define maxm 200010
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
vector<int>G[maxm];
stack<int>st;

int main(){

	int i, j, k, l, test, t = 1;

	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d", &n);

	char s[10];
	int v;

	for (int i = 1; i <= n + n; i++){

		scanf("%s %d", s, &v);

		if (s[0] == 'i'){

			if (!st.empty()){
				G[st.top()].push_back(v);
			}
			st.push(v);
		}
		else st.pop();
	}

	for (int i = 1; i <= n; i++){
		for (int j = 0; j < G[i].size(); j++){
			printf("%d %d\n", i, G[i][j]);
		}
	}


	return 0;
}