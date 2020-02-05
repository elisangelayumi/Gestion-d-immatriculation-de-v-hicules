/**
 * \file validationFormat.cpp
 * \brief Implementation du module qui permet de valider le numero de serie du Vehicule et le format de l'immatriculation
 * \author Elisangela Yumi
 * \version 0.1
 * \date: 2019-09-19
 */

#include <iostream>
#include <string.h>
#include <ctype.h>
#include <sstream>
#include <vector>
#include <map>
#include <numeric>
#include "validationFormat.h"

using namespace std;

namespace util
{


/**
 * \brief permet de valider une plaque en fonction de son type
 * \param[in] p_immatriculation est une string qui represente la plaque a valider
 * \return un booleen qui indique si la plaque est valide ou non
 */
bool validationImmatriculationPromenade (const std::string& p_immatriculation)
{
	bool estValide = true;

	if (p_immatriculation.size() == 4)
	{
		estValide = validerPlaqueSpeciaux(p_immatriculation);
	}
	else
	{
		if (p_immatriculation.size() == 7)
		{
			estValide = validerPlaqueSansPrefixe(p_immatriculation);
		}
		else
		{
			estValide = false;
		}
	}
	return estValide;
}

/**
 * \brief permet de valider la plaque du type SAAQ
 * \param[in] p_immatriculation est une string qui represente la plaque a valider
 * \return un booleen qui indique si la plaque est valide ou non
 */
bool validerPlaqueSpeciaux (const std::string& p_immatriculation)
{
	bool estValide = true;

	for (int i = 0; i < 4; i++)
	{
		char monCaractere = p_immatriculation[i];
		if (isdigit(monCaractere) || islower(monCaractere) || monCaractere == 'O')
		{
			estValide = false;
			return estValide;
		}
	}
	return estValide;
}

/**
 * \brief permet de valider les plaques sans prefixe ainsi que les plaques L
 * \param[in] p_immatriculation est une string qui represente la plaque a valider
 * \return un booléen qui indique si la plaque est valide ou non
 */
bool validerPlaqueSansPrefixe (const std::string& p_immatriculation)
{
	bool estValide = true;
	if (verifierSiContientEspace(p_immatriculation))
	{
		estValide = validerPlaqueQueContientEspace(p_immatriculation);
	}
	else
	{
		estValide = validerPlaqueSansEspace(p_immatriculation);
	}

	return estValide;
}

/**
 * \brief permet de decider s'il y a des espace dans la plaque ou pas
 * \param[in] p_immatriculation est une string qui represente la plaque a verifier si contient d'espace
 * \return un booleen qui indique si la plaque possede d'espace ou non
 */
bool verifierSiContientEspace (const std::string& p_immatriculation)
{
	bool contientEspace = false;
	for (int i = 0; i < 7; i++)
	{
		char monCaractere = p_immatriculation[i];
		if (isspace(monCaractere))
		{
			contientEspace = true;
			break;
		}
	}
	return contientEspace;
}

/**
 * \brief permet de valider les plaques qu'ont de l'espace. Types valides: 000_ABC | ABC_000 | A00_ABC
 * \param[in] p_immatriculation est une string qui represente la plaque a valider
 * \return un booleen qui indique si la plaque est valide ou non
 */
bool validerPlaqueQueContientEspace(const std::string& p_immatriculation)
{
	bool estValide = true;
	for (int i = 0; i < 7; i++)
		{
			char monCaractere = p_immatriculation[i];
			if (islower(monCaractere) || monCaractere == 'O')
			{
				estValide = false;
				return estValide;
			}
		}

	if (isdigit(p_immatriculation[0]) && isdigit(p_immatriculation[1]) && isdigit(p_immatriculation[2]))
	{
		if (isalpha(p_immatriculation[4]) && isalpha(p_immatriculation[5]) && isalpha(p_immatriculation[6]))
		{
			estValide = true;
		}
		else
		{
			estValide = false;
		}
	}
	else if (isalpha(p_immatriculation[0]) && isalpha(p_immatriculation[1]) && isalpha(p_immatriculation[2]))
	{
		 if (isdigit(p_immatriculation[4]) && isdigit(p_immatriculation[5]) && isdigit(p_immatriculation[6]))
		{
			estValide = true;
		}
		 else
		{
			estValide = false;
		}
	}
	else if (isalpha(p_immatriculation[0]) && isdigit(p_immatriculation[1]) && isdigit(p_immatriculation[2]))
	{
		if (isalpha(p_immatriculation[4]) && isalpha(p_immatriculation[5]) && isalpha(p_immatriculation[6]))
		{
			estValide = true;
		}
		else
		{
			estValide = false;
		}
	}
	else
	{
		estValide = false;
	}
	return estValide;
}

/**
 * \brief permet de valider les plaques que n'ont pas d'espace. Type valide: 000H000
 * \param[in] p_immatriculation est une string qui represente la plaque a valider
 * \return un booleen qui indique si la plaque est valide ou non
 */
bool validerPlaqueSansEspace(const std::string& p_immatriculation)
{
	bool statusBool = true;

	if (isalpha(p_immatriculation[3]) && isupper(p_immatriculation[3]) && p_immatriculation[3] != 'O')
	{
		istringstream iss(p_immatriculation);

		string maPlaqueString;
		iss >> maPlaqueString;
		maPlaqueString.erase(3,1);

		for (unsigned int i = 0; i < maPlaqueString.size(); i++)
		{
			if (isalpha(maPlaqueString[i]))
			{
				statusBool = false;
				break;
			}
		}
	}

	else
	{
		statusBool = false;
	}

	return statusBool;
}


/**
 * \brief permet de valider une plaque d'un camion
 * \param[in] p_immatriculation est une string qui represente la plaque a valider
 * \return un booleen qui indique si la plaque est valide ou non
 */

bool validationImmatriculationCamion (const std::string& p_immatriculation)
{
	bool estValide = true;

	if (p_immatriculation.size() == 7)
	{
		estValide = validerPlaqueL(p_immatriculation);
	}
	else
	{
		estValide = false;
	}

	return estValide;
}

/**
 * \brief permet de verifier si la plaque est dans le bon format: L000000 - sans espace avec un L majuscule au debut
 * \param[in] p_immatriculation est une string qui represente la plaque a valider
 * \return un booleen qui indique si la plaque est dans le bon format ou non
 */
bool validerPlaqueL (const std::string& p_immatriculation)
{
	bool statusBool = true;

	if (p_immatriculation[0] == 'L')
	{

		for (int i = 0; i < 7; i++)
		{
			char monCaractere = p_immatriculation[i];
			if (isspace(monCaractere))
			{
				return statusBool = false;
			}
		}

		istringstream iss(p_immatriculation);

		string maPlaqueString;
		iss >> maPlaqueString;
		maPlaqueString.erase(0,1);

		for (unsigned int i = 0; i < maPlaqueString.size(); i++)
		{
			if (isalpha(maPlaqueString[i]))
			{
				return statusBool = false;
			}
		}
	}
	else
	{
		return statusBool = false;
	}

	return statusBool;
}


/**
 * \brief permet de valider le NIV (Vehicle Identification Number)
 * \param[in] p_niv est une string qui represente le NIV a valider
 * \return un booleen qui indique si le NIV est valide ou non
 */
bool validerNiv (const std::string& p_niv)
{
	bool nivEstValide = true;

	if (p_niv.size() != 17)
	{
		nivEstValide = false;
		return nivEstValide;
	}
	else
	{
		nivEstValide = calculerNiv(p_niv);
	}
	return nivEstValide;
}

/**
 * \brief Fait le calcul necessaire pour valider le NIV (Vehicle Identification Number)
 * \param[in] p_niv est une string qui represente le NIV a valider
 * \return un booleen qui indique si le NIV est valide ou non
 */
bool calculerNiv(const std::string& p_niv)
{
	bool nivEstValide = true;
	vector<char> monCharNiv;
	vector<char>::iterator it_monCharNiv;

	for (unsigned int i = 0; i < p_niv.size(); i++)
	{
		it_monCharNiv = monCharNiv.begin() + i;
		monCharNiv.insert(it_monCharNiv, toupper(p_niv[i]));
	}

	/** on passe pour tous les elements du 1er vecteur en remplacent les lettres
	 * par sa valeur correspondante. Et au meme temps on le multiplie pour son "poids" et
	 *  sauvegarde ces produits la dans un 2eme vecteur.*/

	vector<char> mesProductsNiv;
	vector<char>::iterator it_mesProductsNiv;

	for (unsigned int i = 0; i < monCharNiv.size(); i++)
	{
		it_mesProductsNiv = mesProductsNiv.begin() + i;
		if (isalnum(monCharNiv[i]))
		{
			if (isdigit(monCharNiv[i]))
			{
				int valeurConvertieNiv = (monCharNiv[i] - '0');
				int monPoidsNiv = poidsPositionNiv(i);
				int productNiv = valeurConvertieNiv * monPoidsNiv;
				mesProductsNiv.insert(it_mesProductsNiv, productNiv);
			}
			else
			{
				int valeurConvertieNiv = valeursPossiblesNiv(monCharNiv[i]);
				int monPoidsNiv = poidsPositionNiv(i);
				int productNiv = valeurConvertieNiv * monPoidsNiv;
				mesProductsNiv.insert(it_mesProductsNiv, productNiv);
			}
		}
		else
		{
			return false;
		}
	}

	int sommeProducts = accumulate(mesProductsNiv.begin(), mesProductsNiv.end(), 0);
	int checkDigit = sommeProducts % 11;

	if (checkDigit < 10)
	{
		if (checkDigit == monCharNiv[8] - '0')
		{
			nivEstValide = true;
		}

		else
		{
			nivEstValide = false;
		}

	}

	if (checkDigit == 10)
	{
		if (monCharNiv[8] == 'X')
		{
			nivEstValide = true;
		}
		else
		{
			nivEstValide = false;
		}
	}

	return nivEstValide;
}

/**
 * \brief map qui fonctionne comme un 'dictionaire'. Permet de retourner la valeur d'une "cle"
 * \param[in] p_monCharNiv est un char qui represente la cle dont on veut savoir sa valeur correspondante
 * \return  un entier qui represente la valeur correspondante au char recu comme cle
 */
int valeursPossiblesNiv(char p_monCharNiv)
{
	map<char,int> valeursNiv;

	valeursNiv['A']=1;
	valeursNiv['B']=2;
	valeursNiv['C']=3;
	valeursNiv['D']=4;
	valeursNiv['E']=5;
	valeursNiv['F']=6;
	valeursNiv['G']=7;
	valeursNiv['H']=8;
	valeursNiv['J']=1;
	valeursNiv['K']=2;
	valeursNiv['L']=3;
	valeursNiv['M']=4;
	valeursNiv['N']=5;
	valeursNiv['P']=7;
	valeursNiv['R']=9;
	valeursNiv['S']=2;
	valeursNiv['T']=3;
	valeursNiv['U']=4;
	valeursNiv['V']=5;
	valeursNiv['W']=6;
	valeursNiv['X']=7;
	valeursNiv['Y']=8;
	valeursNiv['Z']=9;

	int laValeurNiv = valeursNiv[p_monCharNiv];

	return laValeurNiv;
}

/**
 *\brief map qui permet de retourner le poids par rapport a une position dans la string
 *\param[in] p_position est un entier qui represente la position que le caractere qu'on veut occupe dans le vector "monCharNiv"
 *\return un entier qui represente la valeur correspondante au char recu comme cle la valeur du poids de la position recu comme cle
 */
int poidsPositionNiv(int p_position)
{

	map<char,int> poidsNiv;

	poidsNiv[0]=8; // La position 0 a comme poids attribue la valeur 8
	poidsNiv[1]=7;
	poidsNiv[2]=6;
	poidsNiv[3]=5;
	poidsNiv[4]=4;
	poidsNiv[5]=3;
	poidsNiv[6]=2;
	poidsNiv[7]=10;
	poidsNiv[8]=0;
	poidsNiv[9]=9;
	poidsNiv[10]=8;
	poidsNiv[11]=7;
	poidsNiv[12]=6;
	poidsNiv[13]=5;
	poidsNiv[14]=4;
	poidsNiv[15]=3;
	poidsNiv[16]=2;

	int lePoidsNiv = poidsNiv[p_position]; //on recupere la valeur de la position recu.

	return lePoidsNiv;
}

}// namespace util
