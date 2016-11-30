/*
	Simple List

	This program shows basic usage of QList

	Created 30th November 2016
	By SloCompTech

	https://github.com/SloCompTech/QList

*/
QList<String> myList;
void setup()
{
  Serial.begin(9600);
  myList.push_back("First");
  myList.push_back("Second");
  myList.push_front("New first");
  Serial.println("Items:");
  for(int i=0;i<myList.size();i++)
  {
    Serial.println(myList.at(i));
  }
  myList.pop_back();
  Serial.println("Items:");
  for(int i=0;i<myList.size();i++)
  {
    Serial.println(myList.at(i));
  }
  myList.clear();
}
void loop()
{

}
