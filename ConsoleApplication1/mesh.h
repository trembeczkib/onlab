
#ifndef INPUT_H
#define INPUT_H

#include <vector>
#include "geometry.h"



class front
{
private:
	std::vector<segment> edges;

public:
	front(std::vector<segment> front_vector);
	std::vector<segment> get_front() const;
	void push_edge(segment new_edge);
	void order_by_length();
	void divide_edge(segment &edge, int new_edges, int pos);
	friend std::ostream& operator << (std::ostream & os, const front & f);

};

#endif