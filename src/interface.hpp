#include <imgui.h>
#include <iostream>
#include "piece.hpp"

#pragma once

void StarterMenu(int& game_mode);
void GameWindow(std::vector<std::vector<Piece>>& chessboard, int game_mode);