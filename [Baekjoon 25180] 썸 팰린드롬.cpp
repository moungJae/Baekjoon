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

ll N;

void input() {
	cin >> N;
}

void solution() {
	int cnt = 0;

	if (N < 10) cout << 1;
	else {
		while (N) {
			if (N >= 18) {
				N -= 18;
				cnt += 2;
			}
			else if (N >= 10 && N < 18) {
				if (N % 2 == 0) cnt += 2;
				else cnt += 3;
				N = 0;
			}
			else {
				cnt += 1;
				N = 0;
			}
		}
		cout << cnt;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}