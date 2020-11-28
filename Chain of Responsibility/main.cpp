#include <iostream>
enum class REQUEST{
  SEND,
  RECEIVE,
  CLOSE,
};
class Handler{
public:
  virtual ~Handler(){}
  virtual void HandleRequest(REQUEST) = 0;
protected:
  Handler():_successor(nullptr){}
  Handler(Handler *successor):_successor(successor){}
  Handler *_successor;
};
class SendHandler : public Handler{
public:
  SendHandler(){}
  SendHandler(Handler *_handler):Handler(_handler){}
  ~SendHandler(){}
  virtual void HandleRequest(REQUEST request){
    if (request == REQUEST::SEND){
      std::cout << " process send " << std::endl;
    }else if (_successor != nullptr){
      _successor->HandleRequest(request);
    }else{
      std::cout << "no handler" << std::endl;
    }
  }
};
class CloseHandler : public Handler{
public:
  CloseHandler(){}
  CloseHandler(Handler *_handler):Handler(_handler){}
  ~CloseHandler(){}
  virtual void HandleRequest(REQUEST request){
    if (request == REQUEST::CLOSE){
      std::cout << " process close " << std::endl;
    }else if (_successor != nullptr){
      _successor->HandleRequest(request);
    }else{
      std::cout << "no handler" << std::endl;
    }
  }
};
class ReceiveHandler : public Handler{
public:
  ReceiveHandler(){}
  ReceiveHandler(Handler *_handler):Handler(_handler){}
  ~ReceiveHandler(){}
  virtual void HandleRequest(REQUEST request){
    if (request == REQUEST::RECEIVE){
      std::cout << " process receive  " << std::endl;
    }else if (_successor != nullptr){
      _successor->HandleRequest(request);
    }else{
      std::cout << "no handler" << std::endl;
    }
  }
};
int main(int argc,char *argv[]) {
  Handler *h1 = new SendHandler(NULL);
  Handler *h2 = new ReceiveHandler(h1);
  Handler *h3 = new CloseHandler(h2);
  h3->HandleRequest(REQUEST::CLOSE);
  h2->HandleRequest(REQUEST::SEND);
  h3->HandleRequest(REQUEST::RECEIVE);
  delete h3;
  delete h2;
  delete h1;
  return 0;
}