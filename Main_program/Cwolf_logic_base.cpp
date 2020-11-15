#include <algorithm>
#include <cmath>
#include <ctime>
#include <ctime>
#include <iostream>
#include <map>
#include <random>
#include <stdlib.h>
#include <string>
#include <vector>
#include <windows.h>

short random_v2(short a) {//----------------random
	time_t  t = time(0);
  	std::mt19937 generator(t);
	Sleep(1000);
  	return (generator() % a) + 1;
}

//=======================================Global variables & stuff========================//

std::map<short, std::string> T_last_word;

std::vector<bool> Villager_last_word = {false, false, false}, Werewolf_last_word = {false, false, false};

///////////////////////////////////////////speak

void p_announ_skip(short p) {
	std::cout << "		Player " << p << ": Nothing! ";
	short last_skip_rd = random_v2(5);
	if(last_skip_rd == 1) std::cout << "Just skip me anyway.";
	else if(last_skip_rd == 2) std::cout << "There's nothing I can say.";
	else if(last_skip_rd == 3) std::cout << "Sorry, I can't think of what to say.";
	else if(last_skip_rd == 4) std::cout << "I rather not saying anything.";
	else if(last_skip_rd == 5) std::cout << "There's something urgent, I'm leaving, good bye ~";
	std::cout << std::endl;
}

///////////////////////////////////////////speak//end//
//=======================================Global variables & stuff========================//end//

//=================================================Speak & Last_word=====================//

void user_last_word() {
	std::cout << "[System.warning] Please sub space into \"_\"" << std::endl;
	std::string user_in;
	std::cin >> user_in;
	T_last_word[9] = user_in;
	std::cout << "[System.announ] Your last word is " << user_in << std::endl;
}

void Day_s_mod1(short p, short v1, short v2, short w1, short w2, short h) {
	std::cout << "		Player " << p << " : Villagers ,be careful." << std::endl;
	std::cout << "		Player " << w2 << " : I guess player " << p << " is wolf." << std::endl;
	std::cout << "		Player " << v1 << " : But I think player " << w2 << " actually is the wolf, because he is the man kind that thinks one way but acts another." << std::endl;
	std::cout << "		Player " << v2 << " : Ya, I agree that,you can say that again." << std::endl;
	std::cout << "		Player " << w1 << " : Hey why you gonna say that, maybe you are just the wolf." << std::endl;
	std::cout << "		Player " << v2 << " : How about having a vote, huh?" << std::endl;
	std::cout << "		Player " << h << " : Yeah,I agree that." << std::endl;
}

void Day_s_mod2_1(short v1, short v2, short v3, short w1, short w2, short p) {
	std::cout << "		Player " << w1 << ": I can¡¦t believe that he is a werewolf!" << std::endl;
	std::cout << "		Player " << v1 << ": " << "player " << w1 << ", you're also the werewolf, right?" << std::endl;
	std::cout << "		Player " << w2 << ": How can you say that! Player " << p << " is more suspicious, isn't he?" << std::endl;
	std::cout << "		Player " << v2 << ": Sounds that you're just their partner." << std::endl;
	std::cout << "		Player " << v3 << ": Okay, I think we can have a vote and lynch scapegoat." << std::endl;
}

void Day_s_mod2_2(short v1, short v2, short v3, short w, short p) {
	std::cout << "		Player " << w << ": I can¡¦t believe that he is a werewolf!" << std::endl;
	std::cout << "		Player " << v1 << ": " << "player " << w << ", you're also the werewolf, right?" << std::endl;
	std::cout << "		Player " << w << ": How can you say that! Player " << p << " is more suspicious, isn't he?" << std::endl;
	std::cout << "		Player " << v2 << ": Sounds that you're just their partner." << std::endl;
	std::cout << "		Player " << v3 << ": Okay, I think we can have a vote and lynch scapegoat." << std::endl;
}

void Day_s_mod3(short p, short w1, short w2, short v) {
	std::cout << "		Player " << p << ": Hey, I think "<< w1 << " is the werewolf, I'm the prognosticator." << std::endl;
	std::cout << "		Player " << w1 << ": No, I'm not. Don't frame me." << std::endl;
	std::cout << "		Player " << w2 << ": Ya he isn't the wolf, I'm prognosticator. Don't believe in that fake prognosticator." << std::endl;
	std::cout << "		Player " << v << ": Let's vote that fake out." << std::endl;
}

void Day_4_speak(short v1, short v2, short w1, short w2, short h) {
	std::cout << "		Player " << v1 << ": So, who is the werewolf now?" << std::endl;
	std::cout << "		Player " << w1 << ": I think it's player " << h << ", because ge talks very little, didn't he hide something?" << std::endl;
	std::cout << "		Player " << h << ": No! I'm not!" << std::endl;
	std::cout << "		Player " << v2 << ": Huh stop lying, tell us who is your partner!" << std::endl;
	std::cout << "		Player " << w2 << ": Don't waste time, let's vote him out." << std::endl;
}
//=================================================Speak & Last_word=====================//end//

//=================================================Logic============================//
//=================================================Logic============================//end//
