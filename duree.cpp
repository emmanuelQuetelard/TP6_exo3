/**
 *
 * \file    Duree.cpp
 *
 * \authors M. Laporte
 *
 * \date    02/04/2018
 *
 * \version V2.0
 *
 * \brief  définitions de la classe Duree
 *
 **/
#include <iostream>
#include <iomanip>   // setw()
#include "duree.h"
#include "cexception.h"

using namespace nsUtil;
using namespace std;

#define DUREE nsUtil::Duree

DUREE::Duree  (const ULLong_t duree /* = ULLong_t (0) */)
    : myDuree (duree)
{
    normaliser ();
} // Duree()

DUREE::Duree  (const Duree & duree)
    : myDuree (duree.getDuree ())
{
    normaliser ();


} // Duree()

DUREE::~Duree  (void)
{


} // Duree()

void DUREE::normaliser (void)
{
    myDays    =  myDuree / 86400;
    myHours   = (myDuree % 86400) / 3600;
    myMinutes  = (myDuree % 3600) / 60;
    mySeconds =  myDuree % 60;

} // normaliser()

ULLong_t DUREE::getDuree (void) const { return myDuree; }
void DUREE::setDuree(const unsigned long long& d) noexcept
{
    myDuree = d;
    normaliser();
}

Duree & DUREE::operator ++ (void) noexcept
{
    myDuree++;
    normaliser();

    return (*this);
}
Duree   DUREE::operator ++ (int incr)  noexcept
{
    Duree duree(myDuree);
    myDuree ++;
    normaliser();
    return duree;
}

Duree & DUREE::operator -- (void) throw (CException)
{
    if(myDuree == 0)
        throw CException("durée négative", 36);
    myDuree--;
    normaliser();

    return (*this);
}

Duree   DUREE::operator -- (int decr)  throw (CException)
{
    if(myDuree == 0)
        throw CException("durée négative", 36);
    Duree duree(myDuree);
    myDuree--;
    normaliser();
    return duree;
}

DUREE DUREE::operator + (const Duree & d) const noexcept
{
    return myDuree + d.myDuree;

} // operator +()

DUREE DUREE::operator - (const Duree & d) const throw (CException)
{
    if(myDuree - d.getDuree() <= 0)
        throw CException("durée négative", 36);
    return myDuree - (myDuree < d.myDuree ? myDuree : d.myDuree);

} // operator -()

DUREE DUREE::operator +  (const unsigned long long & d) const noexcept
{
      return myDuree + d;
}

DUREE DUREE::operator -  (const unsigned long long & d) const throw (CException)
{
    if(myDuree - d <= 0)
        throw CException("durée négative", 36);
    return myDuree - (myDuree < d ? myDuree : d);
}

DUREE & DUREE::operator += (const Duree & duree) noexcept
{
    myDuree += duree.getDuree();
    normaliser();
    
    return (*this);
}

DUREE & DUREE::operator += (const unsigned long long & duree) noexcept
{
    myDuree += duree;
    normaliser();
    
    return (*this);
}

DUREE & DUREE::operator -= (const Duree & duree) throw (CException)
{
    if(duree.getDuree() > myDuree)
        throw CException("durée négative", 36);
    myDuree -= duree.getDuree();
    normaliser();
    
    return (*this);
}

DUREE & DUREE::operator -= (const unsigned long long & duree) throw (CException)
{
     if(duree > myDuree)
        throw CException("durée négative", 36);

    myDuree -= duree;
    normaliser();
    
    return (*this);
}

bool DUREE::operator > (const Duree & d) const noexcept
{
    return myDuree > d.myDuree;

} // operator >()

bool DUREE::operator < (const Duree & d) const noexcept
{
    return myDuree < d.myDuree;

} // operator <()

bool DUREE::operator != (const Duree & d) const noexcept
{
    return myDuree != d.myDuree;

} // operator !=()

bool DUREE::operator == (const Duree & d) const noexcept
{
    return myDuree == d.myDuree;

} // operator ==()

#undef DUREE
