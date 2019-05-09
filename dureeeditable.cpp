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
         << setw (10) << myDays    << ':'
         << setfill ('0')
         << setw (2)  << myHours   << " heure(s)"
         << setw (2)  << myMinutes << " minute(s)"
         << setw (2)  << mySeconds << " seconde(s)"
         << setfill (' ')
         << ']';
}

DureeEditable & DureeEditable::operator ++ (void) noexcept
{
   return (*this) = Duree::operator++();
}
DureeEditable   DureeEditable::operator ++ (int incr)  noexcept
{
    return (*this) = Duree::operator++(incr);
}

DureeEditable & DureeEditable::operator -- (void) throw (CException)
{
    return (*this) = Duree::operator--();
}

DureeEditable   DureeEditable::operator -- (int decr)  throw (CException)
{
   return (*this) = Duree::operator--(decr);
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
    return (*this) = Duree::operator+=(duree);
}

DureeEditable & DureeEditable::operator += (const unsigned long long & duree) noexcept
{
  return (*this) = Duree::operator+=(duree);
}

DureeEditable & DureeEditable::operator -= (const Duree & duree) throw (CException)
{
    return (*this) = Duree::operator-=(duree);
}

DureeEditable & DureeEditable::operator -= (const unsigned long long & duree) throw (CException)
{
    return (*this) = Duree::operator-=(duree);
}

}
