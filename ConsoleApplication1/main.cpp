#include <stdio.h>
#include <iostream>
#include "mesh.h"
#include "geometry.h"


int main()
{

	if (-1) {
		point p1;
		p1.set_x(50);
		p1.set_y(50);
		point p2;
		p2.set_x(50);
		p2.set_y(150);
		point p3;
		p3.set_x(100);
		p3.set_y(100);
		point p4;
		p4.set_x(100);
		p4.set_y(50);

		segment s1;
		s1.set_initial(p1);
		s1.set_terminal(p2);

		segment s2;
		s2.set_initial(p2);
		s2.set_terminal(p3);

		segment s3;
		s3.set_initial(p3);
		s3.set_terminal(p4);

		segment s4;
		s4.set_initial(p4);
		s4.set_terminal(p1);

		std::vector<segment> myvector;
		myvector.push_back(s1);
		myvector.push_back(s2);
		myvector.push_back(s3);
		myvector.push_back(s4);

		front myfront = front(myvector);
	}

	point p1 = point(50, 50);
	point p2 = point(50, 100);
	segment s1 = segment(p1, p2);
	std::vector<segment> myvector;
	myvector.push_back(s1);
	front myfront = front(myvector);




	std::cout << std::endl;
/*
	myfront.divide_edge(myfront.get_front()[1],10,1);
	myfront.order_by_length();
	for (auto i : myfront.get_front())
		std::cout << i << ' ';
*/


	std::cout << std::endl;
	point new_point = myfront.find_ideal_point(myfront.get_front()[0]);
	directional_triangle t = * new directional_triangle(myfront.get_front()[0].get_initial(), myfront.get_front()[0].get_terminal(), new_point);
	std::cout << t;
	
	std::getchar();
	return 0;
}
