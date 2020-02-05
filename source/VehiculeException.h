/**
 * \file VehiculeException.h
 * \brief 
 * \author Elisangela Yumi
 * \version 0.1
 * \date: 2019-12-04
 */

#ifndef VEHICULEEXCEPTION_H_
#define VEHICULEEXCEPTION_H_

#include <stdexcept>


/**
* \class VehiculeException
 * \brief Classe pour la gestion des erreurs liees aux vehicules.
*/
class VehiculeException : public std::runtime_error
{
public:

	VehiculeException (const std::string& p_raison):
		runtime_error(p_raison) {}
};



/**
* \class VehiculeDejaPresentException
 * \brief Classe pour gerer l’exception de l’ajout d’un doublon de vehicule dans le dossier du proprietaire.
*/
class VehiculeDejaPresentException : public VehiculeException
{
public:

	VehiculeDejaPresentException (const std::string& p_raison):
		VehiculeException(p_raison) {}
};



/**
* \class VehiculeAbsentException
 * \brief Classe pour gerer l’exception de la tentative de suppression d’un véhicule absent dans le dossier du proprietaire.
*/
class VehiculeAbsentException : public VehiculeException
{
public:
	VehiculeAbsentException (const std::string& p_raison):
		VehiculeException(p_raison) {}
};



#endif /* VEHICULEEXCEPTION_H_ */
