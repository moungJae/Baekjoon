#define _CRT_SECURE_NO_WARNINGS
#include <string>
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

int N;
vector<int> child[123457];
ll W[123457], S[123457];

void input() {
	char t;
	int p;
	ll a;

	cin >> N;
	for (int i = 2; i <= N; i++) {
		cin >> t >> a >> p;
		if (t == 'S') S[i] = a;
		else if (t == 'W') W[i] = a;
		child[p].push_back(i);
	}
}

ll tree_traversal(int cur) {
	ll sum = 0;
	
	if (cur == 1) {
		for (int next : child[cur]) {
			sum += tree_traversal(next);
		}
		return sum;
	}
	else {
		if (child[cur].size() == 0) {
			if (W[cur]) return 0;
			return S[cur];
		}
		else {
			for (int next : child[cur]) {
				sum += tree_traversal(next);
			}
			if (W[cur]) return (sum - W[cur] < 0 ? 0 : sum - W[cur]);
			return sum + S[cur];
		}
	}
}

void solution() {
	cout << tree_traversal(1);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}