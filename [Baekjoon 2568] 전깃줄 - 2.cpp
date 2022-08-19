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
int low, high;
int arr[500001];
int dp[500001];
bool visited[500001];

void input() {
	int index, connect;

	cin >> n;
	low = 1e9;
	for (int i = 0; i < n; i++) {
		cin >> index >> connect;
		arr[index] = connect;
		low = min(low, index);
		high = max(high, index);
	}
}

void solution() {
	vector<int> v;
	stack<int> S;

	for (int i = low; i <= high; i++) {
		if (arr[i] == 0) {
			dp[i] = -1;
			visited[i] = true;
			continue;
		}
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

	for (int i = high; i >= low; i--) {
		if (dp[i] == index) {
			int cur = i;

			S.push(arr[i]);
			visited[i] = true;
			i -= 1;
			while (i >= low) {
				if (dp[i] == -1) {
					i -= 1;
					continue;
				}
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

	for (int i = high; i >= low; i--) {
		if (visited[i])
			continue;
		S.push(i);
	}

	cout << S.size() << endl;
	while (!S.empty()) {
		cout << S.top() << endl;
		S.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}