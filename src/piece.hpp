// #ifndef __PIECE__HPP
// #define __PIECE__HPP
#include <array>
#include <cstdint>
#include <optional>
#include <utility>
#include <vector>

enum class PieceColor : uint8_t {
    Black,
    White
};

enum class PieceType : uint8_t {
    EMPTY,
    QUEEN,
    KING,
    BISHOP,
    KNIGHT,
    ROOK,
    PAWN
};

class Piece {
public:
    Piece();
    Piece(std::pair<int, int> position);
    Piece(PieceColor color, PieceType type, std::pair<int, int> position);
    ~Piece();

    void                      move();
    std::vector<Piece>        select(std::vector<std::vector<Piece>>& chessboard);
    std::pair<int, int>       getPosition();
    PieceType                 getType();
    std::optional<PieceColor> getColor();
    void                      showMoves(std::vector<std::vector<Piece>>& chessboard);
    bool                      operator==(const Piece& piece) const;

private:
    std::optional<PieceColor> m_color;
    PieceType                 m_pieceType;
    std::pair<int, int>       m_position; // (y,x)
};

// class Bishop {
// public:
//     Bishop();
//     ~Bishop();

//     void move();

// private:
// };