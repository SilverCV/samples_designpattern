#include <iostream>
#include <vector>
#include <string>
class Command{
public:
  virtual ~Command(){}
  virtual void Execute() = 0;
protected:
  Command(){}
};
class ConcreteCommand : public Command{
public:
  ConcreteCommand(){}
  ConcreteCommand(const std::string& name):_name(name){}
  ~ConcreteCommand(){}
  void Execute(){
    std::cout << _name << std::endl;
  }
private:
  std::string _name;
};
class Invoker{
public:
  Invoker(){}
  ~Invoker(){}
  void addCommand(Command *c){
    _commnads.emplace_back(c);
  }
  void Run(){
    for (auto c : _commnads) {
      c->Execute();
    }
  }
private:
  std::vector<Command*> _commnads;
};
class Receiver{
public:
  Receiver(){}
  Receiver(Invoker const& ivk):_invoker(ivk){}
  ~Receiver(){}
  void Action(){
    _invoker.Run();
  }
private:
  Invoker _invoker;
};
int main(int argc,char **argv)
{
  ConcreteCommand open("open");
  ConcreteCommand close("close");
  Invoker invoker;
  invoker.addCommand(&open);
  invoker.addCommand(&close);
  Receiver receiver(invoker);
  receiver.Action();
  return 0;
}