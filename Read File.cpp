#include <iostream>
#include <fstream>
#include <string>

int main()
{
    int size;
    std::cout << "Enter a size of your array: ";
    std::cin >> size;
    int* Array = new int[size];

    std::ifstream readFile("E:\\C++\\Zhegalkin-polynomial\\BoolFunctions.txt");
    if (!readFile.is_open()) 
    {
        std::cerr << "Error." << std::endl;
        return 1;
    }

    // Чтение файла построчно и обработка
    std::string line;
    while (std::getline(readFile, line))
    {
        //Пропускаем пустые строки, если ими раздедены сторки в файле
        if (line == "") continue;
        // Пропускаем пробелы и запятые из строки
        for (int i = 0, j = 0; j < size; i++) 
        {
            char c = line[i];

            if (c == ' ' || c == ',') continue;

            Array[j] = c - '0';
            std::cout << Array[j] << ' ';
            j++;
        }
        std::cout << '\n';
    }

    readFile.close();

	return 0;
}

