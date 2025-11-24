#pragma once

#include <concepts>
#include <type_traits>

template <typename T>
concept CardValue = (std::is_enum_v<T> || std::is_integral_v<T>) && std::totally_ordered<T>;

template <typename T>
concept CardSuit = std::is_enum_v<T> && std::equality_comparable<T>;

namespace cards {

template <CardValue ValueType, CardSuit SuitType>
class Card {
 public:
  constexpr explicit Card(ValueType value, SuitType suit) : value(value), suit(suit) {}

  [[nodiscard]] constexpr ValueType getValue() const noexcept {
    return value;
  }
  [[nodiscard]] constexpr SuitType getSuit() const noexcept {
    return suit;
  }

  /**
   * @brief Compare two cards based only on their values
   */
  constexpr auto operator<=>(const Card& other) const noexcept {
    return value <=> other.value;
  }

  constexpr bool operator==(const Card&) const noexcept = default;

 private:
  ValueType value;
  SuitType suit;
};

namespace italian {

/**
 * @brief Italian playing card values
 *
 * @note Values range from 1 (Asso) to 10 (Re)
 */
enum class ItalianCardValue : unsigned short {
  Asso = 1,
  Due = 2,
  Tre = 3,
  Quattro = 4,
  Cinque = 5,
  Sei = 6,
  Sette = 7,
  Fante = 8,
  Cavallo = 9,
  Re = 10
};

/**
 * @brief Italian playing card suits
 */
enum class ItalianCardSuit { Coppe, Denari, Spade, Bastoni };

/**
 * @brief Type alias for an Italian playing card
 */
using ItalianCard = Card<ItalianCardValue, ItalianCardSuit>;
}  // namespace italian
}  // namespace cards
