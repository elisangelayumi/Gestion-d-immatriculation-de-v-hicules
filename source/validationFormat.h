/**
 * \file validationFormat.h
 * \brief declaration des prototypes du module qui permet de valider le numero de série du Vehicule et le format de l'immatriculation
 * \author Elisangela Yumi
 * \version 0.1
 * \date: 2019-09-19
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_

namespace util

{

bool validationImmatriculationPromenade (const std::string& p_immatriculation);

bool validerPlaqueSpeciaux (const std::string& p_immatriculation);

bool validerPlaqueSansPrefixe (const std::string& p_immatriculation);

bool verifierSiContientEspace (const std::string& p_immatriculation);

bool validerPlaqueQueContientEspace(const std::string& p_immatriculation);

bool validerPlaqueSansEspace(const std::string& p_immatriculation);

bool validationImmatriculationCamion (const std::string& p_immatriculation);

bool validerPlaqueL (const std::string& p_immatriculation);

bool validerNiv (const std::string& p_niv);

bool calculerNiv(const std::string& p_niv);

int valeursPossiblesNiv(char p_monCharNiv);

int poidsPositionNiv(int p_position);

} //namespace util

#endif /* VALIDATIONFORMAT_H_ */
