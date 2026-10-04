
#include <iostream>
#include <string>
using namespace std;

class Hero {
public:
    string name = "Unknown";
    int hp = 100;
    int first_hp = hp;
    Hero(string start_name, int start_hp) {
        name = start_name;
        hp = start_hp;
        first_hp = hp;
    }

    void greet() {
        cout << "Hello! I am hero and my name is " << name << " with HP: " << hp << endl;

    }
    void take_damage(int damage) {
        hp = hp - damage;
        cout << name << " got " << damage << " damage!  HP: " << hp << endl;
        if (hp <= 0) {
            cout << name << "Dead in battle" << endl;
        }
        else {
            cout << "HP: " << hp;
        }
    }
    void take_health(int health) {
        if (hp + health > first_hp) {
            hp = first_hp;
            cout << "Health cannot be many more " << first_hp<<endl;
        }
        else {
            hp = hp + health;
            cout << "Health " << name << hp << endl;
        }

    }
    void attack(Hero& enemy, int damage) {
        cout << name << " attacks " << enemy.name << "!" << endl;
        enemy.take_damage(damage);
    }
};

int main() {
    Hero warrior("Vlad", 100);
    Hero wizard("Merrleg", 80);
    Hero helper("Robin", 90);
    warrior.greet();
    wizard.greet();
    helper.greet();
    cout << "\n--- Start" << endl;
    while (true) {
        int value;
        int a, b, c;
        int random_heal = rand();
        cin >> value;
        if (value == 0) {
            break;
        }
        else if (value == 1) {
            wizard.attack(warrior,30);
            warrior.take_health(random_heal);
            
        }
    }
    system("pause");
    return 0;
}
