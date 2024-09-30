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

//Prints the player's role
void get_player_role(std::vector<Player> &player)
{
    std::cout << "Your role is " << global_role_names[player[0].role] << std::endl;   
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
    return (!player[werewolf_index].is_alive || (alive_players_count <= 1));
}

int get_werewolf_index(const std::vector<Player> &player)
{
    int werewolf_index;
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
    int werewolf_target;
    print_alive_players(player);
    std::cout << "Pick a player to kill. Please enter their index number: \n";
    std::cin >> werewolf_target;
    while (werewolf_target == 0)
    {
        std::cout << "You cannot kill yourself because werewolves have excellent health care coverage.\n";
        std::cout << "Please pick another target: ";
        std::cin >> werewolf_target;
    }
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
    std::cout << "Pick a player to kill. Please enter their index number: \n";
    std::cin >> seer_target;
    if (seer_target == 0)
    {
        std::cout << "You picked yourself. The village is fucked.\n";
    }
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
    std::cout << "Night encroaches...\n";
    
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

void day_phase(std::vector<Player> &player, int werewolf_target, int seer_target, int seer_discovered_werewolf)
{
    int vote_target_index;
    std::cout << "Daytime has arrived...\n";
    std::cout << "Last night, the werewolf killed " << player[werewolf_target].name << ".\n";

    if (seer_discovered_werewolf != -1)
    {
        std::cout << "The seer has discovered " << player[seer_target].name << " to be the werewolf.\n";
    }
    else
    {
        std::cout << "The seer did not find the werewolf last night.\n";
    }

    std::cout << "Voting will commence. Each villager will vote to execute the suspected werewolf.\n";
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
}

int main()
{
    std::vector<Player> player;
    
    //Sets up game
    add_user_to_game(player);
    add_classmates_to_game(player);
    assign_roles(player);
    assign_alive(player);
    get_player_role(player);
    print_alive_players(player);    

    int werewolf_index = get_werewolf_index(player);

    while(!check_win_condition(player,werewolf_index))
    {
        int werewolf_target, seer_target;
        int seer_discovered_werewolf = -1;

        night_phase(player, werewolf_target, seer_target, seer_discovered_werewolf);
        day_phase(player, werewolf_target, seer_target, seer_discovered_werewolf);
    }

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