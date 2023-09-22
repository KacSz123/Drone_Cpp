#ifndef GEOMMETRIC_OBJ_HPP
#define GEOMMETRIC_OBJ_HPP
/*!
 * @file geometric_obj.hpp
 * @author {Kacper Szczepanowski} ({kacperszcz159@gmail.com})
 * @brief Contains definition of GeometricObj and all its methods.
 * @version 0.1
 * @date 2023-09-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "matrixNxN.hpp"
#include <vector>
#include "vectorNd.hpp"
/*!
 * @brief New type: std::vector of vector3D
 * 
 */
typedef std::vector<vector3D> VertexVec;

/*!
 * @brief Class describes geometric object in 3D space.
 * 
 * Class contains \p std::vector of \p vector3D , as vertexes
 * and single object of  \p vector3D as center point.
 * Methods provided to this class allow to manipulate object in 3D space 
 * and write coordinates to stream and file.
 * 
 * 
 */
class GeometricObj
{
private:
protected:
    /*!
     * @brief vector of all vertexes 
     * Vector of type \p vector3D.
     */
    VertexVec _vertexes;

    /*!
     * @brief center point
     * 
     */
    vector3D _midPoint;

    /*!
     * @brief Orientation matrix.
     * 
     */
    Matrix3x3 _orientMatrix;

/*!
 * @brief Insert new vertex.
 * 
 * Insert \p vector3D int \p _vertexes.
 * @param[in] v - value to insert. 
 */
    void insertVertex(vector3D v) { this->_vertexes.push_back(v); }
public:
/*!
 * @brief Set the Vertex object
 * 
 * @param[in] i - index of vertex.
 * @param[in] vec - new value.
 */
    void setVertex(int i, const vector3D &&vec) { this->_vertexes[i].setCoords(vec.getCoord(0),
                                                            vec.getCoord(1),vec.getCoord(2)); }
    /*!
 * @brief Set the Vertex object
 * 
 * @param[in] i - index of vertex.
 * @param[in] vec - new value.
 */
    void setVertexCoords(int i, vector3D &vec) { this->_vertexes[i] = vec; }
    void setVertex(int i, vector3D &vec) { this->_vertexes[i] = vec; }
    // void setVertexCoords(int i, vector3D &vec)const { this->_vertexes[i] = vec; }
    /*!
     * @brief Set the Vertex Coords object
     * 
     * @param[in] i - index of vertex/ 
     * @param[in] x  - x value
     * @param[in] y  - y value
     * @param[in] z  - z value
     */
    void setVertexCoords(int i, double x, double y, double z) { this->_vertexes[i].setCoords(x, y, z); }
    
    /*!
     * @brief Set the Mid Point object
     * 
     * @param[in] x  - x value
     * @param[in] y  - y value
     * @param[in] z  - z value
     */
    void setMidPoint(double x, double y, double z) { this->_midPoint.setCoords(x, y, z); }
    
    /*!
     * @brief Set the Mid Point object
     * 
     * @param[in] v - vector object 
     */
    void setMidPoint(vector3D v) { this->_midPoint = v; }

    /*!
     * @brief Set the Orientation object
     * 
     * @param[in] m Matrix3x3 
     */
    void setOrientation(Matrix3x3 m) { this->_orientMatrix = m; }

    /*!
     * @brief Move all vertexes in space.
     * 
     * @param vec - vector of translation.
     */
    void move(vector3D vec);
    /*!
     * @brief Move object in own X axis.
     * 
     * Move object in own X axis. Using own _orientation.
     * 
     * @param[in] x - path length.
     */
    void moveForward(double x);

    /*!
     * @brief Soar object in own X axis.
     * 
     * Move object in own X axis. Using own _orientation.
     * And move up in global Z axis.
     * 
     * @param[in] x - own x path length.
     * @param[in] z - global z path length.
     */
    void soarForward(double x,double z);

    /*!
     * @brief Rotate object.
     * 
     * Proceed rotation of an object. Rotation may be proceed around own axis or
     * global Axis.
     * 
     * @param[in] angle - angle of rotation
     * @param[in] axis - axis of rotation.
     * @param[in] aroundOwnAxis [true: around extraPoint; false; arund (0,0,0)]
     * @param[in] extraVec - reference point
     */
    void rotate(double angle, char axis, bool aroundOwnAxis =true, vector3D extraVec = vector3D(0,0,0));
    
    /*!
     * @brief Rotate object without orientation change.
     * 
     * @param[in] angle - angle of rotation
     * @param[in] axis - axis of rotation.
     */
    void rotateWithStaticOrient(double angle, char axis);

    /*!
     * @brief Get the Mid Point object
     * 
     * @return vector3D  center point
     */
    vector3D getMidPoint()const  { return this->_midPoint; }

    /*!
     * @brief Get the Vertex object
     * 
     * @param[in] i - index if vertex
     * @return vector3D - value of vertex
     */
    vector3D getVertex(int i)const { return this->_vertexes[i]; }

    /*!
     * @brief Get the Orientation object
     * 
     * @return Matrix3x3 orientation matrix
     */
    Matrix3x3 getOrientation()const { return this->_orientMatrix; }

    /*!
     * @brief Construct a new Geometric Obj object
     * 
     */
    GeometricObj();
    /*!
     * @brief Construct a new Geometric Obj object
     * 
     * @param a - number pf vertexex
     */
    GeometricObj(int a);
    /*!
     * @brief Destroy the Geometric Obj object
     * 
     */
    virtual ~GeometricObj(){};

    /*!
     * @brief Virtual method. Write to file.
     * 
     * @return true - succeded
     * @return false - failed
     */
    virtual bool writeToFile(const std::string& ) = 0;
};


#endif //GEOMMETRIC_OBJ_HPP