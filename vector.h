/**
 * @class Vector
 * @brief Vector class works as an Array that resize itself when is full
 *
 *
 *
 * The vector can make array objects of any type
 *
 * @author Mike Gomes
 * @version 01
 * @date 22/03/2016
 *
 * @todo Test again
 *
 */
#ifndef VECTOR_H
#define VECTOR_H


//------------------------------------------------------------------------------

#include <vector>
#include "metadata.h"

using namespace std;

//------------------------------------------------------------------------------

template <class elemType>
class Vector
{
public:
    /**
     * @brief  Default constructor for Vector class
     *
     * Default constructor, sets initial size for 2, but it resizes
     *
     * @return Vector
     */
    Vector(int size = 2);

    /**
     * @brief  constructor for Vector class
     *
     * Default constructor, that gets any type as parameter
     *
     * @return Vector
     */
    Vector(const Vector<elemType>&);

    /**
     * @brief  Default destructor Vector class
     *
     * @return void
     */
    ~Vector();

    /**
     * @brief  insert elements at the end of vector array
     *
     *
     * @return void
     */
    void insert(const elemType&);

    /**
     * @brief  retrieve elements of the array at specific index
     *
     *
     * @return element of the array
     */
    elemType& retrieve(unsigned int index)
    {
        return metadataVector.at(index);
    }

private:
    elemType *list; /// Pointer generic for my list of elements
    int length; /// length of the array
    int maxSize; /// maximum size of the array

    vector<Metadata> metadataVector;

    /**
     * @brief  resize method of the array
     *
     * Everytime that the array reach its capacity I double the size
     *
     *
     * @return void
     */

}; // end class declaration

template <class elemType>
void Vector<elemType>::insert(const elemType& item)
{
    metadataVector.push_back(item);
}

/**
 * @brief  constructor for Vector class
 *
 * Default constructor, that gets any type as parameter
 *
 * @return Vector
 */
template <class elemType>
Vector<elemType>::Vector(int size)
{
    if (size <= 0)
    {
        cout << "Array size must be positive, creating default size of 100." << endl;
        maxSize = 500;
    }
    else
    {
        maxSize = size;
        length = 0;
        metadataVector.resize(maxSize);
    }
}

/**
 * @brief  destructor for Vector class
 *
 * Default destructor
 *
 * @return Vector
 */
template <class elemType>
Vector<elemType>::~Vector()
{
    metadataVector.clear();
}

#endif /* VECTOR_H */
