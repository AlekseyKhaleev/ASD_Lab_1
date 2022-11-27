
#include "SyntaxException.h"
#include <iostream>

void SyntaxException::description()
{
   const char *error_msg[] = {
           "Correct arguments for run this app might be:\n\n",
           "1)./ASD_Lab_1 'input_path' 'sequence'\n",
           "2)./ASD_Lab_1 'input_path' 'sequence' out_path'\n\n",
           "input_path: absolute path to text we need to change\n",
           "sequence:   a symbol stack we need to delete in text\n",
           "out_path:   absolute path to file to save our changes\n",};
   std::cout << "\nSyntax Exception Type " << type << " : " << argc - 1 << " arguments given.\n" << what() << "\n\n";
   for (auto &i: error_msg)
   {
      std::cout << i;
   }
}