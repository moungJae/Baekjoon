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

int N, K;
int arr[100001], imos[100001];

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];
}

void solution() {
	if (K == 1) {
		cout << *max_element(arr, arr + N);
	}
	else {
		int gap = 0, result = -INF, tmp = 0;
		for (int i = 0; i < N; i++) {
			tmp += arr[i];
			gap++;
			if (gap == K) {
				result = max(result, tmp);
				gap--;
				tmp -= arr[i - gap];
			}
		}
		cout << result;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}