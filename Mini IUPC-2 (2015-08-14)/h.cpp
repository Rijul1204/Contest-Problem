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
using namespace std;

#define maxm 1005
#define inf (1<<29)
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

struct point { // Creates normal 2D point
	double x, y;
	point() {}
	point(double xx, double yy) { x = xx, y = yy; }
	// Operator overloading......
	bool operator <(point b)const{
		if (!eq(x, b.x))	return x < b.x;
		return y < b.y;
	}
	bool operator == (point b) const{
		if (eq(x, b.x) && eq(y, b.y))	return true;
		return false;
	}

};

struct segment { // Creates a segment with two end points -> A, B
	point A, B;
	segment() {}
	segment(point P1, point P2) { A = P1, B = P2; }
	bool operator < (const segment &a)const{
		return A<a.A;
	}
};

struct line { // Creates a line with equation ax + by + c = 0
	double a, b, c;
	line() {}
	line(point p1, point p2) {
		a = p1.y - p2.y;
		b = p2.x - p1.x;
		c = p1.x * p2.y - p2.x * p1.y;
	}
};

//Perpendicular Line of a Given Line Through a Point:
inline line findPerpendicularLine(line L, point P) {
	line res; //line perpendicular to L, and intersects with P
	res.a = L.b, res.b = -L.a;
	res.c = -res.a * P.x - res.b * P.y;
	return res;
}

//Intersection - Line, Line:
inline bool intersection(line L1, line L2, point &p) {
	double det = L1.a * L2.b - L1.b * L2.a;
	if (eq(det, 0)) return false;
	p.x = (L1.b * L2.c - L2.b * L1.c) / det;
	p.y = (L1.c * L2.a - L2.c * L1.a) / det;
	return true;
}

// distance between point to line....
inline double distancepl(point P, line L) {
	return fabs(L.a * P.x + L.b * P.y + L.c) / sqrt(L.a * L.a + L.b * L.b);
}

// distance between point to point...
inline double distancepp(point a, point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

//Distance - Point, Segment:
inline double distanceps(point P, segment S) {
	line L1 = line(S.A, S.B), L2; point P1;
	L2 = findPerpendicularLine(L1, P);
	if (intersection(L1, L2, P1))
		if (eq(distancepp(S.A, P1) + distancepp(S.B, P1), distancepp(S.A, S.B)))
			return distancepl(P, L1);
	return min(distancepp(S.A, P), distancepp(S.B, P));
}

//Intersection - Segment, Segment:
inline bool intersection(segment L1, segment L2, point &p) {
	if (!intersection(line(L1.A, L1.B), line(L2.A, L2.B), p)) {
		return false; // can lie on another, just check their equations, and check overlap
	}
	return(eq(distancepp(L1.A, p) + distancepp(L1.B, p), distancepp(L1.A, L1.B)) &&
		eq(distancepp(L2.A, p) + distancepp(L2.B, p), distancepp(L2.A, L2.B)));
}

//Distance - Segment, Segment:
inline double distancess(segment S1, segment S2) {

	point p;
	if (intersection(S1, S2, p)) return 0;

	return min(
		min(distanceps(S1.A, S2), distanceps(S1.B, S2)),
		min(distanceps(S2.A, S1), distanceps(S2.B, S1)));
}

int n, m;

double dist_mat[maxm][maxm];
segment segs[maxm];

int vis[maxm], kas = 1;

bool connected(int s, double len){

	if (s == 2) return true;
	if (vis[s] == kas) return false;
	vis[s] = kas;

	for (int i = 1; i <= n; i++){
		if (dist_mat[s][i] > len + eps) continue;
		if (connected(i, len)) return true;
	}

	return false;
}

double binary_search(){

	double lo = 0, hi = 1000000;
	int turn = 500;

	while (turn--){

		double mid = lo + hi; mid /= 2.0;

		kas++;
		if (connected(1, mid)){
			hi = mid;
		}
		else{
			lo = mid;
		}
	}

	return lo;
}

int main(){

	int i, j, k, l, test, t = 1;

	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while (scanf("%d", &n) == 1){

		if (!n) break;

		int x1, y1, L;
		int x2, y2;

		for (int i = 1; i <= n; i++){

			scanf("%d %d %d", &x1, &y1, &L);

			if (L > 0){
				x2 = x1 + L, y2 = y1;
			}
			else{
				x2 = x1, y2 = y1 - L;
			}

			segs[i] = segment(point(x1, y1), point(x2, y2));
		}

		for (int i = 1; i <= n; i++){

			for (int j = 1; j <= n; j++){
				dist_mat[i][j] = distancess(segs[i], segs[j]);
				//printf("%.2lf ", dist_mat[i][j]);
			}
			//puts("");
		}

		double ans = binary_search();

		printf("%.2lf\n", ans);
		//printf("%.5lf\n", ans);
	}

	return 0;
}