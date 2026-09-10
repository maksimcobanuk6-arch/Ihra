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
class Warrior : public Character {
public:
    Warrior() : Character("Воїн") {}

    void info() override {
        cout << "Сильний персонаж ближнього бою.\n";
    }
};
class Archer : public Character {
public:
    Archer() : Character("Лучник") {}

    void info() override {
        cout << "Атакує ворогів на відстані.\n";
    }
};
class Mage : public Character {
public:
    Mage() : Character("Маг") {}

    void info() override {
        cout << "Використовує магічні атаки.\n";
    }
};
class Assassin : public Character {
public:
    Assassin() : Character("Асасин") {}
    void info() override {
        cout << "Швидкий персонаж прихованої атаки.\n";
    }
};
int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "===== ПРИГОДНИЦЬКА ГРА =====\n";
    Sword sword;
    Bow bow;
    MagicStaff staff;
    Dagger dagger;

    Warrior warrior;
    Archer archer;
    Mage mage;
    Assassin assassin;

    Character* player = nullptr;

    int c;

    cout << "===== ПРИГОДНИЦЬКА ГРА =====\n";
    cout << "1. Воїн\n2. Лучник\n3. Маг\n4. Асасин\n";

    cout << "Виберіть персонажа: ";
    cin >> c;

    if (c == 1)
        player = &warrior;
    else if (c == 2)
        player = &archer;
    else if (c == 3)
        player = &mage;
    else if (c == 4)
        player = &assassin;
    else
        return 0;

    cout << "\nВи вибрали: " << player->getName() << endl;
    return 0;
}