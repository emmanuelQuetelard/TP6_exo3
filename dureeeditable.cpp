#include "dureeeditable.h"

#include <ostream>
#include <iomanip>

namespace nsUtil {
DureeEditable::DureeEditable(const unsigned long long duree) noexcept : Duree(duree)
{

}
DureeEditable::DureeEditable(const Duree& duree) noexcept : Duree(duree)
{

}

DureeEditable::~DureeEditable()
{

}

ostream& DureeEditable::display(ostream& os) const
{
    return os << '['
         << setw (6) << myDays    << ':'
         << setfill ('0')
         << setw (2)  << myHours   << ":"
         << setw (2)  << myMinutes << ":"
         << setw (2)  << mySeconds
         << setfill (' ')
         << ']';
}

DureeEditable & DureeEditable::operator ++ (void) noexcept
{
   return (*this) = Duree::operator++();
}
DureeEditable   DureeEditable::operator ++ (int)  noexcept
{
    return Duree::operator++(0);
}

DureeEditable & DureeEditable::operator -- (void) throw (CException)
{
    return (*this) = Duree::operator--();
}

DureeEditable   DureeEditable::operator -- (int)  throw (CException)
{
   return Duree::operator--(0);
}

DureeEditable DureeEditable::operator + (const Duree & d) const noexcept
{
    return Duree::operator+(d);

} // operator +()

DureeEditable DureeEditable::operator - (const Duree & d) const throw (CException)
{
   return Duree::operator-(d);

} // operator -()

DureeEditable DureeEditable::operator +  (const unsigned long long & d) const noexcept
{
     return Duree::operator+(d);
}

DureeEditable DureeEditable::operator -  (const unsigned long long & d) const throw (CException)
{
    return Duree::operator-(d);
}

DureeEditable & DureeEditable::operator += (const Duree & duree) noexcept
{
    Duree::operator+=(duree);
    return *this;
}

DureeEditable & DureeEditable::operator += (const unsigned long long & duree) noexcept
{
   Duree::operator+=(duree);
    return *this;
}

DureeEditable & DureeEditable::operator -= (const Duree & duree) throw (CException)
{
    Duree::operator-=(duree);
    return *this;
}

DureeEditable & DureeEditable::operator -= (const unsigned long long & duree) throw (CException)
{
    Duree::operator-=(duree);
    return *this;
}

}
