#include <iostream>
#include <string>
using namespace std;

// Класс Flight (Полёт) для управления аэроклубом
class Flight {
private:
    string pilotName;      // ФИО пилота
    string aircraftType;   // Тип воздушного судна
    int duration;          // Длительность полёта в минутах
    string status;         // Статус: запланирован / выполнен / отменён

public:
    // Конструктор по умолчанию
    Flight() {
        pilotName = "Не указан";
        aircraftType = "Не указан";
        duration = 0;
        status = "запланирован";
    }

    // Конструктор с параметрами
    Flight(string name, string type, int dur, string stat) {
        pilotName = name;
        aircraftType = type;
        if (dur >= 0) duration = dur;
        else duration = 0;
        if (stat == "запланирован" || stat == "выполнен" || stat == "отменён")
            status = stat;
        else
            status = "запланирован";
    }

    // Деструктор
    ~Flight() {
        cout << "Полёт пилота " << pilotName << " удалён из системы." << endl;
    }

    // Геттеры
    string getPilotName() { return pilotName; }
    string getStatus() { return status; }

    // Сеттеры с валидацией
    void setPilotName(string name) {
        if (name != "") pilotName = name;
        else cout << "Ошибка: имя не может быть пустым!" << endl;
    }

    void setDuration(int dur) {
        if (dur >= 0) duration = dur;
        else cout << "Ошибка: длительность не может быть отрицательной!" << endl;
    }

    // Метод завершения полёта (смена статуса и фиксация длительности)
    void completeFlight(int actualDuration) {
        if (status == "запланирован") {
            status = "выполнен";
            if (actualDuration >= 0) {
                duration = actualDuration;
                cout << "Полёт завершён. Длительность: " << duration << " мин." << endl;
            }
            else {
                cout << "Ошибка: некорректная длительность!" << endl;
            }
        }
        else {
            cout << "Ошибка: полёт нельзя завершить, так как он уже " << status << "!" << endl;
        }
    }

    // Метод отмены полёта
    void cancelFlight() {
        if (status == "запланирован") {
            status = "отменён";
            cout << "Полёт отменён." << endl;
        }
        else {
            cout << "Ошибка: полёт нельзя отменить, так как он уже " << status << "!" << endl;
        }
    }

    // Метод вывода информации
    void printInfo() {
        cout << "Пилот: " << pilotName << endl;
        cout << "Тип судна: " << aircraftType << endl;
        cout << "Длительность: " << duration << " мин." << endl;
        cout << "Статус: " << status << endl;

    }
};

int main() {
    setlocale(0, "Russian");

    // Создание объекта конструктором по умолчанию
    Flight flight1;
    cout << "Объект 1 (по умолчанию):" << endl;
    flight1.printInfo();

    // Создание объекта конструктором с параметрами
    Flight flight2("Петров П.П.", "Cessna 172", 90, "запланирован");
    cout << "\nОбъект 2 (с параметрами):" << endl;
    flight2.printInfo();

    // Демонстрация всех методов
    cout << "\n--- Демонстрация методов ---" << endl;

    // Геттеры
    cout << "Пилот: " << flight2.getPilotName() << ", Статус: " << flight2.getStatus() << endl;

    // Сеттеры с валидацией (корректные данные)
    flight2.setPilotName("Сидоров С.С.");
    flight2.setDuration(120);
    cout << "После корректной смены данных:" << endl;
    flight2.printInfo();

    // Сеттеры с валидацией (некорректные данные)
    flight2.setPilotName("");
    flight2.setDuration(-30);
    cout << "После некорректной смены данных (ошибки выше):" << endl;
    flight2.printInfo();

    // Завершение полёта
    flight2.completeFlight(110);
    flight2.printInfo();

    // Попытка повторного завершения (валидация)
    flight2.completeFlight(100);

    // Отмена полёта (не должна работать, так как статус уже "выполнен")
    flight2.cancelFlight();

    // Создание нового полёта для демонстрации отмены
    Flight flight3("Иванов И.И.", "Boeing 737", 60, "запланирован");
    cout << "\nНовый полёт:" << endl;
    flight3.printInfo();

    // Отмена полёта
    flight3.cancelFlight();
    flight3.printInfo();

    // Попытка завершить отменённый полёт (валидация)
    flight3.completeFlight(50);

    return 0;
}
