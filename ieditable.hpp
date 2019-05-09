#ifndef IEDITABLE_HPP
#define IEDITABLE_HPP
#include <ostream>

using namespace std;

namespace nsUtil {

    class IEditable {
    protected:
        virtual ostream& display(ostream& os) const = 0;

    public:
        virtual ~IEditable() {}
        friend ostream & operator << (ostream & os, const IEditable & obj);
    };

    inline ostream & operator << (ostream & os, const IEditable & editable)
    {
        return editable.display (os);

    } // operator <<()
}

#endif // IEDITABLE_HPP
