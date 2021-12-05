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
	for(int b = 0; b < n; b++)
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
	
		// ajout des valeurs + somme la 1ère ligne:
	int temp;
	int sum = 0;
	int prod = 1;
	int r = 0;
	std::vector<int> l = {};
	std::vector<std::vector<int>> rList = {};
	for (int i = 0; i < n; i++)
	{
		std::cin >> std::ws >> temp;
		l.push_back(temp);
		sum += temp;
		if (temp > x)
		{
			/*l = Sort(l);
			for (int i = 0; i < l.size(); i++)
			{
				std::cout << l[i];
				if (i != n - 1)
				{
					std::cout << " ";
				}
			}*/
			std::cout << "IMPOSSIBLE" << std::endl;
			return 0;
		}
	}
	if (sum > x)
	{
		std::cout << "IMPOSSIBLE" << std::endl;
		return 0;
	}
	for (int i = 0; i < l.size(); i++)
	{
		if (sum == x && l[i] == 1)
		{
			rList.push_back({ l[i] });
			l = Sort(l);
			for (int i = 0; i < l.size(); i++)
			{
				std::cout << l[i];
				if (i != n - 1)
				{
					std::cout << " ";
				}
			}
			std::cout << std::endl << rList[0][0];
			return 0;
		}
		if (i == l.size())
		{
			std::cout << "IMPOSSIBLE" << std::endl;
			return 0;
		}
	}

		// séparation et seconde somme:
			// si solo:
	for (int i = n-1; i > -1; i--)
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
		if(sumA > abs(sum-sumA))
		{
			for (int i = 0; i < a.size(); i++)
			{
				std::cout << a[i];
				if (i != a.size() -1)
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
			r = l[i] + l[j];
			if (r * sum == x)
			{
				rList.push_back({ l[i], l[j] });
			}
		}
	}
	if (rList.empty())
	{
		std::cout << "IMPOSSIBLE" << std::endl;
		return 0;
	}
			// affichage:
	for (int i = 0; i < l.size(); i++)
	{
		//l = Sort(l);
		std::cout << l[i];
		if (i != n - 1)
		{
			std::cout << " ";
		}
	}
	for (int i = 0; i < 1; i++)
	{
		rList = SortVector(rList);
		rList[0] = Sort(rList[0]);
		std::cout << std::endl << rList[i][0] << " " << rList[i][1];
	}

	return 0;
}