/* �������� �� ����� ��� ���������� ���������
*   ������
* + ������
* + ������
* + ������
* ------
* =�������
*/

#include <iostream>
#include <array>
#include <Windows.h>

void stakanMultiplyer(const std::array<int,7>& stakan, std::array<int, 7>& bytilka) // ��������� �������� �������� �������1, �������� �� 4, ����������� ����� �������� ��������� ������� 2 � �������� �������;
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

bool arrayValuesAreUnique(const std::array<int, 7>& stakan, const std::array<int, 7>& bytilka) // ��������� ������������ ���� �������� ��������� ������� (�������) � ������������ �������� 0,1,3,4 ��������� ������� ����� ����� �������� ���� ��������
{
	bool unique = true;
	for (int counter = 0; counter < 7; ++counter) // �������� ������ ������� ����������
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

	int iterationNumber = 0; // ���������� ��� �������� �������� �� 999999 ��� ����������� ������ � ������ ������
	
	for (int indexCounter = 1; indexCounter < 1000000; ++indexCounter) // �������� ����� ������� �� 0 �� 999999
	{
			iterationNumber += indexCounter;

			for (int innerCounter = 6; innerCounter >= 0; --innerCounter) // ������ ���� ����� ��� �������� ��������� �������
			{
				stakan[innerCounter] = iterationNumber % 10;
				iterationNumber /= 10;

			}
			stakanMultiplyer(stakan, bytilka);

			bool uniqueArrayValues = arrayValuesAreUnique(stakan,bytilka);

			if ((stakan[3] == bytilka[6]) && (stakan[5] == stakan[3]) && (stakan[2] == bytilka[2]) && (stakan[4] == bytilka[5]) && (uniqueArrayValues))
				break; // ��������� ������� �������
	}
	
	// ����� ����� �����������:
		
	std::cout << "������� ��������� "; 
	
	for (int counter = 0; counter < 7; ++counter) // ����� ��������� �������� �������.
	{
		std::cout << stakan[counter] << " ";
	}

	std::cout << " ���\n";

	std::cout << "\n������� �������� �������: ";

	for (int counter = 0; counter < 7; ++counter) //����� ��������� �������� �������
	{
		std::cout << bytilka[counter] << " ";
	}
	
	std::cout << "!\n";

	return 0;
}