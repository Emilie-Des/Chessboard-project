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

        switch (m_pieceType.value())
        {
        case PieceType::ROOK:
            destinations = this->rookMoves(chessboard, destinations, piece_x, piece_y);
            break;

        case PieceType::BISHOP:
            destinations = this->bishopMoves(chessboard, destinations, piece_x, piece_y);
            break;

        case PieceType::KNIGHT:
            destinations = this->knightMoves(chessboard, destinations, piece_x, piece_y);
            break;

        case PieceType::KING:
            destinations = this->kingMoves(chessboard, destinations, piece_x, piece_y);
            break;

        case PieceType::QUEEN:
            destinations = this->queenMoves(chessboard, destinations, piece_x, piece_y);
            break;

        case PieceType::PAWN:
            destinations = this->pawnMoves(chessboard, destinations, piece_x, piece_y);
            break;
        }
    }
    return destinations;
}

std::vector<Piece> Piece::queenMoves(std::vector<std::vector<Piece>>& chessboard, std::vector<Piece>& destinations, int const& piece_x, int const& piece_y)
{
    bool left_border_test{};
    bool right_border_test{};
    bool upper_border_test{};
    bool bottom_border_test{};

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
    return destinations;
}

std::vector<Piece> Piece::kingMoves(std::vector<std::vector<Piece>>& chessboard, std::vector<Piece>& destinations, int const& piece_x, int const& piece_y)
{
    if (piece_x > 0)
    {
        if (piece_y > 0)
            if (!chessboard[piece_y - 1][piece_x - 1].getColor().has_value() || chessboard[piece_y - 1][piece_x - 1].getColor().value() != m_color)
                destinations.push_back(chessboard[piece_y - 1][piece_x - 1]);

        if (piece_y < 7)
            if (!chessboard[piece_y + 1][piece_x - 1].getColor().has_value() || chessboard[piece_y + 1][piece_x - 1].getColor().value() != m_color)
                destinations.push_back(chessboard[piece_y + 1][piece_x - 1]);

        if (!chessboard[piece_y][piece_x - 1].getColor().has_value() || chessboard[piece_y][piece_x - 1].getColor().value() != m_color)
            destinations.push_back(chessboard[piece_y][piece_x - 1]);
    }

    if (piece_x < 7)
    {
        if (piece_y > 0)
            if (!chessboard[piece_y - 1][piece_x + 1].getColor().has_value() || chessboard[piece_y - 1][piece_x + 1].getColor().has_value() && chessboard[piece_y - 1][piece_x + 1].getColor().value() != m_color)
                destinations.push_back(chessboard[piece_y - 1][piece_x + 1]);

        if (piece_y < 7)
            if (!chessboard[piece_y + 1][piece_x + 1].getColor().has_value() || chessboard[piece_y + 1][piece_x + 1].getColor().value() != m_color)
                destinations.push_back(chessboard[piece_y + 1][piece_x + 1]);

        if (!chessboard[piece_y][piece_x + 1].getColor().has_value() || chessboard[piece_y][piece_x + 1].getColor().value() != m_color)
            destinations.push_back(chessboard[piece_y][piece_x + 1]);
    }

    if (piece_y < 7)
        if (!chessboard[piece_y + 1][piece_x].getColor().has_value() || chessboard[piece_y + 1][piece_x].getColor().value() != m_color)
            destinations.push_back(chessboard[piece_y + 1][piece_x]);

    if (piece_y > 0)
        if (!chessboard[piece_y - 1][piece_x].getColor().has_value() || chessboard[piece_y - 1][piece_x].getColor().value() != m_color)
            destinations.push_back(chessboard[piece_y - 1][piece_x]);

    return destinations;
}

std::vector<Piece> Piece::bishopMoves(std::vector<std::vector<Piece>>& chessboard, std::vector<Piece>& destinations, int const& piece_x, int const& piece_y)
{
    bool left_border_test{};
    bool right_border_test{};
    bool upper_border_test{};
    bool bottom_border_test{};

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
    return destinations;
}

std::vector<Piece> Piece::knightMoves(std::vector<std::vector<Piece>>& chessboard, std::vector<Piece>& destinations, int const& piece_x, int const& piece_y)
{
    if (piece_x > 1)
    {
        if (piece_y > 0)
            if (!chessboard[piece_y - 1][piece_x - 2].getColor().has_value() || chessboard[piece_y - 1][piece_x - 2].getColor().value() != m_color)
                destinations.push_back(chessboard[piece_y - 1][piece_x - 2]);

        if (piece_y < 7)
            if (!chessboard[piece_y + 1][piece_x - 2].getColor().has_value() || chessboard[piece_y + 1][piece_x - 2].getColor().value() != m_color)
                destinations.push_back(chessboard[piece_y + 1][piece_x - 2]);
    }
    if (piece_x < 6)
    {
        if (piece_y > 0)
            if (!chessboard[piece_y - 1][piece_x + 2].getColor().has_value() || chessboard[piece_y - 1][piece_x + 2].getColor().value() != m_color)
                destinations.push_back(chessboard[piece_y - 1][piece_x + 2]);

        if (piece_y < 7)
            if (!chessboard[piece_y + 1][piece_x + 2].getColor().has_value() || chessboard[piece_y + 1][piece_x + 2].getColor().value() != m_color)
                destinations.push_back(chessboard[piece_y + 1][piece_x + 2]);
    }

    if (piece_y > 1)
    {
        if (piece_x > 0)
            if (!chessboard[piece_y - 2][piece_x - 1].getColor().has_value() || chessboard[piece_y - 2][piece_x - 1].getColor().value() != m_color)
                destinations.push_back(chessboard[piece_y - 2][piece_x - 1]);

        if (piece_x < 7)
            if (!chessboard[piece_y - 2][piece_x + 1].getColor().has_value() || chessboard[piece_y - 2][piece_x + 1].getColor().value() != m_color)
                destinations.push_back(chessboard[piece_y - 2][piece_x + 1]);
    }

    if (piece_y < 6)
    {
        if (piece_x > 0)
            if (!chessboard[piece_y + 2][piece_x - 1].getColor().has_value() || chessboard[piece_y + 2][piece_x - 1].getColor().value() != m_color)
                destinations.push_back(chessboard[piece_y + 2][piece_x - 1]);

        if (piece_x < 7)
            if (!chessboard[piece_y + 2][piece_x + 1].getColor().has_value() || chessboard[piece_y + 2][piece_x + 1].getColor().value() != m_color)
                destinations.push_back(chessboard[piece_y + 2][piece_x + 1]);
    }

    return destinations;
}

std::vector<Piece> Piece::rookMoves(std::vector<std::vector<Piece>>& chessboard, std::vector<Piece>& destinations, int const& piece_x, int const& piece_y)
{
    for (int i = 0; i <= 7; i++)
    {
        if (i != piece_y)
            destinations.push_back(chessboard[i][piece_x]);

        if (i != piece_x)
            destinations.push_back(chessboard[piece_y][i]);
    }
    return destinations;
}

std::vector<Piece> Piece::pawnMoves(std::vector<std::vector<Piece>>& chessboard, std::vector<Piece>& destinations, int const& piece_x, int const& piece_y)
{
    int direction{1}; ///////////Add assert direction only equal 1 or -1

    if (m_color == PieceColor::White)
    {
        direction = -1;
    }

    if (piece_y - direction == 0 || piece_y - direction == 7)
    {
        destinations.push_back(chessboard[piece_y + 1 * direction][piece_x]);
        destinations.push_back(chessboard[piece_y + 2 * direction][piece_x]);
    }
    else if (piece_y + direction < 7 && piece_y + direction > 0)
    {
        if (piece_x > 0)
        {
            Piece left_forward_piece = chessboard[piece_y + 1 * direction][piece_x - 1];

            if (left_forward_piece.getColor().has_value()
                && left_forward_piece.getColor() != m_color)
                destinations.push_back(chessboard[piece_y + 1 * direction][piece_x - 1]);
        }

        if (piece_x < 7)
        {
            Piece right_forward_piece = chessboard[piece_y + 1 * direction][piece_x + 1];

            if (right_forward_piece.getColor().has_value()
                && right_forward_piece.getColor() != m_color)
                destinations.push_back(chessboard[piece_y + 1 * direction][piece_x + 1]);
        }

        if (!chessboard[piece_y + 1 * direction][piece_x].getColor().has_value())
            destinations.push_back(chessboard[piece_y + 1 * direction][piece_x]);
    }
    return destinations;
}

bool Piece::operator==(const Piece& piece) const
{
    return ((this->m_pieceType == piece.m_pieceType) && (this->m_color == piece.m_color) && (this->m_position == piece.m_position));
}
