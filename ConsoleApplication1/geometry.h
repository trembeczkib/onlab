
#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <iostream>;

class point {

	private:
		double x;
		double y;

	public: 
		point();
		point(double value_x, double value_y);
		void set_x(double value);
		void set_y(double value);
		double get_x();
		double get_y();
		friend std::ostream& operator << (std::ostream & os, point & p);
};

class segment {

private:
	point p_initial;
	point p_terminal;
	double length;
	double angle;

public:
	segment();
	segment(point p_initial, point p_terminal);
	const point get_initial();
	const point get_terminal();
	const double get_length();
	const double get_angle();
	void set_initial(point initial);
	void set_terminal(point terminal);
	friend std::ostream& operator << (std::ostream & os, segment & s);



};

#endif