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

int N;
vector<pair<int, int>> v[100001];

void input()
{
	int p, q, w;
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> p >> q >> w;
		v[p].push_back({ q,w });
		v[q].push_back({ p,w });
	}
}

int max_go(int cur, int before, int* ans)
{
	int ret = 0;
	int max1 = 0, max2 = 0;
	int tmp;

	if (v[cur].size() == 1 && before == -1)
	{
		tmp = v[cur][0].second + max_go(v[cur][0].first, cur, ans);
		return max(tmp, *ans);
	}
	if (v[cur].size() == 1 && v[cur][0].first == before)
		return 0;

	for (int i = 0; i < v[cur].size(); i++)
	{
		int next = v[cur][i].first;
		int weight = v[cur][i].second;
		if (next == before)
			continue;
		ret = max(ret, (tmp = max_go(next, cur, ans) + weight));
		if (tmp > max1)
		{
			max2 = max1;
			max1 = tmp;
		}
		else if (tmp > max2)
			max2 = tmp;
	}

	*ans = max(*ans, max1 + max2);
	return ret;
}

int min_go(int cur, int before, int* ans)
{
	int ret = INF;
	int min1 = INF, min2 = INF;
	int tmp;

	if (v[cur].size() == 1 && before == -1)
	{
		tmp = v[cur][0].second + min_go(v[cur][0].first, cur, ans);
		return min(tmp, *ans);
	}
	if (v[cur].size() == 1 && v[cur][0].first == before)
		return 0;

	for (int i = 0; i < v[cur].size(); i++)
	{
		int next = v[cur][i].first;
		int weight = v[cur][i].second;
		if (next == before)
			continue;
		ret = min(ret, (tmp = min_go(next, cur, ans) + weight));
		if (tmp < min1)
		{
			min2 = min1;
			min1 = tmp;
		}
		else if (tmp < min2)
			min2 = tmp;
	}

	*ans = min(*ans, min1 + min2);
	return ret;
}

void solution()
{
	int x;
	for (int i = 0; i < N; i++)
	{
		if (v[i].size() == 1)
			x = i;
	}

	int ans = 0;
	cout << max_go(x, -1, &ans) << endl;

	ans = INF;
	cout << min_go(x, -1, &ans) << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}