#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <list>
#include <climits>
#include <string.h>
#include <deque>
#include <functional>
#include <stack>
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m;
int h = 1;
vector<int> seg;
void update(int index, int value) {
	index += h - 1;
	seg[index] = value;
	while (index > 1) {
		index /= 2;
		seg[index] = seg[index * 2] + seg[index * 2 + 1];
	}
}
int query(int nodenum, int left, int right, int nodeleft, int noderight) {
	if (left > noderight || right < nodeleft) return 0;
	else if (left <= nodeleft && noderight <= right) return seg[nodenum];
	int mid = (nodeleft + noderight) / 2;
	return query(nodenum * 2, left, right, nodeleft, mid) + query(nodenum * 2 + 1, left, right, mid + 1, noderight);
}
int main() {
	scanf("%d%d", &n, &m);
	while (h < n) h *= 2; 
	seg.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		update(i, num);
	}

	for (int i = 1; i <= m; i++) {
		int left, right;
		scanf("%d%d", &left, &right);
		printf("%d\n", query(1, left, right, 1, h));
	}
	return 0;

}