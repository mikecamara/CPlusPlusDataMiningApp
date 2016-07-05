
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
         * @brief  overload operator = for class vector
         *
         *
         * @return void
         */
        const Vector<elemType>& operator=(const Vector<elemType>&);

        /**
         * @brief  insert elements at the end of vector array
         *
         *
         * @return void
         */
        void insertEnd(const elemType&);

        /**
         * @brief  retrieve elements of the array at specific index
         *
         *
         * @return element of the array
         */
        elemType& retrieveAt(int index)
        {
            return list[index];
        }


    private:
        elemType *list; /// Pointer generic for my list of elements
        int length; /// length of the array
        int maxSize; /// maximum size of the array

        /**
         * @brief  resize method of the array
         *
         * Everytime that the array reach its capacity I double the size
         *
         *
         * @return void
         */
        void resize(int index); ///
};

        /**
         * @brief  insert elements at the end of vector array
         *
         *
         * @return void
         */
        template <class elemType>
        void Vector<elemType>::insertEnd(const elemType& item)
        {
            if(this->length >= this->maxSize)
            {
                // Resize class if list is full
                resize(length * 2);
            }
                this->list[this->length] = item;
                this->length++;
        }

        /**
         * @brief  overload operator = for class vector
         *
         *
         * @return void
         */
        template <class elemType>
        const Vector<elemType>& Vector<elemType>::operator =(const Vector<elemType>& other)
        {
            if(this != &other)
            {
                delete [] list;
                maxSize = other.maxSize;
                length = other.length;
                list = new elemType[maxSize];

                for (int i = 0; i < length; i++)
                {
                    list[i] = other.list[i];
                }
            }
            return *this;
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
                list = new elemType[maxSize];
            }
        }

        /**
         * @brief  constructor for Vector class
         *
         * Default constructor, that gets any type as parameter
         *
         * @return Vector
         */
        template <class elemType>
        Vector<elemType>::Vector(const Vector<elemType>& other)
        {
            maxSize = other.maxSize;
            length = other.length;
            list = new elemType[maxSize];

            for(int i = 0; i < length; i++)
            {
                list[i] = other.list[i];
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
            delete [] list;
        }

        /**
         * @brief  resize method of the array
         *
         * Everytime that the array reach its capacity I double the size
         *
         *
         * @return void
         */
        template <class elemType>
        void Vector<elemType>::resize(int newMaxSize)
        {
            elemType * newList = new elemType[newMaxSize];
            maxSize = newMaxSize;

            for (int i = 0; i < length;i++)
            {
                newList[i] = list[i];
            }

            delete [] list;
            list = newList;

        }

#endif /* VECTOR_H */
