#include <iostream>
#include "ClassList.h"

int main(int argc, char** argv)
{
    List<char> txt{}, seq{argv[2]};
    txt.ReadFromFile(argv[1]);
    std::cout<<std::endl<<"Text:"<<std::endl;
    for(int i=0; i < txt.GetSize(); i++)
    {
        std::cout << txt.Ind(i);
    }
    std::cout<<std::endl<<"Sequence:"<<std::endl;
    for(int i=0; i < seq.GetSize(); i++)
    {
        std::cout << seq.Ind(i);
    }
    txt.DeleteAllSeq(seq);
    std::cout<<std::endl<<"Text without sequence:"<<std::endl;
    for(int i=0; i < txt.GetSize(); i++)
    {
        std::cout << txt.Ind(i);
    }
    txt.WriteToFile(argv[3]);
    return 0;
}



