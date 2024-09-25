#include <iostream>
#include <string>
#include <vector>

/* 
Requirements:
1) List of names
2) Class for players
3) Assigning roles randomly
4) Display of players
5) Actions to vote, accused, and seek.
6) Instructions.
7) End game condition.
*/

enum Role {VILLAGER, WEREWOLF, SEER};

class Player 
{
    public:
        std::string name;
        bool is_alive;
        Role role;
        
        std::string get_name()
        {
            return name;
        }
};

void get_classmate_names(std::vector<Player> &person)
{
    std::vector<std::string> classmates = {"Parsa Faraji", "Connie Zeng", "Zakaria Bouaddou", 
    "Oliver Richards", "Arnav Sharma", "Matteo Brownlow", 
    "Alexander Li", "Glenn Mah", "Jimmy Hsu", "Ali Saremi"};

    for(int i = 0; i < classmates.size(); i++)
    {
        person.push_back();
    }
}

int main()
{
    std::vector<Player> person;
    get_classmate_names(person);
    

    return 0;
}