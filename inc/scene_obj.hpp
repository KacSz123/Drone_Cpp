#ifndef SCENE_OBJ_HPP
#define SCENE_OBJ_HPP


#include<vector>
#include<cmath>

#include"vectorNd.hpp"
#include<cmath>
#include<memory>


/*!
 * @brief Model of SceneObj. 
 * 
 * Allows to compare position with another objects of that, and child
 * classes. Approximate object with suitable circle (for XY plane), and height (in Z axis).
 */
class SceneObj
{
private:
protected:
    /*!
     * @brief Counter of all created objects
     * 
     */
    static uint _allSceneObjectCounter;

    /*!
     * @brief Counter of existing  objects
     * 
     */
    static uint _existingSceneObjectCounter;

    /*!
     * @brief Radius of  safe space. 
     * 
     * Approximation object with circle in \e XY \e plane.
     */
    double _circleRadius;


    /*!
     * @brief Value of safe space. 
     * 
     *  Value of safe space in \e Z axis. 
     */
    double _heightRange;

    /*!
     * @brief Middle of object.
     * 
     * The point is a middle of a approximation circle and height.
     */
    vector3D _position;
public:
/*!
 * @brief Construct a new SceneObj object
 * 
 * Non-parametric constructor.
 */
    SceneObj();
    
    /*!
     * @brief Copy construct a new SceneObj object
     * 
     * Copy constructor for Scene object.
     * @param o - basic object.
     */
    SceneObj(const SceneObj& o)
    {
        _circleRadius = o.getCircleRadius();
        _heightRange = o.getHeight();
        _position = o.getPosition();
    }
    /*!
     * @brief Destroy the SceneObj object
     * 
     */
    ~SceneObj();

    /*!
     * @brief Get the Height object
     * 
     * @return double value.
     */
    double getHeight()const{return _heightRange;}
    
    /*!
     * @brief Get the Position 
     * 
     * @return vector3D - Position.
     */
    vector3D getPosition()const{return _position;}

    /*!
     * @brief Get the _circleRadius object
     * 
     * @return double - _circleRadius.
     */
    double getCircleRadius()const {return _circleRadius;}
    
    /*!
     * @brief Set the _height object
     * 
     * @param a -double value of border height.
     */
    void setHeight(const double &a){_heightRange=a;}

    /*!
     * @brief Set the _position of object.
     * 
     * @param[in] v - vector3D. 
     */
    void setPosition(const vector3D&v) { _position=v;}

    /*!
     * @brief Set the _circleRadius object.
     * 
     * @param[in] a - value of radius.
     */
    void setCircleRadius(const double &a) { _circleRadius=a;}

    /*!
     * @brief Print counters on stdout.
     * 
     * Static method controlling value of \see _allSceneObjectCounter and \see _existingSceneObjectCounter.
     * 
     */
    static void printCounters()
    {
        std::cout << "No. of all created SceneObj<>: " << _allSceneObjectCounter
         << ";\n No. of existing SceneObj<>: " << _existingSceneObjectCounter << std::endl;
    }

     /*!
      * @brief Checking for collision between 2 objects.
      * 
      * Returns \e true if collision detected; \e false if not.
      * @param[in] anotherObj - \b shared_ptr to another object of SceneOb.
      * @return true - collision detected.
      * @return false - not detected.
      */
     bool ifDetectedCollision( std::shared_ptr<SceneObj> anotherObj)const;

};



#endif //SCENE_OBJ_HPP