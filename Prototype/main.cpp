#include <iostream>
class Prototype{
public:
  virtual Prototype* Clone() = 0;
  virtual void Run() = 0;
};

class ConcretePrototype : public Prototype{
public:
  ConcretePrototype(){}
  ConcretePrototype(const ConcretePrototype& rhs){}
  ~ConcretePrototype(){}
  Prototype* Clone() override { return new ConcretePrototype(*this);
  }
  void Run() override {
    std::cout << " test " << std::endl;
  }
};
class Client{
public:
  Client(){
    _prototype = new ConcretePrototype;
  }
~Client(){}
  void Test(){
    Prototype* p2 = _prototype->Clone();
    p2->Run();
  }
private:
Prototype *_prototype;
};
int main(int argc,char *argv[])
{
  Client c;
  c.Test();
  return 0;
}