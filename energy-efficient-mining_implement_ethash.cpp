#include <dogecoin/dogecoin.h>
#include <ethash/ethash.h>

using namespace dogecoin;

int main() {
   // Initialize the Dogecoin network
   Network network = Network::init();

   // Set Ethash as the mining algorithm
   network.setMiningAlgorithm(Ethash);

   // Start the network
   network.start();

   // Wait for network to stabilize
   // ...

   // Stop the network
   network.stop();

   return 0;
}
