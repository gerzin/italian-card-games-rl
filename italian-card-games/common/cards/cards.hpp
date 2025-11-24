#pragma once

namespace cards {

template <typename Values, typename Suit>
class Card {
 public:
  Card(Values value, Suit suit) : value(value), suit(suit) {}

  [[nodiscard]] Values getValue() const noexcept {
    return value;
  }
  [[nodiscard]] Suit getSuit() const noexcept {
    return suit;
  }

 private:
  Values value;
  Suit suit;
};
}  // namespace cards
