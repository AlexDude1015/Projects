#ifndef WEREWOLF_H
#define WEREWOLF_H

#include <string>
#include <vector>

enum Role {VILLAGER, WEREWOLF, SEER};

class Player 
{
    public:
        std::string name;
        bool is_alive;
        Role role;
        Player(std::string user_input)
        {
            name = user_input;
        }

};

void print_day_time();
std::string convert_role_to_string(Role role);
void add_user_to_game(std::vector<Player> &player);
void add_classmates_to_game(std::vector<Player> &player);
void assign_roles(std::vector<Player> &player);
void assign_alive(std::vector<Player> &player);
void print_alive_players(const std::vector<Player> &player);
void get_player_role(const std::vector<Player> &player);
bool check_win_condition(const std::vector<Player> &player, int werewolf_index);
int get_werewolf_index(const std::vector<Player> &player);
int werewolf_player(std::vector<Player> &player);
int werewolf_ai(std::vector<Player> &player);
int seer_player(std::vector<Player> &player);
int seer_ai(std::vector<Player> &player);
void night_phase(std::vector<Player> &player, int &werewolf_target, int &seer_target, int &seer_discovered_werewolf);
int vote_player(const std::vector<Player> &player);
int vote_ai(const std::vector<Player> &player, int seer_discovered_werewolf);
void day_phase(std::vector<Player> &player, int werewolf_target, int seer_target, int seer_discovered_werewolf);
void game_setup(std::vector<Player> &player);
void print_night_time();

#endif
