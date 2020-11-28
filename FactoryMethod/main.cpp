#include <iostream>
class Product{
public:
  virtual ~Product(){}
  virtual void Run() = 0;
};
class Car : public Product{
public:
  Car(){}
  ~Car(){}
  void Run() {
    std::cout << "run in the road" << std::endl;
  }
};
class Creator{
public:
  virtual Product *CreateProduct()=0;
};
template <typename _Product>
class ConcreteCrator : public Creator{
public:
  ConcreteCrator(){}
  ~ConcreteCrator(){}
  _Product *GetProduct(){
    if (_product == NULL){
      _product = CreateProduct();
    }
    return _product;
  }

protected:
  virtual _Product* CreateProduct(){
    return new _Product;
  }
private:
  _Product *_product;
};
int main(int argc,char *argv[])
{
  ConcreteCrator<Car> myCar;
 Car* c = myCar.GetProduct();
 c->Run();
  return 0;
}