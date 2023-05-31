#ifndef HEXAGONAL_PRISM_HPP
#define HEXAGONAL_PRISM_HPP

#include "geometric_obj.hpp"
#include <iostream>

class HexagonalPrism:public GeometricObj
{
    private:

    public:
        HexagonalPrism():GeometricObj(12){};
        HexagonalPrism(vector3D midPt, double height, double radius);        
};
std::ostream& operator << (std::ostream&, HexagonalPrism);


#endif //HEXAGONAL_PRISM_HPP