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
#define maxm 1010
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

int n, x, y;
char dir[20];

int get_reqtim(int goat_x, int shep_x){

	int ret = 0;

	if (goat_x <= shep_x){
		int diff = shep_x - goat_x;
		ret = (diff / 3) + (bool)(diff % 3);
	}
	else{
		ret = goat_x - shep_x;
	}

	return ret;
}

int get_reqtim(node now){

	int ret = abs(now.y) / 2 + abs(now.y) % 2;

	ret += get_reqtim(ret, now.x);

	return ret;
}

int main(){

	int i, j, k, l, test, t = 1;

	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);	

	scanf("%d %d", &x, &y);

	scanf("%s", dir);

	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%s %d %d", &nodes[i].s, &nodes[i].x, &nodes[i].y);

		nodes[i].x -= x, nodes[i].y -= y;

		if (dir[0] == 'L'){
			nodes[i].x = -nodes[i].x;
		}
		else if (dir[0] == 'U'){
			swap(nodes[i].x, nodes[i].y);
			nodes[i].y = -nodes[i].y;
		}
		else if (dir[0] == 'D'){
			swap(nodes[i].x, nodes[i].y);
			nodes[i].x = -nodes[i].x;
		}
	}

	string ans = "";
	int mx_tim = inf;

	for (int i = 0; i < n; i++){
		int curr_tim = get_reqtim(nodes[i]);
		if (curr_tim<mx_tim){
			mx_tim = curr_tim;
			ans = nodes[i].s;
		}
	}

	cout << ans << endl;

	return 0;
}