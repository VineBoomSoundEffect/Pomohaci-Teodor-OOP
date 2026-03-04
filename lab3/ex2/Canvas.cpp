#include <iostream>
#include <stdlib.h>
#include "Canvas.h"

Canvas::Canvas(int width, int height) {
    this->width = width;
    this->height = height;
    this->canvas = (char **)malloc(width * sizeof(char *));
    for (int i = 0; i < width; i++) {
        this->canvas[i] = (char *)malloc(height * sizeof(char));
    }
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            this->canvas[i][j] = ' ';
        }
    }
}
void Canvas::DrawCircle(int x, int y, int ray, char ch) {
}
void Canvas::FillCircle(int x, int y, int ray, char ch) {
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for(int i = left; i <= right; i++) {
        this->canvas[top][i] = ch;
        this->canvas[bottom][i] = ch;
    }
    for(; top <= bottom; top++) {
        this->canvas[top][left] = ch;
        this->canvas[top][right] = ch;
    }
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for(; top <= bottom; top++) {
        for(int i = left; i <= right; i++) {
            this->canvas[top][i] = ch;
        }
    }
}
void Canvas::SetPoint(int x, int y, char ch) {
    this->canvas[y][x] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int x, y, dx, dy, D;

    dx = x2 - x1;
    dy = y2 - y1;

    D = 2 * dy - dx;
    x = x1;
    y = y1;

    while (x <= x2) {
        this->canvas[y][x] = ch;
        if (D > 0) {
            y++;
            D += 2 * (dy - dx);
        }
        else D += 2 * dy;
        x++;
    }
}
void Canvas::Print() {
    for (int i = 0; i < this->width; i++) {
        for (int j = 0; j < this->width; j++) {
            std::cout << this->canvas[i][j];
        }
        std::cout << "\n";
    }
}
void Canvas::Clear() {
    for (int i = 0; i < this->width; i++) {
        for (int j = 0; j < this->width; j++) {
            this->canvas[i][j] = ' ';
        }
    }
}
