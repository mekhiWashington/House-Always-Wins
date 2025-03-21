#include <iostream>
#include <string>
#include <random>
#include <vector>

using namespace std;

struct Card {
    int Value;
    string Suit;
};

vector<Card> Deck; //Cards go in the vector

string getCardName(int value) {
    if (value == 1) return "Ace";
    if (value == 10) {
        string faceCards[] = { "Jack", "Queen", "King" };
        return faceCards[rand() % 3];  // Randomly assign J, Q, or K
    }
    return to_string(value);  // Convert numbers 2-9 to string
}

void InitDeck() {
    string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

    for (string suit : suits) {
        for (int value = 1; value <= 10; value++) {  // 10 represents face cards
            Deck.push_back({ value, suit }); // Adds 1 To Value Each Time This Runs Runs 52 times for all the cards in a deck
        }
    }

    // Shuffle the deck
    srand(time(0));
    random_shuffle(Deck.begin(), Deck.end());
}

Card dealCard() {
    Card drawn_card = Deck.back();  // Get the last card
    Deck.pop_back();  // Remove it from the deck
    return drawn_card;
}

int main()
{
    InitDeck();

    for (int i = 0; i <= 10; i++) {
        Card drawnCard = dealCard();
        cout << "You drew a " << getCardName(drawnCard.Value) << " Of " << drawnCard.Suit << endl;
    }
}


