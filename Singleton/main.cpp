#include <iostream>
class Singleton{
public:
  static Singleton* getInstance();
  void Run(){
    std::cout << "test " << std::endl;
  }
private:
  Singleton(){}
  ~Singleton(){}
  static Singleton *_instance;
};
Singleton *Singleton::_instance = 0;
Singleton* Singleton::getInstance() {
  if (_instance == nullptr){
    _instance = new Singleton();
  }
  return  _instance;
}
int main() {
  Singleton *instance = Singleton::getInstance();
  instance->Run();
  return 0;
}
