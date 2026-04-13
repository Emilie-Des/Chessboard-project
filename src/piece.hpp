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
    explicit Piece(std::pair<int, int> position);
    Piece(std::optional<PieceColor> color, std::optional<PieceType> type, std::pair<int, int> position);
    ~Piece();

    void                      move(std::vector<Piece>& destinations, Piece& moving_piece);
    std::vector<Piece>        select(std::vector<std::vector<Piece>>& chessboard);
    std::pair<int, int>       getPosition();
    std::optional<PieceType>  getType();
    std::optional<PieceColor> getColor();
    void                      setColor(std::optional<PieceColor> new_color);
    void                      setType(std::optional<PieceType> new_type);
    void                      showMoves(std::vector<std::vector<Piece>>& chessboard);
    bool                      operator==(const Piece& piece) const;

private:
    std::optional<PieceColor> m_color;
    std::optional<PieceType>  m_pieceType;
    std::pair<int, int>       m_position; // (y,x)
};