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

ll N, K, Q;

void input() {
	cin >> N >> K >> Q;
}

ll get_lca(ll x, ll y) {
	map<ll, bool> m;
	m[x] = m[y] = true;
	while (x != 1) {
		x = (x + K - 2) / K;
		if (m[x]) return x;
		m[x] = true;
	}
	while (y != 1) {
		y = (y + K - 2) / K;
		if (m[y]) return y;
	}
}

int go_lca(ll x, ll lca) {
	int dist = 0;
	while (x != lca) {
		x = (x + K - 2) / K;
		dist++;
	}
	return dist;
}

void solution() {
	ll x, y, lca;
	while (Q--) {
		cin >> x >> y;
		if (K == 1) {
			cout << abs(x - y) << endl;
		}
		else {
			lca = get_lca(x, y);
			cout << go_lca(x, lca) + go_lca(y, lca) << endl;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}