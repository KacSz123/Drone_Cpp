#ifndef HEXAGONAL_PRISM_HPP
#define HEXAGONAL_PRISM_HPP

#include "geometric_obj.hpp"
#include <iostream>
#include<string>

class HexagonalPrism:public GeometricObj
{
    private:
    void WriteToStreamExample(ostream &output_stream){ output_stream << *this << "\n";}
    public:
        HexagonalPrism():GeometricObj(12){};
        HexagonalPrism(vector3D midPt, double height, double radius); 
        ~HexagonalPrism(){ this->_vertexes.clear(); this->_vertexes.shrink_to_fit();}; 
        bool writeToFile(const std::string &fileName);      
        friend std::ostream& operator << (std::ostream&, HexagonalPrism&);
};


#endif //HEXAGONAL_PRISM_HPP