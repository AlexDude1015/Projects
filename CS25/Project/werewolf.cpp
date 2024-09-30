//The werewolf game is about survival. In the beginning, one random villager is the werewolf, and another is the seer.
//Each night, the werewolf kills a villager, and the seer tries to reveal the werewolf. The following day, the entire
//village votes on the suspected werewolf. That person is executed, and the next round begins...
//The game ends when the werewolf is killed, or one villager is left.

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <chrono>
#include <thread>
#include "werewolf.h"

int main()
{
    std::vector<Player> player;
    //Sets up game
    game_setup(player);
    //Loops each round until somebody wins
    int werewolf_index = get_werewolf_index(player);
    while(!check_win_condition(player,werewolf_index))
    {
        int werewolf_target, seer_target;
        int seer_discovered_werewolf = -1;

        night_phase(player, werewolf_target, seer_target, seer_discovered_werewolf);
        day_phase(player, werewolf_target, seer_target, seer_discovered_werewolf);
    }
    //Victory prompt
    std::cout << "Game over!\n";
    if (player[werewolf_index].is_alive)
    {
        std::cout << "The werewolf won...\n";
    }
    else
    {
        std::cout << "The villagers won!\n";
    }
    return 0;
}

//Adds the user to the game
void add_user_to_game(std::vector<Player> &player)
{
    std::string user_name;
    std::cout << "Please enter your first name to start the game: ";
    std::getline (std::cin, user_name);
    std::cout << "\n";
    Player temp_user(user_name);
    player.push_back(temp_user);
}

//Creates 10 players with classmates' and professor's name.
void add_classmates_to_game(std::vector<Player> &player)
{
    //Stores the classmate's names. Adding or deleting names will affect the player count.
    std::string classmates[] = {"Parsa", "Connie", "Zakaria", "Oliver",
                                "Arnav", "Matteo", "Glenn", "Jimmy", "Orin", 
                                "Sergio", "Delina", "Saurav", "Luwam",
                                "Kailash", "Issac", "Marco", "Maya",
                                "Ahmed", "Jackson", "Oluwaseyi", "Victoria"};

    //Stores the element size of the classmate array.
    int classmates_size = (sizeof(classmates)/sizeof(classmates[0]));

    //Assigns name to each player
    for (int i = 0; i < classmates_size; i++)
    {
        Player temp_classmate(classmates[i]);
        player.push_back(temp_classmate);
    }
}

//Randomly assigns each user a role.
void assign_roles(std::vector<Player> &player)
{
    std::srand(std::time(0));

    //Assigns the werewolf
    int werewolf_index = std::rand() % player.size();
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
void print_alive_players(const std::vector<Player> &player)
{
    std::cout << "\nLiving Players:" << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::vector<int> living_players;
    for (int i = 0; i < player.size(); i++)
    {
        if (player[i].is_alive)
        {
            living_players.push_back(i);
        }
    }
    int next_line_count = 0;
    for (int i = 0; i < living_players.size(); i++)
    {
        std::cout << std::left << "(" << living_players[i] << ")";
        std::cout << std::setw(20) << std::left << player[living_players[i]].name;
        next_line_count++;

        if (next_line_count == 4)
        {
            std::cout << '\n';
            next_line_count = 0;
        }
    }
    std::cout << "\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

//Prints the player's role
void get_player_role(const std::vector<Player> &player)
{
    std::cout << "Your role is " << convert_role_to_string(player[0].role) << "\n\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));   
}

//Game stops if werewolf dies or only one or less villager remains
bool check_win_condition(const std::vector<Player> &player, int werewolf_index)
{
    int alive_players_count = 0;
    for (int i = 0; i < player.size(); i++)
    {
        if (i != werewolf_index)
        {
            alive_players_count++;
        }
    }
    
    //Game over because the werewolf died or enough villagers died
    if ((!player[werewolf_index].is_alive) || (alive_players_count <= 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Gets the player index of the werewolf
int get_werewolf_index(const std::vector<Player> &player)
{
    for (int i = 0; i < player.size(); i++)
    {
        if (player[i].role == WEREWOLF)
        {
            return i;
        }
    }
    return -1;
}

//Player picks a villager to kill
int werewolf_player(std::vector<Player> &player)
{
    int werewolf_target = -1;
    print_alive_players(player);
    std::cout << "Pick a player to kill. Please enter their index number: \n";
    std::cin >> werewolf_target;
    while (werewolf_target == 0)
    {
        std::cout << "You cannot kill yourself because werewolves have excellent health care coverage.\n";
        std::cout << "Please pick another target: ";
        std::cin >> werewolf_target;
    }
    std::cout << "You killed " << player[werewolf_target].name << ".\n"; 
    return werewolf_target;
}

//AI picks a villager to kill
int werewolf_ai(std::vector<Player> &player)
{
    std::vector<int> living_players;
    for (int i = 0; i < player.size(); i++)
    {
        if (player[i].is_alive && player[i].role != WEREWOLF)
        {
            living_players.push_back(i);
        }
    }
    return living_players[std::rand() % living_players.size()];
}

//Player picks somebody to reveal
int seer_player(std::vector<Player> &player)
{
    int seer_target;
    print_alive_players(player);
    std::cout << "Pick a person to inspect. Please enter their index number: \n";
    std::cin >> seer_target;
    if (seer_target == 0)
    {
        std::cout << "You picked yourself. The village is fucked.\n";
    }
    std::cout << "You picked " << player[seer_target].name << " who is a " << convert_role_to_string(player[seer_target].role) << ".\n"; 
    return seer_target;
}

//AI picks somebody to reveal
int seer_ai(std::vector<Player> &player)
{
    std::vector<int> living_players;
    for (int i = 0; i < player.size(); i++)
    {
        if (player[i].is_alive && player[i].role != SEER)
        {
            living_players.push_back(i);
        }
    }
    return living_players[std::rand() % living_players.size()];
}

//First phase of the game
void night_phase(std::vector<Player> &player, int &werewolf_target, int &seer_target, int &seer_discovered_werewolf)
{
    std::cout << "Night falls...\n";
    print_night_time();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    //Werewolf picks target
    if (player[0].role == WEREWOLF)
    {
        werewolf_target = werewolf_player(player);
    }
    else
    {
        werewolf_target = werewolf_ai(player);
    }
    player[werewolf_target].is_alive = false;
    //Seer picks target
    if (player[0].role == SEER && player[0].is_alive)
    {
        seer_target = seer_player(player);
    }
    else
    {
        seer_target = seer_ai(player);
    }
    if (player[seer_target].role == WEREWOLF)
    {
        seer_discovered_werewolf = seer_target;
    }
    std::cout << "The werewolf kills " << player[werewolf_target].name << ".\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    if (seer_discovered_werewolf != -1)
    {
        std::cout << "The seer has discovered " << player[seer_target].name << " to be the werewolf.\n";
    }
    else
    {
        std::cout << "The seer did not discover the werewolf.\n";
    }
    std::cout << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

//Player votes somebody out
int vote_player(const std::vector<Player> &player)
{
    int vote_target;
    print_alive_players(player);
    std::cout << "Vote somebody out: ";
    std::cin >> vote_target;
    std::cout << "\n";
    //Edgecase if player votes dead person
    while (!player[vote_target].is_alive)
    {
        std::cout << "The person you selected is already dead, try again: ";
        std::cin >> vote_target;
        std::cout << "\n";
    }
    return vote_target;
}

//AI votes somebody out
int vote_ai(const std::vector<Player> &player, int seer_discovered_werewolf)
{
    if (seer_discovered_werewolf != -1)
    {
        return seer_discovered_werewolf;
    }
    else
    {
        std::vector<int> living_players;
        for (int i = 0; i < player.size(); i++)
        {
            if (player[i].is_alive)
            {
                living_players.push_back(i);
            }
        }
        return living_players[std::rand() % living_players.size()];
    }
}

//Second phase of the game
void day_phase(std::vector<Player> &player, int werewolf_target, int seer_target, int seer_discovered_werewolf)
{
    int vote_target_index;
    std::cout << "Daytime has arrived...\n";
    print_day_time();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Voting will commence. Each villager will vote to execute the suspected werewolf.\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    if (player[0].is_alive)
    {
        vote_target_index = vote_player(player);
    }
    else
    {
        vote_target_index = vote_ai(player, seer_discovered_werewolf);
    }
    std::cout << player[vote_target_index].name << " has been chosen and executed.\n";
    player[vote_target_index].is_alive = false;
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

//Organizes all setup functions
void game_setup(std::vector<Player> &player)
{
    add_user_to_game(player);
    add_classmates_to_game(player);
    assign_roles(player);
    assign_alive(player);
    get_player_role(player);   
}

//Converts enumeration to string
std::string convert_role_to_string(Role role)
{
    const std::string role_names[] = {"Villager", "Werewolf", "Seer"};
    return role_names[role];
}

void print_night_time()
{
    std::cout << "             *          *    \n";
    std::cout << "        *           *        *\n";
    std::cout << "   *          *    *         *\n";
    std::cout << "      *      *\n";
    std::cout << "          _________\n";
    std::cout << "         /        /\\\n";
    std::cout << "        /        /  \\\n";
    std::cout << "       /________/____\\\n";
    std::cout << "      |        |      |\n";
    std::cout << "      |  _  _  |  []  |\n";
    std::cout << "      | |_|_|  |      |\n";
    std::cout << "      |________|______|\n";
    std::cout << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void print_day_time()
{
    std::cout << "        *****       \n";
    std::cout << "     **       **    \n";
    std::cout << "    *           *   \n";
    std::cout << "    *           *   \n";
    std::cout << "     **       **    \n";
    std::cout << "        *****       \n";
    std::cout << "\n";
    std::cout << "          _________\n";
    std::cout << "         /        /\\\n";
    std::cout << "        /        /  \\\n";
    std::cout << "       /________/____\\\n";
    std::cout << "      |        |      |\n";
    std::cout << "      |  _  _  |  []  |\n";
    std::cout << "      | |_|_|  |      |\n";
    std::cout << "      |________|______|\n";
    std::cout << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

