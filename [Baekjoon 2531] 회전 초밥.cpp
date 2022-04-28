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

int N, d, k, c;
int bob[60001];
int visited[3001];

void input() {
	cin >> N >> d >> k >> c;
	for (int i = 1; i <= N; i++) {
		cin >> bob[i];
	}
}

void solution() {
	int left, right, cnt, result;

	for (int i = N + 1; i <= 2 * N; i++) {
		bob[i] = bob[i - N];
	}
	left = 1, right = 0, cnt = 0, result = 0;
	while (right < 2 * N) {
		right++;
		if (!visited[bob[right]]) cnt++;
		visited[bob[right]]++;
		// cout << result << " : " << cnt << endl;
		result = max(result, cnt);
		if (right - left == k - 1) {
			if (!visited[c]) result = max(result, cnt + 1);
			visited[bob[left]]--;
			if (!visited[bob[left]]) cnt--;
			left++;
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