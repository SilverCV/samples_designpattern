#include <iostream>
#include <vector>
//抽象迭代器声明
template <typename T> class Iterator;
//抽象聚合
template <typename  T>
class Aggregate{
public:
  virtual ~Aggregate(){}
  virtual Iterator<T>* GetIterator() = 0;
  virtual int size() const = 0;
  virtual const T&operator[](size_t index) const = 0;
  virtual void AddItem(T const& t) = 0;

protected:
  Aggregate(){}
};
//抽象迭代器定义接口
template <typename  T>
class Iterator{
public:
  virtual ~Iterator(){}
  virtual void first() = 0;
  virtual void Next() = 0;
  virtual bool IsDone() = 0;
  virtual const T& operator*()  const = 0;
  friend std::ostream&operator<<(std::ostream& os,Iterator& t){
    os << *t;
    return os;
  }
protected:
  Iterator(){}
};
//具体的迭代器
template <typename T>
class ConcreteIterator : public Iterator<T>{
public:
  ConcreteIterator(Aggregate<T>* agg) : _aggregate(agg),current_(0){}
  ~ConcreteIterator(){}
  void first(){
    current_ = 0;
  }
  bool IsDone(){ return current_ >= _aggregate->size();}
  void Next(){
    if (current_ < _aggregate->size()){
      current_ ++;
    }
  }
  const T& operator*()  const{
    if(current_ <= _aggregate->size()){
      return (*_aggregate)[current_];
    }else{
      throw  std::logic_error("index overflow");
    }
  }

private:
  Aggregate<T>* _aggregate;
  size_t current_;
};
//具体聚合
template <typename  T>
class  ConcreteAggregate : public Aggregate<T>{
public:
  ConcreteAggregate(){}
  ~ConcreteAggregate(){}
  Iterator<T>* GetIterator(){
    return new ConcreteIterator<T>(this);
  }
  int size() const {
    return _items.size();
  }
  void AddItem(T const& t){
    _items.emplace_back(t);
  }
  const T& operator[](size_t index) const{
    if (index >= 0 && index < _items.size()){
      return _items[index];
    }else{
      throw std::logic_error("error for index");
    }
  }
private:
  std::vector<T> _items;
};
//测试使用
int main(int argc,char *argv[]) {
  ConcreteAggregate<int> aggtest;
  for (int i = 0; i <10 ; ++i) {
    aggtest.AddItem(i);
  }
  Iterator<int> *it = aggtest.GetIterator();
  for (it->first();!it->IsDone();it->Next()) {
    std::cout << " " << *it << "\t";
  }
  return 0;
}

