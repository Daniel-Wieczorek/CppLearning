#include <iostream>
#include <string>
#include <vector>

/*
There are 3 types of inheritance:
public    -> 'is a relationship between A and B'.
private   ->
protected -> accessible from the: Base class itself, from classess derived from base and not accessible by any objects of Base or Derived

access Specifier         Base class         Derived class
---------------------------------------------------------
public                   public             public
                         protected          protected
                         private            no access

protected                public             protected
                         protected          protected
                         private            no access

private                  public             private
                         protected          private
                         private            no access

*/
class Base{

    public:
    int a {0};
    void display() {std::cout << a << " " << b << " " << c << " " << std::endl;}

    protected:
    int b {0};

    private:
    int c {0};
};


class Derived: public Base 
{

    public:
    void access_base_members()
    {
        a = 100; // ok
        b = 200; // ok
      //  c = 300; // comp error
    }
};

int main()
{

    Base base_object;
    base_object.a = 100; // ok
 //   base_object.b = 200; // comp error
  //  base_object.c = 300; // comp error

    Derived dick;
    dick.a = 100; // ok
 //   dick.b = 200; // comp error
 //   dick.c = 300; // comp error

    return 0;
}