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

int w[2121212], path[2121212], sum[2121212];
int k, leaf, total;

void input() {
	int weight;
	cin >> k;
	leaf = pow(2, k);
	for (int i = 1; i < leaf; i++) {
		cin >> weight;
		w[2 * i] = weight;
		cin >> weight;
		w[2 * i + 1] = weight;
	}
}

void path_weight(int x) {
	if (x >= leaf) {
		return;
	}
	path_weight(2 * x);
	path_weight(2 * x + 1);
	int left = 2 * x, right = 2 * x + 1;
	path[x] = max(path[left] + w[left], path[right] + w[right]);
	sum[x] = sum[left] + sum[right] + path[x] - path[left] + path[x] - path[right];
	return;
}

void solution() {
	path_weight(1);
	cout << sum[1];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}