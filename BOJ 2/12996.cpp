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
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
int n,a,b,c;
ll dp[55][55][55][55];
ll go(int index,int first,int second,int third) {
	if (index>=n && first==0 && second==0 && third==0) return 1;
	if (index >= n) return 0;
	if (first < 0 || second < 0 || third < 0) return 0;
	ll &ret = dp[index][first][second][third];
	if (ret != -1) return ret;
	ret = 0;

	if (first != 0 && second != 0 && third != 0) { 
		ret += go(index + 1, first - 1, second, third);
		ret %= mod;
		ret += go(index + 1, first, second-1, third);
		ret %= mod;
		ret += go(index + 1, first , second, third-1);
		ret %= mod;
		ret += go(index + 1, first - 1, second-1, third);
		ret %= mod;
		ret += go(index + 1, first - 1, second, third-1);
		ret %= mod;
		ret += go(index + 1, first, second-1, third-1);
		ret %= mod;
		ret += go(index + 1, first - 1, second-1, third-1);
		ret %= mod;
	}
	if (first == 0 && second != 0 && third != 0) {
		ret += go(index + 1, first, second - 1, third);
		ret %= mod;
		ret += go(index + 1, first, second, third - 1);
		ret %= mod;
		ret += go(index + 1, first, second - 1, third - 1);
		ret %= mod;
	}
	if (first != 0 && second == 0 && third != 0) {
		ret += go(index + 1, first - 1, second, third);
		ret %= mod;
		ret += go(index + 1, first, second, third - 1);
		ret %= mod;
		ret += go(index + 1, first - 1, second, third - 1);
		ret %= mod;
	}
	if (first != 0 && second != 0 && third == 0) {
		ret += go(index + 1, first - 1, second, third);
		ret %= mod;
		ret += go(index + 1, first, second - 1, third);
		ret %= mod;
		ret += go(index + 1, first - 1, second - 1, third);
		ret %= mod;
	}
	if (first == 0 && second == 0 && third != 0) {
		ret += go(index+1,first, second, third-1);
		ret %= mod;
	}
	if (first == 0 && second != 0 && third == 0) {
		ret += go(index+1,first, second - 1, third);
		ret %= mod;
	}
	if (first != 0 && second == 0 && third == 0) {
		ret += go(index+1,first-1, second, third);
		ret %= mod;
	}
	return ret;
}
int main() {
	scanf("%d%d%d%d", &n,&a,&b,&c);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n",go(0, a,b,c)%mod);
	return 0;
}