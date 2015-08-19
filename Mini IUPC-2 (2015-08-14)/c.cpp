/*
Author      : Rashedul Hasan Rijul ( Silent_coder ).
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
using namespace std;

#define maxm 2010
#define inf (1<<29)
#define ii int

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

ii mini(ii a, ii b){ if (a<b) return a;  return b; }
ii maxi(ii a, ii b){ if (a>b) return a;  return b; }

int n, m;
int vi, ci;

#define cn 7

int board[10][10];


bool drop(int val, int col){

	int row;

	for (row = 1; row <= cn; row++){

		if (board[row][col] == 0) break;
	}
	if (row > cn) return false;

	board[row][col] = val;

	return true;
}

void print(){

	for (int i = cn; i >= 1; i--){
		for (int j = 1; j <= cn; j++){
			if (board[i][j] == 0) printf("#");
			else printf("%d", board[i][j]);
		}
		puts("");
	}

}

void fix_board(){

	// modify board . . .
	for (int j = 1; j <= cn; j++){
		int pn = 1;
		for (int i = 1; i <= cn; i++){
			if (board[i][j] == 0) continue;
			board[pn][j] = board[i][j];
			pn++;
		}
		for (int i = pn; i <= cn; i++){
			board[i][j] = 0;
		}
	}
}

void cal_col_sum(int col_sum[10]){

	for (int j = 1; j <= cn; j++){
		int i = cn;
		for (; i >= 1; i--){
			if (board[i][j] != 0) break;
		}
		col_sum[j] = i;
	}
}

void cal_row_sum(int row_sum[10][10]){

	for (int i = 1; i <= cn; i++){
		for (int j = 1; j <= cn; j++){
			if (board[i][j] == 0){
				row_sum[i][j] = 0;
			}
			else{
				int cnt = 1;
				for (int k = j + 1; k <= cn; k++){
					if (board[i][k] == 0) break;
					cnt++;
				}
				for (int k = j - 1; k >0; k--){
					if (board[i][k] == 0) break;
					cnt++;
				}
				row_sum[i][j] = cnt;
			}
		}
	}
}

bool change_element(int row_sum[10][10], int col_sum[10]){

	bool change = false;

	// check for changes. . .
	for (int i = 1; i <= cn; i++){
		for (int j = 1; j <= cn; j++){
			if (board[i][j] == 0) continue;
			if (board[i][j] == row_sum[i][j] || board[i][j] == col_sum[j]){
				board[i][j] = 0;
				change = true;
			}
		}
	}

	return change;
}

bool changes(){

	int row_sum[10][10];
	int col_sum[10];

	// calculate col_sum
	cal_col_sum(col_sum);

	// calculating row_sum 
	cal_row_sum(row_sum);

	if (!change_element(row_sum, col_sum)) return false;

	fix_board();

	return true;
}

int main(){

	int i, j, k, l, test, t = 1;

	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while (scanf("%d", &n) == 1){

		if (!n) break;
		bool game_over = false;
		memset(board, 0, sizeof(board));

		while (n--){

			scanf("%d %d", &vi, &ci);

			if (game_over) continue;

			game_over = !drop(vi, ci);

			if (game_over) continue;

			while (changes());

			//print();
		}

		if (game_over){
			puts("Game Over!");
		}
		else{
			print();
		}

		puts("");

	}

	return 0;
}