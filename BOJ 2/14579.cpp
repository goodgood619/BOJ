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
#define mod 1000000007
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0, -1,0,1 };
int goy[4] = { 1, 0,-1,0 };
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int gob = 1;
	for (int j = a; j <= b; j++) {
		int sum = 0;
		for (int i = 1; i <= j; i++) {
			sum += i;
		}
		gob *= sum;
		gob %= 14579;
	}
	printf("%d\n", gob);
	return 0;
}