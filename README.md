# CPT113 Hackathon 2 (Group 37)
## Group Members: 
Chong Yi Jian 164364 <br>
Go Yao Xiang 163130 <br>
Choong Yew Chung 163991 <br>

# The Manor - a text-based mysterious horror game
![](../main/images/title.png) <br>
_(Disclaimer: This game, name, and the events portrayed in this game is purely fictional)_ <br>
<br>
Game Description: <br>

You are a private investigative journalist, one day you received an anonymous e-mail from someone asking you to investigate an old private abandoned manor owned by a tycoon back in the 1800s with a dark and sinister past. It was whispered that the manor was a hub for illicit activities, crimes and the secret gatherings of a clandestine cult. Rumor had it that the tycoon had met a gruesome end at the hands of his own wife, who had discovered his infidelity. In her despair, she had taken her own life along with her innocent sons, casting an everlasting shadow over the estate. <br>

The anonymous sender promised you something extraordinary - an unimaginable sum of money that would be wired to you if you took up the challenge of investigating the forsaken manor.<br>

Tempted by greed, and having financial struggles at that time. You decided to take the offer to investigate the manor and unravel the mysteries surrounding the abandoned estate, to shine a light on the dark secrets that lay hidden within its decaying walls. Little do you know what lies on the other side of the wall.

# Features
**MAP DESCRIPTION** <br>
At the start of the game, the player will be spawn in the LIVING ROOM of the manor. In each area of the map, the programme will prompt out a description which can lead the player to imagine the room and find the clues to do the next moves. 

**IMMERSIVE INTERACTION** <br>
As the gameplay progresses, the game introduces a benevolent spirit in the form of a butler who will accompany and assist the player throughout their journey in escaping from the haunted manor. Interacting with the spirit enhances the player’s immersion in the game, providing a more immersive experience during the gameplay. Moreover, the old spirit can help the player to determine whether the command is correct or incorrect, thereby preventing the loss of sanity. 

**ACTION BY COMMAND** <br>
In this game, the player is required to key in command in STRING type. The commands are designed based on the storyline of the game. The player needs to determine what is the exact command that will lead to the action. Player can find the command clues by reading the description of the room.

**ITEMS AND INVENTORY** <br>
In this game, the player is able to interact with various items found in specific rooms. For those items which can be picked up, the items will be stored in the inventory list of the player. The player can always check their inventory to keep track of their progress over time. Players need to interact with several items and find ways to use them wisely to solve the problems faced during the gameplay. 

**SANITY SYSTEM** <br>
As the game storyline is set in a cursed and mysterious old manor, the player will encounter a pervasive energy field of cursed energy in the manor during the gameplay. The sanity is crucial to determine the status of the player. If the sanity dropped down to empty, the player will be deemed as lost and will need to start over again. The sanity system is influenced by the action done by the player and also the amount of false commands they input. 

**SAVE AND LOAD** <br> 
In this detective gameplay mode, the player will encounter numerous challenging problems which require to be solved by thinking and thorough observation. We have implemented a  save and load feature that allows the player to save their game progress during the game and load them when they open the game again. However, to align with the magical game storyline, players only can save their progress when they return to the living room with the input command “SAVE”.

**DETECTIVE GAME MODE** <br>
Throughout the gameplay, the player is required to solve different problems faced by ultilizing the different items that are available. In the map, there are some hints and clues for the player to get some inspiration on what to do. As the game is a text-based game, the player is required to imagine the whole map of the manor. The player will experience a mind-bending gameplay, if you are confident enough in your intelligence, feel free to put it to the test here.

# How to play
**WINNING GOAL** <br>
As stated in the description of the game, the objective for the player is to escape from the building. In order to achieve that goal, the player must navigate throughout the map, finding clues and solving the problems to get the final key which allows the player to escape from the building. 

**ACTION AND COMMAND** <br>
The one and only way players can control their character in this game is by typing in specific commands. The command requirements are stated in each description of the game, players need to be careful of the command typed in. Making a wrong command will result in a penalty to the player’s sanity. 

**ITEMS INTERACTION** <br>
Players can interact with numerous items in the map. For some specific items, the items can be collected and stored in the inventory, allowing players to carry them to different areas of the map for later use.  Players must carefully consider the correct combinations of where to use these items in order to escape from the building.

# Implementation
In order to ensure the game works accordingly and smoothly, there are various implementations in creating and constructing this game.

## Object Oriented Programming (OOP)
In the game “The Manor”,  object oriented programming serves as the backbone of this game. In this game’s programme, we have several classes linked together by inheritance and composition. The Player, also known as the parent class, is responsible for storing the player’s details including the Inventory stored  in the circularly linked list created and also the Sanity value of the player. In the parent class, it consists of the main functions to access the private member variable and also some other core functions like writing the Inventory and Sanity into the Database. <br>

  Next, the programme incorporates a class named House to store the details of the map in the game. This House class is the child class of Player, It inherits the Player class by public so that it could access the public member function of Player to alter or get the variable in Player class. House class has most of the core functionalities in the game which is the transition from one area to another and the objects of different areas in the map. <br>

  All the distinct areas in the map are builded up using different classes each equipped  with different member variables to store the action list in a linked list format.These actions allow the players to interact within each area. All the areas are composed in House class. At the initial state of the game, the object of the classes will be created in the House class.The member function in the House class can access the member functions of the different areas by using the object name when created. <br>

  In each separated area in the map, it will have a linked list for it to store the action in the room that the user can perform. Hence, an object of a linked list class called Action will be created at the initial state of the programme. Based on the condition it will initialise different states of the list to ensure that the programme can identify what action the user can and cannot perform. <br>

**Data encapsulation in programme** <br> 
	In this programme,  both Inheritance and Composite are implemented as key components of OOP. The primary focus of the game revolves around the details of the Player, hence, the class Player which stores the details of the player will be the parent class of the structure such that the other class in the programme will not be able to alter the private member variable in this particular class, ensuring the integrity and encapsulation of its data.<br>
 
  Throughout the whole programme, we have utilised the implementation of Mutator and Acessor to avoid the private member variables to be altered. Besides the player’s details, each area in the map consists of sensitive variables like the action list, to avoid the user having direct access to those variables. Only the House class has the function to access those variables. The user can only alter the variables by key in the correct sequence of commands. 

## Stack
Stack is one of the core functions in this game. In our map, we need to determine the position of the player. In order to ensure the transition of the player in different areas in the map, a stack is used to trace the location of the player. When the player moves to a new area, the stack will push the location of the player into the top of the stack. When the player performs a BACK action, the stack will pop up the stack and determine the position of the player by the stack top value after the POP. By implementing stack in the programme, the movement of the player in the game will be clear and concise. At the start of the game,  the player will be spawned in the Living Room area. The ultimate objective and win condition of the game is to successfully open the main door located in the living room. The stack data structure is utilized in the program to track the player's progress and determine whether the game has been successfully cleared or completed. By clearing the stack, the program identifies that the player has accomplished all necessary objectives, leading to a victorious outcome.

## Linked Lists
**SINGLY LINKED LIST**<br>
In our game, we have implemented a singly linked list called “Action” that store ‘string’ data type. This linked listy is used to store the available actions in different area in the manor. We utilise the search and delete function of linked list to perform command validation and avoiding multiple actions. Action play one of the core function to enable the programme to determine the action available for the player at different area in the map.

**CIRCULARLY LINKED LIST** <br>
In this game, linked lists called “Inventory” are used to store the items that the player has picked up and placed in the inventory. For the inventory, we have implemented a circular linked list in order for the last item to traverse back to the first item. If the player obtains an item, we will append the item into our inventory, also we have a function called _searchItem()_ to traverse through all the nodes and check if that specific item is in our inventory or not and return the value. The items in the inventory will also be saved into the database(.txt) file with the _writeInventory()_ function that traverses through all the nodes in our inventory and write into the database. This linked list play the role to store the items in order to enable the function to determine whether the player have access to certain problems in the game, this linked list also enable us to read and restore the inventory list when reloading a game from database. 
