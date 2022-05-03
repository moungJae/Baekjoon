#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <math.h>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

int N;

void input() {
	cin >> N;
}

bool is_prime(int x) {
	int tmp = sqrt(x);
	
	if (x <= 1)
		return false;
	for (int i = 2; i <= tmp; i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}

void dfs(int prime, int depth) {
	if (depth == N) {
		if (is_prime(prime))
			cout << prime << endl;
		return;
	}

	if (depth == 0) {
		dfs(2, 1);
		dfs(3, 1);
		dfs(5, 1);
		dfs(7, 1);
	}
	else {
		if (!is_prime(prime))
			return;
		for (int i = 1; i <= 9; i += 2) {
			dfs(10 * prime + i, depth + 1);
		}
	}
}

void solution() {
	dfs(0, 0);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}