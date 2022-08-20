#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define ll long long
#define INF 100000000
#define endl '\n'

using namespace std;

int l, n;
int pos[1000001];

void input() {
	cin >> l >> n;
	for (int i = 0; i < n; i++)
		cin >> pos[i];
}

void solution() {
	int min_ans, max_ans;
	
	sort(pos, pos + n);
	min_ans = 0;
	for (int i = 0; i < n; i++) {
		min_ans = max(min_ans, min(pos[i], l - pos[i]));
	}

	int left = pos[0], right = pos[n - 1];
	bool op = true;

	max_ans = 0;
	while (left != 0 || right != l) {
		if (op) {
			left++, right--;
		}
		else {
			if (left > 0) left--;
			if (right < l) right++;
		}
		max_ans++;
		if (left >= right) {
			op = false;
			if (left > right)
				swap(left, right);
		}
	}

	cout << min_ans << " " << max_ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	
	cin >> t;
	while (t--) {
		input();
		solution();
	}

	return 0;
}