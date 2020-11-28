#include <iostream>
#include <string>
#include <functional>
#include <map>
class NonCopyable{
protected:
  NonCopyable() = default;
  virtual ~NonCopyable() = default;
  NonCopyable(const NonCopyable&) = delete; //ban copy constructor
  NonCopyable&operator=(const NonCopyable&) = delete; // ban copy assignment
};
template <typename Func>
class Subject : NonCopyable{ public:
  Subject(){}
  ~Subject(){}
  //register observer
  int Attach(Func&& f){
    return Assign(f);
  }
  int Attach(const Func& f){
    return Assign(f);
  }
  //remove observer
  void Detach(int k){
    _Observers.erase(k);
  }
  //notify all observer when the Subject has changed
  template<typename ...Args>
  void  Notify(Args&& ...args){
    for(auto& it : _Observers){
      it.second(std::forward<Args>(args)...);
    }
  }
private:
  template <typename F>
  int Assign(F&& f){
    int k = _observerId ++;
    _Observers.emplace(k,std::forward<F>(f));
    return k;
  }
  int _observerId = 0; // the No of observer
  std::map<int,Func> _Observers;
};
//
struct StA{
  int a,b;
  void print(int a,int b){std::cout << a << "," << b << std::endl;}
};
void print(int a,int b){std::cout << a << "," << b << std::endl;}
int main(int argc,char **argv)
{
  Subject<std::function<void(int,int)>> mySubject;
  //register observer
  auto key = mySubject.Attach(print);
  StA sta;
  auto lambdaKey = mySubject.Attach([&](int a,int b){sta.a = a;sta.b = b;}); //lambda
  //std::function
  std::function<void(int,int)> f = std::bind(&StA::print,&sta,std::placeholders::_1,std::placeholders::_2);
  mySubject.Attach(f);
  int a = 1,b = 2;
  mySubject.Notify(a,b);
  mySubject.Detach(lambdaKey);

  return 0;
}
#include <list>
namespace Design {

class Subject;
//观察者
class Observer {
public:
  virtual ~Observer(){}
  virtual void Update() = 0;
protected:
  Observer() {}
};
//目标对象
class Subject {
public:
  virtual ~Subject(){}
  //注册观察者
  virtual void Attach(Observer *o){
    _Observers.emplace_back(o);
  }
  //移除观察者
  virtual void Detach(Observer* o){
    _Observers.remove(o);
  }
  //通知
  virtual void Notify(){
    for(auto o : _Observers){
      o->Update();
    }
  }
protected:
  Subject(){}
private:
  std::list<Observer *> _Observers;
};
}