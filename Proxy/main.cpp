#include <iostream>
class Subject{
public:
  virtual ~Subject() {}
  virtual void Operate() = 0;

protected:
  Subject(){}
};
class RealSubject : public Subject{
public:
  RealSubject(){}
  ~RealSubject(){}
  void Operate() override {
    std::cout << " I am real subject" << std::endl;
  }
};
class Proxy : public Subject{
public:
  Proxy() : _sub(nullptr){}
  ~Proxy(){}
  void Operate() override {
    if (_sub == nullptr){
      _sub = new RealSubject;
    }
    _sub->Operate();
  }
private:
  Subject *_sub;
};
int main(int argc,char *argv[])
{
  Proxy p;
  p.Operate();
  return 0;
}