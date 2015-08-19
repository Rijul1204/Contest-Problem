/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
using namespace std;

#define maxm 20
#define maxn ((1<<maxm)+1)
#define inf (1<<29)
#define ii __int64
//#define ii long long int

#define pi  acos(-1.0)
#define eps 1e-9
#define iseq(a,b) (fabs(a-b)<eps)

#define pii pair<int,int>
#define mp  make_pair
#define uu first
#define vv second

ii on(ii n, ii k){ return (n | (1 << k)); }
ii off(ii n, ii k){ return (n - (n&(1 << k))); }
bool chck(ii n, ii k){ return (n&(1 << k)); }

ii mini(ii a, ii b){ if (a < b) return a;  return b; }
ii maxi(ii a, ii b){ if (a > b) return a;  return b; }

int n;
int amount[maxm];

int dp[maxn];

int cal(int mask, int damage){

	if (mask == ((1 << n) - 1)) return 0;

	if (dp[mask] != -1) return dp[mask];

	int n_mask, n_damage, prev, now, next;
	int ret = inf;

	for (int i = 0; i < n; i++){

		n_mask = mask;
		n_damage = damage;
		prev = (i>0) ? (i - 1) : n - 1;
		now = i;
		next = (i<(n - 1)) ? i + 1 : 0;

		if (!chck(mask, prev)){
			n_mask = on(n_mask, prev);
			n_damage -= amount[prev];
		}
		if (!chck(mask, now)){
			n_mask = on(n_mask, now);
			n_damage -= amount[now];
		}
		if (!chck(mask, next)){
			n_mask = on(n_mask, next);
			n_damage -= amount[next];
		}

		if (n_mask == mask) continue;

		ret = mini(cal(n_mask, n_damage) + n_damage, ret);
	}

	return dp[mask] = ret;

}

int main(){

	int i, j, k, l, test, t = 1;

	//freopen("in.txt", "r", stdin);

	while (scanf("%d", &n) == 1){

		int damage = 0;
		for (i = 0; i < n; i++){
			scanf("%d", &amount[i]);
			damage += amount[i];
		}

		memset(dp, -1, sizeof(dp));

		printf("%d\n", cal(0, damage));
	}

	return 0;
}