#ifndef HEXAGONAL_PRISM_HPP
#define HEXAGONAL_PRISM_HPP
/*!
 * @file hexagonal_prism.hpp
 * @author {Kacper Szczepanowski} ({kacperszcz159@gmail.com})
 * @brief Model of class HexagonalPrism based on \p GeometriObj.
 * @version 0.1
 * @date 2023-09-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "geometric_obj.hpp"
#include <iostream>
#include <string>
/*!
 * @brief Describes 3D object: hexagonal prism.
 * 
 * Derived class of \p GeometricObj . Contains suitable methods of 
 * creation vertexes and writing to stream/file.
 */
class HexagonalPrism : public GeometricObj
{
private:
    /*!
     * @brief Writing to stream.
     *
     * Writing coords to stream.
     *
     * @param output_stream Destination stream.
     */
    void WriteToStreamExample(ostream &output_stream) { output_stream << *this << "\n"; }

public:
    /*!
     * @brief Construct a new Hexagonal Prism object
     *
     * Calls \see GeometricObj(int)
     */
    HexagonalPrism() : GeometricObj(12){};

    /*!
     * @brief Construct a new Hexagonal Prism object
     *
     * @param midPt
     * @param height
     * @param radius
     */
    HexagonalPrism(vector3D midPt, double height, double radius);

    /*!
     * @brief Destroy the Hexagonal Prism object
     *
     */
    ~HexagonalPrism()
    {
        this->_vertexes.clear();
        this->_vertexes.shrink_to_fit();
    };

    /*!
     * @brief Write coordinates to file.
     *
     * Write coordinates to file. Return true if succeded, false if failed.
     *
     * @param fileName
     * @return true - succeded
     * @return false - failed
     */
    bool writeToFile(const std::string &fileName);

    /*!
     * @brief Overload of operator \b << .
     *
     * @param[in] strm - ostream object
     * @param[in] hex - buboid instance
     * @return std::ostream&
     */

    friend std::ostream &operator<<(std::ostream &strm, HexagonalPrism &hex);
};

#endif // HEXAGONAL_PRISM_HPP