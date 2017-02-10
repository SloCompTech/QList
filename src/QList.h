/**
 * @file
 * @author  SloCompTech <SloCompTech@gmail.com>
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This class enables to use linked lists
 */

#ifndef LIB_SCP_QLIST
#define LIB_SCP_QLIST

#ifndef NULL
#define NULL 0
#endif

#include "Arduino.h"

template<class T>
class QList
{
private:
  typedef struct node
  {
    T item;
    node *next,*prev;
  }node;

  int len; //!< Size of list >
  node *start,*end; //!< Pointers to start and end >

public:
  QList(); //!< Class constructor >
  ~QList(); //!< Class destructor >

  void push_back(const T i); //!< Push item at the back of list >
  void push_front(const T i);//!< Push item at the front of the list >
  void pop_back(); //!< Pops item from back >
  void pop_front(); //!< Pops item from front >
  T front(); //!< get item from front >
  T back(); //!< get item from back >
  int size(); //!< Returns size of list >
  void clear(); //!< Clears list >
  void clear(int index); //!< Clears list >
  T get(int index); //!< Get item at given index >
  T at(int index); //!< Get item at given index >

  // Non - critical functions
  int length();
  int indexOf(T val);

};
#endif
