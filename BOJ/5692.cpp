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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> PP;
typedef pair<double, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
int fact(int n) {
	int fac = 1;
	for (int i = 1; i <= n; i++) {
		fac *= i;
	}
	return fac;
}
int main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		int p = n;
		int cnt = 0;
		int sum = 0;
		vector<int> v;
		while (p > 0) {
			v.push_back(p % 10);
			cnt++;
			p /= 10;
		}
		for (int i = 1; i <= cnt; i++) {
			sum += v[i - 1] * fact(i);
		}
		printf("%d\n", sum);
	}
	return 0;
}