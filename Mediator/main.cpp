#include <iostream>
class Mediator;
class Person{
public:
  virtual void SetMediator(Mediator *m) = 0;
  virtual void SendMessage(Person *p) = 0;
  virtual void Receive() = 0;

protected:
  Mediator *_mediator;
};
class Mediator{
public:
  virtual void SetSender(Person *p) = 0;
  virtual void SetReceiver(Person *p) = 0;
  virtual void SendMessage(Person *p) = 0;
};
class Sender : public Person{
public:
  void SetMediator(Mediator *m){
    _mediator = m;
  }
  void SendMessage(Person *p){
    _mediator->SendMessage(p);
  }
  void Receive() {
    std::cout <<" Sender receive" << std::endl;
  }
};
class Receiver : public Person{
public:
  void SetMediator(Mediator *m){
    _mediator = m;
  }
  void SendMessage(Person *p){
    _mediator->SendMessage(p);
  }
  void Receive() {
    std::cout <<" Receiver receive" << std::endl;
  }
};
class Servicer : public Mediator{
public:
  virtual void SetSender(Person *p) {
    _sender = p;
  }
  virtual void SetReceiver(Person *p){
    _receiver = p;
  }
  virtual void SendMessage(Person *p){
    if (p == _sender){
      _sender->Receive();
    }else{
      _receiver->Receive();
    }
  }
private:
  Person *_sender;
  Person *_receiver;
};
int main(int argc,char *argv[]) {
  Person *s = new Sender;
  Person *r = new Receiver;
  Servicer *m = new Servicer;
  m->SetReceiver(r);
  m->SetSender(s);
  m->SendMessage(s);
  m->SendMessage(r);
  return 0;
}
