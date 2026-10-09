#include <iostream>
#include <string>

using namespace std;

int main() {
    int age;
    int is_3d;
    int is_vip;
    double const_base_price = 12.0;

    cout << "Введите возраст зрителя: ";
    cin >> age;
    cout << "Формат 3D? (1 - да, 0 - нет): ";
    cin >> is_3d;
    cout << "VIP-место? (1 - да, 0 - нет): ";
    cin >> is_vip;

    // Обработка отрицательного возраста
    if (age < 0) {
        cout << "Ошибка: Возраст не может быть отрицательным!" << endl;
        return 1;
    }

    double final_price = const_base_price;

    // Если ребенок младше 6 лет — вход бесплатный, доплаты не начисляются
    if (age < 6) {
        final_price = 0;
        cout << "\nИтоговая цена: " << final_price << " (Ребенок до 6 лет, вход бесплатный)" << endl;
        return 0;
    }

    // Применение возрастной скидки
    if (age >= 6 && age < 12) {
        final_price -= const_base_price * 0.40; // Скидка 40%
    } else if (age >= 65) {
        final_price -= const_base_price * 0.30; // Скидка 30%
    }

    // Доплаты после возрастной скидки
    if (is_3d == 1) {
        final_price += 4;
    }
    if (is_vip == 1) {
        final_price += 6;
    }

    cout << "\nИтоговая цена: " << final_price << endl;

    return 0;
}
