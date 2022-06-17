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

int T;
double cm[201], kg[201];

void input() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> cm[i] >> kg[i];
	}
}

double getBMI(double CM, double KG) {
	return KG / ((CM / 100.0) * (CM / 100.0));
}

void solution() {
	double BMI;

	for (int i = 0; i < T; i++) {
		if (cm[i] < 140.1) {
			cout << 6 << endl;
		}
		else if (cm[i] >= 140.1 && cm[i] < 146.0){
			cout << 5 << endl;
		}
		else if (cm[i] >= 146.0 && cm[i] < 159.0) {
			cout << 4 << endl;
		}
		else if (cm[i] >= 159.0 && cm[i] < 161.0) {
			BMI = getBMI(cm[i], kg[i]);
			if (BMI >= 16.0 && BMI < 35.0)
				cout << 3 << endl;
			else
				cout << 4 << endl;
		}
		else if (cm[i] >= 161.0 && cm[i] < 204.0) {
			BMI = getBMI(cm[i], kg[i]);
			if (BMI >= 20.0 && BMI < 25.0)
				cout << 1 << endl;
			else if ((BMI >= 18.5 && BMI < 20.0) || (BMI >= 25.0 && BMI < 30.0))
				cout << 2 << endl;
			else if ((BMI >= 16.0 && BMI < 18.5) || (BMI >= 30.0 && BMI < 35.0))
				cout << 3 << endl;
			else
				cout << 4 << endl;
		}
		else {
			cout << 4 << endl;
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