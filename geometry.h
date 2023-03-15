//
// Created by antoine7805 on 15/03/2023.
//

#ifndef PROJETTI202_GEOMETRY_H
#define PROJETTI202_GEOMETRY_H



typedef struct {
    int x;
    int y;
} Point;

typedef struct {
        Point* p1;
        Point* p2;
} Line;

typedef struct {
        Point* center;
        int radius;
} Circle;

typedef struct {
    Point* p1;
    Point* p2;
} Rectangle;

typedef struct {
    Point* p;
    int side;
} Square;

typedef struct {
    Point** points;
} Polygon;

Point* createPoint(int x, int y);
void freePoint(Point* point);
void printPoint(Point* point);

Line* createLine(Point* p1, Point* p2);
void freeLine(Line* line);
void printLine(Line* line);

#endif //PROJETTI202_GEOMETRY_H
