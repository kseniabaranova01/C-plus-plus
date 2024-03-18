#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Структура для хранения точки на плоскости
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
    // Инициализация переменной для хранения результата (в начале предполагаем, что точка находится снаружи треугольника)
    bool res = false;

    // Проходим по каждой стороне треугольника
    for (int i = 0; i < 3; ++i) {
        // Получаем начальную и конечную точки текущей стороны
        const Coordinate& sideStart = triangle[i];
        const Coordinate& sideEnd = triangle[(i + 1) % 3];

        // Если текущая сторона параллельна оси y, пропускаем ее
        if (sideStart.y == sideEnd.y) continue;

        // Проверяем условие пересечения по оси y для текущей стороны
        bool conditionY = (p.y < sideStart.y) != (p.y < sideEnd.y);

        // Проверяем условие пересечения по оси x для текущей стороны
        bool conditionX = p.x < (sideStart.x + ((p.y - sideStart.y) / (sideEnd.y - sideStart.y)) * (sideEnd.x - sideStart.x));

        // Если оба условия выполнены, меняем значение результата
        if (conditionX && conditionY) {
            res = !res;
        }
    }
    // Возвращаем результат: true, если точка находится внутри треугольника, иначе false
    return res;
}


// Структура для хранения результата пересечения отрезков
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
    // Инициализируем вектор для хранения координат пересечения
    vector<Coordinate> intersectionPolygon;

    // Функция для вставки уникальных точек в вектор intersectionPolygon
    auto uniqueInsert = [&intersectionPolygon](const Coordinate& p) {
        // Проверяем, есть ли точка p уже в векторе intersectionPolygon
        for (const Coordinate& i : intersectionPolygon) {
            if (i == p) return;
        }
        // Если точка уникальна, добавляем ее в вектор intersectionPolygon
        intersectionPolygon.push_back(p);
        };

    // Проверяем, какие точки из треугольника triangle1 находятся внутри треугольника triangle2
    for (const Coordinate& i : triangle1) {
        if (isPointInsideTriangle(i, triangle2)) {
            uniqueInsert(i);
        }
    }

    // Проверяем, какие точки из треугольника triangle2 находятся внутри треугольника triangle1
    for (const Coordinate& i : triangle2) {
        if (isPointInsideTriangle(i, triangle1)) {
            uniqueInsert(i);
        }
    }

    // Проверяем пересечения сторон треугольников и добавляем точки пересечения, если они есть
    for (int i = 0; i < 3; ++i) {
        const Coordinate& a1 = triangle1[i];
        const Coordinate& a2 = triangle1[(i + 1) % 3];
        for (int j = 0; j < 3; ++j) {
            const Coordinate& b1 = triangle2[j];
            const Coordinate& b2 = triangle2[(j + 1) % 3];
            // Находим пересечение сторон a1a2 и b1b2
            Intersection res = findSegmentIntersection(a1, a2, b1, b2);
            // Если стороны пересекаются, добавляем точку пересечения в вектор intersectionPolygon
            if (res.areIntersect) {
                uniqueInsert(res.intersectionPoint);
            }
        }
    }

    // Возвращаем вектор координат пересечения
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
    cout << "Введите координаты вершин первого треугольника (x y для каждой вершины):\n";
    vector<Coordinate> triangle1;
    for (int i = 0; i < 3; ++i) {
        double x, y;
        cout << "Введите координаты " << i + 1 << " вершины:\n";
        cin >> x >> y;
        triangle1.push_back(Coordinate(x, y));
    }

    cout << "Введите координаты вершин второго треугольника (x y для каждой вершины):\n";
    vector<Coordinate> triangle2;
    for (int i = 0; i < 3; ++i) {
        double x, y;
        cout << "Введите координаты " << i + 1 << " вершины:\n";
        cin >> x >> y;
        triangle2.push_back(Coordinate(x, y));
    }

    vector<Coordinate> intersectionPolygon = findIntersectionCoordinates(triangle1, triangle2);
    double intersectionArea = calculatePolygonArea(intersectionPolygon);

    cout << "Площадь пересечения треугольников: " << intersectionArea << endl;

    return 0;
}
