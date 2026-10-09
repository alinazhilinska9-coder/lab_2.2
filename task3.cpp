#include <iostream>
#include <string>

using namespace std;

int main() {
    int day;
    int is_evening;

    cout << "Введите номер дня недели (1..7): ";
    cin >> day;
    cout << "Вечерний сеанс? (1 - да, 0 - нет): ";
    cin >> is_evening;

    // Проверка корректности дня недели
    if (day < 1 || day > 7) {
        cout << "Ошибка: Некорректный номер дня недели!" << endl;
        return 1;
    }

    double base_price = 0;
    string day_category;

    // Определение базовой цены через switch
    switch (day) {
        case 1: case 2: case 3: case 4:
            base_price = 10;
            day_category = "Будний день (Пн-Чт)";
            break;
        case 5:
            base_price = 12;
            day_category = "Пятница (Пт)";
            break;
        case 6: case 7:
            base_price = 15;
            day_category = "Выходной день (Сб-Вс)";
            break;
    }

    double final_price = base_price;

    // Вечерняя надбавка (не применяется по средам, т.е. day == 3)
    if (is_evening == 1 && day != 3) {
        final_price += 3;
    }

    cout << "\nЦеновая категория дня: " << day_category << endl;
    cout << "Итоговая цена: " << final_price << endl;

    return 0;
}
