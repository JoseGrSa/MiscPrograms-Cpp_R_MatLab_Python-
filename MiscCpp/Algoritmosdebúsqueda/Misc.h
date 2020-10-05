#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>


class Misc
{
    public:
    std::vector<double> elementos;
    std::vector<double> numeros;

    void genVector() 
    {
        
        double c1 = 0;
        double gen = 0;
        
        std::cout << "How many numbers would you like the to generate (recommended number is 100,000" << std::endl;
        std::cin >> gen;
        while (c1 <= gen)
        {
            elementos.push_back(rand() % RAND_MAX);
            c1++;
        }

    }

    int setNum()
    {
        int c2 = 0;
        size_t val;
        std::cout << "Please insert the numbers you want to be searched for: " << std::endl;
        while (c2 < 5)
        {
            std::cin >> val;
            numeros.push_back(val);
            c2++;

        }
     }
    
};
