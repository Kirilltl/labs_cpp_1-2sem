
//
//#include <iostream>
//
//using namespace std;
//
//struct Axe
//{
//	int length;
//	int weigth;
//};
//
//
//
//class Man
//{
//private:
//
//	int age;
//	Axe* axe;
//
//public:
//
//	// constructor
//	Man(int a)
//	{
//		age = a;
//
//		if (age > 18)
//		{
//			axe = new Axe(); // malloc
//		}
//	}
//
//	// copy constructor
//	Man(const Man& m)
//	{
//		age = m.age;
//	}
//
//	~Man()
//	{
//		delete axe;
//	}
//
//	// operator =
//	Man& operator = (const Man& m)
//	{
//		age = m.age;
//	}
//
//	// setter
//	void setAge(int a)
//	{
//		age = a;
//	}
//
//	// getter
//	int getAge()
//	{
//		return age;
//	}
//
//};
//// print
//void print()
//{
//	cout << age << endl;
//}
//
//
//int main()
//{
//	Man man(1);
//	cout << man.getAge() << endl;
//
//	man.setAge(8);
//	cout << man.getAge() << endl;
//
//	Man child(man);
//	cout << child.getAge() << endl;
//
//	Man father = man;
//	cout << father.getAge() << endl;
//Man father = man;
//father.print();
//}