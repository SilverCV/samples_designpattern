#include <iostream>

class Subsystem1 {
public:
  void Scanner()  {
    std::cout << " subsystem 1" << std::endl;
  }
};
class Subsystem2{
public:
  void Scanner(){
    std::cout << " subsystem 2" << std::endl;
  }
};
class Subsystem3{
public:
  void Linker() {
    std::cout << " subsystem 3" << std::endl;
  }
};
class Facade{
public:
  void Method(){
    _Subsystem1.Scanner();
    _Subsystem2.Scanner();
    _Subsystem3.Linker();
  }
private:
  Subsystem1 _Subsystem1;
  Subsystem2 _Subsystem2;
  Subsystem3 _Subsystem3;
};
int main(int argc,char* argv[])
{
  Facade test;
  test.Method();
  return 0;
}