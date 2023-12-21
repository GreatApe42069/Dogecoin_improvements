#include <dogecoin/dogecoin.h>
#include <openssl/sha.h>

using namespace dogecoin;

int main() {
   // Initialize the Dogecoin network
   Network network = Network::init();

   // Enable SHA-256 encryption for improved security
   network.setEncryptionAlgorithm(SHA256);

   // Regularly check for and apply security updates
   network.checkForUpdates();

   // Start the network
   network.start();

   // Wait for network to stabilize
   // ...

   // Stop the network
   network.stop();

   return 0;
}
