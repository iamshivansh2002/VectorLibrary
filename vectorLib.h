//author : Divyam Makhaik

#ifndef Vector
#define Vector
#include<iostream>


//a class for dynamic array

template<class T>

class Vector
{

private:
    T *data ;
    int size ;

public :

    Vector()
    {
        data  = NULL;
        size = 0;
    }

    Vector(T x[], T n)
    {
        data  = new T[n];
        for(int i = 0 ; i  < n ; i++)
        {
            data[i] = x[i] ;
        }
        size = n ;
    }

// push_back function

    void Push_back(T item)
    {
        T *temp = new T[size + 1];
        for(int i = 0 ; i < size ; i++)
        {
            temp[i] = data[i];
        }
        temp[size] = item ;

        if(data != NULL)
        {
            delete [] data;
        }
        size++;
        data = temp ;
    }

// pop_back function

    void Pop_back()
    {
        if(size == 0)
        {
            std :: cout << "Empty" << "\n";
        }
        else
        {
            T *temp1 = new T[size];
            for(int i = 0 ; i < size - 1 ; i++)
            {
                temp1[i] = data[i];
            }
            // temp1[size] = item ;

            if(data != NULL)
            {
                delete [] data;
            }
            size--;
            data = temp1 ;
        }
    }

    // Assessing items form vector

    T &operator[] (T i )
    {
        return data[i];
    }

    // return size of vector 

    int Size()
    {
        return size ;
    }

    // display vector

    friend std ::  ostream &operator<< (std :: ostream &output, Vector<T> v)
    {
         output << "[ ";
        for(int i = 0 ; i < v.Size() ; i++)
        {
            if(i == v.Size() - 1)
                 output << v[i] << " " ;
            else
                 output << v[i] << " , " ;
        }
         output << "]" ;
        return  output ;
    }


    ~Vector()
    {
        if(data != NULL)
        {
            delete[] data ;
        }
    }
};

#endif 