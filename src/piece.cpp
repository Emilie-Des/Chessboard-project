#include "piece.hpp"
#include <algorithm>
#include <cstddef>
#include <optional>
#include <vector>

Piece::Piece() : m_color(), m_pieceType(), m_position() {}
Piece::~Piece() {}

Piece::Piece(PieceColor color, PieceType type, std::pair<int, int> position) : m_color(color), m_pieceType(type), m_position(position) {}
Piece::Piece(std::pair<int, int> position) : m_color(), m_pieceType(), m_position(position) {}

PieceType Piece::getType()
{
    return m_pieceType;
}

std::optional<PieceColor> Piece::getColor()
{
    return m_color;
}

std::pair<int, int> Piece::getPosition()
{
    return m_position;
}

void Piece::showMoves(std::vector<std::vector<Piece>>& chessboard)
{ ////////Move constructor
    if (m_pieceType != PieceType::EMPTY)
    {
        std::vector<Piece> possibleMoves{};
        switch (m_pieceType)
        {
        case PieceType::KING:
            for (int y = 0; y < chessboard.size(); y++)
            {
                for (int x = 0; x < chessboard[y].size(); x++)
                {
                    if ((x == m_position.first || y == m_position.second) && std::pair(x, y) != m_position)
                    {
                    }
                }
            }
            break;
        case PieceType::QUEEN:
            break;
        case PieceType::PAWN:

            break;
        }
    }
}

void Piece::move()
{
    if (m_pieceType != PieceType::EMPTY)
    {
        switch (m_pieceType)
        {
        case PieceType::KING:
            break;
        case PieceType::QUEEN:
            break;
        case PieceType::PAWN:
            break;
        }
    }
}

std::vector<Piece> Piece::select(std::vector<std::vector<Piece>>& chessboard)
{
    std::vector<Piece> destinations{};
    if (m_pieceType != PieceType::EMPTY)
    {
        int piece_x{getPosition().second};
        int piece_y{getPosition().first};

        int biggest{};

        bool left_border_test{};
        bool right_border_test{};
        bool upper_border_test{};
        bool bottom_border_test{};

        switch (m_pieceType)
        {
        case PieceType::KING:
            for (int i = 0; i <= 7; i++)
            {
                if (i != piece_y)
                {
                    destinations.push_back(chessboard[i][piece_x]);
                }

                if (i != piece_x)
                {
                    destinations.push_back(chessboard[piece_y][i]);
                }
            }

            break;

        case PieceType::QUEEN:
            for (int i = 0; i <= 7; i++)
            {
                left_border_test   = piece_x - i >= 0;
                right_border_test  = i + piece_x <= 7;
                upper_border_test  = piece_y - i >= 0;
                bottom_border_test = i + piece_y <= 7;

                if (i != piece_y)
                {
                    destinations.push_back(chessboard[i][piece_x]);
                }
                if (i != piece_x)
                {
                    destinations.push_back(chessboard[piece_y][i]);
                }
                if (i != 0)
                {
                    if (bottom_border_test && right_border_test) // there's space in the bottom right corner
                    {
                        destinations.push_back(chessboard[piece_y + i][piece_x + i]);
                    }
                    if (upper_border_test && right_border_test) // there's space in the upper right corner
                    {
                        destinations.push_back(chessboard[piece_y - i][piece_x + i]);
                    }
                    if (bottom_border_test && left_border_test) // there's space in the bottom left corner
                    {
                        destinations.push_back(chessboard[piece_y + i][piece_x - i]);
                    }
                    if (upper_border_test && left_border_test) // there's space in the upper left corner
                    {
                        destinations.push_back(chessboard[piece_y - i][piece_x - i]);
                    }
                }
            }

            break;

        case PieceType::PAWN:
            if (m_color == PieceColor::Black)
            {
                if (piece_y < 7)
                {
                    if (piece_x != 0)
                    {
                        destinations.push_back(chessboard[piece_y + 1][piece_x - 1]);
                    }
                    if (piece_x != 7)
                    {
                        destinations.push_back(chessboard[piece_y + 1][piece_x + 1]);
                    }
                }
            }
            else
            {
                if (piece_y > 0)
                {
                    if (piece_x != 0)
                    {
                        destinations.push_back(chessboard[piece_y - 1][piece_x - 1]);
                    }
                    if (piece_x != 7)
                    {
                        destinations.push_back(chessboard[piece_y - 1][piece_x + 1]);
                    }
                }
            }

            break;
        }
    }
    return destinations;
}

bool Piece::operator==(const Piece& piece) const
{
    return ((this->m_pieceType == piece.m_pieceType) && (this->m_color == piece.m_color) && (this->m_position == piece.m_position));
}
