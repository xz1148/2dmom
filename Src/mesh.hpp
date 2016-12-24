#ifndef MESH_HPP
#define MESH_HPP
#include<vector>
#include"cartesian.hpp"
void CreateGeo(double radii, double lc);
void StartMesh();
void ReadMesh(std::vector<Point>& Points, std::vector<Triangle>& Triangles);
#endif /* MESH_HPP */
