#include <iostream>
#include <string>
#include <vector>
#include <istream>

struct structpiece {
	int nCotesPiece;
	std::string couleurPiece;
};

int main()
{
	structpiece sPiece;
	std::string temp;
	std::vector<std::string> r = {};

	int nCouleurs;
	std::cin >> nCouleurs;
	if (nCouleurs <= 0)
	{
		std::cout << "ERROR::sizeof out of range" << std::endl;
		return 1;
	}
	std::vector<std::string> couleurs = {};
	for (int i = 0; i<nCouleurs; i++)
	{
		std::getline(std::cin >> std::ws, temp);
		if (temp.size() > 10)
		{
			std::cout << "ERROR::sizeof out of range" << std::endl;
			return 1;
		}
		couleurs.push_back(temp);
	}

	int nCotes;
	std::cin >> nCotes;
	if (nCotes <= 0)
	{
		std::cout << "ERROR::sizeof out of range" << std::endl;
		return 1;
	}
	std::vector<std::string> couleurscotes = {};
	for (int i = 0; i < nCotes; i++)
	{
		std::getline(std::cin >> std::ws, temp);
		couleurscotes.push_back(temp);
		int check = 0;
		for (int j = 0; j < nCouleurs; j++)
		{
			if (temp == couleurs[j])
			{
				check++;
			}
		}
		if (check == 0)
		{
			std::cout << "ERROR::color not disponible" << std::endl;
			return 1;
		}
	}

	int nPieces;
	std::cin >> nPieces;
	if (nPieces <= 0)
	{
		std::cout << "ERROR::sizeof out of range" << std::endl;
		return 1;
	}
	std::vector<structpiece> pieces = {};
	for (int i = 0; i < nPieces; i++)
	{
		std::cin >> sPiece.nCotesPiece;
		std::getline(std::cin >> std::ws, sPiece.couleurPiece);
		int check = 0;
		for (int j = 0; j < nCouleurs; j++)
		{
			if (sPiece.couleurPiece == couleurs[j])
			{
				check++;
			}
		}
		if (check == 0)
		{
			std::cout << "ERROR::color not disponible" << std::endl;
			return 1;
		}
		pieces.push_back(sPiece);
		check = 0;
		for (int j = 0; j < nCotes; j++)
		{
			if (sPiece.nCotesPiece == nCotes && sPiece.couleurPiece != couleurscotes[j])
			{
				check++;
			}
		}
		if (check == 0)
		{
			r.push_back("X");
		}
		else if(check == nCotes)
		{
			r.push_back("O");
		}
	}

	int check = 0;
	for (int i = 0; i < r.size(); i++)
	{
		std::cout << r[i];
		if (r[i] == "O")
		{
			check++;
		}
		if (i + 1 == r.size())
		{
			check;
		}
	}
	std::cout << std::endl << check << std::endl;

	return 0;
}