#include <iostream>
class Component{
public:
  Component(){}
  virtual ~Component(){}
  virtual void Operation(){}
};

class ConcreteComponent : public Component{
public:
  void Operation() override {
    std::cout << "I am concrete operation" << std::endl;
  }
};

class Decorator : public Component{
public:
  virtual void Operation(){
    _component->Operation();
  }

protected:
  Component* _component;
};

class ConcreteDecoratorA : public Decorator{
public:
  ConcreteDecoratorA(Component* com){
    _component = com;
  }
  void Operation(){
      AddBehavior();
    Decorator::Operation();
  }

private:
  void AddBehavior(){
    std::cout << " I am a decorator" << std::endl;
  }
};

int main(int argc,char * argv[]){
  Component *component = new ConcreteComponent;
  Component* A = new ConcreteDecoratorA(component);
  A->Operation();
  delete component;
  delete A;
  return 0;
}
