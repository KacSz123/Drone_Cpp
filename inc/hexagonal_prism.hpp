#pragma once
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