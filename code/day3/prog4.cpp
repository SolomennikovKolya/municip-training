#include <iostream>
#include <vector>

using namespace std;

int main()
{
	long long n;
	cin >> n;

	if (n == 1)
	{
		cout << "1\n";
		return 0;
	}

	vector<int> nums;
	for (int num = 9; num >= 2; --num)
	{
		while (n % num == 0)
		{
			nums.push_back(num);
			n /= num;
		}
	}

	if (n > 1)
	{
		cout << "-1";
		return 0;
	}

	for (int i = nums.size() - 1; i >= 0; --i)
	{
		cout << nums[i];
	}
	cout << "\n";

	return 0;
}