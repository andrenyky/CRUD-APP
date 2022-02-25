//
// Created by andre on 3/29/2021.
//

#ifndef PROJECT_DYNAMICVECTOR_H
#define PROJECT_DYNAMICVECTOR_H

#include <iostream>
#include <string>
#include "Event.h"
using namespace std;


template<typename T>
class DynamicVector {
public:
    T *elems;
    int size;
    int capacity;

public:
    // default constructor for a DynamicVector
    DynamicVector(int capacity = 10);

    // copy constructor for a DynamicVector
    DynamicVector(const DynamicVector &v);

    ~DynamicVector();

    // assignment operator for a DynamicVector
    DynamicVector &operator=(const DynamicVector &v);

    /*
        Overloading the subscript operator
        Input: pos - a valid position within the vector.
        Output: a reference to the element o position pos.
    */
    T &operator[](int pos);

    // Adds an element to the current DynamicVector.
    void init();
    void add(T e);
    void removeElem(int pos);
    int getSize() const;

private:
    // Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
    void resize(double factor = 2);
};

template<typename T>
DynamicVector<T>::DynamicVector(int capacity) {
    this->size = 0;
    this->capacity = capacity;
    this->elems = new T[capacity];
}

template<typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T> &v) {
    this->capacity = v.capacity;
    this->size = v.size;
    this->elems = new T[this->capacity];
    for(int i=0;i<this->size;i++)
    {
        this->elems[i] = new T(v.elems[i]);
    }
}

template<typename T>
DynamicVector<T>::~DynamicVector() {
delete[] this->elems;
}

template<typename T>
DynamicVector<T> &DynamicVector<T>::operator=(const DynamicVector<T> &v) {
    /*we overload the operator =*/
    this->capacity = v.capacity;
    this->size = v.size;
    this->elems = new T[this->capacity];
    for(int i=0;i<this->size;i++)
    {
        this->elems[i] = new T(v.elems[i]);
    }
    return DynamicVector<T>(1);
}

template<typename T>
T &DynamicVector<T>::operator[](int pos) {
    if(pos<0 || pos>=this->size)
        throw "Wrong index";
    return this->elems[pos];
}

template<typename T>
void DynamicVector<T>::add(T e) {
    /*we add a new element in the dynamic vector*/
   if(this->capacity == this->size)
       this->resize();
   this->elems[this->size++] = e;
}

template<typename T>
void DynamicVector<T>::resize(double factor) {
    /*We multiply the current capacity by 2, we create a new temporary array in which we store
     * the current elements in this->elems, we delete the array elems and we se the temporary array
     * as the new one*/
    capacity = capacity*factor;
    T* tempArr = new T[capacity];
    for(int i=0;i<size;i++)
    {
        tempArr[i]=elems[i];
    }
    delete[] elems;
    elems = tempArr;
}

template<typename T>
int DynamicVector<T>::getSize() const {
    /* we return the size of the Dynamic Vector*/
    return this->size;
    return 0;
}

template <typename T>
void DynamicVector<T>::removeElem(int pos)
{ /* pos-the position of the element we want to remove, we remove the elements in this->elems at a given position */
    for(int i = pos; i <this->size; i ++)
        this->elems[i] = this->elems[i+1];
    this->size--;
}
template <typename T>
void DynamicVector<T>::init() {
    Event event1{"LP concert","I don't know ","20/05/2021",1000,"events.ro/event/lp-aduce-cea-mai-cool-petrecere-a-verii-pe-10-iulie-la-arenele-romane/"};
    Event event2{"Eematico","Activitati pentru copii","23/07/2021",70,"zilesinopti.ro/locuri/11311/eematico"};
    Event event3{"Star Wars","SF Movie","10/05/2021",300,"zilesinopti.ro/locuri/7077/cine-globe"};
    Event event4{"Moroi","Digital Theatre","10/06/2021",500,"zilesinopti.ro/evenimente/54834/moroi-scena-digitala-tnrs"};
    Event event5{"Autobahn","Digital Theatre","11/06/2021",642,"zilesinopti.ro/evenimente/54836/autobahn-scena-digitala-tnrs"};
    Event event6{"Fragment.Experinta restaurarii","Exhibition","11/03/2022",100,"zilesinopti.ro/evenimente/55300/fragment-experienta-restaurarii"};
    Event event7{"Mozartinno","Workshop","23/07/2021",250,"zilesinopti.ro/locuri/11168/mozartinno"};
    Event event8{"Art exhibition","Digital art","12/03/2022",400,"zilesinopti.ro/locuri/303/115-galerie-de-arta-digitala"};
    Event event9{"418 Contemporary Art Gallery","Interesting","13/02/2021",50,"zilesinopti.ro/locuri/304/418-contemporary-art-gallery"};
    Event event10{"Aiuart","Contemporary art","27/11/2021",200,"zilesinopti.ro/locuri/4444/aiurart"};
    this->add(event1);
    this->add(event2);
    this->add(event3);
    this->add(event4);
    this->add(event5);
    this->add(event6);
    this->add(event7);
    this->add(event8);
    this->add(event9);
    this->add(event10);


}
#endif //PROJECT_DYNAMICVECTOR_H
