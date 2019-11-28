#include <iostream>

#include "Subject.h"
#include "Observer.h"



int main()
{
	////////////////////////////////////////////////////////////
	//		        *****  INITIALIZATION *****               //
	////////////////////////////////////////////////////////////
	std::shared_ptr<Subject> subject = std::make_shared<Subject>(12, 13);

	std::shared_ptr<Observer1> observer1 = std::make_shared<Observer1>(subject);
	std::shared_ptr<Observer2> observer2 = std::make_shared<Observer2>(subject);
	std::shared_ptr<Observer12> observer12 = std::make_shared<Observer12>(subject);

	////////////////////////////////////////////////////////////
	//		       *****  SUBJECT CHANGING *****              //
	////////////////////////////////////////////////////////////
	std::cout << "change of subject: attr1=1, attr2=2" << std::endl;
	subject->setAttribute1(1);
	subject->setAttribute2(2);


	////////////////////////////////////////////////////////////
	//		      *****  OBSERVERS TESTING *****              //
	////////////////////////////////////////////////////////////
	std::cout << "state of observer1: " << observer1->getAttribute1() << std::endl;
	std::cout << "state of observer2: " << observer2->getAttribute2() << std::endl;
	std::cout << "state of observer12: " << observer12->getAttribute1() << ", " << observer12->getAttribute2() << std::endl;

	////////////////////////////////////////////////////////////
	//		       *****  SUBJECT CHANGING *****              //
	////////////////////////////////////////////////////////////
	std::cout << "change of subject: attr1=3, attr2=4" << std::endl;
	subject->setAttribute1(3);
	subject->setAttribute2(4);

	////////////////////////////////////////////////////////////
	//		      *****  OBSERVERS TESTING *****              //
	////////////////////////////////////////////////////////////
	std::cout << "state of observer1: " << observer1->getAttribute1() << std::endl;
	std::cout << "state of observer2: " << observer2->getAttribute2() << std::endl;
	std::cout << "state of observer12: " << observer12->getAttribute1() << ", " << observer12->getAttribute2() << std::endl;
	
	system("pause");
	return 0;
}