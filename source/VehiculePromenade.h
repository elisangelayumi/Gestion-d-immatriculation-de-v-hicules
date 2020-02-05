/**
 * \file VehiculePromenade.h
 * \brief Prototype de la classe VehiculePromenade
 * \author Elisangela Yumi
 * \version 0.1
 * \date: 2019-11-20
 */

#ifndef VEHICULEPROMENADE_H_
#define VEHICULEPROMENADE_H_

#include "Vehicule.h"

namespace saaq
{

/**
* \class VehiculePromenade
* \brief La classe VehiculePromenade représente les véhicules de promenade, incluant les habitations motorisées,
*  de 3000 kg ou moins appartenant à un particulier.
*
*	 Attributs: string m_niv: le numero de serie du vehicule;
*	 			string m_immatriculation: le numero de la plaque du vehicule;
*	 			Date m_dateEnregistrement: la date que l'objet a ete cree;
*	 			int m_nbPlaces: le nombre de place que le vehicule possede.
*/
class VehiculePromenade : public Vehicule
{
public:

	VehiculePromenade(const std::string& p_niv, const std::string& p_immatriculation, const int p_nbPlaces );

	void asgImmatriculation(std::string& p_immatriculation);
	const int reqNbPlaces() const;
	virtual double tarificationAnnuelle() const;
	virtual Vehicule* clone() const;
	virtual std::string reqVehiculeFormate() const;

private:

	int m_nbPlaces;
	void verifieInvariant() const;

};

} /* namespace saaq */

#endif /* VEHICULEPROMENADE_H_ */
