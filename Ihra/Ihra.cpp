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