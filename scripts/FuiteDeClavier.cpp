#include <iostream>
#include <string>
#include <vector>

struct Alphabet {
	std::vector<std::string> character = {
		"abcdefghijklmnopqrstuvwxyz",
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
		"\"!#$%&'()*+,-./:;<=>?@[]^_`{|}~\\",
		"0123456789"
	};
	bool maj = false;
	bool min = false;
	bool spe = false;
	bool num = false;
};

int main()
{
	Alphabet st;

	int n, k, index = 0;
	std::cin >> n;
	if (n > 1000000)
	{
		std::cout << "ERROR:sizeof out of range" << std::endl;
		return 1;
	}
	std::cin >> k;
	if (k < 4 || k > 10000)
	{
		std::cout << "ERROR:sizeof out of range" << std::endl;
		return 1;
	}

	std::vector<std::string> chaine = {};			//G=d:Dl:T=9NS1c$9qC%,^EdUVLnU-7
	std::string temp;								//G=d:Dl:T\9NS1c"9qC%,^EdUVLnU-7
	std::cin >> temp;
	chaine.push_back(temp);
	if (chaine[0].size() != n)
	{
		std::cout << "ERROR:sizeof out of range" << std::endl;
		return 1;
	}

	std::vector<std::string> test(chaine[0].size() - k + 1);
	for (int i = k; i < chaine[0].size()+1; i++)
	{
		for (int j = index; j < i; j++)
		{
			test[index].push_back(chaine[0][j]);
		}
		if (i == index + k)
		{
			index++;
		}
	}
	index = 0;
	for (int i = 0; i < test.size(); i++)
	{
		st.maj = false; st.min = false; st.spe = false; st.num = false;
		for (int j = 0; j < test[i].size(); j++)
		{
			for (int g = 0; g < st.character[0].size(); g++)
			{
				if (test[i][j] == st.character[0][g])
				{
					st.min = true;
				}
				if (test[i][j] == st.character[1][g])
				{
					st.maj = true;
				}
			}
			for (int g = 0; g < st.character[2].size(); g++)
			{
				if (test[i][j] == st.character[2][g])
				{
					st.spe = true;
				}
			}
			for (int g = 0; g < st.character[3].size(); g++)
			{
				if (test[i][j] == st.character[3][g])
				{
					st.num = true;
				}
			}
		}
		if (st.spe && st.min && st.maj && st.num)
		{
			index++;
		}
	}
	std::cout << index << std::endl;
	

	return 0;
}