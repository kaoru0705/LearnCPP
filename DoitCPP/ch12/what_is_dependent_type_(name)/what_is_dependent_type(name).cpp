/* https://stackoverflow.com/questions/1527849/how-do-you-understand-dependent-names-in-c */
#include <iostream>
#include <vector>
/* 의존 타입 */
//void NonDependent()
//{
//    //You can access the member size_type directly.
//    //This is precisely specified as a vector of ints.
//
//    typedef std::vector<int> IntVector;
//    IntVector::size_type i;
//
//    /* ... */
//}
//
//template <class T>
//void Dependent()
//{
//
//    //Now the vector depends on the type T. 
//    //Need to use typename to access a dependent name.
//
//    typedef std::vector<T> SomeVector;
//    typename SomeVector::size_type i;
//
//    /* ... */
//}
//
//int main()
//{
//    NonDependent();
//    Dependent<int>();
//    return 0;
//}

//class Dependent
//{
//protected:
//	int data;
//};
//
//class OtherDependent : public Dependent
//{
//public:
//	void printT()const
//	{
//		std::cout << "int: " << data << std::endl;
//	}
//};
//
//int main()
//{
//	OtherDependent o;
//	o.printT();
//	return 0;
//}