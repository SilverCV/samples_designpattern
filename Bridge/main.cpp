#include <iostream>
class Implementor{
public:
  virtual ~Implementor(){}
  virtual void Operation() = 0;
};

class ConcreteImplementorA : public Implementor{
public:
  void Operation() override {
    std::cout << "concrete implement algorithm A" << std::endl;
  }
};

class ConcreteImplementorB : public Implementor{
public:
  void Operation() override {
    std::cout << "concrete implement algorithm B" << std::endl;
  }
};
class Abstraction{
public:
  virtual ~Abstraction(){}
  virtual void Operation() = 0;
protected:
  Implementor *_implementor;
};

class RefindedAbstraction : public Abstraction{
public:
  RefindedAbstraction(Implementor *impl) {
    _implementor = impl;
  }
  ~RefindedAbstraction(){}
  void Operation() override {
    _implementor->Operation();
  }
};

int main(int argc,char *argv[])
{
  ConcreteImplementorB B;
  RefindedAbstraction refindedAbstraction(&B);
  refindedAbstraction.Operation();
  return 0;
}