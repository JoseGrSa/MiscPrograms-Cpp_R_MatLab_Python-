#include "Num.h"


class Sort : public Method
{   

    public:
    Sort() {};
    ~Sort() {};

    void selectionSort(std::vector<double> elementos) // Complexity is O(n^2)
    {
        int p,i,j,min;
        int n = elementos.size();

        for (i=0; i < n-1; i++)
        {
            min = i;
            for (j = i+1; j < n; j++)
            if (elementos[j] < elementos[min]) 
                min = j;

            swap(&elementos[min], &elementos[i]);

        }

        /*for(p=0; p < elementos.size(); p++)
        {
            std::cout << elementos[p] << " ";
            
        } */ // Prints results, but lags on big arrangements
        
    }

void bubbleSort(std::vector<double> elementos) // Complexity is O(n^2)
    {
        int i,j,p;
        int n = elementos.size();

        for (i = 0; i < n-1; i++)
        {
            for(j =0; j < n-i-1; j++)
            {
                if (elementos[j] > elementos[j+1])
                {
                    swap(&elementos[j], &elementos[j+1]);
                }
            }
        }



        /*for(p=0; p < elementos.size(); p++)
        {
            std::cout << elementos[p] << " ";
            
        } */ // Prints results, but lags on big arrangements
        
    }



void insertionSort(std::vector<double> elementos)  
{  
    int i, set, j,p;  
    int n = elementos.size();

    for (i = 1; i < n; i++) 
    {  
        set = elementos[i];  
        j = i - 1;  
  
        while (j >= 0 && elementos[j] > set) 
        {  
            elementos[j + 1] = elementos[j];  
            j = j - 1;  
        }  
        elementos[j + 1] = set;  
    }  

    /*for(p=0; p < elementos.size(); p++)
        {
            std::cout << elementos[p] << " ";
            
        }*/  // Prints results, but lags on big arrangements
        
}  

void mergeSort(std::vector<double> &elementos, int l, int r) {
   int m,p;
   if(l < r) {
      int m = l+(r-l)/2;
      
      mergeSort(elementos, l, m);
      mergeSort(elementos, m+1, r);
      merge(elementos, l, m, r);
   }
}
};    