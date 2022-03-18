#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int N, M, how;
vector<string> info, v[1001], child[1001], zzang;
int inDegree[1001];
map<string, int> m;

void input()
{
	string cur, parent;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> cur;
		m[cur] = how++;
		info.push_back(cur);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> cur >> parent;
		v[m[parent]].push_back(cur);
		inDegree[m[cur]]++;
	}
}

void solution()
{
	queue<string> Q;

	sort(info.begin(), info.end());
	for (string s : info)
	{
		if (!inDegree[m[s]])
			Q.push(s), zzang.push_back(s);
	}
	while (!Q.empty())
	{
		string parent = Q.front();
		Q.pop();
		for (string cur : v[m[parent]])
		{
			if (--inDegree[m[cur]] == 0)
			{
				child[m[parent]].push_back(cur);
				Q.push(cur);
			}
		}
	}
	cout << zzang.size() << endl;
	for (string s : zzang) cout << s << " ";
	cout << endl;
	for (string s : info)
	{
		cout << s << " " << child[m[s]].size() << " ";
		sort(child[m[s]].begin(), child[m[s]].end());
		for (string s_c : child[m[s]])
			cout << s_c << " ";
		cout << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}