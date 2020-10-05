#include "linked_list.h"

using namespace std;

int main()
{    
    try
    {
        LinkedList<int> list;
        
        list.push(2);
        list.push(4);
        list.push(7);
        list.push(50);
        list.push(98);
        list.print();

        list.append(2);
        list.append(1);
        list.print();

        list.insert_item(66, 1);
        list.print();

        //list.delete_item(1);
        list.SortedInsert(60);
        list.print();
        list.Count(2);
        list.RemoveDuplicates();
        list.print();
        list.reverse();
        list.print();
        std::cout << "The following empty line is the deleted list being printed:" << std::endl;
        list.DeleteList();
        list.print();
        list.push(2);
        list.print();
        
        

        for (size_t i = 0; i < list.length(); i++)
        {
            int item;
            list.get_nth(i, item);
            //cout << item << ", ";
        }
        cout << endl;        
    }
    catch(const char* e)
    {
        std::cerr << "ERROR caught: " << e << std::endl;
    } 

    return 0;
}