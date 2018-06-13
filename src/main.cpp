#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <future>
#include "DistCalculator.hpp"
#include <pthread.h>

//---------------------------------------------------------------------------
int main(int argc, char *argv[])
{
   using namespace std;
   std::vector<std::future<int64_t>> future_c;
   if (argc != 2) {
      cout << "Usage: " << argv[0] << " <playedin.csv>";
      exit(1);
   }

   string playedinFile(argv[1]);
   // Create dist calculator
   DistCalculator dc(playedinFile);

   // read queries from standard in and return distances
   DistCalculator::Node a, b;
   while(cin >> a && cin >> b){
	   future_c.push_back(async(launch::async,&DistCalculator::dist,&dc,a,b));
   }

	for(auto &e : future_c) {
     std::cout << e.get() << std::endl;
   }

   // flush output buffer
   cout.flush();
}
//---------------------------------------------------------------------------
