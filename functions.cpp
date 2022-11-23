#include "functions.h"


List<int> PrefixFunction (List<char> &image)
{
    List<int> pi{};// в i-м элементе (его индекс i-1) количество совпавших символов в начале и конце для подстроки длины i.
    // p[0]=0 всегда, p[1]=1, если начинается с двух одинаковых
    pi.PushBack(0);
    for (int i=1; i<image.GetSize(); ++i)
    {
        // ищем, какой префикс-суффикс можно расширить
        int j = pi[i-1]; // длина предыдущего префикса-суффикса, возможно нулевая
        while ((j > 0) && (image[i] != image[j]))// этот нельзя расширить,
        {
            j = pi[j - 1];   // берем длину меньшего префикса-суффикса
        }
        if (image[i] == image[j])
        {
            ++j;  // расширяем найденный (возможно пустой) префикс-суффикс
        }
        pi.PushBack(j);
    }
    return pi;
}

int FindFirst(List<char> &txt, List<char> &image)
{
    List<int> pi = PrefixFunction(image);
    int txtLen=txt.GetSize(), imgLen=image.GetSize();
    for(int k=0,l=0;k<txtLen;)
    {
        if(txt[k] != image[l])
        {
            l == 0?k++:l = pi[l-1];
        }
        else
        {
            if(l == imgLen-1)
            {
                return (k-imgLen+1);
            }
            k++;
            l++;
        }
    }
    return -1;
}

void DeleteAllSeq(List<char> txt, List<char> &image)
{
    int index = FindFirst(txt, image);
    while(index >= 0)
    {
        for(int i =0; i<image.GetSize();i++)
        {
            txt.RemoveAt(index);
        }
        index = FindFirst(txt, image);
    }
}