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

