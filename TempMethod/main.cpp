#include <iostream>
class Application{
public:
  Application(){}
  virtual ~Application(){}
  void Run(){
    Step1();
    Step2();
    Step3();
    Step4();
  }
  virtual void Step1() {};
  void Step2(){
    std::cout << "must be step 2" << std::endl;
  }
  virtual void Step3() {};
  void Step4(){
    std::cout << "must call step4" << std::endl;
  }
};
class Document : public Application {
public:
  void Step1() override{
    std::cout << "temp method 1" << std::endl;
  };
  void Step3() override{
    std::cout << "temp method 3" << std::endl;
  };
};
int main() {
  Document doc;
  doc.Run();
  return 0;
}
