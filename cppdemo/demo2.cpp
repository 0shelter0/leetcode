#include<iostream>

using namespace std;

class myclass{
  public:
  virtual void hello(){cout <<"hello from myclass" << endl;}
  virtual void bye(){cout<< "bye from myclass"<<endl;}
};

class son:public myclass{
public: //派生类中和基类中虚函数同名同参数表的函数，不加virtual也自动成为虚函数
void hello(){cout<<"hello from son"<< endl;}
son(){hello();}
~son(){bye();}
};

class grandson:public son{
  public:
  void hello(){cout<<"hello from grandson"<<endl;}
  void bye(){cout<<"bye from grandson"<< endl;}
  grandson(){cout<<"constructing grandson"<< endl;}
  ~grandson(){cout<<"destructing grandson"<< endl;}
};

int main(){
  grandson gson;
  son *pson;
  pson = &gson;
  pson->hello();

  return 0;
}