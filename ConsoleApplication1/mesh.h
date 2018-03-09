
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
	bool is_inside_front(const point &p);


};


class mesh
{
private:
	front front;
	std::list<directional_triangle> triangles;
	std::list<point> points;
	
public:
	mesh();
	mesh(front f);
	front get_front() const;
	std::list<directional_triangle> get_triangles() const;
	std::list<point> get_points() const;
	
};

class mesh
{
private:
	front front;
	vector 
};

#endif