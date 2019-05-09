#ifndef __CEXCEPTION_H__
#define __CEXCEPTION_H__

#include <string>
#include <exception>

#include "cstcoderr.h"
#include "ieditable.hpp"

namespace nsUtil
{
    class CException : public std::exception, public IEditable
    {
       protected:
          virtual ostream& display(ostream& os) const;

        std::string myLibelle;
        unsigned    myCodErr;

      public :
        CException (const std::string & libelle = std::string(),
                    const unsigned      codErr  = KNoExc)     noexcept;
        virtual ~CException (void)                            noexcept;

        const std::string & getLibelle (void) const           noexcept;
        unsigned            getCodErr  (void) const           noexcept;

        virtual const char* what       (void) const           noexcept;


    }; // CException

} // namespace nsUtil

#endif /*  __CEXCEPTION_H__  */
