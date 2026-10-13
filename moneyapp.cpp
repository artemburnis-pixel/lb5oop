#include <iostream>
#include <windows.h>
#include <clocale>
#include "money.h"

int main() {
    setlocale(LC_ALL, "Ukrainian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "=== демонстрація роботи класу money ===\n\n";

    Money a, b;

    std::cout << "--- введення першої суми (a) ---\n";
    a.Read();

    std::cout << "\n--- введення другої суми (b) ---\n";
    b.Read();

    std::cout << "\nперша сума (a): ";
    a.Display();

    std::cout << "друга сума (b): ";
    b.Display();

    std::cout << "\n--- перевірка методів класу ---\n";

    Money sum = a.Add(b);
    std::cout << "додавання (Add) = ";
    sum.Display();

    Money diff = a.Subtract(b);
    std::cout << "віднімання (Subtract) = ";
    diff.Display();

    double factor = 2.5;
    Money mult = a.MultiplyByFactor(factor);
    std::cout << "множення на число (MultiplyByFactor " << factor << ") = ";
    mult.Display();

    Money div = a.DivideByFactor(factor);
    std::cout << "ділення на число (DivideByFactor " << factor << ") = ";
    div.Display();

    std::cout << "\n=== програму успішно завершено ===\n";
    return 0;
}