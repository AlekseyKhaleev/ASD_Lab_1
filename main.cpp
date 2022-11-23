#include <iostream>
#include "classes.h"
#include "functions.h"

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "ru");
    List<char> txt{}, seq{};
    txt.ReadFromFile(argv[1]);
    seq.Init(argv[2]);
    std::cout<<std::endl<<"Text:"<<std::endl;
    for(int i=0; i < txt.GetSize(); i++)
    {
        std::cout << txt[i];
    }
    std::cout<<std::endl<<"Sequence:"<<std::endl;
    for(int i=0; i < seq.GetSize(); i++)
    {
        std::cout << seq[i];
    }
    int ind = FindFirst(txt,seq);
    std::cout<<std::endl<<"First finded index:"<<std::endl;
    std::cout<<ind;
    std::cout<<std::endl<<"this is:"<<std::endl;
    for(int i=ind; i< ind+seq.GetSize();i++)
    {
        std::cout<<txt[i];
    }
    std::cout<<std::endl<<"Text without sequence:"<<std::endl;

    DeleteAllSeq(txt, seq);
    for(int i=0; i < txt.GetSize(); i++)
    {
        std::cout << txt[i];
    }
    return 0;
}



