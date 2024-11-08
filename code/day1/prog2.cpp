// 2019 - N4

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	int h;
	for (int i = n - 1; i >= 0; --i)
	{
		if (a[i] == (n - i))
		{
			h = n - i;
			break;
		}
		else if (a[i] < (n - i))
		{
			h = n - i - 1;
			break;
		}
	}

	cout << h << "\n";

	return 0;
}