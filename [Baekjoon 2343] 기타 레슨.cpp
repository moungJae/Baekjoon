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

int N, M;
ll X[100001];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> X[i];
}

void solution() {
	ll low = 0, high = INF;
	ll result = INF;
	while (low <= high) {
		ll mid = (low + high) / 2; // 블루레이 크기
		if (mid < *max_element(X, X + N)) {
			low = mid + 1;
		}
		else {
			vector<ll> v;
			ll tmp = 0;
			for (int i = 1; i <= N; i++) {
				if (tmp + X[i] > mid) {
					v.push_back(mid);
					tmp = X[i];
				}
				else tmp += X[i];
			}
			v.push_back(mid);
			if (v.size() > M) {
				low = mid + 1;
			}
			else {
				result = min(result, mid);
				high = mid - 1;
			}
		}
	}
	cout << result;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}