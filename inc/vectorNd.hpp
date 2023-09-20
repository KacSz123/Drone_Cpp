/*!
 * @file vectorNd.hpp
 * @author {Kacper Szczepanowski} ({kacperszcz159@gmail.com})
 * @brief File contains template class VectorNd.
 * @version 0.9
 * @date 2023-06-7
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>

/*!
 * @brief Exception occured with wrong Size of vector.
 * 
 */
struct VectorConstructorException{};

/*!
 * @brief N-size table (vector) of specific type.
 * 
 * Template of vector of  N _coordinates. Object contains N-size table with methods.
 * @tparam T  Type of vector. 
 * @tparam Size Size of vector.
 */
template <typename T, unsigned int Size>
class VectorNd
{
private:
    /*!
     * @brief Table of _coordinates
     * 
     * Table of \e Size coordinates \e T type.
     */
    T _coordinates[Size];

    /*!
    * @brief Counter of all created objects.
    * 
    * Value increments when new VectorNd object is created. Value decrements 
    * when  VectorNd object is destroyed.
    */
    static uint _allVectorCounter;

    /*!
    * @brief Counter of existing  objects.
    * 
    * Value increments when new VectorNd object is created. 
    */
    static uint _existingVectorCounter;
public:
    /*!
     * @brief Construct a new Vector Nd object
     * 
     * Default/non-parametric Constructor. Initialize table \e _coordinates 
     * with zero of the appropriate type.
     */
    VectorNd();

    /*!
     * @brief Construct a new VectorNd object
     * 
     * Constructor intended for creating objects of VectorNd< \e double, \e 3 >.
     * \see vector3D  
     * @param[in] x - x value
     * @param[in] y - y value
     * @param[in] z - z value
     */
    VectorNd(double x, double y, double z);
    /*!
     * @brief Destroy the VectorNd object
     * 
     * Decrements number of existing
     */
    ~VectorNd(){--_existingVectorCounter;}

    /*!
     * @brief Copy construct of VectorNd
     * 
     * Creates new object based on another.
     * 
     * @param[in] v - basic vector
     */
    VectorNd(const VectorNd<T, Size> &v) //: VectorNd{v.getCoord(0), v.getCoord(1),v.getCoord(2)}
    {
        _allVectorCounter++;
        _existingVectorCounter++;
        for (uint i = 0; i < Size; ++i)
            _coordinates[i] = v[i];
    }

    /*!
     * @brief Set the _coordinate value.
     * 
     *  Method intended for \see vector3D, setting values of _coordinates.
     * @param[in] x - value of x coord
     * @param[in] y - value of y coord
     * @param[in] z - value of z coord
     */
    void setCoords(double x, double y, double z)
    {
        this->_coordinates[0] = x;
        this->_coordinates[1] = y;
        this->_coordinates[2] = z;
        if(Size>3)
        {
            for(uint i=3; i<Size; ++i)
            this->_coordinates[i]=0;
        }
        // if(Size<3)
    };  
    /*!
     * @brief Set _coordinates value of specific index.
     * 
     * @param[in] i - index of  _coordinates.
     * @param[in] val - value to insert.
     */
    void setCoord(int const i, const T val) { this->_coordinates[i] = val; };
    
    /*!
     * @brief Get the Coord object
     * 
     * Return one element of _coordinates with specific index.
     * @param[in] i 
     * @return T Value of coordinate. 
     */

    T getCoord(int i) const { return this->_coordinates[i]; };
    /*!
     * @brief Overload of operator \b []. 
     * 
     * Return value of specific element of table \see _coordinates.
     * @param[in] i - index of table \see _coordinates.
     * @return T& - value of specific coordinate.
     */
    T &operator[](int i) { return this->_coordinates[i]; };

    /*!
     * @brief Overload of operator \b []. 
     * 
     * Return value of specific element of table \see _coordinates.
     * @param[in] i - index of table \see _coordinates.
     * @return T& - value of specific coordinate.
     */
    T operator[](int i) const { return this->_coordinates[i]; };
    VectorNd<T, Size> &operator=(VectorNd<T, Size> v)
    {
        for (uint i = 0; i < Size; ++i)
            _coordinates[i] = v[i];
        return *this;
    }
    VectorNd<T, Size> operator=(VectorNd<T, Size> v) const
    {
        for (uint i = 0; i < Size; ++i)
            _coordinates[i] = v[i];
        return *this;
    }
/*!
 * @brief Shows values of counters.
 * 
 * Printing on std output values of \see _allVectorCounter and \see _existingVectorCounter.
 */
    static void printCounters()
    {
        std::cout << "No. of all created Vectors<>: " << _allVectorCounter << ";\n No. of existing Vectors<>: " << _existingVectorCounter << std::endl;
    }
};

template <typename T, unsigned int Size>
VectorNd<T, Size>::VectorNd()
{
    _allVectorCounter++;
    _existingVectorCounter++;
    for (uint i = 0; i < Size; ++i)
        _coordinates[i] = 0;
}
template <typename T, unsigned int Size>
VectorNd<T, Size>::VectorNd(double x, double y, double z)
{
    _allVectorCounter++;
    _existingVectorCounter++;
    if (Size == 3)
    {
        this->_coordinates[0] = x;
        this->_coordinates[1] = y;
        this->_coordinates[2] = z;
    }
    else if (Size < 3)
        throw VectorConstructorException{};
    else
    {
        this->_coordinates[0] = x;
        this->_coordinates[1] = y;
        this->_coordinates[2] = z;
        for (uint i = 3; i < Size; ++i)
            this->_coordinates[i] = 0;
        std::cout << "Vector is bigger than 3. The rest of _coordinates equal 0\n";
    }
}

/*!
 * @brief Overload of operator \b + .
 * 
 * Overload of operator + for template class VectorNd.
 * @tparam T - Type  of VectorNd
 * @tparam Size - size of VectorNd
 * @param[in] vec1 - first component.
 * @param[in] vec2 - second component.
 * @return VectorNd<T, Size> Addition result.
 */
template <typename T, unsigned int Size>
VectorNd<T, Size> operator+(VectorNd<T, Size> vec1, VectorNd<T, Size> vec2)
{
    VectorNd<T, Size> wynik;
    for (int i = 0; i < int(Size); ++i)
        wynik.setCoord(i, vec1.getCoord(i) + vec2.getCoord(i));
    return wynik;
}

/*!
 * @brief Overload of operator \b - .
 * 
 * Overload of operator - for template class VectorNd.
 * @tparam T - Type  of VectorNd
 * @tparam Size - size of VectorNd
 * @param[in] vec1 - first component.
 * @param[in] vec2 - second component.
 * @return VectorNd<T, Size> Subtraction result.
 */
template <typename T, unsigned int Size>
VectorNd<T, Size> operator-(VectorNd<T, Size> vec1, VectorNd<T, Size> vec2)
{
    VectorNd<T, Size> wynik;
    for (int i = 0; i < int(Size); ++i)
        wynik.setCoord(i, vec1.getCoord(i) - vec2.getCoord(i));
    return wynik;
}

/*!
 * @brief Overload of operator \b << .
 * 
 * Overload of operator << for template class VectorNd. Intendend to 
 * print VectorNd on stdout with std::cout.
 * @tparam T - Type  of VectorNd
 * @tparam Size - size of VectorNd
 * @param[out] ostrm - Output stream.
 * @param[in] v - VectorNd.
 * @return std::ostream&  output ostream.
 */
template <typename T, unsigned int Size>
std::ostream &operator<<(std::ostream &ostrm, VectorNd<T, Size> v)
{
    for (int i = 0; i < int(Size); ++i)
        ostrm << v.getCoord(i) << " ";
    return ostrm;
}

/*!
 * @brief Overload of operator \b += .
 * 
 * Overload of operator += for template class VectorNd.
 * @tparam T - Type  of VectorNd
 * @tparam Size - size of VectorNd
 * @param[in] vec1 - first component.
 * @param[in] vec2 - second component.
 * @return VectorNd<T, Size> Addition result.
 */
template <typename T, unsigned int Size>
VectorNd<T, Size> &operator+=(VectorNd<T, Size> vec1, VectorNd<T, Size> vec2)
{
    for (int i = 0; i < int(Size); ++i)
        vec2.setCoord(i, vec1.getCoord(i) + vec2.getCoord(i));
    return vec2;
}


/*!
 * @brief Overload of operator \b -= .
 * 
 * Overload of operator -= for template class VectorNd.
 * @tparam T - Type  of VectorNd
 * @tparam Size - size of VectorNd
 * @param[in] vec1 - first component.
 * @param[in] vec2 - second component.
 * @return VectorNd<T, Size> Subtraction result.
 */
template <typename T, unsigned int Size>
VectorNd<T, Size> &operator-=(VectorNd<T, Size> &vec1, VectorNd<T, Size> vec2)
{
    for (int i = 0; i < int(Size); ++i)
        vec1.setCoord(i, vec1.getCoord(i) - vec2.getCoord(i));
    return vec1;
}

/*!
 * @brief Overload of operator \b * .
 * 
 * Overload of operator * for template class VectorNd.
 * Multiplication of a vector and constant.
 * @tparam T - Type  of VectorNd
 * @tparam Size - size of VectorNd
 * @param[in] vec1 - Vector - first component.
 * @param[in] a - Constant- second component.
 * @return VectorNd<T, Size> Multiplication result.
 */
template <typename T, unsigned int Size>
VectorNd<T, Size> &operator*(VectorNd<T, Size> vec1, double a)
{
    for (int i = 0; i < int(Size); ++i)
        vec1.setCoord(i, vec1.getCoord(i) * a);
    return vec1;
}
/*!
 * @brief Overload of operator \b * .
 * 
 * Overload of operator * for template class VectorNd.
 * Multiplication of  constant and vector.
 * @tparam T - Type  of VectorNd
 * @tparam Size - size of VectorNd
 * @param[in] a - Constant- first component.
 * @param[in] vec1 - Vector - second component.
 * @return VectorNd<T, Size> Multiplication result.
 */
template <typename T, unsigned int Size>
VectorNd<T, Size> &operator*(double a, VectorNd<T, Size> vec1)
{
    for (int i = 0; i < int(Size); ++i)
        vec1.setCoord(i, vec1.getCoord(i) * a);
    return vec1;
}

/*!
 * @brief Coordinates in three-dimensional space.
 * 
 * Type of VectorNd describing coordinates in three-dimensional space.
 */
typedef VectorNd<double, 3> vector3D;

template <typename T, unsigned int Size>
uint VectorNd<T, Size>::_allVectorCounter = 0;

template <typename T, unsigned int Size>
uint VectorNd<T, Size>::_existingVectorCounter = 0;

#endif // VECTOR_HPP