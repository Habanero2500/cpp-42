/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 12:05:35 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/07 13:33:09 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//A file must be taken as argument with the format "date | value"
// Date format has to be y-m-d
// A value has to be a float or an int between 0 and 100.


//Charger le fichier csv en memoire 
// stocker les datas dans la map
// - faire un gnl avec chaque saut stocke dans une iteration de map
// - stocker une partie de la ligne dans date l'autre dans val

// affichage avec la bonne date + si pas la date exacte chercher la precedente
// multiplication avec le check si >= 0 et <= 1000

int main ( int argc, char **argv)
{
    if(argc != 2)
    {
        std::cerr << "One and only one argument needed" << std::endl;
        return 1;
    }
    try
    {
        std::ifstream in(argv[1]);
        BitcoinExchange btc(in);
    }
    catch( std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}