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

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	vector<pair<int, int>> v;
	map<int, int> m1, m2;
	for (int i = 0; i < 3; i++) {
		int x, y;
		cin >> x >> y;
		m1[x]++, m2[y]++;
		v.push_back({ x,y });
	}

	int x, y;
	for (int i = 0; i < 3; i++) {
		if (m1[v[i].first] == 1) x = v[i].first;
		if (m2[v[i].second] == 1) y = v[i].second;
	}
	cout << x << " " << y << endl;

	return 0;
}