#include <iostream>
class Element;

class Visitor{
public:
  virtual ~Visitor(){}
  virtual void visitElementA(Element *e) = 0;
  virtual void visitElementB(Element *e) = 0;
};
class Element{
public:
  virtual ~Element(){}
  virtual void Accept(Visitor& visitor) = 0;
};
class ConcreteElementA : public Element{
public:
  void Accept(Visitor& visitor){
    visitor.visitElementA(this);
  }
};

class ConcreteElementB: public Element{
public:
  void Accept(Visitor& visitor) override {
    visitor.visitElementB(this);
  }
};

class VisitorA : public Visitor{
public:
  void visitElementA(Element *e)  {
    std::cout << "visitor A process element A" << std::endl;
  }
  void visitElementB(Element *e)  {
    std::cout << "visitor A process element B" << std::endl;
  }
};
class VisitorB : public Visitor{
public:
  void visitElementA(Element *e)  {
    std::cout << "visitor B process element A" << std::endl;
  }
  void visitElementB(Element *e)  {
    std::cout << "visitor B process element B" << std::endl;
  }
};
int main(int argc,char *argv[]) {
  ConcreteElementA a;
  VisitorA va;
  a.Accept(va);
  return 0;
}
