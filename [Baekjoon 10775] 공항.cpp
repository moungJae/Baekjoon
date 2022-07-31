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
#include <time.h>
#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;

int G;
int P;
int g[100001];
int parent[100001];
int END = 0;

void input() {
	cin >> G;
	cin >> P;
	for (int i = 1; i <= P; i++)
		cin >> g[i];
}

int get_parent(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = get_parent(parent[x]);
}

void go_union(int x, int y) {
	x = get_parent(x);
	y = get_parent(y);
	
	if (x > y) parent[x] = y;
	else parent[y] = x;
}

void solution() {
	int cnt = 0;
	int p;

	for (int i = 1; i <= G; i++)
		parent[i] = i;
	for (int i = 1; i <= P; i++) {
		if ((p = get_parent(g[i])) != END) {
			go_union(p - 1, p);
			cnt++;
		}
		else break;
	}

	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	input();
	solution();

	return 0;
}