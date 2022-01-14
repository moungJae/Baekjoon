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
#define INF 100000000
#define endl '\n'
#define ll long long

using namespace std;

int N, M, K;
ll X[1000001];
ll seg_tree[2000001];

void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) cin >> X[i];
}

void set_Segtree(int idx, int left, int right) {
	if (left == right) {
		seg_tree[idx] = X[left];
		return;
	}
	int mid = (left + right) / 2;
	set_Segtree(2 * idx, left, mid);
	set_Segtree(2 * idx + 1, mid + 1, right);
	seg_tree[idx] = seg_tree[2 * idx] + seg_tree[2 * idx + 1];
}

void update_Segtree(int idx, int left, int right, int pos, ll val) {
	if (pos < left || right < pos) return;
	if (left == pos && right == pos) {
		seg_tree[idx] = val;
		return;
	}
	int mid = (left + right) / 2;
	update_Segtree(2 * idx, left, mid, pos, val);
	update_Segtree(2 * idx + 1, mid + 1, right, pos, val);
	seg_tree[idx] = seg_tree[2 * idx] + seg_tree[2 * idx + 1];
}

ll query(int idx, int left, int right, int q_left, int q_right) {
	if (right < q_left || q_right < left) return 0;
	if (q_left <= left && right <= q_right) return seg_tree[idx];
	int mid = (left + right) / 2;
	return query(2 * idx, left, mid, q_left, q_right)
		+ query(2 * idx + 1, mid + 1, right, q_left, q_right);
}

void solution() {
	int query_cnt = M + K;
	int a, b;
	ll c;

	set_Segtree(1, 1, N);
	while (query_cnt--) {
		cin >> a >> b >> c;
		if (a == 1) {
			update_Segtree(1, 1, N, b, c);
		}
		else if (a == 2) {
			cout << query(1, 1, N, b, c) << endl;
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