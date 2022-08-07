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
#include <list>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

int N;
int w[31];
map<int, bool> dp[31];

bool check(int weight, int total, int idx) {
	if (idx == N) {
		return (weight == total);
	}
	if (dp[idx][total])
		return false;

	dp[idx][total] = true;
	return (check(weight, total + w[idx], idx + 1) 
		|| check(weight, total, idx + 1)
		|| check(weight, total - w[idx], idx + 1));
}

void init() {
	for (int i = 0; i <= 30; i++) {
		dp[i].clear();
	}
}

void input() {
	int cnt;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> w[i];
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int weight;

		cin >> weight;
		init();
		if (check(weight, 0, 0)) cout << "Y" << endl;
		else cout << "N" << endl;
	}
}

void solution() {

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	input();
	solution();

	return 0;
}