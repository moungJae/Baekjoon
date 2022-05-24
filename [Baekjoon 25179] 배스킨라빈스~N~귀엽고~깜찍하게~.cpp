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

ll N, M;

void input() {
	cin >> N >> M;
}

void solution() {
	ll x = M + 1;
	N -= 1;
	if (N % x == 0) cout << "Can't win";
	else cout << "Can win";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}