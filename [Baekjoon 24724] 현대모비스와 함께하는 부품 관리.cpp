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

int T, N;
ll A, B;

void input() {
	
}

bool compare(pair<ll, ll> x, pair<ll, ll> y) {
	if (x.first == y.first)
		return x.second < y.second;
	return x.first < y.first;
}

void solution() {
	cin >> T;
	for (int test = 1; test <= T; test++) {
		ll u, v;
		vector<pair<ll, ll>> vec;

		cout << "Material Management " << test << endl;
		cin >> N >> A >> B;
		for (int i = 1; i <= N; i++) {
			cin >> u >> v;
			vec.push_back({ u, v });
		}
		sort(vec.begin(), vec.end(), compare);
		if (vec[0].first <= A && vec[0].second <= B) {
			cout << "Classification ---- End!" << endl;
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