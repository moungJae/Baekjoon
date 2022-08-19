#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define INF 100000000
#define endl '\n'

using namespace std;

int n;
int arr[40001];

void input() {	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void solution() {
	vector<int> v;

	for (int i = 0; i < n; i++) {
		int index = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
		
		if (index == v.size()) {
			v.push_back(arr[i]);
		}
		else if (index < v.size()) {
			v[index] = arr[i];
		}
	}
	cout << v.size() << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}