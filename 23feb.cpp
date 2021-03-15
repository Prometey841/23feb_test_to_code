/* Заменить на числа для выполнения равенства
*   СТАКАН
* + СТАКАН
* + СТАКАН
* + СТАКАН
* ------
* =БУТЫЛКА
*/

#include <iostream>
#include <array>
#include <Windows.h>

void stakanMultiplyer(const std::array<int,7>& stakan, std::array<int, 7>& bytilka) // суммируем значения элемента массива1, умножаем на 4, присваиваем цифры значения элементам массива 2 в обратном порядке;
{
	bytilka = { 0,0,0,0,0,0,0 };
	for (int counter = 6; counter >= 0; --counter)
	{
		
		bytilka[counter] += stakan[counter] * 4;
		bytilka[counter] = bytilka[counter] % 10;
		if (stakan[counter]*4 > 9)

		bytilka[counter-1]= stakan[counter]*4/10;
	}
}

bool arrayValuesAreUnique(const std::array<int, 7>& stakan, const std::array<int, 7>& bytilka) // проверяем уникальность всех значений элементов массива (булытка) и уникальность значений 0,1,3,4 элементов массива сткан среди значений двух стаканов
{
	bool unique = true;
	for (int counter = 0; counter < 7; ++counter) // проверка работы функции умножителя
	{
		for (int innerCounter = 0; innerCounter < 7; ++innerCounter)
		{
			if ((bytilka[0] == stakan[innerCounter]) || (bytilka[1] == stakan[innerCounter]) || (bytilka[3] == stakan[innerCounter]) || (bytilka[4] == stakan[innerCounter]))
			{
				unique = false;
				break;
			}
			if ((bytilka[innerCounter] == bytilka[counter]) && (innerCounter != counter))
			{
				unique = false;
				break;
			}
		}
	}
	return unique;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::array<int,7> stakan   { 0,0,0,0,0,0,0 };
	std::array<int, 7> bytilka { 0,0,0,0,0,0,0 };

	int iterationNumber = 0; // переменная для перебора значений до 999999 для последующей записи в массив стакан
	
	for (int indexCounter = 1; indexCounter < 1000000; ++indexCounter) // итерация чисел стакана от 0 до 999999
	{
			iterationNumber += indexCounter;

			for (int innerCounter = 6; innerCounter >= 0; --innerCounter) // запись цифр числа как значений элементов массива
			{
				stakan[innerCounter] = iterationNumber % 10;
				iterationNumber /= 10;

			}
			stakanMultiplyer(stakan, bytilka);

			bool uniqueArrayValues = arrayValuesAreUnique(stakan,bytilka);

			if ((stakan[3] == bytilka[6]) && (stakan[5] == stakan[3]) && (stakan[2] == bytilka[2]) && (stakan[4] == bytilka[5]) && (uniqueArrayValues))
				break; // проверяем базовое условие
	}
	
	// далее вывод результатов:
		
	std::cout << "Стаканы ударились "; 
	
	for (int counter = 0; counter < 7; ++counter) // вывод итогового значения стакана.
	{
		std::cout << stakan[counter] << " ";
	}

	std::cout << " раз\n";

	std::cout << "\nИскомое значение БУТЫЛКИ: ";

	for (int counter = 0; counter < 7; ++counter) //вывод итогового значения бутылки
	{
		std::cout << bytilka[counter] << " ";
	}
	
	std::cout << "!\n";

	return 0;
}