#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
class Component{
public:
  virtual ~Component(){}
  virtual void Process() = 0;
  virtual void Add(Component *){}
  virtual void Remove(Component *){}
  Component *getChild(int){ return nullptr;}

protected:
  Component(){}
  Component(const std::string& name): _name(name){}
  std::string _name;
};

class Composite : public Component{
public:
  Composite(){}
  Composite(const std::string& name):Component(name){}
  ~Composite(){}
  void Process(){
    std::cout << "name : " << _name << std::endl;
    for (auto c : _component) {
      c->Process();
    }
  }
  void Add(Component *c){
    _component.emplace_back(c);
  }
  void Remove(Component *c){
    auto it = std::find(_component.begin(),_component.end(),c);
    if (it != _component.end()){
      Component *temp = *it;
      _component.erase(it);
      delete temp;
      temp = nullptr;
    }
  }
  Component *getChild(int index){
    if (index < 0 || index > _component.size()){
      return nullptr;
    }
    return _component[index];
  }
private:
  std::vector<Component *> _component;
};
class Leaf : public Component{
public:
  Leaf(){}
  Leaf(std::string const& name) :Component(name){}
  ~Leaf(){}

  void Process(){
    std::cout << "I am " << _name << std::endl;
  }
};
int main(int argc,char *argv[])
{
  Composite* root = new Composite("root");
  Composite* leftTree = new Composite("left tree");
  Composite* rightTree = new Composite("right tree");

  Leaf *leaf1 = new Leaf("left leaf 1");
  Leaf *leaf2 = new Leaf("right leaf 2");
  Leaf *leaf3 = new Leaf("left leaf 3");
  Leaf *leaf4 = new Leaf("right leaf 4");
  leftTree->Add(leaf1);
  leftTree->Add(leaf2);

  rightTree->Add(leaf3);
  rightTree->Add(leaf4);
  root->Add(leftTree);
  root->Add(rightTree);

  root->Process();

  leftTree->Remove(leaf1);
  leftTree->Remove(leaf2);
  rightTree->Remove(leaf3);
  rightTree->Remove(leaf4);
  root->Remove(rightTree);
  root->Remove(leftTree);
  delete root;
  return 0;
}