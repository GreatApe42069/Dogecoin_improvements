#include <dogecoin/dogecoin.h>

using namespace dogecoin;

int main() {
   // Initialize the Dogecoin network
   Network network = Network::init();

   // Increase the block size to improve scalability
   network.setBlockSize(8 * 1024 * 1024);

   // Start the network
   network.start();

   // Wait for network to stabilize
   // ...

   // Stop the network
   network.stop();

   return 0;
}
