#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>


class Method
{
    public:
    std::vector<double> elementos;
    
void genVector() 
    {
        
        double c1 = 0;
        double gen = 0;
        
        std::cout << "How many numbers would you like the to generate (recommended number is 100,000)" << std::endl;
        std::cin >> gen;
        while (c1 <= gen)
        {
            elementos.push_back(rand() % RAND_MAX);
            c1++;
        }

    }

void swap(double *a, double *b)
{
    double store = *a;
    *a = *b;
    *b = store;


}

void merge(std::vector<double> &elementos, int left, int middle, int right)
    {
        int i, j, k;
        int num1 = middle - left + 1;
        int num2 = right - middle;

        std::vector<int> izq;
        std::vector<int> der;

        for (i = 0; i < num1; i++)
        {
            izq.push_back(elementos[left + i]);
        }
        for (j = 0; j < num2; j++)
        {
            der.push_back(elementos[middle + 1 + j]);
        }

        i = 0;
        j = 0;
        k = left;

        while(i < num1 && j < num2)
        {
            if(izq[i] <= der[j])
            {
                elementos[k] = izq[i];
                i++;
            }
            else
            {
                elementos[k] = der[j];
                j++;
            }
            k++;
        }

        while(i < num1)
        {
            elementos[k] = izq[i];
            i++;
            k++;
        }

        while(j < num2)
        {
            elementos[k] = der[j];
            j++;
            k++;
        }
    }
    };
