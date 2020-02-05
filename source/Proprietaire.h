/**
 * \file Proprietaire.h
 * \brief Prototype de la classe Proprietaire
 * \author Elisangela Yumi
 * \version 0.1
 * \date: 2019-11-21
 */

#ifndef PROPRIETAIRE_H_
#define PROPRIETAIRE_H_

#include "Vehicule.h"
#include <vector>

namespace saaq {


/**
* \class Proprietaire
* \brief La classe Proprietaire permet de faire la gestion des Véhicules.
*
*	 Attributs: string p_nom: le nom du proprietaire;
*	 			string p_prenom: le prenom du proprietaire;
*
*/
class Proprietaire
{
public:

	Proprietaire(const std::string& p_nom, const std::string& p_prenom);

	~Proprietaire();
	Proprietaire(const Proprietaire& p_nouveauProprietaire);
	Proprietaire& operator=(const Proprietaire& p_proprietaire);

	const std::string reqNom() const;
	const std::string reqPrenom() const;

	std::string reqProprietaireFormate() const;

	void ajouterVehicule(const Vehicule& p_nouveauVehicule);

	void supprimerVehicule (const std::string& p_niv);




private:

	std::string m_nom;
	std::string m_prenom;
	std::vector<Vehicule*> m_vVehicules;

	bool VehiculeEstDejaPresent(const std::string& p_niv) const;

	void verifieInvariant() const;

};

} /* namespace saaq */

#endif /* PROPRIETAIRE_H_ */
