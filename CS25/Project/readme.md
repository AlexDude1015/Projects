# Werewolf game

**Intro:**

The werewolf game is about survival. In the beginning, one random villager is the werewolf, and another is the seer.
Each night, the werewolf kills a villager, and the seer tries to reveal the werewolf. The following day, the entire
village votes on the suspected werewolf. That person is executed, and the next round begins...

The game ends when the werewolf is killed, or all but one villager is alive.


### Project Requirements:

**Variable & Constants**

Below is a function that prints the living players. Whenever a function is only accessing a variable, its parameters are **const** so that data isn't accidentally altered.

```cpp
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
```

**Naming Conventions**

**Mathamatical Expressions**

**Console Input/Output**

**Stand Library Use**

**Comments**

**Fundamental Datatype**

**Initialization & Working with Numbers**

**Random Numbers & Formatting Output**

**Data Types Size & Limits**

**Boolean & Comparisons**

**String & Characters**

**Arrays and Type Conversion**

**Control Structure (if/else, loops)**

**Loop Variants & Nesting**

**Functions**

**Namespaces & Organizing Code**

**Debugging**


