# Werewolf game by Alexander Li

**Intro:**

The werewolf game is about survival. In the beginning, one random villager is the werewolf, and another is the seer.
Each night, the werewolf kills a villager, and the seer tries to reveal the werewolf. The following day, the entire
village votes on the suspected werewolf. That person is executed, and the next round begins...

The game ends when the werewolf is killed, or all but one villager is alive.


### Project Requirements:

---

**Variable & Constants**

Below is a function that prints the living players. Whenever a function is only accessing a variable, its parameters are **const** so that data isn't accidentally altered.

```cpp
//Prints the player's role
void get_player_role(const std::vector<Player> &player)
{
    std::cout << "Your role is " << global_role_names[player[0].role] << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));   
}
```

---

**Naming Conventions**

The naming convention I used was **snake case**. Furthermore, I gave each variable specific names to avoid bugs later down the road.

```cpp
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
```
---

**Mathamatical Expressions**

The order of arithmatic starts from left to right. The code below is a statement that returns a random element of an array. It works because the statement is read from the left to right, and values in brackets are higher in the order of operations. 

```cpp
return living_players[std::rand() % living_players.size()];
```


---

**Console Input/Output**

Outputs can be modified with the #iomanip library. Functions like `setw(0)` modifies an output's minimum length, and `left` aligns content to the left.


```cpp
std::cout << std::setw(20) << std::left << player[living_players[i]].name;
```

---

**Standard Library Use**

`<string>` was one of the libraries used in my project. To define a variable or function with the data type, it needs a scope resolution operator.

```cpp
#include <string>

std::string global_role_names[] = {"Villager", "Werewolf", "Seer"};
```
---

**Comments**

Every function in my program has a comment on top that describes what it does.

```cpp
//Prints the player's role
void get_player_role(const std::vector<Player> &player)
{
    std::cout << "Your role is " << global_role_names[player[0].role] << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));   
}
```

---


**Fundamental Datatype**

I picked datatypes that made my program simple and clear. For instance, the easiest way to store a player's name was a string. A player's alive/dead status is binary, so it's stored in a boolean. Lastly, roles are stored as an enumeration because it made the roles, WEREWOLF, SEER, and VILLAGER, clear when it was manipilated in other functions.

```cpp
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
```
---

**Initialization & Working with Numbers**

The code below is a "for loop" that creates a new line everytime it prints four players. The variable `next_line_count` is initialized to `0` outside of the loop. Then, it is incremented each pass. Whenever `next_line_count` is `4`, a new line starts and the counter restarts.

```cpp
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
```

---

**Random Numbers & Formatting Output**

`rand()` is a pseudo-random number generator meaning it's not truly random. The program requires external inputs as a seed which is why `srand(time(0))` is nessesary. 

Since `rand()` could generate a number over two billion, a modulus operator can format the output to a desirable size. `player.size()` was ideal, since a random number would generate between zero and one less than the total size of the vector.

```cpp
std::srand(std::time(0));

//Assigns the werewolf
int werewolf_index = std::rand() % player.size();
player[werewolf_index].role = WEREWOLF;
```

---

**Data Types Size & Limits**

---

**Boolean & Comparisons**

---

**String & Characters**

---

**Arrays and Type Conversion**

---

**Control Structure (if/else, loops)**

---

**Loop Variants & Nesting**



---

**Functions**

---

**Namespaces & Organizing Code**

---

**Debugging**

---

