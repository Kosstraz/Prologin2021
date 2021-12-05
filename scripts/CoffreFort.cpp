#include <iostream>
#include <vector>

struct Fil {
	int puce1;
	int puce2;
};

struct Question {
	int puce_a;
	int puce_b;
};

//void CalculerSignaux(int n, int m, int r, const std::vector<int>& signaux, const std::vector<Fil>& fils, const std::vector<Question>& questions)
//{
	
//}

int main()
{
		// Structures:
	Fil fil;
	Question question;

		// initialisations:
	int n, m, r;
	int temp;
	std::vector<int> signaux = {};
	std::vector<Fil> fils = {};
	std::vector<Question> questions = {};

	std::cin >> n;
	std::cin >> m;
	if (m != n - 1)
	{
		std::cout << "ERROR::sizeof out of range" << std::endl;
		return 1;
	}
	std::cin >> r;
	if (n < 1 || n > 100000 || m != n - 1 || r < 0 || r > 100000)
	{
		std::cout << "ERROR::sizeof out of range" << std::endl;
		return 1;
	}

		// ajout des signaux:
	for (int i = 0; i < n; i++)
	{
		std::cin >> std::ws >> temp;
		signaux.push_back(temp);
		if (temp < 0 || temp > 1671404011)
		{
			std::cout << "ERROR::sizeof out of range" << std::endl;
			return 1;
		}
	}
		// récupération des fils et des questions:
	for (int i = 0; i < m; i++)
	{
		std::cin >> fil.puce1 >> fil.puce2;
		fils.push_back(fil);
		if (fil.puce1 < 0 || fil.puce1 >= n || fil.puce2 < 0 || fil.puce2 >= n)
		{
			std::cout << "ERROR::sizeof out of range" << std::endl;
			return 1;
		}
	}

	for (int i = 0; i < r; i++)
	{
		std::cin >> question.puce_a >> question.puce_b;
		questions.push_back(question);
		if (question.puce_a < 0 || question.puce_a >= n || question.puce_b < 0 || question.puce_b >= n)
		{
			std::cout << "ERROR::sizeof out of range" << std::endl;
			return 1;
		}
	}
	
		// lancement du "décryptage":
	//CalculerSignaux(n, m, r, signaux, fils, questions);


	return 0;
}