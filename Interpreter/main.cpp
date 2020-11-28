#include <iostream>
#include <string>
using Context = std::string;
class AbsrtactExpression{
public:
  virtual ~AbsrtactExpression(){}
  virtual void Interpret(Context& c) = 0;
protected:
  AbsrtactExpression(){}
};
class TermnialExpression : public AbsrtactExpression{
public:
  TermnialExpression(){}
  ~TermnialExpression(){}
  void Interpret(Context& c){
    std::cout << "Terminaled" << std::endl;
  }
};
class NonterminalExpress : public AbsrtactExpression{
public:
  NonterminalExpress(){}
  NonterminalExpress(AbsrtactExpression* e): _exp(e){}
  ~NonterminalExpress(){}
  void Interpret(Context& c){
    _exp->Interpret(c);
  }
private:
  AbsrtactExpression *_exp;
};
class HExpression : public AbsrtactExpression{
public:
  void Interpret(Context& c){
    int pos = c.find_first_of('H');
    if (pos >= 0){
      std::cout << c[pos] << std::endl;
    }
  }
};
int main(int argc,char* argv[])
{
  Context s = "Hello";
  HExpression hexp;
  NonterminalExpress nonterminalExpress(&hexp);
  nonterminalExpress.Interpret(s);
  return 0;
}