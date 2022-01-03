#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <malloc.h>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

int N, C;
vector<ll> v;

void input() {
	ll x;
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
}

void solution() {
	int left = 1, right = v[N - 1] - v[0]; 
	int result, start, cnt;

	while (left <= right) {
		int mid = (left + right) / 2; // gap 
		start = v[0], cnt = 1;

		for (int i = 1; i < N; i++) {
			if (mid <= v[i] - start) { // gap보다 크거나 같을 경우
				cnt++;
				start = v[i];
			}
		}

		if (cnt >= C) { // 공유기 수가 많으니 gap 증가
			left = mid + 1, result = mid;
		}
		else { // 공유기 수가 적으니 gap 감소
			right = mid - 1;
		}
	}

	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}