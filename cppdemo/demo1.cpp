#include<bits/stdc++.h>

using namespace std;

class Base{
  public:
  void fun1() {this->fun2();}
  virtual void fun2() {cout << "Base::fun2()" << endl;}
};

class Derived:public Base{
public:
  virtual void fun2() {cout << "Derived:func2()" << endl;}
};


int main(){

  Derived d;
  Base * pBase = & d;
  pBase->fun1(); // Derived:func2()

  return 0;
}