#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <string_view>

using namespace std;

int main() {
    random_device rd;
    char a[] = "This magic trick uses namespace std";

    string_view sv(a);
    cout << sv.substr(sv.size() - 3) << "\n";

/*
    char your_card = '?';

    int nCards = sv.size() - sv.rfind(your_card);

    cout << nCards << "\n";
    assert(sv.end()[-nCards] == your_card);

/*
    span s(a);
    for (int i=0; i < nCards; ++i) {
        uniform_int_distribution dist(0, 10);
        rotate(s.begin() + dist(rd),
               prev(s.end()),
               s.end());
    }

    // Your chosen card has now been buried in the middle of the deck.

/*
    // One card rises from the pack... higher than all the rest...

    auto risen_card = *max(sv.begin(), sv.end());

/*
    // Is this your card?
    cout << risen_card << "\n";

    assert(risen_card == your_card);
/**/
}
