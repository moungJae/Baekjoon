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

int N, M;
ll X[100001];
ll min_Segtree[262145];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> X[i];
	}
}

void set_Min_Segtree(int idx, int left, int right) {
	if (left == right) {
		min_Segtree[idx] = X[left];
		return;
	}
	int mid = (left + right) / 2;
	set_Min_Segtree(2 * idx, left, mid);
	set_Min_Segtree(2 * idx + 1, mid + 1, right);
	min_Segtree[idx] = min(min_Segtree[2 * idx], min_Segtree[2 * idx + 1]);
}

ll query_Min_Segtree(int idx, int left, int right, int q_left, int q_right) {
	if (right < q_left || q_right < left) {
		return INF;
	}
	if (q_left <= left && right <= q_right) {
		return min_Segtree[idx];
	}
	int mid = (left + right) / 2;
	ll a = query_Min_Segtree(2 * idx, left, mid, q_left, q_right);
	ll b = query_Min_Segtree(2 * idx + 1, mid + 1, right, q_left, q_right);
	return min(a, b);
}

void solution() {
	int a, b;
	set_Min_Segtree(1, 1, N);
	while (M--) {
		cin >> a >> b;
		cout << query_Min_Segtree(1, 1, N, a, b) << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}