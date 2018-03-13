
#ifndef INPUT_H
#define INPUT_H

#include <vector>
#include <list>
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
	point find_ideal_point(const segment &s);
};


class mesh
{
private:
	front f;
	std::list<directional_triangle> triangles;
	std::list<point> points;
	
public:
	mesh();
	mesh(const front &f);
	front get_front() const;
	std::list<directional_triangle> get_triangles() const;
	std::list<point> get_points() const;
	bool search_for_nearby_points(const point &p, double radius, point &nearest_point);
	
};

#endif