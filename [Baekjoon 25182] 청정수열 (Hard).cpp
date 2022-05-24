#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

ll N;

void input() {
	cin >> N;
}

void solution() {
	ll ans = 0, cnt = 1;
	ll div = 1000000007;

	for (ll i = 1; i <= N; i++) {
		ll tmp = (i * i) % div;
		tmp = (tmp * (i + 1)) % div;
		ans = (ans + tmp) % div;
		tmp = (i * i) % div;
		cnt = (cnt * tmp) % div;
	}
	cout << ans << " " << cnt;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}