/**********************************************************************************************************************
* Данный модуль содержит определения методов собственных классов, определенных в "classes.h"
**********************************************************************************************************************/

/* Подключение модулей */
#include "SyntaxException.h"
#include <iostream>

void SyntaxException::description()
{
   /*****************************************************************************************************************
   * Цель: Вывести в STDOUT сообщение с описанием полученной ошибки аргументов и краткую справку.
   * Исходные данные:
    *  type - закрытая переменная класса SyntaxException
    *  argc - закрытая переменная класса SyntaxException
   * Результат: В поток вывода выведено сообщение об ошибке.
   * Вызываемые модули: <string>, "classes.h"
   * Описание алгоритма:
   * 1) Определяется массив string[], содержащий общую информацию о корректных аргументах
   * 2) Выводится сообщение, в котором:
    * type - тип ошибки
    * argc - количество полученных аргументов
    * what() - возвращенное описание ошибки
   * 3) В цикле по строчно выводится базовое сообщение
   * Дата: 15 / 05 / 2022 Версия 1.01
   * Автор: Студент НГТУ ИРИТ, Халеев А. А. гр. 21-ИВТз
   * Исправления: нет
   *****************************************************************************************************************/
   const char *error_msg[] = {
           "Correct arguments for run this app:\n\n", "./ASD_Lab_1 input_path sequence out_path\n",
           "input_path: absolute path to text we need to change\n",
           "sequence: a symbol stack we need to delete in text\n\n",
           "out_path: path/name for file to save our changes;\n",};
   std::cout << "\nSyntax Exception Type " << type << " : " << argc - 1 << " arguments given.\n" << what() << "\n\n";
   for (auto &i: error_msg)
   {
      std::cout << i;
   }
}