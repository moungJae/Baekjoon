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
int arr[5001];

void input() {
	cin >> N;
}

void solution() {
	int gap;

	gap = N / 2;
	if (N % 2) {
		for (int x = gap + 1; x > 1; x--) {
			cout << x << " " << x + gap << " ";
		}
		cout << 1;
	}
	else {
		for (int x = gap; x >= 1; x--) {
			cout << x << " " << x + gap << " ";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}