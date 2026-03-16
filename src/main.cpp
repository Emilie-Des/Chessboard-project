#include <imgui.h>
#include <array>
#include <iostream>
#include "piece.hpp"
#include "quick_imgui/quick_imgui.hpp"

std::array<std::array<Piece, 8>, 8> New_Game()
{
    // Piece R1{PieceColor::Black, PieceType::ROOK};
    // Piece N1{PieceColor::Black, PieceType::KNIGHT};
    // Piece B1{PieceColor::Black, PieceType::BISHOP};
    // Piece Q1{PieceColor::Black, PieceType::QUEEN};
    // Piece K1{PieceColor::Black, PieceType::KING};
    // Piece B2{PieceColor::Black, PieceType::BISHOP};
    // Piece N2{PieceColor::Black, PieceType::KNIGHT};
    // Piece R2{PieceColor::Black, PieceType::ROOK};

    // Piece P1{PieceColor::Black, PieceType::PAWN};
    // Piece P2{PieceColor::Black, PieceType::PAWN};
    // Piece P3{PieceColor::Black, PieceType::PAWN};
    // Piece P4{PieceColor::Black, PieceType::PAWN};
    // Piece P5{PieceColor::Black, PieceType::PAWN};
    // Piece P6{PieceColor::Black, PieceType::PAWN};
    // Piece P7{PieceColor::Black, PieceType::PAWN};
    // Piece P8{PieceColor::Black, PieceType::PAWN};

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

    Piece C1, C2, C3, C4, C5, C6, C7, C8{};
    Piece D1, D2, D3, D4, D5, D6, D7, D8{};
    Piece E1, E2, E3, E4, E5, E6, E7, E8{};
    Piece F1, F2, F3, F4, F5, F6, F7, F8{};

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

    std::array<std::array<Piece, 8>, 8> chessboard{
        R1, N1, B1, Q1, K1, B2, N2, R2,
        P1, P2, P3, P4, P5, P6, P7, P8,
        C1, C2, C3, C4, C5, C6, C7, C8,
        D1, D2, D3, D4, D5, D6, D7, D8,
        E1, E2, E3, E4, E5, E6, E7, E8,
        F1, F2, F3, F4, F5, F6, F7, F8,
        P9, P10, P11, P12, P13, P14, P15, P16,
        R3, N3, B3, K2, Q2, B4, N4, R4
    };
    ///////////////////////Comment faire un mouv ?
    return chessboard;
}

int main()
{
    float value{0.f};

    float padding = 0;

    quick_imgui::loop(
        "Chess",
        {
            .init = [&]() {},
            .loop =
                [&]() {
                    ImGui::ShowDemoWindow(); // This opens a window which shows tons of examples of what you can do with ImGui. You should check it out! Also, you can use the "Item Picker" in the top menu of that demo window: then click on any widget and it will show you the corresponding code directly in your IDE!

                    ImGui::Begin("Example");

                    ImGui::SliderFloat("My Value", &value, 0.f, 3.f);

                    if (ImGui::Button("1", ImVec2{50.f, 50.f}))
                        std::cout << "Clicked button 1\n";
                    ImGui::SameLine(); // Draw the next ImGui widget on the same line as the previous one. Otherwise it would be below it

                    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{1.f, 0.f, 0.f, 1.f}); // Changes the color of all buttons until we call ImGui::PopStyleColor(). There is also ImGuiCol_ButtonActive and ImGuiCol_ButtonHovered

                    ImGui::PushID(2); // When some ImGui items have the same label (for exemple the next two buttons are labeled "Yo") ImGui needs you to specify an ID so that it can distinguish them. It can be an int, a pointer, a string, etc.
                                      // You will definitely run into this when you create a button for each of your chess pieces, so remember to give them an ID!
                    if (ImGui::Button("Yo", ImVec2{50.f, 50.f}))
                        std::cout << "Clicked button 2\n";
                    ImGui::PopID(); // Then pop the id you pushed after you created the widget

                    ImGui::SameLine();
                    ImGui::PushID(3);
                    if (ImGui::Button("Yo", ImVec2{50.f, 50.f}))
                        std::cout << "Clicked button 3\n";
                    ImGui::PopID();

                    ImGui::PopStyleColor();

                    ImGui::End();
                    /////////////////////////////////////////////////
                    std::array<std::array<Piece, 8>, 8> chessboard{New_Game()};

                    ImGui::Begin("Chess");
                    ImGui::PushStyleVar(ImGuiStyleVar_WindowMinSize, ImVec2(1200, 1200));

                    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(padding, padding));

                    int                num_case = 0;
                    std::vector<Piece> destinations{};

                    for (int y{0}; y < 8; y++)
                    {
                        for (int x{0}; x < 8; x++)
                        {
                            if (y % 2 == x % 2)
                            {
                                ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.9f, 0.7f, 0.9f, 1.f});
                            }
                            else
                            {
                                ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.3f, 0.f, 0.3f, 1.f});
                            }

                            if (chessboard[y][x].getColor() == PieceColor::Black)
                            {
                                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4{0.f, 0.f, 0.f, 1.f});
                            }
                            else
                            {
                                ImGui::PushStyleColor(ImGuiCol_Text, ImVec4{1.f, 1.f, 1.f, 1.f});
                            }

                            ImGui::PushID(num_case);

                            if (chessboard[y][x].getType() == PieceType::KING)
                            {
                                if (ImGui::Button("R", ImVec2{150.f, 150.f}))
                                    std::cout << y << "," << x << "  ";
                            }
                            else if (chessboard[y][x].getType() == PieceType::QUEEN)
                            {
                                if (ImGui::Button("D", ImVec2{150.f, 150.f}))
                                    std::cout << y << "," << x << "  ";
                            }
                            else if (chessboard[y][x].getType() == PieceType::BISHOP)
                            {
                                if (ImGui::Button("F", ImVec2{150.f, 150.f}))
                                    std::cout << y << "," << x << "  ";
                            }
                            else if (chessboard[y][x].getType() == PieceType::KNIGHT)
                            {
                                if (ImGui::Button("C", ImVec2{150.f, 150.f}))
                                    std::cout << y << "," << x << "  ";
                            }
                            else if (chessboard[y][x].getType() == PieceType::ROOK)
                            {
                                if (ImGui::Button("T", ImVec2{150.f, 150.f}))
                                    std::cout << y << "," << x << "  ";
                            }
                            else if (chessboard[y][x].getType() == PieceType::PAWN)
                            {
                                if (ImGui::Button("P", ImVec2{150.f, 150.f}))
                                    destinations = chessboard[x][y].select(chessboard);
                                // std::cout << y << "," << x << "  ";
                            }

                            else
                            {
                                if (ImGui::Button("", ImVec2{150.f, 150.f}))
                                    std::cout << y << "," << x << "  ";
                            }
                            ImGui::SameLine();

                            ImGui::PopID();
                            ImGui::PopStyleColor();
                            ImGui::PopStyleColor();
                            num_case++;
                        }
                        ImGui::NewLine();
                    }

                    for (auto piece : destinations)
                    {
                        ImGui::PushStyleColor(ImGuiCol_Border, ImVec4{0.9f, 0.2f, 0.9f, 1.f});
                    }

                    ImGui::PopStyleVar(2);

                    ImGui::End();
                },
        }
    );
}