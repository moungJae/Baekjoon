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

vector<pair<double, double>> v1, v2;
const double PI = 3.1415926535;

void input() {
	double x, y;
	
	v1.clear(), v2.clear();
	for (int i = 0; i < 3; i++) {
		cin >> x >> y;
		v1.push_back({ x, y });
		v2.push_back({ y, x });
	}
}

bool compare(pair<double, double> x, pair<double, double> y) {
	if (x.first == y.first) {
		return x.second > y.second;
	}
	return x.first < y.first;
}

double slope(pair<double, double> p1, pair<double, double> p2) {
	return (p2.second - p1.second) / (p2.first - p1.first);
}

double get_volume(pair<double, double> p1, pair<double, double> p2) {
	double a, b;

	a = slope(p1, p2);
	b = p1.second - a * p1.first;
	return PI * (pow(a, 2) * (pow(p2.first, 3) - pow(p1.first, 3)) / 3.0 
		+ a * b * (pow(p2.first, 2) - pow(p1.first, 2))
		+ pow(b, 2) * (p2.first - p1.first));
}

double volume(vector<pair<double, double>> v) {
	double ans = 0.0;

	// case 1
	if (v[0].second >= v[1].second && v[0].second >= v[2].second) {
		if (v[0].first == v[1].first) {
			ans = get_volume(v[0], v[2]) - get_volume(v[1], v[2]);
		}
		else if (v[1].first == v[2].first) {
			ans = get_volume(v[0], v[1]) - get_volume(v[0], v[2]);
		}
		else {
			if (slope(v[0], v[1]) < slope(v[1], v[2])) {
				ans = get_volume(v[0], v[2]) - (get_volume(v[0], v[1]) + get_volume(v[1], v[2]));
			}
			else {
				ans = (get_volume(v[0], v[1]) + get_volume(v[1], v[2])) - get_volume(v[0], v[2]);
			}
		}
	}
	// case 2
	else if (v[1].second >= v[0].second && v[1].second >= v[2].second) {
		if (v[1].first == v[2].first) {
			ans = get_volume(v[0], v[1]) - get_volume(v[0], v[2]);
		}
		else {
			ans = get_volume(v[0], v[1]) + get_volume(v[1], v[2]) - get_volume(v[0], v[2]);
		}
	}
	// case 3
	else if (v[2].second >= v[0].second && v[2].second >= v[1].second) {
		if (v[0].first == v[1].first) {
			ans = get_volume(v[0], v[2]) - get_volume(v[1], v[2]);
		}
		else {
			if (slope(v[0], v[1]) < slope(v[1], v[2])) {
				ans = get_volume(v[0], v[2]) - (get_volume(v[0], v[1]) + get_volume(v[1], v[2]));
			}
			else {
				ans = (get_volume(v[0], v[1]) + get_volume(v[1], v[2])) - get_volume(v[0], v[2]);
			}
		}
	}
	return ans;
}

void solution() {
	double ans1, ans2;

	sort(v1.begin(), v1.end(), compare);
	ans1 = volume(v1);
	sort(v2.begin(), v2.end(), compare);
	ans2 = volume(v2);

	printf("%.6f %.6f\n", ans1, ans2);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	input();
	solution();

	return 0;
}