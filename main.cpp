#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// ��������� ��� �������� ����� �� ���������
struct Coordinate {
    double x, y;

    Coordinate(double x = 0, double y = 0) : x(x), y(y) {}

    bool operator ==(const Coordinate& other) const {
        return (x == other.x && y == other.y);
    }
};


double calculateTriangleArea(const Coordinate& a, const Coordinate& b, const Coordinate& c) {
    return 0.5 * abs((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y));
}


bool isPointInsideTriangle(const Coordinate& p, const vector<Coordinate>& triangle) {
    // ������������� ���������� ��� �������� ���������� (� ������ ������������, ��� ����� ��������� ������� ������������)
    bool res = false;

    // �������� �� ������ ������� ������������
    for (int i = 0; i < 3; ++i) {
        // �������� ��������� � �������� ����� ������� �������
        const Coordinate& sideStart = triangle[i];
        const Coordinate& sideEnd = triangle[(i + 1) % 3];

        // ���� ������� ������� ����������� ��� y, ���������� ��
        if (sideStart.y == sideEnd.y) continue;

        // ��������� ������� ����������� �� ��� y ��� ������� �������
        bool conditionY = (p.y < sideStart.y) != (p.y < sideEnd.y);

        // ��������� ������� ����������� �� ��� x ��� ������� �������
        bool conditionX = p.x < (sideStart.x + ((p.y - sideStart.y) / (sideEnd.y - sideStart.y)) * (sideEnd.x - sideStart.x));

        // ���� ��� ������� ���������, ������ �������� ����������
        if (conditionX && conditionY) {
            res = !res;
        }
    }
    // ���������� ���������: true, ���� ����� ��������� ������ ������������, ����� false
    return res;
}


// ��������� ��� �������� ���������� ����������� ��������
struct Intersection {
    bool areIntersect;
    Coordinate intersectionPoint;

    Intersection(bool areIntersect = false, const Coordinate& intersectionPoint = Coordinate())
        : areIntersect(areIntersect), intersectionPoint(intersectionPoint) {}
};


Intersection findSegmentIntersection(const Coordinate& a, const Coordinate& b, const Coordinate& c, const Coordinate& d) {
    double top1 = (d.x - c.x) * (c.y - a.y) - (d.y - c.y) * (c.x - a.x);
    double top2 = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    double bottom = (d.x - c.x) * (b.y - a.y) - (d.y - c.y) * (b.x - a.x);
    if (bottom != 0) {
        double alpha = top1 / bottom;
        double beta = top2 / bottom;
        if (alpha <= 1 && alpha > 0 && beta <= 1 && beta > 0) {
            return Intersection(true, Coordinate(a.x + alpha * (b.x - a.x), a.y + alpha * (b.y - a.y)));
        }
    }
    return Intersection();
}


vector<Coordinate> findIntersectionCoordinates(const vector<Coordinate>& triangle1, const vector<Coordinate>& triangle2) {
    // �������������� ������ ��� �������� ��������� �����������
    vector<Coordinate> intersectionPolygon;

    // ������� ��� ������� ���������� ����� � ������ intersectionPolygon
    auto uniqueInsert = [&intersectionPolygon](const Coordinate& p) {
        // ���������, ���� �� ����� p ��� � ������� intersectionPolygon
        for (const Coordinate& i : intersectionPolygon) {
            if (i == p) return;
        }
        // ���� ����� ���������, ��������� �� � ������ intersectionPolygon
        intersectionPolygon.push_back(p);
        };

    // ���������, ����� ����� �� ������������ triangle1 ��������� ������ ������������ triangle2
    for (const Coordinate& i : triangle1) {
        if (isPointInsideTriangle(i, triangle2)) {
            uniqueInsert(i);
        }
    }

    // ���������, ����� ����� �� ������������ triangle2 ��������� ������ ������������ triangle1
    for (const Coordinate& i : triangle2) {
        if (isPointInsideTriangle(i, triangle1)) {
            uniqueInsert(i);
        }
    }

    // ��������� ����������� ������ ������������� � ��������� ����� �����������, ���� ��� ����
    for (int i = 0; i < 3; ++i) {
        const Coordinate& a1 = triangle1[i];
        const Coordinate& a2 = triangle1[(i + 1) % 3];
        for (int j = 0; j < 3; ++j) {
            const Coordinate& b1 = triangle2[j];
            const Coordinate& b2 = triangle2[(j + 1) % 3];
            // ������� ����������� ������ a1a2 � b1b2
            Intersection res = findSegmentIntersection(a1, a2, b1, b2);
            // ���� ������� ������������, ��������� ����� ����������� � ������ intersectionPolygon
            if (res.areIntersect) {
                uniqueInsert(res.intersectionPoint);
            }
        }
    }

    // ���������� ������ ��������� �����������
    return intersectionPolygon;
}



double calculatePolygonArea(const vector<Coordinate>& polygon) {
    if (polygon.size() <= 2) return 0;
    if (polygon.size() == 3) return calculateTriangleArea(polygon[0], polygon[1], polygon[2]);

    Coordinate center;
    for (const Coordinate& i : polygon) {
        center.x += i.x;
        center.y += i.y;
    }
    center.x /= polygon.size();
    center.y /= polygon.size();

    vector<Coordinate> sortedPolygon = polygon;
    sort(sortedPolygon.begin(), sortedPolygon.end(), [&center](const Coordinate& a, const Coordinate& b) {
        return atan2(a.x - center.x, a.y - center.y) < atan2(b.x - center.x, b.y - center.y);
        });

    double area = 0;
    for (size_t i = 0; i < sortedPolygon.size(); ++i) {
        const Coordinate& p1 = sortedPolygon[i];
        const Coordinate& p2 = sortedPolygon[(i + 1) % sortedPolygon.size()];
        area += 0.5 * (p1.x * p2.y - p2.x * p1.y);
    }

    return abs(area);
}

int main() {
    cout << "������� ���������� ������ ������� ������������ (x y ��� ������ �������):\n";
    vector<Coordinate> triangle1;
    for (int i = 0; i < 3; ++i) {
        double x, y;
        cout << "������� ���������� " << i + 1 << " �������:\n";
        cin >> x >> y;
        triangle1.push_back(Coordinate(x, y));
    }

    cout << "������� ���������� ������ ������� ������������ (x y ��� ������ �������):\n";
    vector<Coordinate> triangle2;
    for (int i = 0; i < 3; ++i) {
        double x, y;
        cout << "������� ���������� " << i + 1 << " �������:\n";
        cin >> x >> y;
        triangle2.push_back(Coordinate(x, y));
    }

    vector<Coordinate> intersectionPolygon = findIntersectionCoordinates(triangle1, triangle2);
    double intersectionArea = calculatePolygonArea(intersectionPolygon);

    cout << "������� ����������� �������������: " << intersectionArea << endl;

    return 0;
}
