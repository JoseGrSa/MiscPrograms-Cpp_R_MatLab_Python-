#include "Misc.h"


class Busqueda : public Misc
{

    public:
    Busqueda() {};
    ~Busqueda() {};


    void busquedaSecuencial(std::vector<double> elementos,std::vector<double> numeros)
    {
        int j = 5;
        int a = 0;

        while (a < j)
        {
            int i = 0;
            char band = 'F';
            while (i < elementos.size() && band == 'F')
            {
                if(elementos[i] == numeros[a]){band = 'V';}
                else{i++;}
            }
            if (band == 'F'){std::cout << "Busqueda secuencial: " << "The index of: " <<  numeros[a] << " is " << "-1" << std::endl;}
            else if (band == 'V'){std::cout << "Busqueda secuencial: " << "The index of: " <<  numeros[a] << " is " << i-1 << std::endl;}
            a++; 
        }
    }

    void busquedaSecuencialOrdenada1(std::vector<double> elementos,std::vector<double> numeros) 
    {

        int j = 5;
        int a = 0;
        std::sort(elementos.begin(), elementos.end());
        
        while (a < j)
        {
            int i = 0;
            char band = 'F';
            while (i < elementos.size() && band == 'F')
            {
                if(elementos[i] == numeros[a]){band = 'V';}
                else{i++;}
            }
            if (band == 'F'){std::cout << "Busqueda secuencialordenada1: " << "The index of: " <<  numeros[a] << " is " << "-1" << std::endl;}
            else if (band == 'V'){std::cout << "Busqueda secuencialordenada1: " << "The index of: " <<  numeros[a] << " is " << i-1 << std::endl;}
            a++;  
        }


    }

   /* void busquedaSecuencialOrdenada2(std::vector<double> elementos,std::vector<double> numeros) 
    {

        int j = 5;
        int a = 0;
        std::sort(elementos.begin(), elementos.end());
        
        while (a < j)
        {
            int i = 0;
            char band = 'F';
            while (i < elementos.size() && band == 'F')
            {
                if(elementos[i] == numeros[a]){band = 'V';}
                else{i++;}
            }
            if (band == 'F'){std::cout << "The index of: " <<  numeros[a] << " is " << "-1" << std::endl;}
            else if (band == 'V'){std::cout << "The index of: " <<  numeros[a] << " is " << i-1 << std::endl;}
            a++;  
        }


    } */
     
    void busquedaBinaria(std::vector<double> elementos,std::vector<double> numeros)
    {
        std::sort(elementos.begin(), elementos.end());
        int j = 5;
        int a = 0;

        while (a < j)
        {
            
            int left = 0;
            int right = elementos.size();
            int middle;
            char key = 'F';
            
            while(left <= right)
            {
                middle = (left+right)/2;
                if(elementos[middle] == numeros[a]){key = 'V'; break;}
                if(elementos[middle] > numeros[a]){right = middle-1; middle = (left+right)/2;}
                if(elementos[middle] < numeros[a]){left = middle+1; middle = (left+right)/2;}
            }

            if (key == 'V'){std::cout << "Busqueda Binaria: " << "The index of: " <<  numeros[a] << " is " << middle << std::endl;}
            else{std::cout << "Busqueda Binaria: " << "The index of: " <<  numeros[a] << " is " << "-1" << std::endl;}
            a++;    
        }
    }


};


