#include <vtkVersion.h>
#include <vtkTriangle.h>
#include <vtkCellArray.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include "plot.hpp"
#include <iostream>
#include "cartesian.hpp"
#include <vector>

using namespace std;

vtkSmartPointer<vtkActor> CreateTriangleActors(Triangle triangle)
{
//	Triangle triangle = triangles[0];
	Point p1 = triangle.GetPoint(0);
	Point p2 = triangle.GetPoint(1);
	Point p3 = triangle.GetPoint(2);
	vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
	points->InsertNextPoint(p1.GetX(), p1.GetY(), 0.0);
	points->InsertNextPoint(p2.GetX(), p2.GetY(), 0.0);
	points->InsertNextPoint(p3.GetX(), p3.GetY(), 0.0);

	vtkSmartPointer<vtkTriangle> vtk_triangle = vtkSmartPointer<vtkTriangle>::New();
	vtk_triangle->GetPointIds()->SetId(0, 0);
	vtk_triangle->GetPointIds()->SetId(1, 1);
	vtk_triangle->GetPointIds()->SetId(2, 2);

	vtkSmartPointer<vtkCellArray> vtk_triangle_cells = vtkSmartPointer<vtkCellArray>::New();
	vtk_triangle_cells->InsertNextCell(vtk_triangle);

	vtkSmartPointer<vtkPolyData> trianglePolyData = vtkSmartPointer<vtkPolyData>::New();
	trianglePolyData->SetPoints(points);
	trianglePolyData->SetPolys(vtk_triangle_cells);
	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputData(trianglePolyData);
	vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New(); // array of smart pointer
	actor->SetMapper(mapper);
	return actor;
}


void Patch(vector<Triangle>& tri_list)
{
// initialize
//	vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
//	points->InsertNextPoint(1.0, 0.0, 0.0);
//	points->InsertNextPoint(0.0, 0.0, 0.0);
//	points->InsertNextPoint(0.0, 1.0, 0.0);
//	points->InsertNextPoint(0.0, 0.0, 3.0);
//
//	vtkSmartPointer<vtkTriangle> triangle = vtkSmartPointer<vtkTriangle>::New();
//	triangle->GetPointIds()->SetId(0, 0);
//	triangle->GetPointIds()->SetId(1, 1);
//	triangle->GetPointIds()->SetId(2, 2);
//
//	vtkSmartPointer<vtkCellArray> triangles = vtkSmartPointer<vtkCellArray>::New();
//	triangles->InsertNextCell(triangle);
//
//	vtkSmartPointer<vtkPolyData> trianglePolyData = vtkSmartPointer<vtkPolyData>::New();
//	trianglePolyData->SetPoints(points);
//	trianglePolyData->SetPolys(triangles);
//
//
//	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New(); // array of smart pointer
//	mapper->SetInputData(trianglePolyData);
//
//	vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New(); // array of smart pointer
//	actor->SetMapper(mapper);
	int N_tri = tri_list.size();
	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
	for (int i=0; i<N_tri; i++)
	{
		vtkSmartPointer<vtkActor> actor_temp = CreateTriangleActors(tri_list[i]);
		renderer->AddActor(actor_temp);
	}
	renderWindow->AddRenderer(renderer);
	renderWindowInteractor->SetRenderWindow(renderWindow);
	renderWindowInteractor->Start();
}
