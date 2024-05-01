#include <string>
#include <iostream>
#include <vector>

class Librarian {
public:
    virtual void update(const std::string& magazineName) = 0;
};

// Конкретная реализация наблюдателя - библиотекарь
class ConcreteLibrarian : public Librarian {
private:
    std::vector<std::string> magazineList;

public:
    void update(const std::string& magazineName) override {
        magazineList.push_back(magazineName);
    }

    void displayMagazines() {
        std::cout << "List of magazines observed by the librarian:" << std::endl;
        for (const auto& magazine : magazineList) {
            std::cout << "- " << magazine << std::endl;
        }
    }
};

class Magazine {
private:
    std::string name;
    std::vector<Librarian*> observers; // Список наблюдателей

public:
    Magazine(const std::string& name) : name(name) {}

    void addObserver(Librarian* observer) {
        observers.push_back(observer);
    }

    void publish() {
        for (const auto& observer : observers) {
            observer->update(name);
        }
    }
};

int main() {
    // Создаем объекты
    ConcreteLibrarian librarian;
    Magazine magazine1("Magazine1");
    Magazine magazine2("Magazine2");

    // Подписываем библиотекаря на журналы
    magazine1.addObserver(&librarian);
    magazine2.addObserver(&librarian);

    // Публикуем журналы
    magazine1.publish();
    magazine2.publish();

    // Выводим список журналов, отслеживаемых библиотекарем
    librarian.displayMagazines();

    return 0;
}