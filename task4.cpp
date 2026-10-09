#include <iostream>
#include <string>

using namespace std;

int main() {
    int day;
    int age;
    char format; // 'N' или 'I'
    int is_student;

    cout << "Введите день недели (1..7): ";
    cin >> day;
    cout << "Введите возраст: ";
    cin >> age;
    cout << "Введите формат сеанса (N - обычный, I - IMAX): ";
    cin >> format;
    cout << "Зритель является студентом? (1 - да, 0 - нет): ";
    cin >> is_student;

    // Проверка корректности ввода данных
    if (day < 1 || day > 7) {
        cout << "Ошибка: Некорректный день недели!" << endl;
        return 1;
    }
    if (age < 0) {
        cout << "Ошибка: Возраст не может быть отрицательным!" << endl;
        return 1;
    }
    if (format != 'N' && format != 'n' && format != 'I' && format != 'i') {
        cout << "Ошибка: Некорректный код формата сеанса!" << endl;
        return 1;
    }

    double base_price = 0;

    // Определение базовой цены через switch по дню недели
    switch (day) {
        case 1: case 2: case 3: case 4:
            base_price = 11;
            break;
        case 5:
            base_price = 13;
            break;
        case 6: case 7:
            base_price = 16;
            break;
    }

    double final_price = base_price;
    string applied_rule = "Базовая цена";

    // Доплата за IMAX
    if (format == 'I' || format == 'i') {
        final_price += 5;
        applied_rule += " + надбавка IMAX";
    }

    // Применение скидок в зависимости от возраста и статуса
    if (age < 7) {
        final_price = 0;
        applied_rule = "Бесплатный билет (до 7 лет)";
    } else if (age >= 7 && age <= 17) {
        final_price -= base_price * 0.5; // Скидка 50% от базовой цены
        applied_rule += " + Детская скидка 50%";
    } else if (is_student == 1) {
        final_price -= base_price * 0.2; // Скидка 20% от базовой цены
        applied_rule += " + Студенческая скидка 20%";
    } else {
        applied_rule += " + Без скидок";
    }

    // Проверка минимальной цены (не применяется для бесплатного билета)
    if (age >= 7 && final_price < 5) {
        final_price = 5;
        applied_rule += " (Ограничение: минимальная цена 5)";
    }

    cout << "\n--- Итог ---" << endl;
    cout << "Итоговая цена: " << final_price << endl;
    cout << "Применённое правило: " << applied_rule << endl;

    return 0;
}
