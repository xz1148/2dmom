radii = 1;
lc = 0.1;
Point(1) = {0, 0, 0,lc};
Point(2) = {radii, 0, 0, lc};
Point(3) = {-radii, 0, 0, lc};
Circle(4) = {2, 1, 3};
Circle(5) = {3, 1, 2};
Line Loop(6) = {4, 5};
Plane Surface(7) = {6};