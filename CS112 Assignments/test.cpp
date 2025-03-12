#include <iostream>
using namespace std;
class animal
{
	public:
	virtual	void speak()
		{
			 cout << "Dog: Woof! Woof!" << endl; 
		}
		 virtual ~animal() {} 
};
class dog : public animal
{       public:
	  void speak() override { 
	  cout << " woof ! " << endl; }
};
class robot : public animal
{public:
	  void speak() override { cout << " beep! beep ! " << endl;
	   }
};
class RobotDog : public dog , public robot {
	
public:
	
 void speak() override { cout << " Bark! Beep ! " << endl;
 
}
 };
int main()
{  cout<<"creatures speak :"<<endl;
 dog *d = new dog();
    robot *r = new robot();
    RobotDog *rd= new RobotDog();

    d->speak();
    r->speak();  
    rd->speak();
  

    delete d;
    delete r;
    return 0;
}
