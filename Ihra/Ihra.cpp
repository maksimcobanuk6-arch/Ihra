#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
class Weapon {
public:
    virtual void use() = 0;
    virtual string getName() = 0;
    virtual ~Weapon() {}
};
class Sword : public Weapon {
public:
    void use() override {
        cout << "Атака мечем!\n";
    }

    string getName() override {
        return "Меч";
    }
};
class Bow : public Weapon {
public:
    void use() override {
        cout << "Постріл з лука!\n";
    }

    string getName() override {
        return "Лук";
    }
};
int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "===== ПРИГОДНИЦЬКА ГРА =====\n";

    return 0;
}
class MagicStaff : public Weapon {
public:
    void use() override {
        cout << "Магічна атака!\n";
    }

    string getName() override {
        return "Магічний посох";
    }
};
class Dagger : public Weapon {
public:
    void use() override {
        cout << "Швидка атака кинджалом!\n";
    }
    string getName() override {
        return "Кинджал";
    }
};
class Character {
protected:
    string name;
    Weapon* weapon = nullptr;
public:
    Character(string n) : name(n) {}
    void setWeapon(Weapon* w) {
        weapon = w;
        cout << "Зброя: " << weapon->getName() << endl;
    }
    void attack() {
        if (weapon)
            weapon->use();
        else
            cout << "У вас немає зброї!\n";
    }
    string getName() {
        return name;
    }
    string getWeapon() {
        return weapon ? weapon->getName() : "Немає";
    }
    virtual void info() = 0;
    virtual ~Character() {}
};