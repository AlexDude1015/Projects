#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>

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
std::string global_role_names[] = {"Villager", "Werewolf", "Seer"};

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
        Player(std::string user_input)
        {
            name = user_input;
        }

};

//Adds the user to the game
void add_user_to_game(std::vector<Player> &player)
{
    std::string user_name;
    std::cout << "Please enter your first and last name: ";
    std::getline (std::cin, user_name);
    std::cout << "\n";
    Player temp_user(user_name);
    player.push_back(temp_user);
}

//Creates 10 players with classmates' and professor's name.
void add_classmates_to_game(std::vector<Player> &player)
{
    //Stores the classmate's names. Adding or deleting names will affect the player count.
    std::string classmates[] = {"Parsa Faraji", "Connie Zeng", "Zakaria Bouaddou", 
    "Oliver Richards", "Arnav Sharma", "Matteo Brownlow", 
    "Alexander Li", "Glenn Mah", "Jimmy Hsu", "Ali Saremi"};

    //Stores the element size of the classmate array.
    int classmates_size = (sizeof(classmates)/sizeof(classmates[0]));

    //Assigns name to each player
    for (int i = 0; i < classmates_size; i++)
    {
        Player temp_classmate(classmates[i]);
        player.push_back(temp_classmate);
    }
}

void assign_roles(std::vector<Player> &player)
{
    std::srand(std::time(0));

    //Assigns the werewolf
    int werewolf_index = 
    player[werewolf_index].role = WEREWOLF;

    //Assigns the seer
    int seer_index = 0;
    do
    {
        seer_index = std::rand() % player.size();
    }
    while(seer_index == werewolf_index);
    player[seer_index].role = SEER;

    //Assigns everybody else as a villager
    for (int i = 0; i < player.size(); i++)
    {
        if ((i != werewolf_index) && (i != seer_index))
        {
            player[i].role = VILLAGER;
        }
    }

}

//Assigns living for every player or resets the game
void assign_alive(std::vector<Player> &player)
{
    for (int i = 0; i < player.size(); i++)
    {
        player[i].is_alive = true;
    }
}

//Prints out living players
void print_alive_players(std::vector<Player> &player)
{
    //Counts living players
    int living_players = 0;

    //Formats the printing
    std::cout << "Living Players:" << "\n";
    for (int i = 0; i < player.size(); i++)
    {
        if (player[i].is_alive == true)
        {
            std::cout << std::left << "(" << i << ")";
            std::cout << std::setw(20) << std::left << player[i].name;
            ++living_players;
        }

        //Creates a new line after every three players
        if (living_players % 3 == 0)
        {
            std::cout << "\n";
        }
    }
    std::cout << "\n\n";
}

//Groups all the set up functions for clarity
void game_set_up(std::vector<Player> &player)
{
    add_user_to_game(player);
    add_classmates_to_game(player);
    assign_roles(player);
    assign_alive(player);
    print_alive_players(player);
}

void get_player_role(std::vector<Player> &player)
{
    std::cout << "Your role is " << global_role_names[player[0].role] << std::endl;   
}

int main()
{
    std::vector<Player> player;
    
    //Sets up game
    game_set_up(player);
    get_player_role(player);

    //Starts game
    


    return 0;
}