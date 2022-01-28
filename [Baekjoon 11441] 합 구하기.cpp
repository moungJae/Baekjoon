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

int N, K;
int arr[100001], segTree[300001];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
}

void set_Segtree(int idx, int left, int right) {
	if (left == right) {
		segTree[idx] = arr[left];
		return;
	}

	int mid = (left + right) / 2;
	set_Segtree(idx * 2, left, mid);
	set_Segtree(idx * 2 + 1, mid + 1, right);
	segTree[idx] = segTree[idx * 2] + segTree[idx * 2 + 1];
}

int query_Segtree(int idx, int left, int right, int q_left, int q_right) {
	if (right < q_left || q_right < left) return 0;
	if (q_left <= left && right <= q_right) return segTree[idx];
	int mid = (left + right) / 2;
	return query_Segtree(2 * idx, left, mid, q_left, q_right)
		+ query_Segtree(2 * idx + 1, mid + 1, right, q_left, q_right);
}

void solution() {
	int left, right;
	set_Segtree(1, 1, N);
	cin >> K;
	while (K--) {
		cin >> left >> right;
		cout << query_Segtree(1, 1, N, left, right) << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}