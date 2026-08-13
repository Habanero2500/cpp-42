/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 13:32:31 by jmetayer          #+#    #+#             */
/*   Updated: 2026/07/28 13:30:43 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0)
{  
    
}
Point::Point(float x, float y) : _x(x), _y(y)
{
    
}

Point::Point(const Point& data)
    : _x(data.getX()), _y(data.getY())
{
    
}
Point::~Point ( void )
{
    
}

Point& Point::operator=(const Point&)
{
    return *this;
}

Fixed Point::getX() const
{
    return _x;
}

Fixed Point::getY() const
{
    return _y;
}

float areaSize( Point const &a, Point const &b, Point const &c)
{
    Fixed valA = a.getX()*(b.getY() - c.getY());
    Fixed valB = b.getX()*(c.getY() - a.getY());
    Fixed valC = c.getX()*(a.getY() - b.getY());
    Fixed area = (valA + valB + valC)/2;
    if(area < 0.0001f)
        area = area * (-1);
    return(area.toFloat());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    //Algorithme dit des Aires. Si l'aire de PAB + l'aire de PAC + l'aire de PBC = ABC. Le point est dans le triangle.
    //Detection des points sur l'arrete : un des triangles egal a 0.
    //Calcul de l'aire orientee : A(x1, y1), B(x2, y2), C(x3, y3)
    //(x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2))/2
    Fixed area = areaSize( a, b, c );
    // std::cout << "Value total : " << area << std::endl;
    Fixed area1 = areaSize( point, b, c );
    // std::cout << "Value area1 : " << area1 << std::endl;
    if(area1 == 0)
        return false;
    Fixed area2 = areaSize( a, point, c );
    // std::cout << "Value area2 : " << area2 << std::endl;
    if(area2 == 0)
        return false;
    Fixed area3 = areaSize( a, b, point );
    // std::cout << "Value area3 : " << area3 << std::endl;
    if(area3 == 0)
        return false;
    // std::cout << "Total value : " << (area1 + area2 + area3 - area) << std::endl;
    if((area1 + area2 + area3 - area) == 0 )
        return true;
    return false;
}