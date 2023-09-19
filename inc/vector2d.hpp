#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
// #include <cstdlib>
struct VectorConstructorException
{
};

template <typename T, unsigned int Size>
class Vector2d
{
private:
    T coordinates[Size];

public:
    static uint _allVectorCounter;
    static uint _existingVectorCounter;
    Vector2d();
    Vector2d(double, double, double);
    ~Vector2d()
    {
        // --_allVectorCounter;
        --_existingVectorCounter;
    }


    Vector2d(const Vector2d<T, Size> &v) //: Vector2d{v.getCoord(0), v.getCoord(1),v.getCoord(2)}
    {

        _allVectorCounter++;
        _existingVectorCounter++;
        for (uint i = 0; i < Size; ++i)
            coordinates[i] = v[i];
    }
    void setCoords(double x, double y, double z)
    {
        this->coordinates[0] = x;
        this->coordinates[1] = y;
        this->coordinates[2] = z;
    };
    void setCoord(int i, T val) { this->coordinates[i] = val; };
    inline T getCoord(int i) const { return this->coordinates[i]; };
    inline double &operator[](int i) { return this->coordinates[i]; };
    inline double operator[](int i) const { return this->coordinates[i]; };
    Vector2d<T, Size> &operator=(Vector2d<T, Size> v)
    {
        for (uint i = 0; i < Size; ++i)
            coordinates[i] = v[i];
        return *this;
    }
    Vector2d<T, Size> operator=(Vector2d<T, Size> v) const
    {
        // _allVectorCounter++;
        // _existingVectorCounter++;
        for (uint i = 0; i < Size; ++i)
            coordinates[i] = v[i];
        return *this;
    }

    static void printCounters()
    {
        std::cout << "No. of all created Vectors<>: " << _allVectorCounter << ";\n No. of existing Vectors<>: " << _existingVectorCounter << std::endl;
    }
};

template <typename T, unsigned int Size>
Vector2d<T, Size>::Vector2d()
{
    // _allVectorCounter++;
    // _existingVectorCounter++;
    _allVectorCounter++;
    _existingVectorCounter++;
    for (uint i = 0; i < Size; ++i)
        coordinates[i] = 0;
}
template <typename T, unsigned int Size>
Vector2d<T, Size>::Vector2d(double x, double y, double z)
{
    _allVectorCounter++;
    _existingVectorCounter++;
    if (Size == 3)
    {
        this->coordinates[0] = x;
        this->coordinates[1] = y;
        this->coordinates[2] = z;
    }
    else if (Size < 3)
        throw VectorConstructorException{};
    else
    {
        this->coordinates[0] = x;
        this->coordinates[1] = y;
        this->coordinates[2] = z;
        for (uint i = 3; i < Size; ++i)
            this->coordinates[i] = 0;
        std::cout << "Vector is bigger than 3. The rest of coordinates equal 0\n";
    }
}
template <typename T, unsigned int Size>
Vector2d<T, Size> operator+(Vector2d<T, Size> vec1, Vector2d<T, Size> vec2)
{
    Vector2d<T, Size> wynik;
    for (int i = 0; i < int(Size); ++i)
        wynik.setCoord(i, vec1.getCoord(i) + vec2.getCoord(i));
    return wynik;
}

template <typename T, unsigned int Size>
Vector2d<T, Size> operator-(Vector2d<T, Size> vec1, Vector2d<T, Size> vec2)
{
    Vector2d<T, Size> wynik;
    for (int i = 0; i < int(Size); ++i)
        wynik.setCoord(i, vec1.getCoord(i) - vec2.getCoord(i));
    return wynik;
}
template <typename T, unsigned int Size>
std::ostream &operator<<(std::ostream &ostrm, Vector2d<T, Size> v)
{
    for (int i = 0; i < int(Size); ++i)
        ostrm << v.getCoord(i) << " ";
    return ostrm;
}
template <typename T, unsigned int Size>
Vector2d<T, Size> &operator+=(Vector2d<T, Size> vec1, Vector2d<T, Size> vec2)
{
    for (int i = 0; i < int(Size); ++i)
        vec2.setCoord(i, vec1.getCoord(i) + vec2.getCoord(i));
    return vec2;
}

template <typename T, unsigned int Size>
Vector2d<T, Size> &operator-=(Vector2d<T, Size> &vec1, Vector2d<T, Size> vec2)
{
    for (int i = 0; i < int(Size); ++i)
        vec1.setCoord(i, vec1.getCoord(i) - vec2.getCoord(i));
    return vec1;
}

template <typename T, unsigned int Size>
Vector2d<T, Size> &operator*(Vector2d<T, Size> vec1, double a)
{
    for (int i = 0; i < int(Size); ++i)
        vec1.setCoord(i, vec1.getCoord(i) * a);
    return vec1;
}

template <typename T, unsigned int Size>
Vector2d<T, Size> &operator*(double a, Vector2d<T, Size> vec1)
{
    for (int i = 0; i < int(Size); ++i)
        vec1.setCoord(i, vec1.getCoord(i) * a);
    return vec1;
}

////
typedef Vector2d<double, 3> vector3D;

template <typename T, unsigned int Size>
uint Vector2d<T, Size>::_allVectorCounter = 0;

template <typename T, unsigned int Size>
uint Vector2d<T, Size>::_existingVectorCounter = 0;

#endif // VECTOR_HPP