#include <iostream>
class ITarget{
public:
  virtual ~ITarget(){}
  virtual void Process() = 0;

protected:
  ITarget(){}
};
class Adaptee{
public:
  void OldInterface(){
    std::cout << "exec " << std::endl;
  }
};
class Adapter : public  ITarget{
public:
  Adapter(Adaptee *_p){
    _adaptee = _p;
  }
  void Process(){
    _adaptee->OldInterface();
  }
private:
  Adaptee *_adaptee;
};
int main(int argc,char *argv[])
{
  Adaptee *_p = new Adaptee;
  ITarget *target = new Adapter(_p);
  target->Process();
  delete _p;
  delete target;
  return 0;
}