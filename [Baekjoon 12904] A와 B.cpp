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

string S, T;

void input() {
	cin >> S;
	cin >> T;
}

void solution() {
	while (S.size() != T.size()) {
		char c = T[T.size() - 1];
		
		T.pop_back();
		if (c == 'B') reverse(T.begin(), T.end());
	}
	cout << (S == T);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}