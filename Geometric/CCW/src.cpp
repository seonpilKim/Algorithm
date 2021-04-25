#include <iostream>

using namespace std;

struct Point {
	int x;
	int y;

	Point(int x, int y)
		: x(x), y(y) {}
};

struct Line {
	Point start;
	Point end;

	Line(Point start, Point end)
		: start(start), end(end) {}
};

long long CCW(const Point& A, const Point& B, const Point& C) {
	const long long external_product = (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);

	if (external_product > 0)
		return 1;
	else if (external_product == 0)
		return 0;
	else if (external_product < 0)
		return -1;
}

bool isIntersect(const Line& A, const Line& B) {
	const int case1 = CCW(A.start, A.end, B.start) * CCW(A.start, A.end, B.end);
	const int case2 = CCW(B.start, B.end, A.start) * CCW(B.start, B.end, A.end);

	if (case1 == 0 && case2 == 0) {
		pair<int, int> p1 = make_pair(A.start.x, A.start.y);
		pair<int, int> p2 = make_pair(A.end.x, A.end.y);
		pair<int, int> p3 = make_pair(B.start.x, B.start.y);
		pair<int, int> p4 = make_pair(B.end.x, B.end.y);

		if (p1 > p2)
			swap(p1, p2);
		if (p3 > p4)
			swap(p3, p4);

		return p1 <= p4 && p3 <= p2;
	}

	return case1 <= 0 && case2 <= 0;
}