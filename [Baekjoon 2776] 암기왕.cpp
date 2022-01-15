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

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> N;
		vector<int> v(N);
		for (int i = 0; i < N; i++) {
			ll x;
			cin >> x;
			v[i] = x;
		}
		sort(v.begin(), v.end());
		cin >> M;
		for (int i = 0; i < M; i++) {
			ll x;
			cin >> x;
			int idx = lower_bound(v.begin(), v.end(), x) - v.begin();
			if (idx == N || v[idx] != x) cout << 0 << endl;
			else cout << 1 << endl;
		}
	}

	return 0;
}