#include "bidder.hpp"
#include "auctioneer.hpp"
#include <cstdlib>

void Bidder::update(Auctioneer *auctioneer) {
    // TODO: decide whether to retaliate with a new bid. Only bid if:
    //   - the new highest bid wasn't placed by this same bidder
    //   - this bidder's next bid (highest bid * bid_increase_perc) would not
    //     exceed its budget
    //   - a randomly generated probability roll succeeds, per bid_probability
    //     (see Lab-08.pptx on <random> / rand())
    // If all three hold, compute the new bid and call
    // auctioneer->accept_bid(new_bid, this).
    Bidder* current_highest_bidder = auctioneer->getHighestBidder();
    double current_highest_bid = auctioneer->getHighestBid();
    double bid_chance = static_cast<double>(rand()) / RAND_MAX; 

    if (current_highest_bidder != this && 
        current_highest_bid * bid_increase_perc <= budget && 
        bid_chance < bid_increase_perc) {
            auctioneer->accept_bid(current_highest_bid * bid_increase_perc, this);
            highest_bid = current_highest_bid * bid_increase_perc;
        }
}

string Bidder::getName() const {
    return name;
}