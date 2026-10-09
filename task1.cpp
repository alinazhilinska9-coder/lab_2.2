#include <iostream>
#include <string>

using namespace std;

int main() {
    int age;
    double base_price;
    int is_student;

    cout << "Введите возраст зрителя: ";
    cin >> age;
    cout << "Введите базовую цену билета: ";
    cin >> base_price;
    cout << "Зритель является студентом? (1 - да, 0 - нет): ";
    cin >> is_student;

    // Проверка на корректность ввода
    if (age < 0 || base_price < 0) {
        cout << "Ошибка: Возраст и цена не могут быть отрицательными!" << endl;
        return 1;
    }

    string category;
    double final_price = base_price;

    // Определение категории и расчёт цены
    if (age < 6) {
        category = "Ребенок (до 6 лет)";
        final_price = 0;
    } else if (age >= 6 && age <= 17) {
        category = "Ребенок/Подросток (6-17 лет)";
        final_price = base_price * 0.5; // Скидка 50%
    } else if (is_student == 1) {
        category = "Взрослый студент";
        final_price = base_price * 0.8; // Скидка 20%
    } else {
        category = "Взрослый (полная стоимость)";
        final_price = base_price;
    }

    cout << "\nКатегория зрителя: " << category << endl;
    cout << "Итоговая цена: " << final_price << endl;

    return 0;
}
