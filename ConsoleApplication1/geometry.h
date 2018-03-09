
#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <iostream>

class point {

	private:
		double x;
		double y;

	public: 
		point();
		point(double value_x, double value_y);
		void set_x(double value);
		void set_y(double value);
		double get_x() const;
		double get_y() const;
		friend std::ostream& operator << (std::ostream & os, const point & p);
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
	point get_initial() const;
	point get_terminal() const;
	double get_length() const;
	double get_angle() const;
	void set_initial(point initial);
	void set_terminal(point terminal);
	friend std::ostream& operator << (std::ostream & os, const segment & s);
	friend bool length_sort(const segment s1, const segment s2);



};

class directional_triangle {
private:
	point A;
	point B;
	point C;
	double a;
	double b;
	double c;
	double alfa;
	double beta;
	double gamma;
	
public:
	directional_triangle(point p1, point p2, point p3);
	directional_triangle();
	void set_A(point p);
	void set_B(point p);
	void set_C(point p);
	point get_A() const;
	point get_B() const;
	point get_C() const;
	double get_a() const;
	double get_b() const;
	double get_c() const;
	double get_alfa() const;
	double get_beta() const;
	double get_gamma() const;
	friend std::ostream& operator << (std::ostream & os, const directional_triangle & t);
};

#endif