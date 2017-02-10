#include "QList.h"

// Constructor
template<class T>
QList<T>::QList()
{
  len = 0;
  start = NULL;
  end = NULL;
}

// Destructor
template<class T>
QList<T>::~QList()
{
  clear();
}

// Push at front
template<class T>
void QList<T>::push_front(const T i)
{
  node *tmp = new node;
  tmp->item = i;
  tmp->next = NULL;
  tmp->prev = NULL;

  if(start==NULL) // If list is empty
  {
    start = tmp;
    end = tmp;
  }
  else // Insert at start
  {
    tmp->next = start;
    start->prev = tmp;
    start = tmp;
  }
  len++; // Increase size counter
}

// Push at back
template<class T>
void QList<T>::push_back(const T i)
{
  node *tmp = new node;
  tmp->item = i;
  tmp->next = NULL;
  tmp->prev = NULL;

  if(end==NULL) // If list is empty
  {
    start = tmp;
    end = tmp;
  }
  else // Insert at the end
  {
    tmp->prev = end;
    end->next = tmp;
    end = tmp;
  }
  len++; // Increase size counter
}

// Pop from front
template<class T>
void QList<T>::pop_front()
{
  if(start!=NULL)
  {
    node *tmp = start;
    start = start->next;
    if(start!=NULL) // Re-link next item to NULL
      start->prev = NULL;
    else // List became empty so we need to clear end
      end = NULL;
    delete tmp;
    len--; // Decrease counter
  }
}

// Pop from back
template<class T>
void QList<T>::pop_back()
{
  if(end!=NULL)
  {
    node *tmp = end;
    end = end->prev;
    if(end!=NULL) //Re-link previous item to NULL
      end->next = NULL;
    else // List became empty so we need to clear start
      start = NULL;
    len--; // Decrease counter
  }
}

// Get item from front
template<class T>
T QList<T>::front()
{
  if(start!=NULL)
    return start->item;
  //TODO: Catch error when list is empty
}

//Get item from back
template<class T>
T QList<T>::back()
{
  if(end!=NULL)
    return end->item;
  //TODO: Catch error when list is empty
}

// Get size
template<class T>
int QList<T>::size()
{
  return this->len;
}

// Clear list
template<class T>
void QList<T>::clear()
{
  node *tmp = start;
  while(start!=NULL)
  {
    tmp = start;
    start = start->next;
    delete tmp;
    len--; // Decrease counter
  }
  end = NULL;
}
template<class T>
void QList<T>::clear(int index)
{
  node *tmp = start;
  for(int i=0;i<=index&&tmp!=NULL;i++)
  {
    if(i==index)
    {
      if(tmp->prev!=NULL)
        tmp->prev->next = tmp->next;
      else
        start = tmp->next;

      if(tmp->next!=NULL)
        tmp->next->prev = tmp->prev;
      else
        end = tmp->prev;

      len--; // Decrease counter
      break;
    }
  }
}

// Get at index
template<class T>
T QList<T>::get(int index)
{
  node *tmp = start;
  for(int i=0;i<=index&&tmp!=NULL;i++)
  {
    if(i==index)
      return tmp->item;
    else
      tmp=tmp->next;
  }
  //TODO: Catch error when index is out of range
}

template<class T>
T QList<T>::at(int index)
{
  node *tmp = start;
  for(int i=0;i<=index&&tmp!=NULL;i++)
  {
    if(i==index)
      return tmp->item;
    else
      tmp=tmp->next;
  }
  return T(); // Return default value
}

// Get length
template<class T>
int QList<T>::length()
{
  return this->len;
}

// Get index of value
template<class T>
int QList<T>::indexOf(T val)
{
  for(int i=0;i<this->size();i++)
    if(this->at(i) == val)
      return i;
  return -1;
}
