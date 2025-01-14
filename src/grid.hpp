#pragma once
#include <vector>

class Grid {
    public:
        Grid(int width, int height, int cell_size)
        : rows(height/cell_size), columns(width/cell_size), cell_size(cell_size), cells(rows, std::vector<int>(columns, 0)){};
        void Draw();
        void SetValue(int row, int column, int value);
        int GetValue(int row, int column);
        bool IsWithinBounds(int row, int column);
        int GetRows() {return rows;}
        int GetColumns() {return columns;}
        void FillRandom();
        void Clear();
        void ToggleCell(int row, int column);
    private:
        int rows;
        int columns;
        int cell_size;
        std::vector<std::vector<int>> cells;
};