// C++ program for DDA Line Drawing algorithm.

#include <iostream>
#include <cmath>
#include <graphics.h>

// Function to implement DDA Line Drawing Algorithm
void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;

    float x = x1;
    float y = y1;

    putpixel(round(x), round(y), WHITE);

    for (int i = 1; i <= steps; i++) {
        x += xIncrement;
        y += yIncrement;
        putpixel(round(x), round(y), WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1, y1, x2, y2;

    std::cout << "Enter the coordinates of the first point (x1, y1): ";
    std::cin >> x1 >> y1;

    std::cout << "Enter the coordinates of the second point (x2, y2): ";
    std::cin >> x2 >> y2;

    drawLineDDA(x1, y1, x2, y2);

    delay(5000); // Display the line for 5 seconds
    closegraph();

    return 0;
}
