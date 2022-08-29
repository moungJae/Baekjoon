#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <string.h>

#define ll long long
#define INF 100000000
#define endl '\n'

using namespace std;

int N;
char num[12];

void input() {
	cin >> N;
}

bool is_descend() {
	int i = 0;

	if (!num[1] && num[0] == '9')
		return false;

	while (num[i + 1]) {
		if (num[i] < num[i + 1])
			i++;
		else
			return false;
	}
	return true;
}

int get_idx() {
	int i = 0;

	if (strlen(num) == 1)
		return 0;
	while (num[i + 1]) {
		if (num[i] < num[i + 1])
			i++;
		else break;
	}
	return i;
}

void show_num() {
	reverse(num, num + strlen(num));
	printf("%s\n", num);
}

void solution() {
	int idx;

	for (int i = 0; i <= 10; i++)
		num[i] = '\0';
	
	idx = 0;
	num[idx] = '0';
	while (strlen(num) <= 10) {
		idx = 0;
		while (is_descend()) {
			if ((N--) == 0) {
				show_num();
				exit(0);
			}
			num[idx] += 1;
		}
		if (!num[1]) {
			if ((N--) == 0) {
				show_num();
				exit(0);
			}
			num[0] = '0', num[1] = '1';
		}
		else {
			while (!is_descend()) {
				idx = get_idx();
				if (idx + 2 == strlen(num) && num[idx + 1] == '9') {
					for (int i = 0; i <= idx + 2; i++)
						num[i] = '0' + i;
					break;
				}
				num[idx + 1] += 1;
				num[idx] = '0';
			}
		}
	}

	cout << -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}