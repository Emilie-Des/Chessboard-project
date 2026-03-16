#include "piece.hpp"
#include <cstddef>
#include <optional>
#include <vector>

Piece::Piece() : m_color(), m_pieceType(), m_position() {}
Piece::~Piece() {}

Piece::Piece(PieceColor color, PieceType type, std::pair<int, int> position) : m_color(color), m_pieceType(type), m_position(position) {}

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

void Piece::showMoves(std::array<std::array<Piece, 8>, 8>& chessboard)
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

std::vector<Piece> Piece::select(std::array<std::array<Piece, 8>, 8>& chessboard)
{
    std::vector<Piece> destinations{};
    if (m_pieceType != PieceType::EMPTY)
    {
        switch (m_pieceType)
        {
        case PieceType::KING:
            break;
        case PieceType::QUEEN:
            break;
        case PieceType::PAWN:
            if (m_color == PieceColor::Black)
            {
                destinations.push_back(chessboard[m_position.first][m_position.second - 1]);
            }
            else
            {
                destinations.push_back(chessboard[m_position.first][m_position.second + 1]);
            }

            break;
        }
    }
    return destinations;
}
