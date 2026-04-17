#include "interface.hpp"
#include <imgui.h>
#include "quick_imgui/quick_imgui.hpp"

void StarterMenu(int& game_mode)
{
    ImGui::BeginChildFrame(90, ImVec2{400, 200});
    // ImGui::OpenPopup(1);
    // ImGui::popup
    ImGui::PushStyleVar(ImGuiStyleVar_WindowMinSize, ImVec2(500, 500));
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{1.f, 0.f, 0.f, 1.f});

    if (ImGui::Button("Mode standard", ImVec2{100.f, 50.f}))
        // ImGui::CloseCurrentPopup();
        game_mode = 0;
    ImGui::SameLine();
    if (ImGui::Button("Mode Chaos", ImVec2{100.f, 50.f}))
        game_mode = 1;

    ImGui::PopStyleVar();
    ImGui::PopStyleColor();
    // ImGui::EndPopup();
    ImGui::EndChildFrame();
}

void GameWindow(std::vector<std::vector<Piece>>& chessboard, int game_mode)
{
    float              padding = 0;
    std::vector<Piece> destinations{};
    Piece*             ptr_selected{};
    const auto         ptr_addr = ptr_selected;

    quick_imgui::loop(
        "Chess",
        {
            .init = [&]() {},
            .loop =
                [&]() {
                    ImGui::Begin("Chess");
                    StarterMenu(game_mode);

                    ImGui::PushStyleVar(ImGuiStyleVar_WindowMinSize, ImVec2(1200, 1200));

                    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(padding, padding));

                    if (ImGui::IsMouseClicked(ImGuiMouseButton_Right))
                    {
                        destinations.clear();
                        ptr_selected = ptr_addr;
                    }
                    int num_case = 0;
                    for (int y{0}; y < 8; y++)
                    {
                        for (int x{0}; x < 8; x++)
                        {
                            bool is_destination{};
                            is_destination = std::find(destinations.begin(), destinations.end(), chessboard[y][x]) != destinations.end();
                            if (is_destination)
                            {
                                ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.9f, 0.5f, 0.0f, 1.f});
                            }
                            else if (y % 2 == x % 2)
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
                                {
                                    if (!destinations.empty())
                                        chessboard[y][x].move(destinations, *ptr_selected);
                                    else
                                    {
                                        destinations = chessboard[y][x].select(chessboard);
                                        ptr_selected = &chessboard[y][x];
                                        std::cout << "clicked : " << x << ";" << y << " case : " << (chessboard[y][x].getPosition()).first << ";" << (chessboard[y][x].getPosition()).second << " | ";
                                    }
                                }
                            }
                            else if (chessboard[y][x].getType() == PieceType::QUEEN)
                            {
                                if (ImGui::Button("D", ImVec2{150.f, 150.f}))
                                {
                                    if (!destinations.empty())
                                        chessboard[y][x].move(destinations, *ptr_selected);
                                    else
                                    {
                                        destinations = chessboard[y][x].select(chessboard);
                                        ptr_selected = &chessboard[y][x];
                                        std::cout << "clicked : " << x << ";" << y << " case : " << (chessboard[y][x].getPosition()).first << ";" << (chessboard[y][x].getPosition()).second << " | ";
                                    }
                                }
                            }
                            else if (chessboard[y][x].getType() == PieceType::BISHOP)
                            {
                                if (ImGui::Button("F", ImVec2{150.f, 150.f}))
                                {
                                    if (!destinations.empty())
                                        chessboard[y][x].move(destinations, *ptr_selected);
                                    else
                                    {
                                        destinations = chessboard[y][x].select(chessboard);
                                        ptr_selected = &chessboard[y][x];
                                        std::cout << "clicked : " << x << ";" << y << " case : " << (chessboard[y][x].getPosition()).first << ";" << (chessboard[y][x].getPosition()).second << " | ";
                                    }
                                }
                            }
                            else if (chessboard[y][x].getType() == PieceType::KNIGHT)
                            {
                                if (ImGui::Button("C", ImVec2{150.f, 150.f}))
                                {
                                    if (!destinations.empty())
                                        chessboard[y][x].move(destinations, *ptr_selected);
                                    else
                                    {
                                        destinations = chessboard[y][x].select(chessboard);
                                        ptr_selected = &chessboard[y][x];
                                        std::cout << "clicked : " << x << ";" << y << " case : " << (chessboard[y][x].getPosition()).first << ";" << (chessboard[y][x].getPosition()).second << " | ";
                                    }
                                }
                            }
                            else if (chessboard[y][x].getType() == PieceType::ROOK)
                            {
                                if (ImGui::Button("T", ImVec2{150.f, 150.f}))
                                {
                                    if (!destinations.empty())
                                        chessboard[y][x].move(destinations, *ptr_selected);
                                    else
                                    {
                                        destinations = chessboard[y][x].select(chessboard);
                                        ptr_selected = &chessboard[y][x];
                                        std::cout << "clicked : " << x << ";" << y << " case : " << (chessboard[y][x].getPosition()).first << ";" << (chessboard[y][x].getPosition()).second << " | ";
                                    }
                                }
                            }
                            else if (chessboard[y][x].getType() == PieceType::PAWN)
                            {
                                if (ImGui::Button("P", ImVec2{150.f, 150.f}))
                                {
                                    if (!destinations.empty())
                                        chessboard[y][x].move(destinations, *ptr_selected);
                                    else
                                    {
                                        destinations = chessboard[y][x].select(chessboard);
                                        ptr_selected = &chessboard[y][x];
                                        std::cout << "clicked : " << x << ";" << y << " case : " << (chessboard[y][x].getPosition()).first << ";" << (chessboard[y][x].getPosition()).second << " | ";
                                    }
                                }
                            }

                            else
                            {
                                if (ImGui::Button("", ImVec2{150.f, 150.f}))
                                    chessboard[y][x].move(destinations, *ptr_selected);
                            }
                            ImGui::SameLine();

                            ImGui::PopID();
                            ImGui::PopStyleColor();
                            ImGui::PopStyleColor();
                            num_case++;
                        }
                        ImGui::NewLine();
                    }

                    ImGui::PopStyleVar(2);

                    ImGui::End();
                },
        }
    );
}