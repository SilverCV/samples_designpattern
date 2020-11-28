#include <iostream>

class Strategy{
public:
  Strategy(){}
  virtual ~Strategy(){}
  virtual void DoAlgorithm() = 0;
};
class ConcreteStrategyA : public Strategy{
public:
  void DoAlgorithm() {
    std::cout << "strategy A" << std::endl;
  }
};
class ConcreteStrategyB : public Strategy{
public:
  void DoAlgorithm() {
    std::cout << "strategy B" << std::endl;
  }
};
class ConcreteStrategyC : public Strategy{
public:
  void DoAlgorithm() {
    std::cout << "strategy C" << std::endl;
  }
};
class Context{
public:
  void Operation(Strategy& theStrategy){
    theStrategy.DoAlgorithm();
  }
};
int main(int argc,char *argv[])
{
  Context x;
  ConcreteStrategyA a;
  ConcreteStrategyB b;
  ConcreteStrategyC c;
  x.Operation(a);
  x.Operation(b);
  x.Operation(c);
  return 0;
}