#include "mesh.hpp"
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include "cartesian.hpp"

using namespace std;

void CreateGeo(double radii, double lc)
{
	ofstream GeoFile;
	GeoFile.open("circle_tmp.geo");
	GeoFile << "radii = " << setprecision(15) << radii << ";\n";
	GeoFile << "lc = " << setprecision(15) << lc << ";\n";
	//GeoFile << "lc = radii/5;\n";
	GeoFile << "Point(1) = {0, 0, 0,lc};\n";
	GeoFile << "Point(2) = {radii, 0, 0, lc};\n";
	GeoFile << "Point(3) = {-radii, 0, 0, lc};\n";
	GeoFile << "Circle(4) = {2, 1, 3};\n";
	GeoFile << "Circle(5) = {3, 1, 2};\n";
	GeoFile << "Line Loop(6) = {4, 5};\n";
	GeoFile << "Plane Surface(7) = {6};\n";
	GeoFile.close();


}

void StartMesh()
{
	int i;
	i = system("gmsh -2 circle_tmp.geo");
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
		//cout << line << endl;
		stringstream ssline(line); // create a string stream of the line
		for(int i=0; i<4; i++)
		{
			getline(ssline, buffer, ' ');
			PointXYZ[i] = atof(buffer.c_str());
		}
		Points.push_back(Point(PointXYZ[1], PointXYZ[2]));
	}
}

void ReadElements(vector<Triangle>& Triangles, vector<Point> Points, ifstream& MeshFile, int NElements)
{
	string LineBuf;
	string Token;
	for (int i=0; i<NElements; i++)
	{
		getline(MeshFile, LineBuf);    //read the line
		stringstream ssLineBuf(LineBuf);
		getline(ssLineBuf, Token, ' '); //skip the first token
		getline(ssLineBuf, Token, ' '); //read the second token(element type)
		// cout << Token << endl;
		if (Token == "15") 
		{
			// cout << "Reading a point" << endl;	
		}
		else if (Token == "2")
		{
			Triangle tri_temp;
			getline(ssLineBuf, Token, ' '); // the third token (number of tages)
			getline(ssLineBuf, Token, ' '); // the fourth token (tag1)
			getline(ssLineBuf, Token, ' '); // the fifth token (tag2)
			getline(ssLineBuf, Token, ' '); // the sixth token (index of point1)
			tri_temp.GetPoint(0) = Points[atoi(Token.c_str()) - 1];
			getline(ssLineBuf, Token, ' '); // the sixth token (index of point2)
			tri_temp.GetPoint(1) = Points[atoi(Token.c_str()) - 1];
			getline(ssLineBuf, Token, ' '); // the sixth token (index of point3)
			tri_temp.GetPoint(2) = Points[atoi(Token.c_str()) - 1];
			Triangles.push_back(tri_temp);
		}
	}
	cout << "the number of triangles is " << Triangles.size() << endl;  
}
void ReadMesh(vector<Point>& Points, vector<Triangle>& Triangles)
{
	// vector<Point> Points;
	// vector<Triangle> Triangles;
	int NPoint;
	int NElements;
	string buffer;
	string line;
	ifstream MeshFile("./circle_tmp.msh");
	if (MeshFile.is_open()) {cout << "open successfully" << endl;}
	else cout << "cannot open file." << endl;
	SkipLine(MeshFile,4);	
	getline(MeshFile, line);
	NPoint = atoi(line.c_str());
	cout << "The number of points is " << NPoint << endl;
	ReadPoints(Points, MeshFile, NPoint);
//	for (int i=0; i<NPoint; i++)
//	{
//		cout << Points[i] << endl;	
//	}
//	cout << "the number of elements is " << Points.size() << endl;
//	cout << "the value of NPoints is" << NPoint << endl;
	SkipLine(MeshFile, 2);
	getline(MeshFile, line);
	NElements = atoi(line.c_str());
	cout << "The number of elements is " << NElements << endl;
	ReadElements(Triangles, Points, MeshFile, NElements);
	MeshFile.close();
}

