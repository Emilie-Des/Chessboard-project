#include <imgui.h>
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>
#include "interface.hpp"
#include "piece.hpp"
#include "quick_imgui/quick_imgui.hpp"

std::vector<std::vector<Piece>> New_Game()
{
    Piece R1{PieceColor::Black, PieceType::ROOK, std::pair(0, 0)};
    Piece N1{PieceColor::Black, PieceType::KNIGHT, std::pair(0, 1)};
    Piece B1{PieceColor::Black, PieceType::BISHOP, std::pair(0, 2)};
    Piece Q1{PieceColor::Black, PieceType::QUEEN, std::pair(0, 3)};
    Piece K1{PieceColor::Black, PieceType::KING, std::pair(0, 4)};
    Piece B2{PieceColor::Black, PieceType::BISHOP, std::pair(0, 5)};
    Piece N2{PieceColor::Black, PieceType::KNIGHT, std::pair(0, 6)};
    Piece R2{PieceColor::Black, PieceType::ROOK, std::pair(0, 7)};

    Piece P1{PieceColor::Black, PieceType::PAWN, std::pair(1, 0)};
    Piece P2{PieceColor::Black, PieceType::PAWN, std::pair(1, 1)};
    Piece P3{PieceColor::Black, PieceType::PAWN, std::pair(1, 2)};
    Piece P4{PieceColor::Black, PieceType::PAWN, std::pair(1, 3)};
    Piece P5{PieceColor::Black, PieceType::PAWN, std::pair(1, 4)};
    Piece P6{PieceColor::Black, PieceType::PAWN, std::pair(1, 5)};
    Piece P7{PieceColor::Black, PieceType::PAWN, std::pair(1, 6)};
    Piece P8{PieceColor::Black, PieceType::PAWN, std::pair(1, 7)};

    Piece C1{std::pair(2, 0)};
    Piece C2{std::pair(2, 1)};
    Piece C3{std::pair(2, 2)};
    Piece C4{std::pair(2, 3)};
    Piece C5{std::pair(2, 4)};
    Piece C6{std::pair(2, 5)};
    Piece C7{std::pair(2, 6)};
    Piece C8{std::pair(2, 7)};

    Piece D1{std::pair(3, 0)};
    Piece D2{std::pair(3, 1)};
    Piece D3{std::pair(3, 2)};
    Piece D4{std::pair(3, 3)};
    Piece D5{std::pair(3, 4)};
    Piece D6{std::pair(3, 5)};
    Piece D7{std::pair(3, 6)};
    Piece D8{std::pair(3, 7)};

    Piece E1{std::pair(4, 0)};
    Piece E2{std::pair(4, 1)};
    Piece E3{std::pair(4, 2)};
    Piece E4{std::pair(4, 3)};
    Piece E5{std::pair(4, 4)};
    Piece E6{std::pair(4, 5)};
    Piece E7{std::pair(4, 6)};
    Piece E8{std::pair(4, 7)};

    Piece F1{std::pair(5, 0)};
    Piece F2{std::pair(5, 1)};
    Piece F3{std::pair(5, 2)};
    Piece F4{std::pair(5, 3)};
    Piece F5{std::pair(5, 4)};
    Piece F6{std::pair(5, 5)};
    Piece F7{std::pair(5, 6)};
    Piece F8{std::pair(5, 7)};

    Piece P9{PieceColor::White, PieceType::PAWN, std::pair(6, 0)};
    Piece P10{PieceColor::White, PieceType::PAWN, std::pair(6, 1)};
    Piece P11{PieceColor::White, PieceType::PAWN, std::pair(6, 2)};
    Piece P12{PieceColor::White, PieceType::PAWN, std::pair(6, 3)};
    Piece P13{PieceColor::White, PieceType::PAWN, std::pair(6, 4)};
    Piece P14{PieceColor::White, PieceType::PAWN, std::pair(6, 5)};
    Piece P15{PieceColor::White, PieceType::PAWN, std::pair(6, 6)};
    Piece P16{PieceColor::White, PieceType::PAWN, std::pair(6, 7)};

    Piece R3{PieceColor::White, PieceType::ROOK, std::pair(7, 0)};
    Piece N3{PieceColor::White, PieceType::KNIGHT, std::pair(7, 1)};
    Piece B3{PieceColor::White, PieceType::BISHOP, std::pair(7, 2)};
    Piece K2{PieceColor::White, PieceType::KING, std::pair(7, 3)};
    Piece Q2{PieceColor::White, PieceType::QUEEN, std::pair(7, 4)};
    Piece B4{PieceColor::White, PieceType::BISHOP, std::pair(7, 5)};
    Piece N4{PieceColor::White, PieceType::KNIGHT, std::pair(7, 6)};
    Piece R4{PieceColor::White, PieceType::ROOK, std::pair(7, 7)};

    std::vector<std::vector<Piece>> chessboard = {
        {R1, N1, B1, Q1, K1, B2, N2, R2},
        {P1, P2, P3, P4, P5, P6, P7, P8},
        {C1, C2, C3, C4, C5, C6, C7, C8},
        {D1, D2, D3, D4, D5, D6, D7, D8},
        {E1, E2, E3, E4, E5, E6, E7, E8},
        {F1, F2, F3, F4, F5, F6, F7, F8},
        {P9, P10, P11, P12, P13, P14, P15, P16},
        {R3, N3, B3, K2, Q2, B4, N4, R4}
    };
    return chessboard;
}

int main()
{
    // io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
    std::vector<std::vector<Piece>> chessboard{New_Game()};
    int                             game_mode{0};

    // StarterMenu(game_mode);

    GameWindow(chessboard, game_mode);

    // float value{0.f};

    // quick_imgui::loop(
    //     "Chess",
    //     {
    //         .init = [&]() {},
    //         .loop =
    //             [&]() {
    //                 ImGui::ShowDemoWindow(); // This opens a window which shows tons of examples of what you can do with ImGui. You should check it out! Also, you can use the "Item Picker" in the top menu of that demo window: then click on any widget and it will show you the corresponding code directly in your IDE!

    //                 ImGui::Begin("Example");

    //                 ImGui::SliderFloat("My Value", &value, 0.f, 3.f);

    //                 if (ImGui::Button("1", ImVec2{50.f, 50.f}))
    //                     std::cout << "Clicked button 1\n";
    //                 ImGui::SameLine(); // Draw the next ImGui widget on the same line as the previous one. Otherwise it would be below it

    //                 ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{1.f, 0.f, 0.f, 1.f}); // Changes the color of all buttons until we call ImGui::PopStyleColor(). There is also ImGuiCol_ButtonActive and ImGuiCol_ButtonHovered

    //                 ImGui::PushID(2); // When some ImGui items have the same label (for exemple the next two buttons are labeled "Yo") ImGui needs you to specify an ID so that it can distinguish them. It can be an int, a pointer, a string, etc.
    //                                   // You will definitely run into this when you create a button for each of your chess pieces, so remember to give them an ID!
    //                 if (ImGui::Button("Yo", ImVec2{50.f, 50.f}))
    //                     std::cout << "Clicked button 2\n";
    //                 ImGui::PopID(); // Then pop the id you pushed after you created the widget

    //                 ImGui::SameLine();
    //                 ImGui::PushID(3);
    //                 if (ImGui::Button("Yo", ImVec2{50.f, 50.f}))
    //                     std::cout << "Clicked button 3\n";
    //                 ImGui::PopID();

    //                 ImGui::PopStyleColor();

    //                 ImGui::End();
    /////////////////////////////////////////////////
    // }
    // ,
    // }
    // );
}