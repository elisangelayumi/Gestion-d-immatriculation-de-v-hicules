/**
 * \file Proprietaire.cpp
 * \brief  Implementation de la classe Proprietaire
 * \author Elisangela Yumi
 * \version 0.1
 * \date: 2019-11-21
 */

#include "Proprietaire.h"
#include "VehiculeException.h"
#include <sstream>
#include <iomanip>

using namespace std;

namespace saaq {

/**
 * \brief Constructeur avec parametres
 * \param[in] p_nom Le nom du proprietaire;
 * \param[in] p_prenom Le prenom du proprietaire;
 * \pre p_nom est une string pas vide;
 * \pre p_prenom est une string pas vide;
 * \pos m_nom prends la valeur de p_nom;
 * \pos m_prenom prends la valeur de p_prenom;
 * \return Un objet Proprietaire
 */
Proprietaire::Proprietaire(const std::string& p_nom, const std::string& p_prenom) :
	m_nom(p_nom), m_prenom(p_prenom)
{
	PRECONDITION(!p_nom.empty());
	PRECONDITION(!p_prenom.empty());

	POSTCONDITION(m_nom == p_nom);
	POSTCONDITION(m_prenom == p_prenom);

	INVARIANTS();
}


/**
 * \brief Destructeur de la classe Proprietaire qui va s'occuper de vider la liste et de liberer la memoire
 */
Proprietaire::~Proprietaire()
{

	for (std::vector<Vehicule*> ::iterator iter = m_vVehicules.begin(); iter != this->m_vVehicules.end(); iter++)
	{
		delete *iter;
	}
	this->m_vVehicules.clear();
}

/**
 * \brief Constructeur copie de la classe Proprietaire
 */
Proprietaire::Proprietaire(const Proprietaire& p_nouveauProprietaire)
:m_nom(p_nouveauProprietaire.m_nom),m_prenom(p_nouveauProprietaire.m_prenom)
{

	for (std::vector<Vehicule*> ::const_iterator iter = p_nouveauProprietaire.m_vVehicules.begin(); iter != p_nouveauProprietaire.m_vVehicules.end(); iter++)
	{
		this->ajouterVehicule(**iter);
	}

	INVARIANTS();
}

/**
 * \brief Surcharge de l'opérateur d'affectation qui est utilisé pour dupliquer un objet dans un autre
 * où ce rôle est dévolu au constructeur de copie
 * \return Adresse de l'objet Proprietaire
 */
Proprietaire& Proprietaire::operator=(const Proprietaire& p_proprietaire)
{
	if (this != & p_proprietaire)
	{
		delete &this->m_nom;
		delete &this->m_prenom;
		for (std::vector<Vehicule*> ::iterator iter = m_vVehicules.begin(); iter != this->m_vVehicules.end(); iter++)
		{
			delete *iter;
		}

		m_vVehicules.clear();


		this->m_nom = p_proprietaire.m_nom;

		this->m_prenom = p_proprietaire.m_prenom;

		for (std::vector<Vehicule*> ::iterator iter = m_vVehicules.begin(); iter != this->m_vVehicules.end(); iter++)
		{
			this->ajouterVehicule(**iter);
		}
	}

	INVARIANTS();

	return *this;


}


/**
 * \brief Acceseur pour Nom
 * \return m_nom Le nom de famille du proprietaire
 */
const std::string Proprietaire::reqNom() const
{
	return m_nom;
}

/**
 * \brief Acceseur pour Prenom
 * \return m_prenom Le nom du proprietaire
 */
const std::string Proprietaire::reqPrenom() const
{
	return m_prenom;
}


/**
 * \brief Retourne une chaine de caractere formate qui contient les informations relatives a chaque vehicule
 * du proprietaire
 * \return un string qui contient l'information de l'objet vehicule
 */
std::string Proprietaire::reqProprietaireFormate() const
{
	string separateur = "-----------------------------------------";

	std::ostringstream os;
	os << "Proprietaire : " << endl
	   << separateur << endl
	   << " Nom    : " << m_nom << endl
	   << " Prenom : " << m_prenom << endl
	   << separateur << endl;
		for (std::vector<Vehicule*> ::const_iterator iter = m_vVehicules.begin(); iter != this->m_vVehicules.end(); iter++)
	   {
		   os << (*iter)->reqVehiculeFormate()
			<< separateur << endl ;
	   }

	return os.str();
}


/**
 * \brief Methode permet d’ajouter un Vehicule au vecteur de Véhicules.
 * \param[in] p_nouveauVehicule objet vehicule passé par référence constante qui sera clone et ajoute dans le vecteur
 * \throws si le vehicule existe deja dans le vecteur une exception est levee
 */
void Proprietaire::ajouterVehicule (const Vehicule& p_nouveauVehicule)
{
	if (!VehiculeEstDejaPresent(p_nouveauVehicule.reqNiv()))
	{
		this->m_vVehicules.push_back(p_nouveauVehicule.clone());
	}
	else
	{

		throw VehiculeDejaPresentException("Impossible l'ajout! Ce vehicule existe deja. ");
	}


	INVARIANTS();
}

/**
 * \brief permet de verifier si le Proprietaire a deja ce Vehicule c.a.d avec le meme NIV
 * \param[in] p_niv est une string qui represente le numero d'identification du Vehicule qui est en train d'etre ajoute
 * \return un booleen qui indique si le Proprietaire a deja ce vehcule ou non
 */
bool Proprietaire::VehiculeEstDejaPresent(const std::string& p_niv) const
{
	for (std::vector<Vehicule*>::const_iterator iter = m_vVehicules.begin(); iter != this->m_vVehicules.end(); iter++)
	{
		if ((*iter)->reqNiv() == p_niv)
		{
			return true;
		}
	}
	return false;
}


/**
 * \brief Methode permet de supprimer un Véhicule du vecteur de Véhicules.
 * \param[in] p_niv une string qui represente le niv du vehicule a suprimmer
 * \pre p_niv n'est pas vide
 * \throws si le vehicule n'existe pas dans le vecteur une exception est levee
 */
void Proprietaire::supprimerVehicule (const std::string& p_niv)
{
	PRECONDITION(!p_niv.empty());

	if(!VehiculeEstDejaPresent(p_niv))
	{
		throw VehiculeAbsentException("Impossible la supression! Ce vehicule n'existe pas.");
	}


	for (std::vector<Vehicule*>::iterator iter = m_vVehicules.begin(); iter != m_vVehicules.end(); iter++)
	    {
	        if((*iter)->reqNiv() == p_niv)
	        {
	            delete (*iter);
	            iter = m_vVehicules.erase(iter);
	            if(iter == m_vVehicules.end()){
	            	iter--;
	            }

	        }
	    }
}


/**
 * \brief pour vérifier l'invariant de classe dans l'implantation de la théorie du contrat
 */
void Proprietaire::verifieInvariant() const
{
	INVARIANT(!m_nom.empty());
	INVARIANT(!m_prenom.empty());
}


} /* namespace saaq */
