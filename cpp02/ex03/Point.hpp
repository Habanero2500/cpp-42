/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 13:32:35 by jmetayer          #+#    #+#             */
/*   Updated: 2026/07/10 14:41:03 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>
#include "Fixed.hpp"

class Point{
    
    private : 
        const Fixed _x;
        const Fixed _y;

    public : 
        
        //Canonical form: 
        Point( void );
        Point( const Point &data );
        ~Point ( void );
        Point &operator= (const Point& data);
        Point(float x, float y);


        //Utils: 
        Fixed getX() const;
        Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif