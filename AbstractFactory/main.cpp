#include <iostream>
//抽象产品 手机
class AbstractPhone{
public:
  virtual ~AbstractPhone(){}
  virtual void Phone() = 0;
};
//具体产品
class Iphone : public AbstractPhone{
public:
  void Phone(){
    std::cout << " iphone " << std::endl;
  }
};
class XiaomiPhone: public AbstractPhone{
public:
  void Phone(){
    std::cout << " xiao mi " << std::endl;
  }
};
//抽象产品 personal computer
class AbstractPC{
public:
  virtual ~AbstractPC(){}
  virtual void PC() = 0;
};
class MacOs : public AbstractPC{
public:
  void PC(){
    std::cout << " MACOS " << std::endl;
  }
};
class XiaomiPC: public AbstractPC{
public:
  void PC(){
    std::cout << " xiao mi pc" << std::endl;
  }
};
//抽象工厂
class AbstractFactory{
public:
  virtual ~AbstractFactory(){}
  virtual AbstractPhone* createPhone() = 0;
  virtual AbstractPC* createPC() = 0;
};
// apple
class Apple : public  AbstractFactory{
public:
  Apple(){
    _pc = NULL;
    _phone = NULL;
  }
  ~Apple(){}
  AbstractPhone *createPhone(){
    if (_phone == NULL){
      _phone = new Iphone;
    }
    return _phone;
  }
  AbstractPC *createPC(){
    if (_pc == NULL){
      _pc = new MacOs;
    }
    return _pc;
  }
private:
  AbstractPC *_pc;
AbstractPhone *_phone;
};
//小米
class XiaoMi : public  AbstractFactory{
public:
  XiaoMi(){
    _pc = NULL;
    _phone = NULL;
  }
  ~XiaoMi(){}
  AbstractPhone *createPhone(){
    if (_phone == NULL){
      _phone = new XiaomiPhone;
    }
    return _phone;
  }
  AbstractPC *createPC(){
    if (_pc == NULL){
      _pc = new XiaomiPC;
    }
    return _pc;
  }
private:
  AbstractPC *_pc;
  AbstractPhone *_phone;
};
//client
class Client{
public:
  void setFactory(AbstractFactory *factory){
    this->_factory = factory;
  }
  void test(){
    _pc = _factory->createPC();
    _phone = _factory->createPhone();
    _pc->PC();
    _phone->Phone();
  }
private:
  AbstractFactory *_factory;
  AbstractPC *_pc;
  AbstractPhone *_phone;
};
int main(int argc,char **argv)
{
  Client c;
  Apple *apple = new Apple;
  c.setFactory(apple);
  c.test();
  return 0;
}
