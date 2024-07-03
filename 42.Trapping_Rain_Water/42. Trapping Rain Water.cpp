#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0; // Случаи, когда вектор слишком мал для хранения воды

        bool tmpBegin = true, tmpEnd = true;
        int x = 0;

        // Удаление всех начальных элементов до первого элемента, который не меньше следующего
        while (tmpBegin && x < height.size() - 1) {
            if (height[x] < height[x + 1]) x++;
            else {
                height.erase(height.begin(), height.begin() + x);
                tmpBegin = false;
            }
        }

        if (height.size() < 3) return 0;

        int y = height.size() - 1;

        // Удаление всех конечных элементов после последнего элемента, который не меньше предыдущего
        while (tmpEnd && y > 0) {
            if (height[y] < height[y - 1]) {
                y--;
            }
            else {
                height.erase(height.begin() + y + 1, height.end());
                tmpEnd = false;
            }
        }

        if (height.size() < 3) return 0;

        int leftBorder = 0, rightBorder = 0, count = 0, area = 0, result = 0, columnHeight = 0, leftBorderIndex = 0, rightBorderIndex = 0;
        int i = 1;

        // Основной цикл для вычисления площади удерживаемой воды
        while (i < height.size()) {
            leftBorderIndex = i - 1;
            leftBorder = height[i - 1];
            rightBorderIndex = i;
            rightBorder = height[i];

            while (leftBorder - rightBorder > columnHeight && i < height.size()) {
                i++;
                if (i >= height.size()) {
                    // Возврат и повторная попытка с увеличенной высотой столбца
                    i = rightBorderIndex;
                    columnHeight++;
                    count = -1;
                }
                if (i < height.size()) {
                    rightBorder = height[i];
                }
                count++;
            }

            // Вычисление площади удерживаемой воды
            area = min(leftBorder, rightBorder) * count;

            for (int j = leftBorderIndex + 1; j < i; j++) {
                area -= height[j];
            }
            result += area;

            // Обнуление переменных
            area = 0;
            i++;
            count = 0;
            columnHeight = 0;
        }
        return result;
    }
};



int main()
{
	Solution s;
	vector<int>heights = { 0, 2, 0};
	cout << s.trap(heights);
}