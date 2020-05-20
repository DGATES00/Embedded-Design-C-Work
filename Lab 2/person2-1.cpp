#include <iostream>
using namespace std;

class Person{
      //public:
      private:    
	    int age;
	    string name;
      public:
      static int count;
      Person(){
               age = 99;
               name = "";
               count++;
      }
      Person(int a, string n){
                 age = a;
                 name = n;
                 count++;
      }
      ~Person(){
                cout << "Destroying an obeject...!" << endl;
                count--;
                }
      void setAge(int a) {
           age = a;
      }
      int getAge();
     
};

int Person::getAge() {
    return age;
}

int Person::count = 0;

int main(){
	  Person p1;
    Person *p2 = new Person(50, "John");
    p1.setAge(20);
	  //p1.age = 20;
	  cout << p1.getAge() << endl;
    //cout << "count is " << p1.count << endl;
    cout << p2->getAge() << endl;
    delete p2;
    //Person pArray[30];
    Person *pArray;
    pArray = new Person[30];
    pArray[0].setAge(25);
    cout << pArray[0].getAge() << endl;
    cout << "count is " << pArray[12].count << endl;
    delete[] pArray;
    cout << "count is " << p1.count << endl;
}
