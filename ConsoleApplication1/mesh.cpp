#include "geometry.h"
#include "mesh.h"
#include <iostream>
#include <bitset>
#include <sstream>
#include <cmath>
#include <algorithm> 

std::ostream& operator << (std::ostream & os, const front & f) {

	return os;
}

front::front(std::vector<segment> front_vector) {
	edges = front_vector;
}

 std::vector<segment> front::get_front() const {
	return this->edges;
}


void front::push_edge(segment edge) {
	this->edges.push_back(edge);
}

void front::order_by_length() {
	std::sort(edges.begin(), edges.end(), length_sort);
}

void front::divide_edge(segment &edge , int new_edges, int pos) {
	edges.erase(edges.begin() + pos);
	point last_terminal;
	point new_initial = edge.get_initial();
	double dy = sin(edge.get_angle())*edge.get_length() / new_edges;
	double dx = cos(edge.get_angle())*edge.get_length() / new_edges;
	segment last_edge;
	last_edge.set_terminal(edge.get_terminal());
	for (int i = 1; i < new_edges; i++) {
		segment new_edge;
		new_edge.set_initial(new_initial);
		last_terminal.set_x(new_initial.get_x() + dx);
		last_terminal.set_y(new_initial.get_y() + dy);
		new_edge.set_terminal(last_terminal);
		new_initial = last_terminal;
		last_edge.set_initial(new_initial);
		this->push_edge(new_edge);
	}
	this->push_edge(last_edge);
}
