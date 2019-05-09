#ifndef DUREEEDITABLE_H
#define DUREEEDITABLE_H

#include "ieditable.hpp"
#include "duree.h"
namespace nsUtil {
    class DureeEditable :public Duree, public IEditable
    {
    protected:
        virtual ostream& display(ostream& os) const;
    public:
        explicit DureeEditable(const unsigned long long duree=0) noexcept;
        DureeEditable(const Duree& duree) noexcept;

        virtual ~DureeEditable();

        DureeEditable & operator ++ (void) noexcept; // préincrémentation de la classe CX
        DureeEditable   operator ++ (int)  noexcept; // postincrémentation de la classe CX

        DureeEditable & operator -- (void) throw (CException); // préincrémentation de la classe CX
        DureeEditable   operator -- (int)  throw (CException); // postincrémentation de la classe CX

        DureeEditable operator +  (const Duree & d) const noexcept;
        DureeEditable operator -  (const Duree & d) const throw (CException);

        DureeEditable operator +  (const unsigned long long & d) const noexcept;
        DureeEditable operator -  (const unsigned long long & d) const throw (CException);

        DureeEditable & operator += (const Duree &) noexcept;
        DureeEditable & operator += (const unsigned long long &) noexcept;

        DureeEditable & operator -= (const Duree &) throw (CException);
        DureeEditable & operator -= (const unsigned long long &) throw (CException);

    };

}

#endif // DUREEEDITABLE_H
