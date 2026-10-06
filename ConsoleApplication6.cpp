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
    //int information_about_health (int )

    void greet() {
        cout << "Hello! I am hero and my name is " << name << " with HP: " << hp << endl;

    }
    void take_damage(int damage) {
        hp = hp - damage;
        //cout << name << " got " << damage << " damage!  HP: " << hp ;
        if (hp <= 0) {
            cout << name << "Dead in battle" << endl;
        }
        else {
            cout << "HP: " << hp << endl;
        }
    }
    void take_health(int health) {
        if (hp + health > first_hp) {
            hp = first_hp;
            cout << "Health cannot be many more " << first_hp << endl;
        }
        else {
            hp = hp + health;
            cout << "Health " << name << " " << hp << endl;
        }

    }
    void attack(Hero& enemy, int damage) {
        cout << name << " attacks " << enemy.name << "!" << " ";
        enemy.take_damage(damage);
    }
};
class Wizard : public Hero {
public:
    int mana;
    Wizard(string name, int start_hp, int mana) :Hero(start_name, start_hp) { mana = start_mana };
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
        
        //int random_heal = rand();
        cin >> value;
        if (value == 0) {
            cout << "Game has end" << endl;
            break;

        }
        else if (value == 1) {
            cout << "action 1: attack" << endl;
            cout << "action 2: health" << endl;
            cout << "Choose action " << endl;
            cout << "Choose action " << endl;

            int action;
            cin >> action;
            switch (action) {
            case 0:
                cout << "Game has end" << endl;
                break;
            case 1:
                if (wizard.hp < 40) {
                    warrior.attack(wizard, 30);
                    cout << "Look! " << wizard.name << "does heal" << endl;
                    wizard.take_health(20);
                    wizard.attack(warrior, 20);
                    cout << warrior.name << " Help me " << helper.name << endl;
                    helper.attack(wizard, 10);
                    wizard.attack(helper, 20);
                }
                else {
                    warrior.attack(wizard, 30);
                    cout << warrior.name << " Help me " << helper.name << endl;
                    helper.attack(wizard, 10);
                }
                break;
            case 2: 
                //int massive[3]{}
                double persent_hp = (warrior.hp / 100.0) * 70;
                if (warrior.hp < persent_hp ) {
                    cout << warrior.name << " drink heal" << endl;
                    warrior.take_health(15);
                }
                else {
                    cout << "get " << helper.name << " heal" << endl;
                    helper.take_health(15);
                    cout << wizard.name << " does attack with a big effort" << endl;
                    wizard.attack(helper, 25);
                }
                break;
           
            }


        }


    }//else if

} //while

