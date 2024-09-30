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

---

**Stand Library Use**

---

**Comments**

---


**Fundamental Datatype**

---


**Initialization & Working with Numbers**

---

**Random Numbers & Formatting Output**

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

**Functions**

---

**Namespaces & Organizing Code**

---

**Debugging**

---

