#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
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
using namespace std;
typedef long long ll;
#define INF 1000000000
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
int n,m;
int board[105][105];
int main() {
	scanf("%d%d", &n,&m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			board[i][j] = 1e9;
		}
	}
	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		board[first][second] = 1;
		board[second][first] = -1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][k] == 1 && board[k][j] == 1) board[i][j] = 1;
				if (board[i][k] == -1 && board[k][j] == -1) board[i][j] = -1;
			}
		}
	}
	int sum = 1e9;
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		int sum2 = 0;
		int cnt = 1;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (board[i][j] == 1 || board[i][j] == -1) cnt++;
		}
		printf("%d\n", n - cnt);
	}
	return 0;
}