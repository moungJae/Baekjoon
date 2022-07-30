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
#include <time.h>
#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

int N;
bool check[500001];
int X[500001];
ll segtree[2000000], cnt[500001];
vector<int> v;
map<int, int> m;
int num;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X[i];
		v.push_back(X[i]);
	}
}

void set_coordinate_compression() {
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		int cur = v[i];

		if (m[cur]) {
			cnt[m[cur]]++;
			continue;
		}
		m[cur] = ++num;
		cnt[m[cur]]++;
	}
}

void set_segtree(int idx, int left, int right) {
	if (left == right) {
		segtree[idx] = cnt[left];
		return;
	}
	int mid = (left + right) / 2;

	set_segtree(2 * idx, left, mid);
	set_segtree(2 * idx + 1, mid + 1, right);
	segtree[idx] = segtree[2 * idx] + segtree[2 * idx + 1];
}

ll find_segtree(int idx, int left, int right, int q_left, int q_right) {
	if (right < q_left || q_right < left) {
		return 0;
	}
	if (q_left <= left && right <= q_right) {
		return segtree[idx];
	}
	int mid = (left + right) / 2;
	
	return find_segtree(2 * idx, left, mid, q_left, q_right)
		+ find_segtree(2 * idx + 1, mid + 1, right, q_left, q_right);
}

ll update_segtree(int idx, int left, int right, int del) {
	ll ret = 0;

	if (right < del || del < left) {
		return 0;
	}
	if (left == right) {
		ret = segtree[idx];
		segtree[idx] = 0;
		return ret;
	}
	int mid = (left + right) / 2;

	ret = max({ ret, update_segtree(2 * idx, left, mid, del),
		update_segtree(2 * idx + 1, mid + 1, right, del) });
	segtree[idx] -= ret;
	return ret;
}

void solution() {
	ll ans = 0;

	set_coordinate_compression();
	set_segtree(1, 1, num);

	for (int i = 0; i < N; i++) {
		int cur = m[X[i]];

		if (check[cur])
			continue;
		ans += find_segtree(1, 1, num, 1, cur - 1);
		update_segtree(1, 1, num, cur);
		check[cur] = true;
	}

	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	input();
	solution();

	return 0;
}