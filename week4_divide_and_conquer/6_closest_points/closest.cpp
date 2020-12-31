#include <bits/stdc++.h> 
using namespace std; 

class Point 
{ 
	public: 
	double x, y; 
}; 

int compareX(const void* a, const void* b) 
{ 
	Point *p1 = (Point *)a, *p2 = (Point *)b; 
	return (p1->x - p2->x); 
} 

int compareY(const void* a, const void* b) 
{ 
	Point *p1 = (Point *)a, *p2 = (Point *)b; 
	return (p1->y - p2->y); 
} 

double dist(Point p1, Point p2) 
{ 
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + 
				(p1.y - p2.y)*(p1.y - p2.y) 
			); 
} 

double bruteForce(Point P[], int n) 
{ 
	double min = __DBL_MAX__; 
	for (int i = 0; i < n; ++i) 
		for (int j = i+1; j < n; ++j) 
			if (dist(P[i], P[j]) < min) 
				min = dist(P[i], P[j]); 
	return min; 
} 

double min(double x, double y) 
{ 
	return (x < y)? x : y; 
} 


double stripClosest(Point strip[], int size, double d) 
{ 
	double min = d; 

	qsort(strip, size, sizeof(Point), compareY); 

	for (int i = 0; i < size; ++i) 
		for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j) 
			if (dist(strip[i],strip[j]) < min) 
				min = dist(strip[i], strip[j]); 

	return min; 
} 

double closestUtil(Point P[], int n) 
{ 
	if (n <= 3) 
		return bruteForce(P, n); 

	int mid = n/2; 
	Point midPoint = P[mid]; 

	double dl = closestUtil(P, mid); 
	double dr = closestUtil(P + mid, n - mid); 

	double d = min(dl, dr); 

	Point strip[n]; 
	int j = 0; 
	for (int i = 0; i < n; i++) 
		if (abs(P[i].x - midPoint.x) < d) 
			strip[j] = P[i], j++; 

	return min(d, stripClosest(strip, j, d) ); 
} 

double closest(Point P[], int n) 
{ 
	qsort(P, n, sizeof(Point), compareX); 

	return closestUtil(P, n); 
} 

int main() 
{ 
  	int n ;
  	cin>>n;

	Point P[n];
  	for(int i = 0 ; i < n ; i++){
    	cin>>P[i].x>>P[i].y;
    }
	cout << closest(P, n); 
	return 0; 
} 

