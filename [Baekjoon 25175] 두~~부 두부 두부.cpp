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

int N, M, K;

void input() {
	cin >> N >> M >> K;
}

void solution() {
	if (K == 3) cout << M;
	else if (K > 3) {
		M += (K - 3);
		if (M % N == 0) cout << N;
		else cout << M % N;
	} 
	else {
		M -= (3 - K);
		while (M <= 0) {
			M += N;
		}
		cout << M;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}