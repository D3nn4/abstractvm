#include <iostream>
#include "abstractvm.hpp"

int main(int argc, char ** argv)
{
    AbstractVM vm;
    if(argc > 1){
        vm.run(argv[1]);
    }
    else {
        vm.run();
    }
    std::cout << "The End.\n";

return 0;
}
