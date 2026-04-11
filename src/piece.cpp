#include "piece.hpp"
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
        int x{};
        int y{};

        switch (m_pieceType)
        {
        case PieceType::KING:
            break;
        case PieceType::QUEEN:
            break;
        case PieceType::PAWN:
            if (m_color == PieceColor::Black)
            {
                if (m_position.first < 7)
                {
                    if (m_position.second != 0)
                    {
                        destinations.push_back(chessboard[m_position.first + 1][m_position.second - 1]);
                    }
                    if (m_position.second != 7)
                    {
                        destinations.push_back(chessboard[m_position.first + 1][m_position.second + 1]);
                    }
                }
            }
            else
            {
                if (m_position.first > 0)
                {
                    if (m_position.second != 0)
                    {
                        destinations.push_back(chessboard[m_position.first - 1][m_position.second - 1]);
                    }
                    if (m_position.second != 7)
                    {
                        destinations.push_back(chessboard[m_position.first - 1][m_position.second + 1]);
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
