#include <iostream>
#include <vector>

using namespace std;

const int MAX_COORD = 1000;

typedef struct point
{
	int x, y;
} point;

void find_max_s(vector<point> &A)
{
	vector<vector<int>> B(MAX_COORD * 2, vector<int>(MAX_COORD * 2, 0));
	for (auto p : A)
	{
		B[MAX_COORD + p.y][MAX_COORD + p.x] = 1;
	}

	int max_s = 0;
	int ans_x1, ans_x2, ans_x3, ans_x4;
	int ans_y1, ans_y2, ans_y3, ans_y4;
	for (auto p1 : A)
	{
		for (auto p2 : A)
		{
			if (p1.x == p2.x || p1.y == p2.y)
				continue;
			if (B[MAX_COORD + p1.y][MAX_COORD + p2.x] && B[MAX_COORD + p2.y][MAX_COORD + p1.x])
			{
				int s = abs(p1.x - p2.x) * abs(p1.y - p2.y);
				if (s > max_s)
				{
					max_s = s;

					ans_x1 = p1.x;
					ans_y1 = p1.y;

					ans_x2 = p2.x;
					ans_y2 = p2.y;

					ans_x3 = p2.x;
					ans_y3 = p1.y;

					ans_x4 = p1.x;
					ans_y4 = p2.y;
				}
			}
		}
	}
	cout << ans_x1 << " " << ans_y1 << "\n";
	cout << ans_x2 << " " << ans_y2 << "\n";
	cout << ans_x3 << " " << ans_y3 << "\n";
	cout << ans_x4 << " " << ans_y4 << "\n";
}

int main()
{
	int param_a, param_b, param_c;
	cin >> param_a >> param_b >> param_c;

	int n;
	cin >> n;

	vector<point> A;
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		point p{x, y};
		A.push_back(p);
	}

	vector<point> A1, A2;
	for (auto p : A)
	{
		int z = param_a * p.x + param_b * p.y + param_c;
		if (z > 0)
			A1.push_back(p);
		else
			A2.push_back(p);
	}

	find_max_s(A1);
	find_max_s(A2);

	return 0;
}