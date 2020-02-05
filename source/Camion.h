/**
 * \file Camion.h
 * \brief Prototype de la classe Camion
 * \author Elisangela Yumi
 * \version 0.1
 * \date: 2019-11-21
 */

#ifndef CAMION_H_
#define CAMION_H_

#include "Vehicule.h"

namespace saaq {


/**
* \class Camion
* \brief La classe Camion représente les camions de transport de marchandise générale, véhicules de plus de 3000 kg de
*  type commercial dont la tarification de l’immatriculation dépend du poids et du nombre d’essieux
*
*	 Attributs: string m_niv: le numero de serie du vehicule;
*	 			string m_immatriculation: le numero de la plaque du vehicule;
*	 			Date m_dateEnregistrement: la date que l'objet a ete cree;
*	 			int m_nbPlaces: le nombre de place que le vehicule possede.
*/
class Camion : public Vehicule
{
public:

	Camion(const std::string& p_niv, const std::string& p_immatriculation, double p_poids, int nbEssieux);

	const double reqPoids() const;
	const int reqNbEssieux() const;
	void asgImmatriculation(std::string& p_immatriculation);

	virtual double tarificationAnnuelle() const;
	virtual Vehicule* clone() const;
	virtual std::string reqVehiculeFormate() const;

private:

	double m_poids;
	int m_nbEssieux;
	void verifieInvariant() const;

};

} /* namespace saaq */

#endif /* CAMION_H_ */
