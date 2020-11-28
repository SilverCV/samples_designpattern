#include <iostream>
#include <string>
class House {
 public:
  House() {}
  House(const std::string& window, const std::string& door)
      : _window(window), _door(door) {}
  ~House() {}
  void setWindow(const std::string& window) { _window = window; }
  void setDoor(const std::string& door) { _door = door; }
  void Show(){
    std::cout << "the window is " << _window << std::endl;
    std::cout << "the door is " << _door << std::endl;
  }
 private:
  std::string _door;
  std::string _window;
};
class HouseBuilder {
 public:
  virtual ~HouseBuilder(){}
  virtual House* getHouse() = 0;
  virtual void BuildHouse() = 0;
  virtual void BuildDoor() = 0;
  virtual void BuildWindow() = 0;

protected:
  HouseBuilder() {}
};
class ConcreteHouseBuilder : public HouseBuilder {
 public:
  ConcreteHouseBuilder(){}
  ~ConcreteHouseBuilder(){}
  void BuildHouse(){
    _house = new House;
  }
  House* getHouse() { return _house;
  }
  void BuildDoor() {
    _house->setDoor("wood door");
  }
  void BuildWindow() {
    _house->setWindow(" small window ");
  }

 private:
  House* _house;
};
class Director{
public:
  Director() {}

  ~Director(){}
  House* Construct(HouseBuilder* builder){
    builder->BuildHouse();
    builder->BuildDoor();
    builder->BuildWindow();
    return builder->getHouse();
  }

};
int main(int argc, char* argv[]) {
  HouseBuilder* builder = new ConcreteHouseBuilder;
  Director D;
  House *house = D.Construct(builder);
  house->Show();
  return 0;
}