#include <raylib.h>
#include <iostream>
#include "simulation.hpp"

int main() {
    Color grey = {29, 29, 29, 255};
    const int window_width = 1000;
    const int window_height = 1000;
    const int cell_size = 5;
    int fps = 12;

    InitWindow(window_width, window_height, "Game of Life");
    SetTargetFPS(fps);
    Simulation simulation {window_width, window_height, cell_size};

    // Simulation loop
    while (WindowShouldClose() == false) {
    
        // 1. Event handling
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Vector2 mouse_position = GetMousePosition();
            int row = mouse_position.y / cell_size;
            int column = mouse_position.x / cell_size;
            simulation.ToggleCell(row, column);
        }
        if (IsKeyPressed(KEY_ENTER)) {
            simulation.Start();
            SetWindowTitle("Game of Life is running...");
        }
        else if (IsKeyPressed(KEY_SPACE)) {
            simulation.Stop();
            SetWindowTitle("Game of Life is stopped.");
        }
        else if (IsKeyPressed(KEY_F)) {
            fps += 2;
            SetTargetFPS(fps);
        }
        else if (IsKeyPressed(KEY_S)) {
            if (fps > 5) {
                fps -= 2;
                SetTargetFPS(fps);
            }
        }
        else if (IsKeyPressed(KEY_R)) {
            simulation.CreateRandomState();
        }
        else if (IsKeyPressed(KEY_C)) {
            simulation.ClearGrid();
        }

        // 2. Updating state
        simulation.Update();

        // 3. Drawing
        BeginDrawing();
        ClearBackground(grey);
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
}