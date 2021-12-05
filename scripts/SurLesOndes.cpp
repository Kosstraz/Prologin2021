#include <iostream>
#include <vector>

int main()
{
	int n, count, x = 1000;
	std::cin >> n;
	std::vector<int> freqs = {};
	
	if (n < 1 || n > 1000)
	{
		std::cout << "ERROR::value out of range" << std::endl;
		return 1;
	}
	for (int i = 0; i<n; i++)
	{
		std::cin >> count;
		freqs.push_back(count);
		if (x > freqs[i] && freqs[i]%3 == 0)
			x = freqs[i];
	}
	if(x == 1000)
	{
		std::cout << "ERROR::No multiples of 3 were found" << std::endl;
		return 1;
	}
	std::cout << x;
	return 0;
}