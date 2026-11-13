
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "bidder.hpp"
#include "auction.hpp"

using namespace std;

const double MIN_PROBABILITY = 0;
const double MAX_PROBABILITY = 100;

/*
Returns a random double in [min, max). See Lab-08.pptx for why rand()/RAND_MAX
is used here instead of hardcoding a probability.
*/
double generateRandom(double min, double max)
{
  double f = (double)rand() / RAND_MAX;
  return min + f * (max - min);
}

int main()
{
  srand(time(0));

  vector<Bidder *> bidders;
  string itemName;
  string strPrice;
  double price;
  string answer;
  string bidderName;
  string strbidderBudget;
  double bidderBudget;
  string strBidProbability;
  double bidProbability;
  string strBidIncreasePerc;
  double bidIncreasePerc;

  // Preloaded test bidders.
  bidders.push_back(new Bidder("Jojo", 3000, generateRandom(MIN_PROBABILITY, MAX_PROBABILITY), 1.2));
  bidders.push_back(new Bidder("Melissa", 7000, generateRandom(MIN_PROBABILITY, MAX_PROBABILITY), 1.5));
  bidders.push_back(new Bidder("Priya", 15000, generateRandom(MIN_PROBABILITY, MAX_PROBABILITY), 1.1));
  bidders.push_back(new Bidder("Kewei", 800, generateRandom(MIN_PROBABILITY, MAX_PROBABILITY), 1.9));
  bidders.push_back(new Bidder("Scott", 4000, generateRandom(MIN_PROBABILITY, MAX_PROBABILITY), 2));

  // TODO: prompt the user for the item name and starting price.
  cout << "Enter item name" << endl;
  getline(cin, itemName);
  cout << "Enter price" << endl;
  getline(cin, strPrice);
  price = stod(strPrice);

  // TODO: give the user the option to either start the auction with just
  // the preloaded bidders above, or add more bidders first (prompting for
  // each new bidder's name, budget, bid_probability, and bid_increase_perc).
  while (true) {
    cout << "Add more bidders? y/n" << endl;
    getline(cin, answer);
    if (answer == "y"){
      cout << "Enter name" << endl;
      getline(cin, bidderName);
      cout << "Enter budget" << endl;
      getline(cin, strbidderBudget);
      bidderBudget = stod(strbidderBudget);
      cout << "Enter bid probability" << endl;
      getline(cin, strBidProbability);
      bidProbability = stod(strBidProbability);
      cout << "Enter bid increase perc" << endl;
      getline(cin, strBidIncreasePerc);
      bidIncreasePerc = stod(strBidIncreasePerc);
    }
    bidders.push_back(new Bidder(bidderName, bidderBudget, bidProbability, bidIncreasePerc));
    cout << "Continue? y/n" << endl;
    getline(cin, answer);
    if (answer == "n") break;
  }

  cout << "Starting Auction!!" << endl;
  cout << "------------------" << endl;
  Auction my_auction(bidders);
  // my_auction.simulate_auction("Antique Vase", 100);
  my_auction.simulate_auction(itemName, price);

  for (Bidder *bidder : bidders)
  {
    delete bidder;
  }
  return 0;
}
