#include <iostream>
using namespace std;

class Avatar {
private:
    string name;
    int health = 20, maxHealth = 20;
    int strength = 50;

    //default constructor (if no other constructor is defined, default is ussed
    //if any other constructor defined(except default), default is no longer available

public:
    Avatar(){
        name = "Joel";
    }

    Avatar(string aName, int aHealth, int aStrength = 10) : name(aName), health(aHealth), strength(aStrength){
        name = aName;
        health = aHealth;
        maxHealth = health;
        strength = aStrength;

    }

    //accessor/mutator functions = (getter/setter) functions
    string getName(){
        return name;
    }

    int getHealth(){
        return health;
    }

    int getStrength(){
        return strength;
    }

    void setName(string aName){
        name = aName;

    }

    void setHealth(int aHealth){
        health = aHealth;

        if (health < 0)
            health = 0;
        else if (health > maxHealth)
            health = maxHealth;
    }

    //member functions
    void printFormattedHealth(){
        cout << name << ": ";

        for (int i = 0; i < health; i++)
            cout << "@";
        for (int i = health; i < maxHealth; i++)
            cout << "-";
        cout << endl;
    }

    void attack(Avatar &enemy){
        int damage = computeDamage();

        cout << this->name << " Strikes " << enemy.name << " for " << damage << " damage! " << endl;
        enemy.setHealth(enemy.health - damage);

    }
private:
    int computeDamage(){
        int damage = rand() % int(strength * .25) + 1;
        //100 lines of code to compute damage
        return damage;
    }

};

int main() {

    Avatar player1;

    Avatar enemySet[5]{
            enemySet[0] = Avatar("Devil", 10, 15),
            enemySet[1] = Avatar("princess", 5, 10),
            enemySet[2] = Avatar("Ellie", 5, 10),
            enemySet[3] = Avatar("Clicker", 20, 15),
            enemySet[4] = Avatar("Bad Human", 8, 10)
    };

    srand(time(0));

    int re = rand() % 5;
    Avatar enemy = enemySet[re];

    cout << player1.getName() + " confronts the " + enemy.getName() + "...";
    player1.printFormattedHealth();
    enemy.printFormattedHealth();
    char response;

    bool flee = false;

    do {
        cout << "Will you (A)ttack or (R)un away: " << endl;
        cin >> response;

        if (response == 'A' || response == 'a') {
            player1.attack(enemy);
            player1.printFormattedHealth();
            enemy.printFormattedHealth();
        } else {
            cout << "You run away to never be found again...";
            break;
        };

        if (enemy.getHealth() > 0) {
            cout << enemy.getName() << " is preparing to attack...";
            cout << "Should you (S)tand and fight or (R)un like a fool...";
            cin >> response;

            if (response == 'S' || response == 's') {
                enemy.attack(player1);
                player1.printFormattedHealth();
                enemy.printFormattedHealth();

            } else {
                cout << "You look like a fool running away...";
                break;
            }
        }
    } while (player1.getHealth() > 0 && enemy.getHealth() > 0 && !flee);
    player1.printFormattedHealth();
    enemy.printFormattedHealth();

    if (enemy.getHealth() > 0){
        cout << enemy.getName() << " wins!";
    }else {
        cout << player1.getName() << " is victorious!";
    }




    //Object-Oriented Programming: problem solving by modeling after real world concepts
    //extensible: can create own types, classes, objects, etc. to expand on the language
    //3 faucets of OOP:
    //1- encapsulation
    //2- inheritance
    //3- polymorphism

    //class - used to describe objects with the same attributes and operations (functions)
    // like a cookie cutter metaphor or blueprint
    // rhodes class metaphor - assembly line (Actually has working parts to it)

    //classes generally have 3 parts (none of which are required)
    //1. attributes (member values)  - properties (name, DOB, SSN, etc)
    //2. constructors     - how you build(instantiate) an object(from a class)
    //3. member functions    - what the instance (object) does

    //feature visibility
    //1. private  - access is restricted to the defining class
    //2. public   - access is available throughout the program
    //3. protected  - access in the defining class and any subclasses




    return 0;
}
