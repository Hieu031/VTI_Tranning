#include <iostream>
#include "typeinfo"

using namespace std;

int main(){
   auto x = 100;
   auto y = 30.5f;
   auto z = '@';
   auto t = 1000000000000000;
   auto p = make_pair(10, 20);
   // auto l = 30.5d;
   cout << "Kieu du lieu cua x : " << typeid(x).name() << endl;
   cout << "Kieu du lieu cua y : " << typeid(y).name() << endl;
   cout << "Kieu du lieu cua z : " << typeid(z).name() << endl;
   cout << "Kieu du lieu cua t : " << typeid(t).name() << endl;
   cout << "Kieu du lieu cua p : " << typeid(p).name() << endl;
   // cout << "Kieu du lieu cua l : " << typeid(l).name() << endl;
   return 0;
}