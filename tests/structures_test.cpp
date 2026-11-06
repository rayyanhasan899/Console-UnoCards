#define main original_game_main
#include "../Console-UnoCards.cpp"
#undef main
#include <cassert>
int main() {
    Stack deck;
    bool threw=false;
    try { deck.pop(); } catch(const std::out_of_range&) { threw=true; }
    assert(threw);
    deck.push('R',4); deck.push('G',7);
    assert(deck.pop().getNumber()==7);
    assert(deck.pop().getNumber()==4);
    assert(deck.isEmpty());
    Player player;
    threw=false;
    try { player.getSpecificCard(0); } catch(const std::out_of_range&) { threw=true; }
    assert(threw);
    deck.push('B',3); player.addAtFront(deck);
    assert(player.getPlayerHandSize()==1 && player.getSpecificCard(0).getNumber()==3);
    player.deleteAtEnd();
    assert(player.getPlayerHandSize()==0);
}
