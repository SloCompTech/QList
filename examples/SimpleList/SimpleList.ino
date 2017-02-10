/*
	Simple List

	This program shows basic usage of QList

	Created 30th November 2016
	By SloCompTech

	https://github.com/SloCompTech/QList

*/
#include "QList.h"
QList<String> myList;
void setup()
{
  Serial.begin(9600);
  myList.push_back("First"); // Add item at the back of the line
  myList.push_back("Second");
  myList.push_front("New first"); // Ad item at the front of the line
  Serial.println("Items:");
  // Go through items
  for(int i=0;i<myList.size();i++)
  {
    Serial.println(myList.at(i));
  }
  myList.pop_back(); // Remove item at the back of the line
  Serial.println("Items:");
  for(int i=0;i<myList.size();i++)
  {
    Serial.println(myList.at(i));
  }
  myList.clear(); // Clear all items in table
}
void loop()
{

}
