#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define ll long long
#define INF 100000000
#define endl '\n'

using namespace std;

int n;
int arr[100001];
int dp[100001];
bool visited[100001];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void solution() {
	vector<int> v;
	stack<int> S;

	for (int i = 0; i < n; i++) {
		int index = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
		
		dp[i] = index + 1;
		if (index == v.size()) {
			v.push_back(arr[i]);
		}
		else if (index < v.size()) {
			v[index] = arr[i];
		}
	}

	int index = v.size();

	for (int i = n - 1; i >= 0; i--) {
		if (dp[i] == index) {
			int cur = i;

			S.push(arr[i]);
			visited[i] = true;
			i -= 1;
			while (i >= 0) {
				if (dp[cur] == dp[i] + 1 && arr[i] < S.top()) {
					cur = i;
					S.push(arr[i]);
					visited[i] = true;
				}
				i -= 1;
			}
			break;
		}
	}

	while (!S.empty())
		S.pop();

	for (int i = n - 1; i >= 0; i--) {
		if (visited[i])
			continue;
		S.push(i);
	}

	cout << S.size() << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}