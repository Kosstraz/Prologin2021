#include <iostream>
#include <vector>

std::vector<int> RemoveAt(std::vector<int> list, int index)
{
	std::vector<int> l = {};
	for (int i = 0; i < list.size(); i++)
	{
		if (i != index)
		{
			l.push_back(list[i]);
		}
	}

	return l;
}

std::vector<int> Sort(std::vector<int> list)
{
	int index = -1;
	int n = list.size();
	std::vector<int> l = {};
	for (int b = 0; b < n; b++)
	{
		index = -1;
		for (int i = 0; i < list.size(); i++)
		{
			if (index == -1)
			{
				index = i;
			}
			if (list[index] > list[i])
			{
				index = i;
			}
		}
		if (index > -1)
		{
			l.push_back(list[index]);
			list = RemoveAt(list, index);
		}
	}

	return l;
}

std::vector<std::vector<int>> RemoveVectorAt(std::vector<std::vector<int>> list, int index)
{
	std::vector<std::vector<int>> l = {};
	for (int i = 0; i < list.size(); i++)
	{
		if (i != index)
		{
			l.push_back({ list[i][0],  list[i][1] });
		}
	}

	return l;
}

std::vector<std::vector<int>> SortVector(std::vector<std::vector<int>> list)
{
	int index = -1;
	int indexindex = -1;
	int n = list.size();
	std::vector<std::vector<int>> l = {};
	for (int b = 0; b < n; b++)
	{
		index = -1;
		for (int i = 0; i < list.size(); i++)
		{
			if (index == -1)
			{
				index = i;
			}
			if ((list[index][0] > list[i][0] && list[index][1] < list[i][0]) && (list[index][0] > list[i][1] && list[index][1] < list[i][1]))
			{
				index = i;
			}
		}
		if (index > -1)
		{
			l.push_back({ list[index][0], list[index][1] });
			list = RemoveVectorAt(list, index);
		}
	}

	return l;
}

std::vector<std::vector<int>> SortDoubleVector(std::vector<std::vector<int>> list)
{
	int index = -1;
	int indexindex = -1;
	int n = list.size();
	std::vector<std::vector<int>> l = {};
	for (int b = 0; b < n; b++)
	{
		index = -1;
		for (int i = 0; i < list.size(); i++)
		{
			if (index == -1)
			{
				index = i;
			}
			if ((list[index][0] > list[i][0] && list[index][1] < list[i][0]) && (list[index][0] > list[i][1] && list[index][1] < list[i][1]))
			{
				index = i;
			}
		}
		if (index > -1)
		{
			l.push_back({ list[index][0], list[index][1], list[index][2] });
			list = RemoveVectorAt(list, index);
		}
	}

	return l;
}

int main()
{
		// initialisation des variables:
	int x, n;
	std::cin >> x;
	std::cin >> n;
	if (n < 2 || n > 10000)
	{
		std::cout << "ERROR::sizeof out of range" << std::endl;
		return 1;
	}

	int temp;
	int r;
	int sum = 0;
	int prod = 1;
	std::vector<int> l = {};
	std::vector<std::vector<int>> rl = {};
	for (int i = 0; i < n; i++)
	{
		std::cin >> std::ws >> temp;
		l.push_back(temp);
		sum += temp;
	}
	if (sum >= x)
	{
		std::cout << "IMPOSSIBLE" << std::endl;
		return 0;
	}

	// séparation et seconde somme:
		// si solo:
	for (int i = n - 1; i > -1; i--)
	{
		if (l[i] * sum == x)
		{
			r = l[i];
		}
	}
	for (int i = 0; i < l.size(); i++)
	{
		prod *= l[i];
	}
	if (prod == x)
	{
		std::vector<int> a = {};
		int sumA = 0;
		int sumL = 0;
		for (int i = 0; i < l.size(); i++)
		{
			if (i < l.size() / 2)
			{
				a.push_back(l[i]);
				sumA += l[i];
				l = RemoveAt(l, i);
			}
			else
			{
				sumL += l[i];
			}
		}
		if (sumA > abs(sum - sumA))
		{
			for (int i = 0; i < a.size(); i++)
			{
				std::cout << a[i];
				if (i != a.size() - 1)
				{
					std::cout << " ";
				}
			}
			std::cout << std::endl;
			for (int i = 0; i < l.size(); i++)
			{
				std::cout << l[i];
				if (i != n - 1)
				{
					std::cout << " ";
				}
			}
			return 0;
		}
		if (sumA <= abs(sum - sumA))
		{
			for (int i = 0; i < l.size(); i++)
			{
				std::cout << l[i];
				if (i != n - 1)
				{
					std::cout << " ";
				}
			}
			std::cout << std::endl;
			for (int i = 0; i < a.size(); i++)
			{
				std::cout << a[i];
				if (i != a.size() - 1)
				{
					std::cout << " ";
				}
			}
			return 0;
		}
	}

		// sinon:
	for (int i = n - 1; i > -1; i--)
	{
		for (int j = n - 1; j > -1; j--)
		{
			for (int g = n - 1; g > -1; g--)
			{
				r = l[i] + l[j] + l[g];
				if (r * sum == x)
				{
					rl.push_back({ l[i], l[j], l[g] });
				}
				else if ((r - l[g]) * sum == x)
				{
					rl.push_back({ l[i], l[j] });
				}
			}
		}
	}
	/*for (int i = n - 1; i > -1; i--)
	{
		for (int j = n - 1; j > -1; j--)
		{
			for (int g = n - 1; g > -1; g--)
			{
				r = l[i] + l[j] + l[g];
				if (r * sum == x)
				{
					rl.push_back({ l[i], l[j], l[g] });
					std::cout << rl[g][2];
				}
				else if ((r - l[g]) * sum == x)
				{
					rl.push_back({ l[i], l[j] });
				}
			}
		}
	}*/
		// Produit des sommes:
	/*for (int i = n - 1; i > -1; i--)
	{
		for (int j = n - 1; j > -1; j--)
		{
			r = l[i] + l[j];
			if (r * sum == x)
			{
				rl.push_back({ l[i], l[j] });
			}
			else
			{
				for (int g = j; g > -1; g--)
				{
					r += l[g];
					if (r * sum == x)
					{
						rl.push_back({ l[i], l[j], l[g] });
					}
				}
			}
		}
	}*/
	if (rl.empty())
	{
		std::cout << "IMPOSSIBLE" << std::endl;
		return 0;
	}
	// affichage:
	for (int i = 0; i < l.size(); i++)
	{
		l = Sort(l);
		std::cout << l[i];
		if (i != n - 1)
		{
			std::cout << " ";
		}
	}
	for (int i = 0; i < 1; i++)
	{
		if (rl[i].size() != 3)
		{
			rl = SortVector(rl);
			rl[i] = Sort(rl[i]);
			std::cout << std::endl << rl[i][0] << " " << rl[i][1];
		}
		if (rl[i].size() == 3)
		{
			rl[i] = Sort(rl[i]);
			std::cout << std::endl << rl[i][0] << " " << rl[i][1] << " " << rl[i][2];
		}
	}

	return 0;
}