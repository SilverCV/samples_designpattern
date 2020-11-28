#include <iostream>
class IState{
public:
  virtual void Handle() = 0;
};
class Context{
public:
  void SetState(IState *s){
    _state = s;
  }
  void Request(){
    _state->Handle();
  }
private:
  IState *_state;
};
class FlyState : public IState{
public:
  void Handle(){
    std::cout << " in flying " << std::endl;
  }
};
class RunState : public IState{
public:
  void Handle(){
    std::cout << " in running " << std::endl;
  }
};
int main(int argc,char *argv[])
{
  Context c;
  IState *fly = new FlyState;
  IState *Run = new RunState;
  c.SetState(fly);
  c.Request();
  c.SetState(Run);
  c.Request();
  delete Run;
  delete fly;
  return 0;
}