#ifndef CUBOID_HPP
#define CUBOID_HPP
/*!
 * @file cuboid.hpp
 * @author {Kacper Szczepanowski} ({kacperszcz159@gmail.com})
 * @brief Contains definition of class Cuboid based on \p GeometricObj
 * @version 0.1
 * @date 2023-09-20
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "vectorNd.hpp"
#include "matrixNxN.hpp"
#include "geometric_obj.hpp"
#include <list>
/*!
 * @brief Model of Cuboid in 3D space.
 *
 * Contains information about vertexes ( \p vector3d ), center point.
 * Class is based on \p GeometriObj
 *
 */
class Cuboid : public GeometricObj //,public SceneObj
{
    using GeometricObj::operator=;

private:
    /*!
     * @brief Visualization variable.
     *
     * Help variable for visualization in gnuplot (surface plot).
     */
    double y;
    // double x;
    // double z;

public:
    /*!
     * @brief Construct a new Cuboid object
     *
     */
    Cuboid() : GeometricObj(8){};

    /*!
     * @brief Construct a new Cuboid object
     *
     * @param[in] midPt - center point
     * @param[in] lenX - x size.
     * @param[in] lenY - y size.
     * @param[in] lenZ - z size.
     * @param[in] y - help var.
     */
    Cuboid(const vector3D &midPt, const double lenX,
           const double lenY, const double lenZ, const double y = 30);

    ///////////////////////////////////////////////////////////////// rule of 5

    /*!
     * @brief Destroy the Cuboid object
     *
     */
    ~Cuboid()
    {
        if (_vertexes.size())
        {
            this->_vertexes.clear();
            this->_vertexes.shrink_to_fit();
        }
    };

    Cuboid(const Cuboid &C) : GeometricObj(C)
    {
        // for (int i = 0; i < 8; ++i)
        // {
        //     this->setVertex(i, C.getVertex(i));
        // }
        // this->setMidPoint(C.getMidPoint());
        this->y = C.getY();
    }

    Cuboid(Cuboid &&C) : GeometricObj(C)
    {
        // for (int i = 0; i < 8; ++i)
        // {
        //     this->setVertex(i, C.getVertex(i));
        // }
        // this->setMidPoint(C.getMidPoint());
        this->y = C.getY();
    }

    Cuboid &operator=(const Cuboid &C)
    {
        for (int i = 0; i < this->getVertexesNumber(); ++i)
        {
            this->setVertex(i, C.getVertex(i));
        }
        this->setOrientation(C.getOrientation());
        this->setMidPoint(C.getMidPoint());
        this->y = C.getY();
        return *this;
    }

    Cuboid &operator=(Cuboid &&C)
    {
        for (int i = 0;i < this->getVertexesNumber(); ++i)
        {
            this->setVertex(i, C.getVertex(i));
        }
        this->setOrientation(C.getOrientation());

        this->setMidPoint(C.getMidPoint());
        this->setOrientation(C.getOrientation());
        this->y = C.getY();
        return *this;
    }
    //////////////////////////////////////////////////////////////////////////////////////
    /*!
     * @brief Get \p y value
     *
     * @return double y
     */
    double getY() const { return y; }

    /*!
     * @brief Print vertexes on std out.
     *
     */
    void printVertexes()
    {
        for (VertexVec::iterator i = _vertexes.begin(); i != _vertexes.end(); ++i)
            std::cout << *i << std::endl;
        std::cout << std::endl;
    };

    /*!
     * @brief Overload of operator \b << .
     *
     *
     *
     *
     * @param strm - ostream object
     * @param rect - buboid instance
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &strm, Cuboid &rect);

    /*!
     * @brief Writing to stream.
     *
     * @param output_stream Destination stream.
     */
    void WriteToStreamExample(ostream &output_stream) { output_stream << (*this) << "\n"; }

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
};

#endif // CUBOID_HPP