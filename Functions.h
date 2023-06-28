//this file is to store the global function in the programme
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <iomanip>
using namespace std;

		//function to show the opening of the game
void opening(){
	cout<<"\n==================================================================================================\n";
	cout<<"*"<<"\t"<<" _____   __   __   _____         __    __      ____     _    _   _______   ______"<<setw(8)<<"\t*"<<endl;
	cout<<"*"<<"\t"<<"|__ __| |  ||  |  |  ___|       |  |  |  |    /__  |   | \\  | | |       | |   _  \\"<<setw(7)<<"\t*"<<endl;
	cout<<"*"<<"\t"<<"  | |   |  ||  |  | |___        |   |/ / |   /|__| |   |  \\_| | |   =   | |  |_|  \\"<<setw(6)<<"\t*"<<endl;
	cout<<"*"<<"\t"<<"  | |   |  ==  |  | |___        | ||__/| |  /  __  |   |   _  | |   =   | |   __  /"<<setw(6)<<"\t*"<<endl;
	cout<<"*"<<"\t"<<"  |_|   |__||__|  |_____|       |_|    |_| /__/  |_|   |__| \\_| |_______| |__|  |_\\"<<setw(6)<<"\t*"<<endl;
	cout<<"==================================================================================================\n"<<endl;
	
	cout<<"REMINDER: Please write all the word in UPPERCASE letters\n\n";
	
	cout<< setw(5)<<" "<<"START Game/NEW Game\n";
	cout<< setw(5)<<" "<< "LOAD game.\n";
	cout<< setw(5)<<" "<< "QUIT Game. \n\n";
}

		//function to show the introduction of the game
void introduction(){
	cout << "\n===============================================================================================\n";
	cout << "You are a freelance investigative journalist, you received an anonymous e-mail\n"; 
	cout << "offering you a big sum of money to investigate a private abandoned mansion owned\n";
	cout << "by a tycoon back in the 1800s. The promise of a substantial sum of money was hard\n"; 
	cout << "to ignore, especially when it involved an eerie mansion with a mysterious past.\n\n";
	cout << "You arrive at the front gate of the abandoned mansion and you see flickering of dim\n";
	cout << "lights coming from inside the mansion. You wonder to yourself, isn't this place\n"; 
	cout << "abandoned from a long time ago? However, you get overwhelmed by your own\n";
	cout << "curiosity. The next thing you know, you are standing in the big grand hall of the\n";
	cout << "mansion......\n\n";
	cout << "\"BANG!...\" The main door behind you slammmed loudly, you tried to LEAVE the manor using the\n";
	cout << "main door but failed to. You are now trapped in THE MANOR.\n";
	cout <<	"A voice whispered to your ears. \"Seems like you got yourself into trouble young man......\"\n";
	cout << "You hear his voice, but you can't see the person whispering to you.\n";
	cout <<"\n\"I'm ASCII, the butler of this manor, I will be guiding you the way but you must be\n"; 
	cout <<"cautious with every step you take as danger lingers in every corner of the house\".\n";
	cout << "\n===============================================================================================\n";
	
	system("pause");
}

		//function to show when player cleared the game
void gameEnd(){
	cout<<"\n=======================================================================================\n";
	cout<<"\t #     # ###  #####  ####### ####### ######  #     # \n";
	cout<<"\t #     #  #  #     #    #    #     # #     #  #   #  \n";
	cout<<"\t #     #  #  #          #    #     # #     #   # #   \n";
	cout<<"\t #     #  #  #          #    #     # ######     #    \n";
	cout<<"\t  #   #   #  #          #    #     # #   #      #    \n";
	cout<<"\t   # #    #  #     #    #    #     # #    #     #    \n";
	cout<<"\t    #    ###  #####     #    ####### #     #    #    \n";
	cout<<"\n========================================================================================\n";
	cout<<"\nCongratulations on your triumphant escape from the terrifying manor. You have\n"; 
	cout<<"conquered the darkness and emerged victorious. But remember, some secrets can\n";
	cout<<"never truly be extinguished. As you leave the haunted halls behind, carry with you\n";
	cout<<"the knowledge that the shadows may still whisper. The story of the manor may be\n"; 
	cout<<"over, but its echoes will linger, awaiting the curious souls who dare to uncover the\n"; 
	cout<<"deeper truth......\n\n\n";
	
	system("pause");
}


#endif
