#include "piece.hpp"
#include <algorithm>
#include <cstddef>
#include <optional>
#include <vector>

Piece::Piece() : m_color(), m_pieceType(), m_position() {}
Piece::~Piece() {}

Piece::Piece(std::optional<PieceColor> color, std::optional<PieceType> type, std::pair<int, int> position) : m_color(color), m_pieceType(type), m_position(position) {}
Piece::Piece(std::pair<int, int> position) : m_color(std::nullopt), m_pieceType(std::nullopt), m_position(position) {}

std::optional<PieceType> Piece::getType()
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

void Piece::setColor(std::optional<PieceColor> new_color)
{
    m_color = new_color;
}

void Piece::setType(std::optional<PieceType> new_type)
{
    m_pieceType = new_type;
}

void Piece::showMoves(std::vector<std::vector<Piece>>& chessboard)
{ ////////Move constructor
    if (m_pieceType.has_value())
    {
        std::vector<Piece> possibleMoves{};
        switch (m_pieceType.value())
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

void Piece::move(std::vector<Piece>& destinations, Piece& moving_piece)
{
    if (std::find(destinations.begin(), destinations.end(), *this) != destinations.end())
    {
        std::optional<PieceColor> col = moving_piece.getColor();
        this->setColor(col);
        this->setType(moving_piece.getType());

        moving_piece.setType(std::nullopt);
        moving_piece.setColor(std::nullopt);

        destinations.clear();
    }
}

std::vector<Piece> Piece::select(std::vector<std::vector<Piece>>& chessboard)
{
    std::vector<Piece> destinations{};
    if (m_pieceType.has_value())
    {
        int piece_x{getPosition().second};
        int piece_y{getPosition().first};

        int biggest{};

        bool left_border_test{};
        bool right_border_test{};
        bool upper_border_test{};
        bool bottom_border_test{};

        bool left_enemy_test{};
        bool right_enemy_test{};

        switch (m_pieceType.value())
        {
        case PieceType::ROOK:
            for (int i = 0; i <= 7; i++)
            {
                if (i != piece_y)
                    destinations.push_back(chessboard[i][piece_x]);

                if (i != piece_x)
                    destinations.push_back(chessboard[piece_y][i]);
            }
            break;

        case PieceType::BISHOP:
            for (int i = 0; i <= 7; i++)
            {
                left_border_test   = piece_x - i >= 0;
                right_border_test  = i + piece_x <= 7;
                upper_border_test  = piece_y - i >= 0;
                bottom_border_test = i + piece_y <= 7;

                if (bottom_border_test && right_border_test) // there's space in the bottom right corner
                    destinations.push_back(chessboard[piece_y + i][piece_x + i]);

                if (upper_border_test && right_border_test) // there's space in the upper right corner
                    destinations.push_back(chessboard[piece_y - i][piece_x + i]);

                if (bottom_border_test && left_border_test) // there's space in the bottom left corner
                    destinations.push_back(chessboard[piece_y + i][piece_x - i]);

                if (upper_border_test && left_border_test) // there's space in the upper left corner
                    destinations.push_back(chessboard[piece_y - i][piece_x - i]);
            }
            break;

        case PieceType::KNIGHT:
            if (piece_x > 1)
            {
                if (piece_y > 0)
                    destinations.push_back(chessboard[piece_y - 1][piece_x - 2]);

                if (piece_y < 7)
                    destinations.push_back(chessboard[piece_y + 1][piece_x - 2]);
            }
            if (piece_x < 6)
            {
                if (piece_y > 0)
                    destinations.push_back(chessboard[piece_y - 1][piece_x + 2]);

                if (piece_y < 7)
                    destinations.push_back(chessboard[piece_y + 1][piece_x + 2]);
            }

            if (piece_y > 1)
            {
                if (piece_x > 0)
                    destinations.push_back(chessboard[piece_y - 2][piece_x - 1]);

                if (piece_x < 7)
                    destinations.push_back(chessboard[piece_y - 2][piece_x + 1]);
            }

            if (piece_y < 6)
            {
                if (piece_x > 0)
                    destinations.push_back(chessboard[piece_y + 2][piece_x - 1]);

                if (piece_x < 7)
                    destinations.push_back(chessboard[piece_y + 2][piece_x + 1]);
            }

            break;

        case PieceType::KING:
            if (piece_x > 0)
            {
                if (piece_y > 0)
                    destinations.push_back(chessboard[piece_y - 1][piece_x - 1]);

                if (piece_y < 7)
                    destinations.push_back(chessboard[piece_y + 1][piece_x - 1]);

                destinations.push_back(chessboard[piece_y][piece_x - 1]);
            }

            if (piece_x < 7)
            {
                if (piece_y > 0)
                    destinations.push_back(chessboard[piece_y - 1][piece_x + 1]);

                if (piece_y < 7)
                    destinations.push_back(chessboard[piece_y + 1][piece_x + 1]);

                destinations.push_back(chessboard[piece_y][piece_x + 1]);
            }

            if (piece_y < 7)
                destinations.push_back(chessboard[piece_y + 1][piece_x]);

            if (piece_y > 0)
                destinations.push_back(chessboard[piece_y - 1][piece_x]);

            break;

        case PieceType::QUEEN:
            for (int i = 0; i <= 7; i++)
            {
                left_border_test   = piece_x - i >= 0;
                right_border_test  = i + piece_x <= 7;
                upper_border_test  = piece_y - i >= 0;
                bottom_border_test = i + piece_y <= 7;

                if (i != piece_y)
                    destinations.push_back(chessboard[i][piece_x]);

                if (i != piece_x)
                    destinations.push_back(chessboard[piece_y][i]);

                if (i != 0)
                {
                    if (bottom_border_test && right_border_test) // there's space in the bottom right corner
                        destinations.push_back(chessboard[piece_y + i][piece_x + i]);

                    if (upper_border_test && right_border_test) // there's space in the upper right corner
                        destinations.push_back(chessboard[piece_y - i][piece_x + i]);

                    if (bottom_border_test && left_border_test) // there's space in the bottom left corner
                        destinations.push_back(chessboard[piece_y + i][piece_x - i]);

                    if (upper_border_test && left_border_test) // there's space in the upper left corner
                        destinations.push_back(chessboard[piece_y - i][piece_x - i]);
                }
            }

            break;

        case PieceType::PAWN:
            if (m_color == PieceColor::Black)
            {
                if (piece_y == 1)
                {
                    destinations.push_back(chessboard[piece_y + 1][piece_x]);
                    destinations.push_back(chessboard[piece_y + 2][piece_x]);
                }
                else if (piece_y < 7)
                {
                    left_enemy_test  = chessboard[piece_y + 1][piece_x - 1].getColor() == PieceColor::White;
                    right_enemy_test = chessboard[piece_y + 1][piece_x + 1].getColor() == PieceColor::White;

                    if (piece_x > 0)
                        if (left_enemy_test)
                            destinations.push_back(chessboard[piece_y + 1][piece_x - 1]);

                    if (piece_x < 7)
                        if (right_enemy_test)
                            destinations.push_back(chessboard[piece_y + 1][piece_x + 1]);

                    if (!(left_enemy_test || right_enemy_test))
                        destinations.push_back(chessboard[piece_y + 1][piece_x]);
                }
            }
            else
            {
                if (piece_y == 6)
                {
                    destinations.push_back(chessboard[piece_y - 1][piece_x]);
                    destinations.push_back(chessboard[piece_y - 2][piece_x]);
                }
                else if (piece_y > 0)
                {
                    left_enemy_test  = chessboard[piece_y - 1][piece_x - 1].getColor() == PieceColor::Black;
                    right_enemy_test = chessboard[piece_y - 1][piece_x + 1].getColor() == PieceColor::Black;

                    if (!(left_enemy_test || right_enemy_test))
                        destinations.push_back(chessboard[piece_y - 1][piece_x]);

                    if (piece_x != 0)
                        if (left_enemy_test)
                            destinations.push_back(chessboard[piece_y - 1][piece_x - 1]);

                    if (piece_x != 7)
                        if (right_enemy_test)
                            destinations.push_back(chessboard[piece_y - 1][piece_x + 1]);
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
