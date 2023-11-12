#include <iostream>

int main() {
    double H, W, x1, y1, x2, y2, w, h, dist;
    std::cout << "Set H: ";
    std::cin >> H;
    std::cout << "Set W: ";
    std::cin >> W;
    std::cout << "Set x1: ";
    std::cin >> x1;
    std::cout << "Set y1: ";
    std::cin >> y1;
    std::cout << "Set x2: ";
    std::cin >> x2;
    std::cout << "Set y2: ";
    std::cin >> y2;
    std::cout << "Set w: ";
    std::cin >> w;
    std::cout << "Set h: ";
    std::cin >> h;




    if (w < x1 || h < y1) {
        std::cout << "0";
    }

    else if (((x2 - W / 2) >= (W / 2 - x1)) && ((y2 - H / 2) >= (H / 2 - y1))) {
        if (w - x1 <= h - y1) {
            dist = w - x1;
            std::cout << dist;
        }
        else {
            dist = h - y1;
            std::cout << dist;
        }

    }
    else if (((x2 - W / 2) >= (W / 2 - x1)) && ((y2 - H / 2) <= (H / 2 - y1))) {
        if (w - x1 <= h - y2) {
            dist = w - x1;
            std::cout << dist;
        }
        else {
            dist = h - y2;
            std::cout << -dist;
        }
    }

    else if (((x2 - W / 2) <= (W / 2 - x1)) && ((y2 - H / 2) <= (H / 2 - y1))) {
        if (w - x2 <= h - y2) {
            dist = w - x2;
            std::cout << -dist;
        }
        else {
            dist = h - y2;
            std::cout << -dist;
        }
    }

    else if (((x2 - W / 2) <= (W / 2 - x1)) && ((y2 - H / 2) >= (H / 2 - y1))) {
        if (w - x2 <= h - y1) {
            dist = w - x2;
            std::cout << -dist;
        }
        else {
            dist = h - y1;
            std::cout << dist;
        }

    }

    else {
        std::cout << "Impossible to fit two tables";
    }
}