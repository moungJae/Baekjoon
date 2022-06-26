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

ll A, B;

void input() {
	cin >> A >> B;
}

ll even_f(ll x, ll gap) {
	if (gap % 4 == 0)
		return x;
	else if (gap % 4 == 1)
		return 1;
	else if (gap % 4 == 2)
		return x + 1;
	return 0;
}

ll odd_f(ll x, ll y, ll gap) {
	if (gap % 4 == 0)
		return x;
	else if (gap % 4 == 1)
		return x ^ y;
	else if (gap % 4 == 2)
		return x - 1;
	return (x - 1) ^ y;
}

void solution() {
	if (A % 2 == 0)
		cout << even_f(B, B - A);
	else
		cout << odd_f(A, B, B - A);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}