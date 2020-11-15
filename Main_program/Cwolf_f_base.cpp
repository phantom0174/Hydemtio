#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <map>
#include <random>
#include <stdlib.h>
#include <string>
#include <vector>
#include <windows.h>
#include "Cwolf_logic_base.cpp"
#include "Cwolf_music_data.cpp"

/////////////////////////////////////////////////////Insert music/////////

void Start_program_t() {
	Start_program();
}

void Enter_program_t() {
	Enter_program();
}

void System_announ_t() {
	System_announ();
}

void Game_ended_t() {
	Game_ended();
}

void System_abnormal_t() {
	System_abnormal();
}

/////////////////////////////////////////////////////Insert music/////////end//

//============================basic class====================//
class player{
	public:
		char card = 'n';
		bool exist = true;
		bool check = false;
};
//============================basic class====================//end//

//=======================================Global variables & stuff========================//

bool user = 0;

short werewolf_as_random;

bool Witch_revive_potion_use = false, Witch_poison_potion_use = false;

std::vector<short> PDTN, player_dead; // player_dead this night

std::map<short, std::string> Prognosticator_check;

std::vector<player> Player_list;

std::vector<char> card_storage;

std::vector<short> Werewolf_player, Villager_player, Hunter_player, Witch_player, Prognosticator_player;

short Witch_saved_player = -1;

short hunter_will_kill = -1;
//=======================================Global variables & stuff========================//end//

//=============================================functions==============================//

//////////////////////////////////////////////////////////speak//

bool Day_s_mod1_c() {//--------------------Day_speak_mod_1-----------//
	short dvc = 0, dwc = 0;
	for(short i = 0; i < player_dead.size(); i++) {
		if(Player_list[player_dead[i] - 1].card == 'v') dvc++;
		else if(Player_list[player_dead[i] - 1].card == 'w') dwc++;
	}
	
	if(dvc == 1 || (dvc == 1 && dwc == 1) || dwc == 1) {
		bool P_e = Player_list[Prognosticator_player[0] - 1].exist;
		bool H_e = Player_list[Hunter_player[0] - 1].exist;
		std::vector<short> Sv, Sw;
		for(short i = 0; i < 3; i++) {
			if(Player_list[Villager_player[i] - 1].exist == 1) Sv.push_back(Villager_player[i]);
		}
		for(short i = 0; i < 3; i++) {
			if(Player_list[Werewolf_player[i] - 1].exist == 1) Sw.push_back(Werewolf_player[i]);
		}
		if(P_e == 1 && H_e == 1 && Sv.size() >= 2 && Sw.size() >= 2) {
			Day_s_mod1(Prognosticator_player[0], Sv[0], Sv[1], Sw[0], Sw[1], Hunter_player[0]);
			goto mod1_access;
		}
		else goto mod1_skip;
	}
	else goto mod1_skip;
	
	mod1_access:
		if(user == 1) std::cout << "M1 access!" << std::endl;
		return 1;
		
	mod1_skip:
		if(user == 1) std::cout << "M1 not access!" << std::endl;
		return 0;
}

//--------------------Day_speak_mod_1-----------//end//

bool Day_s_mod2_c() {//--------------------Day_speak_mod_2-----------//
	if(Player_list[Hunter_player[0] - 1].exist == 0) {
		for(short i = 0; i < 3; i++) {
			if(Player_list[Villager_player[i] - 1].exist == 0) goto mod2_skip;
		}
		short dwc = 0;
		for(int i = 0; i < player_dead.size(); i++) {
			if(Player_list[player_dead[i] - 1].card == 'w') dwc++;
		}
		std::vector<short> Sw;
		for(int i = 0; i < 3; i++) {
			if(Player_list[Werewolf_player[i] - 1].exist == 1) Sw.push_back(Werewolf_player[i]);
		}
		
		if(dwc == 1) {
			Day_s_mod2_1(Villager_player[0], Villager_player[1], Villager_player[2], Sw[0], Sw[1], Prognosticator_player[0]);
			goto mod2_access;
		}
		else if(dwc == 2) {
			Day_s_mod2_2(Villager_player[0], Villager_player[1], Villager_player[2], Sw[0], Prognosticator_player[0]);
			goto mod2_access;
		}
		else goto mod2_skip;
	}
	else goto mod2_skip;
	
	mod2_access:
		if(user == 1) std::cout << "M2 access!" << std::endl;
		return 1;
	
	mod2_skip:
		if(user == 1) std::cout << "M2 not access!" << std::endl;
		return 0;
}

//--------------------Day_speak_mod_2-----------//end//

bool Day_s_mod3_c() {//--------------------Day_speak_mod_3-----------//
	std::vector<short> Sv, Sw;
	for(short i = 0; i < 3; i++) {
		if(Player_list[Villager_player[i] - 1].exist == 1) Sv.push_back(Villager_player[i]);
		if(Player_list[Werewolf_player[i] - 1].exist == 1) Sw.push_back(Werewolf_player[i]);
	}
	if(Sv.size() == 1 && Sw.size() >= 2) {
		Day_s_mod3(Prognosticator_player[0], Sw[0], Sw[1], Sv[0]);
	}
	else goto mod3_skip;
	
	mod3_access:
		if(user == 1) std::cout << "M3 access!" << std::endl;
		return 1;
	
	mod3_skip:
		if(user == 1) std::cout << "M3 not access!" << std::endl;
		return 0;

}
//--------------------Day_speak_mod_3-----------//end//

bool Day_s_mod4_c() {//--------------------Day_speak_mod_4-----------//
	if(Player_list[Prognosticator_player[0] - 1].exist == 0 && Player_list[Hunter_player[0] - 1].exist == 1) {
		std::vector<short> Sv, Sw;
		for(short i = 0; i < 3; i++) {
			if(Player_list[Villager_player[i] - 1].exist == 1) Sv.push_back(Villager_player[i]);
			if(Player_list[Werewolf_player[i] - 1].exist == 1) Sw.push_back(Werewolf_player[i]);
		}
		if(Sv.size() >= 2 || Sw.size() >= 2) {
			Day_4_speak(Sv[0], Sv[1], Sw[0], Sw[1], Hunter_player[0]);
		}
		else goto mod4_skip;
	}
	else goto mod4_skip;
	
	
	
	mod4_access:
		if(user == 1) std::cout << "M4 access!" << std::endl;
		return 1;
	
	mod4_skip:
		if(user == 1) std::cout << "M4 not access!" << std::endl;
		return 0;
}

//--------------------Day_speak_mod_4-----------//end//

//////////////////////////////////////////////////////////speak//end//

//========================================================================================//tool
short random(short a) {//----------------random
	time_t  t = time(0);
  	std::mt19937 generator(t);
	Sleep(1000);
  	return (generator() % a) + 1;
}

void Selected() {
	std::cout << "Selected!" << std::endl;
}

void de_acro(char a) {//----------------------de-acronym the cards
	if(a == 'v') std::cout << "Villager";
	else if(a == 'h') std::cout << "Hunter";
	else if(a == 'w') std::cout << "Werewolf";
	else if(a == 'i') std::cout << "Witch";
	else if(a == 'p') std::cout << "Prognosticator";
	else if(a == 'n') std::cout << "N/A";
}

void card_restore() {//-----------------------------restore the cards & shuffle
	card_storage = {'w', 'h', 'w', 'v', 'p', 'v', 'v', 'i', 'w'};
	time_t t = time(0);
	std::shuffle(card_storage.begin(), card_storage.end(), std::mt19937(t));
	if(user == 1) {
		std::cout << std::endl;
		std::cout << "{";
		for(short i = 0; i < card_storage.size(); i++) {
			std::cout << card_storage[i];
			if(i != 8) std::cout << " ";
		}
		std::cout << "}" << std::endl;
	}
}

//========================================================================================//check

void death_until_now() {
	std::cout << "player dead until now : ";
	for(short i = 0; i < player_dead.size(); i++) {
		std::cout << player_dead[i] << " ";
	}
	std::cout << std::endl;
}
void all_sit_check() {
	std::cout << std::endl;
	for(int i = 0; i < Player_list.size(); i++) {
		if(i == 8) std::cout << "(You)";
		std::cout << "Player " << i + 1 << ":: ";
		std::cout << " Card: ";
		de_acro(Player_list[i].card);
		std::cout << " , Exist: " << Player_list[i].exist;
		std::cout << " , Check: " << Player_list[i].check << std::endl;
	}
}

void Werewolf_player_cout() {
	for(int i = 0; i < Werewolf_player.size() - 1; i++) {
		std::cout << Werewolf_player[i] << " ";
	}
}

void all_player_career() {
	std::cout << "Werewolf_player: "; 
	for(int i = 0; i < Werewolf_player.size(); i++) {
		std::cout << Werewolf_player[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Villager_player: "; 
	for(int i = 0; i < Villager_player.size(); i++) {
		std::cout << Villager_player[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Hunter_player: ";
	for(int i = 0; i < Hunter_player.size(); i++) {
		std::cout << Hunter_player[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Witch_player: "; 
	for(int i = 0; i < Witch_player.size(); i++) {
		std::cout << Witch_player[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Prognosticator_player: "; 
	for(int i = 0; i < Prognosticator_player.size(); i++) {
		std::cout << Prognosticator_player[i] << " ";
	}
	std::cout << std::endl;
}

bool user_exist_check() {
	if(Player_list[8].exist == false) {
		System_abnormal();
		std::cout << "[System.error] You are already dead." << std::endl;
		return false;
	}
	else return true;
}

short game_situ_check() {
	short Villager_death = 0, God_death = 0, Werewolf_death = 0;
	for(int i = 0; i < 3; i++) {
		if(Player_list[Villager_player[i] - 1].exist == false) Villager_death++;
	}
	if(Player_list[Witch_player[0] - 1].exist == false) God_death++;
	if(Player_list[Hunter_player[0] - 1].exist == false) God_death++;
	if(Player_list[Prognosticator_player[0] - 1].exist == false) God_death++;
	for(int i = 0; i < 3; i++) {
		if(Player_list[Werewolf_player[i] - 1].exist == false) Werewolf_death++;
	}
	if(Werewolf_death == 3) return 1;
	else if(Villager_death == 3 || God_death == 3) return 0;
	return 2;
}
//========================================================================================//movement

void dealing() {
	Start_dealing();
	card_restore();
	short player_turn = 0;
	while(player_turn < 9) {
		
		//--------------------------------------------------try to be a real random
		short chosen_card = random(card_storage.size());
		std::cout << chosen_card << std::endl;
		Player_list[player_turn].card = card_storage[chosen_card - 1];
		
		
		if(card_storage[chosen_card - 1] == 'w') Werewolf_player.push_back(player_turn + 1); 
		else if(card_storage[chosen_card - 1] == 'v') Villager_player.push_back(player_turn + 1);
		else if(card_storage[chosen_card - 1] == 'h') Hunter_player.push_back(player_turn + 1);
		else if(card_storage[chosen_card - 1] == 'i') Witch_player.push_back(player_turn + 1);
		else if(card_storage[chosen_card - 1] == 'p') Prognosticator_player.push_back(player_turn + 1);
		
		card_storage.erase(card_storage.begin() + chosen_card - 1, card_storage.begin() + chosen_card);
		player_turn++;
	}
	
	std::sort(Werewolf_player.begin(), Werewolf_player.end());
	std::sort(Villager_player.begin(), Villager_player.end());
	
	card_storage.clear();
	Dealing_finished();
	system("pause");
	system("cls");
}

void User_werewolf_kill() {
	short willing_kill;
	std::cout << "[System.alert] Your partners are: ";
	Werewolf_player_cout();
	std::cout << ", you can't kill them." << std::endl;
	System_announ();
	std::cout << "[System.announ] Which person do you want to kill?" << std::endl;
	user_re_kill:
		std::cin >> willing_kill;
		if(willing_kill <= 0 || willing_kill > 9) {
			System_abnormal();
			std::cout << "[System.warning] Out of range!" << std::endl;
			goto user_re_kill;
		}
		for(int i = 0; i < Werewolf_player.size() - 1; i++) {
			if(willing_kill == Werewolf_player[i]) {
				System_abnormal();
				std::cout << "[System.warning] You can't kill your partner!" << std::endl;
				goto user_re_kill;
			}
		}
		if(willing_kill == 9) {
			System_abnormal();
			std::cout << "[System.warning] You can't suicide!" << std::endl;
			goto user_re_kill;
		}
		else if(Player_list[willing_kill - 1].exist == false) {
			System_abnormal();
			std::cout << "[System.error] That people is already dead!" << std::endl;
			goto user_re_kill;
		}
		
		Selected();
		Player_list[willing_kill - 1].exist = false;
		PDTN.push_back(willing_kill);
}

void Comp_kill() {
	comp_re_kill:
		short comp_will_kill = random(9);
		for(int i = 0; i < Werewolf_player.size(); i++) {
			if(comp_will_kill == Werewolf_player[i]) goto comp_re_kill;
		}
		if(Player_list[comp_will_kill - 1].exist == false) goto comp_re_kill;
		
		Selected();
		Player_list[comp_will_kill - 1].exist = false;
		PDTN.push_back(comp_will_kill);
}

void User_Prognosticator_check() {
	if(Prognosticator_check.empty() != 1) {
		System_announ();
		std::cout << "[System.announ] People that you've already know are:" << std::endl;
		for(int i = 1; i <= 8; i++) {
			std::cout << "Player " << i << " : " << Prognosticator_check[i] << std::endl;
		}
	}
	std::cout << "[System.announ] Who do you want to check?" << std::endl;
	user_re_check:
		short willing_check;
		std::cin >> willing_check;
		if(willing_check <= 0 || willing_check > 9) {
			System_abnormal();
			std::cout << "[System.warning] Out of range!" << std::endl;
			goto user_re_check;
		}
		if(willing_check == 9) {
			System_abnormal();
			std::cout << "[System.warning] You can't check yourself!" << std::endl;
			goto user_re_check;
		}
		else if(Player_list[willing_check - 1].check == true) {
			System_abnormal();
			std::cout << "[System.error] That people has been checked!" << std::endl;
			goto user_re_check;
		}
		
		Selected();
		std::string side;
		char career = Player_list[willing_check - 1].card;
		if(career == 'v' || career == 'h' || career == 'i' || career == 'p') {
			System_announ();
			std::cout << "[System.announ] A good one!" << std::endl;
			side = "Good";
		}
		else {
			System_announ();
			std::cout << "[System.announ] A bad one!" << std::endl;
			side = "Bad";
		}
		Player_list[willing_check - 1].check = true;
		Prognosticator_check[willing_check] = side;
}

void Comp_check() {
	comp_re_check:
		short comp_will_check = random(9);
		if(comp_will_check == Prognosticator_player[0]) goto comp_re_check;
		if(Player_list[comp_will_check - 1].check == true) goto comp_re_check;
		
		Selected();
		std::string side;
		char career = Player_list[comp_will_check - 1].card;
		if(career == 'v' || career == 'h' || career == 'i' || career == 'p') side = "Good";
		else side = "Bad";
		Player_list[comp_will_check - 1].check = true;
		Prognosticator_check[comp_will_check] = side;
}

void User_witch_revival() {
	bool revival_potion;
	System_murmur();
	std::cout << "[System.murmur] -player " << PDTN[0] << "." << std::endl;
	std::cout << "[System.announ] Do you want to save the victim with your life potion?(0/1)" << std::endl;
	std::cin >> revival_potion;
	Selected();
	if(revival_potion == 1) {
		Witch_revive_potion_use = true;
		Witch_saved_player = PDTN[0];
		Player_list[PDTN[0] - 1].exist = true;
		PDTN.clear();
	}
}

void User_witch_poison() {
	bool poison_potion;
	System_announ();
	std::cout << "[System.announ] Witch, who do you want to kill with your death potion?(0/1)" << std::endl;
	std::cin >> poison_potion;
	if(poison_potion == 1) {
		short user_witch_willing_kill;
		user_witch_re_kill:
		std::cin >> user_witch_willing_kill;
		if(user_witch_willing_kill <= 0 || user_witch_willing_kill > 9) {
			System_abnormal();
			std::cout << "[System.warning] Out of range!" << std::endl;
			goto user_witch_re_kill;
		}
		if(user_witch_willing_kill == 9) {
			System_abnormal();
			std::cout << "[System.warning] You can't suicide!" << std::endl;
			goto user_witch_re_kill;
		}
		else if(Player_list[user_witch_willing_kill - 1].exist == false) {
			System_abnormal();
			std::cout << "[System.error] That people is already dead!" << std::endl;
			goto user_witch_re_kill;
		}
		
		Selected();
		Witch_poison_potion_use = true;
		Player_list[user_witch_willing_kill - 1].exist = false;
		PDTN.push_back(user_witch_willing_kill);
	}
}

void comp_witch_revival() {
	System_announ();
	std::cout << "[System.announ] Do you want to save the victim with your life potion?" << std::endl;
	Selected();
	if(random(2) == 1) {
		Witch_revive_potion_use = true;
		Witch_saved_player = PDTN[0];
		Player_list[PDTN[0] - 1].exist = true;
		PDTN.clear();
	}
}

void comp_witch_poison() {
	System_announ();
	std::cout << "[System.announ] Witch, who do you want to kill with your death potion?" << std::endl;
	if(random(2) == 1) {
		comp_witch_re_kill:
			short comp_witch_willing_kill = random(9);
			if(Player_list[comp_witch_willing_kill - 1].exist == false) goto comp_witch_re_kill;
			if(comp_witch_willing_kill == Witch_player[0]) goto comp_witch_re_kill;
			
			Selected();
			Player_list[comp_witch_willing_kill - 1].exist = false;
			PDTN.push_back(comp_witch_willing_kill);
		Witch_poison_potion_use = true;
	}
}

short Day_vote() {
	short user_willing_vote;
	user_re_vote:
		std::cin >> user_willing_vote;
		if(user_willing_vote <= 0 || user_willing_vote > 9) {
			System_abnormal();
			std::cout << "[System.warning] Out of range!" << std::endl;
			goto user_re_vote;
		}
		if(user_willing_vote == 9) {
			System_abnormal();
			std::cout << "[System.warning] You can't suicide!" << std::endl;
			goto user_re_vote;
		}
		else if(Player_list[user_willing_vote - 1].exist == false) {
			System_abnormal();
			std::cout << "[System.error] That people is already dead!" << std::endl;
			goto user_re_vote;
		}
		
		Selected();
		Player_list[user_willing_vote - 1].exist = false;
		PDTN.push_back(user_willing_vote);
		return user_willing_vote;
}

short Day_comp_vote() {
	comp_re_vote:
		short comp_will_vote = random(3);
		std::cout << comp_will_vote << std::endl;
		if(Player_list[Werewolf_player[comp_will_vote - 1] - 1].exist == false) goto comp_re_vote;
		
		Selected();
		Player_list[Werewolf_player[comp_will_vote - 1] - 1].exist = false;
		PDTN.push_back(comp_will_vote);
		return Werewolf_player[comp_will_vote - 1];
}

void User_hunter_kill() {
	short user_hunter_willing_kill;
	user_h_re:
		std::cout << "		Do you want to kill anyone?(enter 0 not to kill)" << std::endl;
		std::cin >> user_hunter_willing_kill;
		if(user_hunter_willing_kill == 0) goto user_h_skip;
		if(user_hunter_willing_kill < 0 || user_hunter_willing_kill > 9) {
			System_abnormal();
			std::cout << "[System.warning] Out of range!" << std::endl;
			goto user_h_re;
		}
		if(user_hunter_willing_kill == 9) {
			System_abnormal();
			std::cout << "[System.warning] You can't suicide!" << std::endl;
			goto user_h_re;
		}
		else if(Player_list[user_hunter_willing_kill - 1].exist == false) {
			System_abnormal();
			std::cout << "[System.error] That people is already dead!" << std::endl;
			goto user_h_re;
		}
		
		Selected();
		hunter_will_kill = user_hunter_willing_kill;
		Player_list[user_hunter_willing_kill - 1].exist = false;
		
	user_h_skip:
		std::cout << "[System.announ] Ok!" << std::endl;
}
//=============================================functions==============================//end//

/////////////////////////////////////////////////////Insert logic/////////

void user_last_word_f() { //bi-terminal
	user_last_word();
}

void comp_sub_last_word_f(short p) {
	if(Player_list[p - 1].card == 'v') {
		v_lst_re:
			short c = random(3);
			if(Villager_last_word[c - 1] == true) goto v_lst_re;
			else {
				if(c == 1) {
					short v_g = random(2), selected_player;
					std::vector<short> God_alive, Villager_alive;
					for(int i = 0; i < 3; i++) {
						if(Player_list[Villager_player[i] - 1].exist == 1 && Villager_player[i] != p) Villager_alive.push_back(Villager_player[i]);
						goto god_alive;
					}
					god_alive:
					if(Player_list[Hunter_player[0] - 1].exist == 1) God_alive.push_back(Hunter_player[0]);
					if(Player_list[Witch_player[0] - 1].exist == 1) God_alive.push_back(Witch_player[0]);
					if(Player_list[Prognosticator_player[0] - 1].exist == 1) God_alive.push_back(Prognosticator_player[0]);
					
					if(v_g == 1 && Villager_alive.size() > 1) {
						selected_player = Villager_alive[random(Villager_alive.size()) - 1];
						goto v_1_ct;
					}
					else if(v_g == 2 && God_alive.size() > 0){
						selected_player = God_alive[random(God_alive.size()) - 1];
						goto v_1_ct;
					}
					
					goto p_announ_skip_c;
					
					v_1_ct:
						std::cout << "		Player " << p << ": Hey, I'm not a wolf, why you guys just don't believe me? I think player" << selected_player << " is more like a wereolf, Lynch him in the next day." << std::endl;
						Villager_last_word[c - 1] = true;
				}
				else if(c == 2) {
					short selected_villager, selected_werewolf;
					std::vector<short> Villager_alive, Werewolf_alive;
					for(int i = 0; i < 3; i++) {
						if(Player_list[Werewolf_player[i] - 1].exist == 1) Werewolf_alive.push_back(Werewolf_player[i]);
						if(Player_list[Villager_player[i] - 1].exist == 1 && Villager_player[i] != p) Villager_alive.push_back(Villager_player[i]);
					}
					if(Villager_alive.size() > 1 && Werewolf_alive.size() > 0) {
						selected_villager = Villager_alive[random(Villager_alive.size()) - 1];
						selected_werewolf = Werewolf_alive[random(Werewolf_alive.size()) - 1];
						goto v_2_ct;
					}
					
					goto p_announ_skip_c;
					
					v_2_ct:
						std::cout << "		Player " << p << ": LOL. That's fine, I just saw that player " << selected_villager << " and player " << selected_werewolf << " voted me, right? I think they are werewolves, for no reason." << std::endl;
						Villager_last_word[c - 1] = true;
				}
				else {
					short selected_player;
					std::vector<short> Player_alive;
					for(int i = 0; i < 9; i++) {
						if(Player_list[i].exist == 1 && (i + 1) != p) Player_alive.push_back(i);
					}
					selected_player = Player_alive[random(Player_alive.size()) - 1];
					std::cout << "		Player " << p << ": Player " << selected_player << " is the wolf, I'm the Prognosticator." << std::endl;
					Villager_last_word[c - 1] = true;
				}
			}
	}
	else if(Player_list[p - 1].card == 'w') {
		w_lst_re:
			short c = random(3);
			if(Werewolf_last_word[c - 1] == true) goto w_lst_re;
			else {
				if(c == 1) {
					short selected_player;
					std::vector<short> Player_except_w_alive;
					for(short i = 0; i < 9; i++) {
						if(Player_list[i].card != 'w' && Player_list[i].exist == 1) Player_except_w_alive.push_back(i + 1);
					}
					if(Player_except_w_alive.size() > 0) {
						selected_player = Player_except_w_alive[random(Player_except_w_alive.size()) - 1];
						goto w_1_ct;
					}
					
					goto p_announ_skip_c;
					
					w_1_ct:
						std::cout << "		Player " << p << ": Hey, player " << selected_player << " is the wolf, I'm the Prognosticator." << std::endl;
						Werewolf_last_word[c - 1] = true;
				}
				else if(c == 2) {
					short selected_player;
					std::vector<short> Player_except_w_alive;
					for(short i = 0; i < 9; i++) {
						if(Player_list[i].card != 'w' && Player_list[i].exist == 1) Player_except_w_alive.push_back(i + 1);
					}
					if(Player_except_w_alive.size() > 0) {
						selected_player = Player_except_w_alive[random(Player_except_w_alive.size()) - 1];
						goto w_2_ct;
					}
					
					goto p_announ_skip_c;
					
					w_2_ct:
						std::cout << "		Player " << p << ": Com'on why did you do that! Player " << selected_player << ", are you the wolf? Your behavior has been a little bit strange." << std::endl;
						Werewolf_last_word[c - 1] = true;
				}
				else {
					short selected_player;
					std::vector<short> Player_except_w_alive;
					for(short i = 0; i < 9; i++) {
						if(Player_list[i].card != 'w' && Player_list[i].exist == 1) Player_except_w_alive.push_back(i + 1);
					}
					if(Player_except_w_alive.size() > 0) {
						selected_player = Player_except_w_alive[random(Player_except_w_alive.size()) - 1];
						goto w_3_ct;
					}
					
					goto p_announ_skip_c;
					
					w_3_ct:
						std::cout << "		Player " << p << ": No! I'm villager! Trust me! Player " << selected_player << " are you the wolf?" << std::endl;
				 		Werewolf_last_word[c - 1] = true;
				}
			}
	}
	else if(Player_list[p - 1].card == 'p') {
		short selected_werewolf;
		bool w_selected = false;
		for(int i = 1; i <= 9; i++) {
			if(user == 1) std::cout << "Player " << i << " : " << Prognosticator_check[i] << std::endl;
			if(Prognosticator_check[i] == "Bad" && Player_list[i - 1].exist == 1) {
				selected_werewolf = i;
				w_selected = true;
				goto p_next;
			}
		}
		if(w_selected == false) goto p_announ_skip_c;
		
		p_next:
			std::cout << "		Player " << p << ": Player " << selected_werewolf << " is werewolf." << std::endl;
	}
	else if(Player_list[p - 1].card == 'h') {
		short selected_p;
		std::vector<short> Player_alive;
		for(short i = 0; i < 9; i++) {
			if(Player_list[i].exist == 1 && (i + 1) != p) Player_alive.push_back(i + 1);
		}
		selected_p = Player_alive[random(Player_alive.size()) - 1];
		hunter_will_kill = selected_p;
		Player_list[hunter_will_kill - 1].exist = false;
		std::cout << "		Player " << p << ": Player " << selected_p << " is werewolf, so DIE WITH ME!." << std::endl;
	}
	else if(Player_list[p - 1].card == 'i') {
		if(Witch_saved_player != -1) {
			std::cout << "		Player " << p << ": I'm witch, and player " << Witch_saved_player << " is not a werewolf, I've just saved him." << std::endl;
		}
		else {
			short selected_v;
			std::vector<short> Villager_alive;
			for(short i = 0; i < 3; i++) {
				if(Player_list[Villager_player[i] - 1].exist == 1) Villager_alive.push_back(Villager_player[i]);
			}
			
			if(Villager_player.size() != 0) {
				selected_v = Villager_alive[random(Villager_alive.size()) - 1];
				std::cout << "		Player " << p << ": I'm witch, and player " << selected_v << " is not a werewolf, I've just saved him" << std::endl;
			}
			else {
				goto p_announ_skip_c;
			}
		}
	}
	goto mega_skip;
	
	p_announ_skip_c:
		p_announ_skip(p);
		
	mega_skip:
		std::cout << "";
}

/////////////////////////////////////////////////////Insert logic/////////end//
