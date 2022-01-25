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

int N, H;
int height[200002];
int imos[500002];

void input() {
	cin >> N >> H;
	for (int i = 1; i <= N; i++) {
		cin >> height[i];
	}
}

void set_imos(int x, int y) {
	imos[x] += 1, imos[y] -= 1;
}

void solution() {
	int cnt = 0, result = 0;
	for (int i = 1; i <= N; i++) {
		if (i % 2) set_imos(0, height[i]);
		else set_imos(H - height[i], H);
	}
	for (int i = 0; i < H; i++) {
		imos[i] += imos[i - 1];
	}
	result = *min_element(imos, imos + H);
	for (int i = 0; i < H; i++) {
		if (result == imos[i]) cnt++;
	}
	cout << result << " " << cnt;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}