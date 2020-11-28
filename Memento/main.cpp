#include <iostream>
#include <string>
#include <vector>
class Memento{
public:
  Memento(){}
  Memento(std::string const& _state):_State(_state){}
  ~Memento(){}
  const std::string& GetState() const{
    return _State;
  }
  void SetState(std::string const& state){
    _State = state;
  }
private:
  std::string _State;
};
class Originator{
public:
  Originator(){}
  ~Originator(){}
  void ChangeState(std::string const& state){
    _state = state;
  }
  void SetMemento(Memento const& m){
    _state = m.GetState();
  }
  Memento CreateMemento() const{
    return Memento(_state);
  }
  void Output() const{
    std::cout << "current state is :" << _state << std::endl;
  }
private:
  std::string _state;
};

int main(int argc,char *argv[])
{
  Memento mem;
  Originator originator;
  originator.ChangeState("state 1");
  originator.Output();
  mem = originator.CreateMemento();
  originator.ChangeState("state 2");
  originator.Output();
  originator.SetMemento(mem);
  originator.Output();
  return 0;
}