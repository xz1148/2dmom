#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "cartesian.hpp"

using namespace std;
void ReadMATLAB(vector<Point>& p1, vector<Point>& p2, vector<Point>& p3)
{
	ifstream file;
	string line;
	file.open("output.txt");
	getline(file, line);  // skip the first line
	double p1_x_buf;
	double p1_y_buf;
	double p2_x_buf;
	double p2_y_buf;
	double p3_x_buf;
	double p3_y_buf;
	while(getline(file, line))
	{
		stringstream ss_buf(line);
		Point p1_tmp, p2_tmp, p3_tmp;
		ss_buf >> p1_x_buf >>  p1_y_buf >> p2_x_buf >> p2_y_buf >> p3_x_buf >> p3_y_buf;
		p1_tmp.SetX(p1_x_buf);
		p1_tmp.SetY(p1_y_buf);
		p2_tmp.SetX(p2_x_buf);
		p2_tmp.SetY(p2_y_buf);
		p3_tmp.SetX(p3_x_buf);
		p3_tmp.SetY(p3_y_buf);
		p1.push_back(p1_tmp);
		p2.push_back(p2_tmp);
		p3.push_back(p3_tmp);
	}
	cout << line << endl;

}
