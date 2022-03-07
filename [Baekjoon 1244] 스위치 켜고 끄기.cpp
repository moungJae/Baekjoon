#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <math.h>

#define ll long long

using namespace std;

int N, S;
int swi[101];
int stu[101][2];

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> swi[i];
	cin >> S;
	for (int i = 1; i <= S; i++)
		cin >> stu[i][0] >> stu[i][1];
}

void solution()
{
	int left, right, k;

	for (int i = 1; i <= S; i++)
	{
		if (stu[i][0] == 1)
		{
			k = stu[i][1];
			for (int j = k; j <= N; j += k)
				swi[j] = (swi[j] == 1 ? 0 : 1);
		}
		else if (stu[i][0] == 2)
		{
			left = right = stu[i][1];
			while (left >= 1 && right <= N)
			{
				if (swi[left] != swi[right])
					break;
				left--, right++;
			}
			for (int j = left + 1; j < right; j++)
				swi[j] = (swi[j] == 1 ? 0 : 1);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		cout << swi[i] << " ";
		if (i % 20 == 0) cout << endl;
	}
}

int main()
{
	input();
	solution();

	return 0;
}