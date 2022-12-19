#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct XY {
    float x, y;
} XY;
static const XY *xy_origin;

int turn(const void *p1, const void *p2) {
    const XY *xy1 = p1, *xy2 = p2;
    XY  origin_xy1 = {xy1->x - xy_origin->x, xy1->y - xy_origin->y},
        origin_xy2 = {xy2->x - xy_origin->x, xy2->y - xy_origin->y};

    long long area = (long long) origin_xy1.x * origin_xy2.y - (long long) origin_xy1.y * origin_xy2.x;
    return (area > 0) - (area < 0);
}

float traverse_clockwise(XY coord[], const unsigned n) {
    double perimeter = 0;
    double len[50] = {0};

    for (unsigned i = 1; i < n; ++i)
        if (coord[i].y < coord[0].y) {
            XY temp = coord[0];
            coord[0] = coord[i];
            coord[i] = temp;
        }

    xy_origin = &coord[0];
    qsort(coord + 1, n - 1, sizeof *coord, turn);
    for (int i = 0; i < n; ++i)
        printf("{%f, %f}\n", coord[i].x, coord[i].y);

    for (int i = 0; i < n; i++) {
        if (i < n - 1)
            len[i] = sqrt(pow((coord[i + 1].x - coord[i].x), 2) + pow((coord[i + 1].y - coord[i].y), 2));
        else
            len[i] = sqrt(pow((coord[0].x - coord[i].x), 2) + pow((coord[0].y - coord[i].y), 2));
    }

    for (int i = 0; i < n; i++)
        perimeter = perimeter + len[i];
    return perimeter;
}

int main() {
    XY coord[] = {76, 67.1, -8.3, 18, 55, 93.3, 77, 33, 21.3, 99, -20, 50, -8.3, 82, 55, 6.7,  21.3, 0.76};
//    XY coord[] = {3.97, 0.82, 2.26, 3.69, 5.39, 2.16, 2.03, 2.11, 5.36, 4.06};
//    XY coord[] = {1, 5, 7, 1, 7, 5, 1, 1};
    const int n = sizeof coord / sizeof *coord;
    printf("Perimeter of the figure = %f", traverse_clockwise(coord, n));
}
