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
#include <list>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

int N, Q;
ll A[100001];
ll segtree[300001];

void input() {
	cin >> N >> Q;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
}

void set_segtree(int idx, int left, int right) {
	if (left == right) {
		segtree[idx] = A[left];
		return;
	}
	int mid = (left + right) / 2;
	
	set_segtree(2 * idx, left, mid);
	set_segtree(2 * idx + 1, mid + 1, right);
	segtree[idx] = segtree[2 * idx] + segtree[2 * idx + 1];
}

ll find_segtree(int idx, int left, int right, int q_left, int q_right) {
	if (q_left <= left && right <= q_right) {
		return segtree[idx];
	}
	if (right < q_left || q_right < left)
		return 0;
	int mid = (left + right) / 2;

	return find_segtree(2 * idx, left, mid, q_left, q_right)
		+ find_segtree(2 * idx + 1, mid + 1, right, q_left, q_right);
}

void update_segtree(int idx, int left, int right, int query) {
	if (left == query && right == query) {
		segtree[idx] = A[query];
		return;
	}
	if (right < query || query < left)
		return;
	int mid = (left + right) / 2;

	update_segtree(2 * idx, left, mid, query);
	update_segtree(2 * idx + 1, mid + 1, right, query);
	segtree[idx] = segtree[2 * idx] + segtree[2 * idx + 1];
}

void solution() {
	int a, x, y;
	ll b;

	set_segtree(1, 1, N);
	while (Q--) {
		cin >> x >> y >> a >> b;
		cout << find_segtree(1, 1, N, min(x, y), max(x, y)) << endl;
		A[a] = b;
		update_segtree(1, 1, N, a);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}