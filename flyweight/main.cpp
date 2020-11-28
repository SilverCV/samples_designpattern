#include <iostream>
#include <string>
#include <map>
class Flyweight{
public:
  virtual void Operation() = 0;
};
class ConcreteFlyweight : public Flyweight{
public:
  void Operation() override {
    std::cout << "flyweight" << std::endl;
  }
};

class FlyweightFactory{
public:
  Flyweight *GetFlyweight(std::string const& key){
    auto iterator = _flyweight.find(key);
    if (iterator != _flyweight.end()){
      return iterator->second;
    }else{
      _flyweight[key] = new ConcreteFlyweight;
      return _flyweight[key];
    }
  }
private:
  std::map<std::string,Flyweight*> _flyweight;
};
int main(int argc,char *argv[]){
  FlyweightFactory ff;
  Flyweight *flyweight = ff.GetFlyweight("test");
  flyweight->Operation();
  return 0;
}