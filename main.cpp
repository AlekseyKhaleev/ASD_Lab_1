#include <iostream>
#include "ClassList.h"
#include "SyntaxException.h"

int main(int argc, char **argv)
{
   try
   {
      if (argc == 3||argc == 4)                   // получено 2 или 3 пользовательских аргумента + argc
      {
         std::fstream input_txt(argv[1], std::ios::in | std::ios::binary);
         if (!input_txt.is_open())               // Не удалось открыть файл
         {
            throw SyntaxException("Unable to open specified file. Check that the specified file exists", 1, argc);
         } else                                  // Если файл открыт успешно, продолжаем работу с его содержимым

         {
            input_txt.seekg(0, std::ios::end);   // перемещаем курсор из начала в конец файла
            long file_size = input_txt.tellg();  // сохраняем размер файла
            input_txt.close();                   // закрываем файл
            if (input_txt.is_open())
            {
               throw SyntaxException("Unable to close specified file", 2, argc);
            }
            if (file_size == 0)                  // если файл пустой
            {
               throw SyntaxException("The specified file is empty", 2, argc);
            } else                               // если файл не пустой
            {
               List<char> txt{}, seq{argv[2]};
               txt.ReadFromFile(argv[1]);
               std::cout << "\nText:" << std::endl;
               for (int i = 0; i < txt.GetSize(); i++)
               {
                  std::cout << txt.Ind(i);
               }
               std::cout << std::endl << "\nSequence:" << std::endl;
               for (int i = 0; i < seq.GetSize(); i++)
               {
                  std::cout << seq.Ind(i);
               }
               txt.DeleteAllSeq(seq);
               std::cout << std::endl << "\nText without sequence:" << std::endl;
               for (int i = 0; i < txt.GetSize(); i++)
               {
                  std::cout << txt.Ind(i);
               }
               std::cout<<std::endl;
               txt.WriteToFile(argv[3]);
            }
         }
      } else
      {
         throw SyntaxException("Wrong number of arguments", 9, argc);
      }
   } catch (SyntaxException &ex) // Если поймали собственное исключение (переданы некорректные аргументы командной строки)
   {
      ex.description();          // Вызываем сообщение, соответствующее ошибке с помощью метода .description()
      return 1;
   }
   return 0;
}



