/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 16:21:04 by jmetayer          #+#    #+#             */
/*   Updated: 2026/09/29 20:16:10 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main ( void )
{
    std::vector<int> v; //Conteneurs type tableau 
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (vector<int>::iterator it = v.begin(); it != v.end() ; ++it )
        cout << *it << " is found in the container" << endl;

    
}

//Container sequentiel comme vector (tableau[]) list(liste doublement chainee) deque(file a double entree) 
//Comment faire pour avoir um template sur les conteneurs
//Es-ce que mon exception marche bien
//Type T sur le type du containeur ou sur la variable de type contenue ? 
