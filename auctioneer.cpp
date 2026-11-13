#include "auctioneer.hpp"

void Auctioneer::register_bidder(Bidder *bidder) {
    // TODO: add bidder to the bidders vector.
    bidders.push_back(bidder);
}

void Auctioneer::reset_auctioneer() {
    // TODO: clear the bidders vector and reset highest_bid/highest_bidder.
    bidders.clear();
    highest_bidder = nullptr;
    highest_bid = 0;
}

void Auctioneer::notify_bidders() {
    // TODO: call update(this) on every registered bidder except
    // highest_bidder (a bidder cannot retaliate to their own bid).
    for (Bidder* bidder : bidders) {
        if (bidder != highest_bidder) {
            bidder->update(this);
        }
    }
}

void Auctioneer::accept_bid(double bid, Bidder *bidder) {
    // TODO: if bid > highest_bid, record the new highest_bid/highest_bidder
    // and call notify_bidders().
    if (bid > highest_bid) {
        if (bidder != nullptr) {
            cout << bidder->getName() << "bidded $" << bid << " in response to "
            << (highest_bidder ? highest_bidder->getName() : "Starting bid")
            << "'s bid of $" << highest_bid << endl;
        }

        highest_bidder = bidder;
        highest_bid = bid;
        notify_bidders();
    }
}

double Auctioneer::getHighestBid() const {
    return highest_bid;
}

Bidder* Auctioneer::getHighestBidder() const {
    return highest_bidder;
}

void Auctioneer::printBiddersSummary() {
    cout << "----Bidder's Summary----" << endl;
    for (Bidder* bidder : bidders) {
        cout << *bidder << endl;
    }
}