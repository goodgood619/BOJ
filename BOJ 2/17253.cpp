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
#define mod 1000000009
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1;
typedef unsigned long long lll;

int main() {
	setbuf(stdout, NULL);
	ll n;
	scanf("%lld", &n);
	if (n == 0) {
		printf("NO\n");
		return 0;
	}
	while (1) {
		if (n == 0) break;
		if (n % 3 == 2) {
			printf("NO\n");
			return 0;
		}
		else n /= 3;
	}
	printf("YES\n");
	return 0;
}