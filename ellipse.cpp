#include <iostream>
#include <graphics.h>
using namespace std;
#define ROUND(a) ((int)(a+0.5))

void ellipsePlotPoints(int xCenter, int yCenter, int x, int y) {
    putpixel(xCenter + x, yCenter + y, GREEN);
    putpixel(xCenter - x, yCenter + y, GREEN);
    putpixel(xCenter + x, yCenter - y, GREEN);
    putpixel(xCenter - x, yCenter - y, GREEN);
}

void ellipseMidpoint(int xCenter, int yCenter, int Rx, int Ry) {
    int Rx2 = Rx * Rx;
    int Ry2 = Ry * Ry;
    int twoRx2 = 2 * Rx2;
    int twoRy2 = 2 * Ry2;
    int p;
    int x = 0;
    int y = Ry;
    int px = 0;
    int py = twoRx2 * y;

    // Plot the first set of points 
    ellipsePlotPoints(xCenter, yCenter, x, y);

    // Region 1 
    p = ROUND(Ry2 - (Rx2 * Ry) + (0.25 * Rx2));
    while (px < py) {
        x++;
        px += twoRy2;
        if (p < 0)
            p += Ry2 + px;
        else {
            y--;
            py -= twoRx2;
            p += Ry2 + px - py;
        }
        ellipsePlotPoints(xCenter, yCenter, x, y);
    }

    // Region 2
    p = ROUND(Ry2 * (x + 0.5) * (x + 0.5) + Rx2 * (y - 1) * (y - 1) - Rx2 * Ry2);
    while (y > 0) {
        y--;
        py -= twoRx2;
        if (p > 0)
            p += Rx2 - py;
        else {
            x++;
            px += twoRy2;
            p += Rx2 - py + px;
        }
        ellipsePlotPoints(xCenter, yCenter, x, y);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int a, b, xcen, ycen;

    cout << "Length of major axis of the ellipse: ";
  	cin >> a;
    cout << "Length of minor axis of the ellipse: ";
    cin >> b;
    cout << "Enter coordinates of center: ";
    cin >> xcen >> ycen;

    ellipseMidpoint(xcen, ycen, a, b);

    getch();
    closegraph();

    return 0;
}

