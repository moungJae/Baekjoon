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

int N, M;
int H[100002];
int imos[100002];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) 
		cin >> H[i];
}

void set_imos(int a, int b, int k) {
	imos[a] += k, imos[b + 1] += -k;
}

void apply_imos() {
	for (int i = 1; i <= N; i++) {
		imos[i] += imos[i - 1];
	}
}

void solution() {
	int a, b, k;
	while (M--) {
		cin >> a >> b >> k;
		set_imos(a, b, k);
	}
	apply_imos();
	for (int i = 1; i <= N; i++) cout << H[i] + imos[i] << " ";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}