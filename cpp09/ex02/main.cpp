/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:23:55 by jmetayer          #+#    #+#             */
/*   Updated: 2026/10/09 16:20:12 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*Ford Johnson algorithm (merge, insertin sort)
Etape 1 on regroupe les elements par pairs, le plus grand de vient a_i et le plus petit devient b_i 
Si un element reste seul on l'appelle le stagler. 


Jacobsthal : 

insertion binaire ; exemple de la camera et qu'on ma pet mon tel 

parois l'insetion binaire est opti (suite a jacobstah)
parfois pas : 
On va determiner grace a l'ordre d'insertion jacobstah de quel element on va s'occuper 
Quand la valeur donner par jacobstalh depasse la taille du pool, on les affecte dans la mainchain par ordre degressif 
mainchain vs pendchain 
ls

Quel container ? 



*/
int main (int argc, char **argv)
{
    if(argc != 2)
    {
        std::cerr << "One and only one argument needed" << std::endl;
        return 1;
    }
    try
    {
        PmergeMe(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}