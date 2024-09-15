#include <iostream>
#include <algorithm>

int maxArea(int heights[], int num) {
    int maxArea = 0;
    int x = 0, y = num - 1;

    while (x < y) {
        int area = std::min(heights[x], heights[y]) * (y- x);
        maxArea = std::max(maxArea, area);

        if (heights[x] < heights[y]) {
            x++;
        } else {
            y--;
        }
    }

    return maxArea;
}

int main() {
    int num;
    std::cout << "Enter the number of elements: ";
    std::cin >> num;

    int heights[num];
    std::cout << "Enter the heights: ";
    for (int i = 0; i < num; ++i) {
        std::cin >> heights[i];
    }

    std::cout << "Max area: " << maxArea(heights, num) << std::endl;
    return 0;
}
