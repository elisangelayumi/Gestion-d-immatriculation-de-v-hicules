/**
 * \file Vehicule.h
 * \brief Prototype de la classe Vehicule
 * \author Elisangela Yumi
 * \version 0.1
 * \date: 2019-10-12
 */

#ifndef VEHICULE_H_
#define VEHICULE_H_
#include <string>
#include "Date.h"
#include "ContratException.h"
#include "validationFormat.h"


namespace saaq {

/**
* \class Vehicule
* \brief Classe Vehicule permettant de modeliser les objets vehicules
*
*	 Attributs: string m_niv: le numero de serie du vehicule;
*	 			string m_immatriculation: le numero de la plaque du vehicule;
*	 			Date m_dateEnregistrement: la date que l'objet a ete cree.
*
*	 Note: a la construction d’un nouvel objet Vehicule, la date d’enregistrement est celle du systeme.
*/
class Vehicule
{
public:
	Vehicule(const std::string& p_niv, const std::string& p_immatriculation);

	virtual ~Vehicule(){} ;

	virtual Vehicule* clone() const =0;

	virtual double tarificationAnnuelle() const=0;

	const std::string reqNiv() const;
	const std::string reqImmatriculation() const;
	const util::Date reqdateEnregistrement() const;
	virtual std::string reqVehiculeFormate() const=0;
	bool operator== (const Vehicule& p_vehicule) const;

protected:

	void asgImmatriculation(std::string& p_immatriculation);

private:

	std::string m_niv;
	std::string m_immatriculation;
	util::Date m_dateEnregistrement;
	void verifieInvariant() const;
};

} /* namespace saaq */

#endif /* VEHICULE_H_ */
