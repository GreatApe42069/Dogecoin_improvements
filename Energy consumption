#include <dogecoin/dogecoin.h>

using namespace dogecoin;

int main() {
   // Initialize the Dogecoin network
   Network network = Network::init();

   // Switch to Proof-of-Stake consensus algorithm
   network.setConsensusAlgorithm(ProofOfStake);

   // Start the network
   network.start();

   // Wait for network to stabilize
   // ...

   // Stop the network
   network.stop();

   return 0;
}
