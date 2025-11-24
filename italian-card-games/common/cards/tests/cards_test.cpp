#include "italian-card-games/common/cards/cards.hpp"

#include <gtest/gtest.h>

using namespace cards::italian;

TEST(CardTest, ConstructorAndGetters) {
  constexpr ItalianCard card(ItalianCardValue::Asso, ItalianCardSuit::Coppe);

  EXPECT_EQ(card.getValue(), ItalianCardValue::Asso);
  EXPECT_EQ(card.getSuit(), ItalianCardSuit::Coppe);
}

TEST(CardTest, ConstexprConstruction) {
  constexpr ItalianCard card1(ItalianCardValue::Re, ItalianCardSuit::Denari);
  constexpr ItalianCard card2(ItalianCardValue::Fante, ItalianCardSuit::Spade);

  static_assert(card1.getValue() == ItalianCardValue::Re);
  static_assert(card2.getSuit() == ItalianCardSuit::Spade);
}

TEST(CardTest, EqualityComparison) {
  ItalianCard card1(ItalianCardValue::Tre, ItalianCardSuit::Bastoni);
  ItalianCard card2(ItalianCardValue::Tre, ItalianCardSuit::Bastoni);
  ItalianCard card3(ItalianCardValue::Tre, ItalianCardSuit::Coppe);
  ItalianCard card4(ItalianCardValue::Quattro, ItalianCardSuit::Bastoni);

  EXPECT_EQ(card1, card2);
  EXPECT_NE(card1, card3);
  EXPECT_NE(card1, card4);
}

TEST(CardTest, OrderingByValue) {
  ItalianCard card1(ItalianCardValue::Asso, ItalianCardSuit::Coppe);
  ItalianCard card2(ItalianCardValue::Re, ItalianCardSuit::Coppe);
  ItalianCard card3(ItalianCardValue::Asso, ItalianCardSuit::Denari);

  EXPECT_LT(card1, card2);
  EXPECT_GT(card2, card1);
  EXPECT_LE(card1, card2);
  EXPECT_GE(card2, card1);

  // Same value, different suit - should be equal in ordering
  EXPECT_FALSE(card1 < card3);
  EXPECT_FALSE(card1 > card3);
  EXPECT_LE(card1, card3);
  EXPECT_GE(card1, card3);
}

TEST(CardTest, AllCardValues) {
  ItalianCard asso(ItalianCardValue::Asso, ItalianCardSuit::Coppe);
  ItalianCard due(ItalianCardValue::Due, ItalianCardSuit::Coppe);
  ItalianCard tre(ItalianCardValue::Tre, ItalianCardSuit::Coppe);
  ItalianCard quattro(ItalianCardValue::Quattro, ItalianCardSuit::Coppe);
  ItalianCard cinque(ItalianCardValue::Cinque, ItalianCardSuit::Coppe);
  ItalianCard sei(ItalianCardValue::Sei, ItalianCardSuit::Coppe);
  ItalianCard sette(ItalianCardValue::Sette, ItalianCardSuit::Coppe);
  ItalianCard fante(ItalianCardValue::Fante, ItalianCardSuit::Coppe);
  ItalianCard cavallo(ItalianCardValue::Cavallo, ItalianCardSuit::Coppe);
  ItalianCard re(ItalianCardValue::Re, ItalianCardSuit::Coppe);

  EXPECT_LT(asso, due);
  EXPECT_LT(due, tre);
  EXPECT_LT(tre, quattro);
  EXPECT_LT(quattro, cinque);
  EXPECT_LT(cinque, sei);
  EXPECT_LT(sei, sette);
  EXPECT_LT(sette, fante);
  EXPECT_LT(fante, cavallo);
  EXPECT_LT(cavallo, re);
}

TEST(CardTest, AllSuits) {
  ItalianCard coppe(ItalianCardValue::Asso, ItalianCardSuit::Coppe);
  ItalianCard denari(ItalianCardValue::Asso, ItalianCardSuit::Denari);
  ItalianCard spade(ItalianCardValue::Asso, ItalianCardSuit::Spade);
  ItalianCard bastoni(ItalianCardValue::Asso, ItalianCardSuit::Bastoni);

  EXPECT_EQ(coppe.getSuit(), ItalianCardSuit::Coppe);
  EXPECT_EQ(denari.getSuit(), ItalianCardSuit::Denari);
  EXPECT_EQ(spade.getSuit(), ItalianCardSuit::Spade);
  EXPECT_EQ(bastoni.getSuit(), ItalianCardSuit::Bastoni);

  EXPECT_NE(coppe, denari);
  EXPECT_NE(coppe, spade);
  EXPECT_NE(coppe, bastoni);
}
