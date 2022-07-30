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

int n;
ll X[100001];
int segTree[300001];

bool input() {
	cin >> n;
	if (n == 0) return false;
	for (int i = 1; i <= n; i++) {
		cin >> X[i];
	}
	return true;
}

void set_Segtree(int idx, int left, int right) {
	if (left == right) {
		segTree[idx] = left;
		return;
	}
	int mid = (left + right) / 2;
	set_Segtree(2 * idx, left, mid);
	set_Segtree(2 * idx + 1, mid + 1, right);
	segTree[idx] = X[segTree[2 * idx]] > X[segTree[2 * idx + 1]] ? 
		segTree[2 * idx + 1] : segTree[2 * idx];
}

int query_Segtree(int idx, int left, int right, int q_left, int q_right) {
	if (right < q_left || q_right < left) return -1;
	if (q_left <= left && right <= q_right) {
		return segTree[idx];
	}
	int mid = (left + right) / 2;
	int A = query_Segtree(2 * idx, left, mid, q_left, q_right);
	int B = query_Segtree(2 * idx + 1, mid + 1, right, q_left, q_right);
	if (A == -1) return B;
	if (B == -1) return A;
	if (X[A] > X[B]) return B;
	return A;
}

ll max_Square(int left, int right) {
	if (left == right) {
		return X[left];
	}

	int mid = query_Segtree(1, 1, n, left, right);

	ll S = (ll)(right - left + 1) * X[mid];
	if (left <= mid - 1) {
		S = max(S, max_Square(left, mid - 1));
	}
	if (mid + 1 <= right) {
		S = max(S, max_Square(mid + 1, right));
	}

	return S;
}

void solution() {
	set_Segtree(1, 1, n);
	cout << max_Square(1, n) << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();


	return 0;
}