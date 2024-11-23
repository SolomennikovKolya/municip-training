#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct point
{
	int x, y;
} point;

typedef struct
{
	int h0;
	int w0;
	int x0_num;
	int x0_den;
} point_data;

int nod(int a, int b)
{
	if (a < 0)
		return nod(-a, b);
	if (b < 0)
		return nod(a, -b);
	if (a == 0)
		return b;
	if (b == 0)
		return a;

	if (a > b)
		return nod(b, a % b);
	else
		return nod(b % a, b);
}

bool comp_data(point_data &d1, point_data &d2)
{
	return d1.h0 == d2.h0 && d1.w0 == d2.w0 && d1.x0_den == d2.x0_den && d1.x0_num == d2.x0_num;
}

bool comp(const point_data &d1, const point_data &d2)
{
	if (d1.h0 != d2.h0)
		return d1.h0 < d2.h0;
	if (d1.w0 != d2.w0)
		return d1.w0 < d2.w0;
	if (d1.x0_num != d2.x0_num)
		return d1.x0_num < d2.x0_num;
	if (d1.x0_den != d2.x0_den)
		return d1.x0_den < d2.x0_den;

	return false;
}

int main()
{
	int n;
	cin >> n;
	vector<point> a(n);
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		point p{x, y};
		a[i] = p;
	}

	vector<point_data> b;
	for (auto p1 : a)
	{
		for (auto p2 : a)
		{
			int x1 = p1.x;
			int y1 = p1.y;
			int x2 = p2.x;
			int y2 = p2.y;
			if (x1 > x2)
			{
				x1 = p2.x;
				y1 = p2.y;
				x2 = p1.x;
				y2 = p1.y;
			}
			// printf("(%d, %d) (%d, %d)\n", x1, y1, x2, y2);

			if (x1 == x2 && y1 == y2)
				continue;

			int w = x2 - x1;
			int h = y2 - y1;
			int nod_wh = nod(w, h);
			// cout << "nod_wh: " << nod_wh << "\n";
			// cout << "w: " << w << " h: " << h << "\n";

			point_data data;
			data.h0 = h / nod_wh;
			data.w0 = w / nod_wh;

			if (y1 == y2)
			{
				data.x0_num = y1;
				data.x0_den = 0;
			}
			else
			{
				int num = x1 * (y2 - y1) - y1 * (x2 - x1);
				int den = y2 - y1;
				int nod_num_den = nod(num, den);
				// cout << "nod_num_den: " << nod_num_den << "\n";

				data.x0_num = num / nod_num_den;
				data.x0_den = den / nod_num_den;
			}

			b.push_back(data);
		}
	}

	sort(b.begin(), b.end(), comp);

	int max_points = 1;

	int cur_points = 1;
	point_data cur_data = b[0];

	for (int i = 1; i < b.size(); ++i)
	{
		if (comp_data(b[i], cur_data))
		{
			cur_points++;
			if (cur_points > max_points)
			{
				max_points = cur_points;
			}
		}
		else
		{
			cur_points = 1;
			cur_data = b[i];
		}
	}

	cout << max_points << "\n";

	return 0;
}