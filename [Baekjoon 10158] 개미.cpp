#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define ll long long
#define INF 100000000
#define endl '\n'

using namespace std;

ll w, h;
ll p, q;
ll t;

void input() {
	cin >> w >> h;
	cin >> p >> q;
	cin >> t;
}

void solution() {
	ll x = t % (2 * w);
	ll y = t % (2 * h);
	ll op = 1;

	while (x--) {
		if (p == w)
			op = -1;
		else if (p == 0)
			op = 1;
		p += op;
	}

	op = 1;
	while (y--) {
		if (q == h)
			op = -1;
		else if (q == 0)
			op = 1;
		q += op;
	}
	cout << p << " " << q;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}