#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <math.h>
#include <string>
#include <map>

#define ll long long

using namespace std;

int N;
vector<int> v[11];
int people[11];
bool visited[11], check[11];

void input()
{
	int how, cur, next;

	cin >> N;
	for (cur = 1; cur <= N; cur++)
		cin >> people[cur];
	for (cur = 1; cur <= N; cur++)
	{
		cin >> how;
		for (int i = 0; i < how; i++)
		{
			cin >> next;
			v[cur].push_back(next);
			v[next].push_back(cur);
		}
	}
}

int red_true(int how)
{
	queue<int> Q;
	int red, blue;
	int red_cnt, blue_cnt, red_people, blue_people;

	for (int i = 1; i <= N; i++)
	{
		if (!visited[i]) blue = i;
		else red = i;
		check[i] = false;
	}
	red_people = people[red], red_cnt = 1, check[red] = true;
	Q.push(red);
	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		for (int next : v[x])
		{
			if (visited[next] && !check[next])
			{
				check[next] = true;
				red_people += people[next];
				red_cnt++;
				Q.push(next);
			}
		}
	}
	blue_people = people[blue], blue_cnt = 1, check[blue] = true;
	Q.push(blue);
	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		for (int next : v[x])
		{
			if (!visited[next] && !check[next])
			{
				check[next] = true;
				blue_people += people[next];
				blue_cnt++;
				Q.push(next);
			}
		}
	}
	if (red_cnt + blue_cnt == N)
		return abs(red_people - blue_people);
	return 1e9;
}

int blue_true(int how)
{
	queue<int> Q;
	int red, blue;
	int red_cnt, blue_cnt, red_people, blue_people;

	for (int i = 1; i <= N; i++)
	{
		if (visited[i]) blue = i;
		else red = i;
		check[i] = false;
	}
	red_people = people[red], red_cnt = 1, check[red] = true;
	Q.push(red);
	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		for (int next : v[x])
		{
			if (!visited[next] && !check[next])
			{
				check[next] = true;
				red_people += people[next];
				red_cnt++;
				Q.push(next);
			}
		}
	}
	blue_people = people[blue], blue_cnt = 1, check[blue] = true;
	Q.push(blue);
	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();
		for (int next : v[x])
		{
			if (visited[next] && !check[next])
			{
				check[next] = true;
				blue_people += people[next];
				blue_cnt++;
				Q.push(next);
			}
		}
	}
	if (red_cnt + blue_cnt == N)
		return abs(red_people - blue_people);
	return 1e9;
}

int diff(int how)
{
	return min(red_true(how), blue_true(how));
}

int dfs(int n, int how)
{
	int ret = 1e9;

	if (n == how)
		return diff(n);
	for (int i = 1; i <= N; i++)
	{
		if (visited[i]) continue;
		visited[i] = true;
		ret = min(ret, dfs(n + 1, how));
		visited[i] = false;
	}
	return ret;
}

void solution()
{
	int result = 1e9;
	for (int i = 1; i <= N / 2; i++)
	{
		result = min(result, dfs(0, i));
	}
	cout << (result == 1e9 ? -1 : result);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}