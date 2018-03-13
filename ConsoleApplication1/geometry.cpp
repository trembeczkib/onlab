#include "geometry.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

std::ostream& operator << (std::ostream & os, const point & p) {
	os << "x: " << p.get_x() << " | y: " << p.get_y() ;
	return os;
}

std::ostream& operator<<(std::ostream & os, const segment & s) {
	os <<  "\n Initial point: " << s.get_initial() << " | Terminal point: " << s.get_terminal();
	return os;
}

std::ostream& operator << (std::ostream & os, const directional_triangle & t) {
	os << "\n Vertices: A: " << t.get_A() << " B: " << t.get_B() << " C: " << t.get_C() << std::endl;
	os << " Sides: a: " << t.get_a() << " b: " << t.get_b() << " c: " << t.get_c() << std::endl;
	os << " Angles: alfa: " << t.get_alfa() << " beta: " << t.get_beta() << " gamma: " << t.get_gamma() << std::endl;
	return os;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

bool length_sort(const segment s1, const segment s2) {
	return (s1.get_length() < s2.get_length());
}


point::point() {
	this->x = 0;
	this->y = 0;
}

point::point(double value_x, double value_y) {
	this->x = value_x;
	this->y = value_y;
}

void point::set_x(double value) {
	this->x = value;
}

void point::set_y(double value) {
	this->y = value;
}

double point::get_x() const {
	return this->x;
}


double point::get_y() const {
	return this->y;
}

//////////////////////////////////////////////////////////////////////////////////////////////////


segment::segment(point p_initial, point p_terminal) {
	this->p_initial = p_initial;
	this->p_terminal = p_terminal;
	this->length = sqrt(pow(p_terminal.get_x()-p_initial.get_x(),2)+pow(p_terminal.get_y() - p_initial.get_y(), 2));
	this->angle = tanh((p_terminal.get_y() - p_initial.get_y()) / (p_terminal.get_x() - p_initial.get_x()));
}

segment::segment() {
	point zero;
	this->p_initial = zero;
	this->p_terminal = zero;
	this->length = 0;
	this->angle = 0;
}

void segment::set_initial(point initial) {
	this->p_initial = initial;
	this->length = sqrt(pow(p_terminal.get_x() - p_initial.get_x(), 2) + pow(p_terminal.get_y() - p_initial.get_y(), 2));
	this->angle = tanh((p_terminal.get_y() - p_initial.get_y()) / (p_terminal.get_x() - p_initial.get_x()));
}

void segment::set_terminal(point terminal) {
	this->p_terminal = terminal;
	this->length = sqrt(pow(p_terminal.get_x() - p_initial.get_x(), 2) + pow(p_terminal.get_y() - p_initial.get_y(), 2));
	this->angle = tanh((p_terminal.get_y() - p_initial.get_y()) / (p_terminal.get_x() - p_initial.get_x()));
}

double segment::get_length() const {
	return this->length;
}

double segment::get_angle() const {
	return this->angle;
}

point segment::get_initial() const {
	return this->p_initial;
}

point segment::get_terminal() const {
	return this->p_terminal;
}

//////////////////////////////////////////////////////////////////////////////////////////////////


directional_triangle::directional_triangle(point p1, point p2, point p3) {
	this->A = p1;
	this->B = p2;
	this->C = p3;
	this->a = sqrt((C.get_x() - B.get_x())*(C.get_x() - B.get_x()) + (C.get_y() - B.get_y())*(C.get_y() - B.get_y()));
	this->b = sqrt((A.get_x() - C.get_x())*(A.get_x() - C.get_x()) + (A.get_y() - C.get_y())*(A.get_y() - C.get_y()));
	this->c = sqrt((B.get_x() - A.get_x())*(B.get_x() - A.get_x()) + (B.get_y() - A.get_y())*(B.get_y() - A.get_y()));
	this->gamma = acos((c*c-a*a-b*b) / (-2*a*b));
	this->beta = acos((b*b - a*a - c*c) / (-2 * a*c));
	this->alfa = acos((a*a - c*c - b*b) / (-2 * c*b));
}

directional_triangle::directional_triangle() {
	point zero;
	this->A = zero;
	this->B = zero;
	this->C = zero;
	this->a = sqrt((C.get_x() - B.get_x())*(C.get_x() - B.get_x()) + (C.get_y() - B.get_y())*(C.get_y() - B.get_y()));
	this->b = sqrt((A.get_x() - C.get_x())*(A.get_x() - C.get_x()) + (A.get_y() - C.get_y())*(A.get_y() - C.get_y()));
	this->c = sqrt((B.get_x() - A.get_x())*(B.get_x() - A.get_x()) + (B.get_y() - A.get_y())*(B.get_y() - A.get_y()));
	this->gamma = acos((c*c - a*a - b*b) / (-2 * a*b));
	this->beta = acos((b*b - a*a - c*c) / (-2 * a*c));
	this->alfa = acos((a*a - c*c - b*b) / (-2 * c*b));
}

void directional_triangle::set_A(point p) {
	this->A = p;
	this->a = sqrt((C.get_x() - B.get_x())*(C.get_x() - B.get_x()) + (C.get_y() - B.get_y())*(C.get_y() - B.get_y()));
	this->b = sqrt((A.get_x() - C.get_x())*(A.get_x() - C.get_x()) + (A.get_y() - C.get_y())*(A.get_y() - C.get_y()));
	this->c = sqrt((B.get_x() - A.get_x())*(B.get_x() - A.get_x()) + (B.get_y() - A.get_y())*(B.get_y() - A.get_y()));
	this->gamma = acos((c*c - a*a - b*b) / (-2 * a*b));
	this->beta = acos((b*b - a*a - c*c) / (-2 * a*c));
	this->alfa = acos((a*a - c*c - b*b) / (-2 * c*b));
}

void directional_triangle::set_B(point p) {
	this->B = p;
	this->a = sqrt((C.get_x() - B.get_x())*(C.get_x() - B.get_x()) + (C.get_y() - B.get_y())*(C.get_y() - B.get_y()));
	this->b = sqrt((A.get_x() - C.get_x())*(A.get_x() - C.get_x()) + (A.get_y() - C.get_y())*(A.get_y() - C.get_y()));
	this->c = sqrt((B.get_x() - A.get_x())*(B.get_x() - A.get_x()) + (B.get_y() - A.get_y())*(B.get_y() - A.get_y()));
	this->gamma = acos((c*c - a*a - b*b) / (-2 * a*b));
	this->beta = acos((b*b - a*a - c*c) / (-2 * a*c));
	this->alfa = acos((a*a - c*c - b*b) / (-2 * c*b));
}

void directional_triangle::set_C(point p) {
	this->C = p;
	this->a = sqrt((C.get_x() - B.get_x())*(C.get_x() - B.get_x()) + (C.get_y() - B.get_y())*(C.get_y() - B.get_y()));
	this->b = sqrt((A.get_x() - C.get_x())*(A.get_x() - C.get_x()) + (A.get_y() - C.get_y())*(A.get_y() - C.get_y()));
	this->c = sqrt((B.get_x() - A.get_x())*(B.get_x() - A.get_x()) + (B.get_y() - A.get_y())*(B.get_y() - A.get_y()));
	this->gamma = acos((c*c - a*a - b*b) / (-2 * a*b));
	this->beta = acos((b*b - a*a - c*c) / (-2 * a*c));
	this->alfa = acos((a*a - c*c - b*b) / (-2 * c*b));
}

point directional_triangle::get_A() const {
	return this->A;
}

point directional_triangle::get_B() const {
	return this->B;
}

point directional_triangle::get_C() const {
	return this->C;
}

double directional_triangle::get_a() const {
	return this->a;
}

double directional_triangle::get_b() const {
	return this->b;
}

double directional_triangle::get_c() const {
	return this->c;
}

double directional_triangle::get_alfa() const {
	return this->alfa;
}

double directional_triangle::get_beta() const {
	return this->beta;
}

double directional_triangle::get_gamma() const {
	return this->gamma;
}