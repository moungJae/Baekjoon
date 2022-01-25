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

int tmp[1 << 20];
int A[1 << 20];
int N, k;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	cin >> k;
}

void sorting(int l1, int r1, int l2, int r2) {
	// cout << l1 << ", " << r1 << " - " << l2 << ", " << r2 << endl;
	int i = 0, idx1 = l1, idx2 = l2;
	while (idx1 <= r1 && idx2 <= r2) {
		if (A[idx1] < A[idx2]) {
			tmp[i++] = A[idx1++];
		}
		else {
			tmp[i++] = A[idx2++];
		}
	}

	while (idx1 <= r1) {
		tmp[i++] = A[idx1++];
	}

	while (idx2 <= r2) {
		tmp[i++] = A[idx2++];
	}

	i = 0;
	while (l1 <= r2) {
		A[l1++] = tmp[i++];
	}
}

void divide_and_conquer(int left, int right, int ok) {
	if (left == right) {
		return;
	}
	int mid = (left + right) / 2;
	divide_and_conquer(left, mid, 2 * ok);
	divide_and_conquer(mid + 1, right, 2 * ok);
	sorting(left, mid, mid + 1, right);
	// cout << left << " - " << right << " => " << ok << endl;
	if (ok == k) {
		for (int i = left; i <= right; i++) {
			cout << A[i] << " ";
		}
	}
}

void solution() {
	divide_and_conquer(0, N - 1, 1);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}