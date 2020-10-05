#include "Sort.h"
#include "timer.h"

int main()
{

Sort sort1;
sort1.genVector();


/*int p;
for(p=0; p < sort1.elementos.size(); p++)
        {
            std::cout << sort1.elementos[p] << " "; //Prints arrangement, usefull for small arrangements, takes ages on bigger ones
        }*/

std::cout << std::endl << "Sorters: " << std::endl;

std::cout << "Sorting by Selection Sort O(n^2) " << std::endl;
DECLARE_TIMING(t);
START_TIMING(t);
sort1.selectionSort(sort1.elementos);
STOP_TIMING(t);
SHOW_TIMING(t, "Selection Sort:");
std::cout << std::endl << "Sorting by Bubble Sort Sort O(n^2) " << std::endl;
DECLARE_TIMING(t1);
START_TIMING(t1);
sort1.bubbleSort(sort1.elementos);
STOP_TIMING(t1);
SHOW_TIMING(t1, "Bubble Sort:");
std::cout << std::endl << " Sorting by Insertion Sort Sort O(n^2)" << std::endl;
DECLARE_TIMING(t3);
START_TIMING(t3);
sort1.insertionSort(sort1.elementos);
STOP_TIMING(t3);
SHOW_TIMING(t3, "Insertion Sort:");
std::cout << std::endl << "Sorting by Merge Sort Sort O(nlogn) " << std::endl;
DECLARE_TIMING(t4);
START_TIMING(t4);
sort1.mergeSort(sort1.elementos,0,sort1.elementos.size()-1);
STOP_TIMING(t4);
SHOW_TIMING(t4, "Merge Sort:");


}




