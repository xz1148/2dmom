#include "mesh.hpp"
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "cartesian.hpp"

using namespace std;
void StartMesh()
{
	system("gmsh -2 ../circle.geo");
}

void SkipLine(ifstream& MeshFile, int N) // skip n lines in reading
{
	string line;
	for (int i=0; i<N; i++)
	{
		getline(MeshFile, line);
	}
	
}

void ReadPoints(vector<Point>& Points, ifstream& MeshFile, int NPoint)
{
	double PointXYZ[4]; // the coordinate of points
	string line;
	string buffer;
	for (int i=0; i<NPoint; i++)
	{
		getline(MeshFile,line);
		cout << line << endl;
		stringstream ssline(line); // create a string stream of the line
		for(int i=0; i<4; i++)
		{
			getline(ssline, buffer, ' ');
			PointXYZ[i] = atof(buffer.c_str());
		}
		Points.push_back(Point(PointXYZ[1], PointXYZ[2]));
	}
}


void ReadMesh()
{
	vector<Point> Points;
	int NPoint;
	string buffer;
	string line;
	ifstream MeshFile("../circle.msh");
	if (MeshFile.is_open()) {cout << "open successfully" << endl;}
	else cout << "cannot open file." << endl;
	SkipLine(MeshFile,4);	
	
	getline(MeshFile, line);
	NPoint = atoi(line.c_str());
	ReadPoints(Points, MeshFile, NPoint);
	for (int i=0; i<NPoint; i++)
	{
		cout << Points[i] << endl;	
	}
	cout << "the number of elements is " << Points.size() << endl;
	cout << "the value of NPoints is" << NPoint << endl;
	MeshFile.close();
}
