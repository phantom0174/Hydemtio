#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <map>
#include <stdlib.h>
#include <string>
#include <vector>
#include "D:\The Werewolves of Miller's Hollow\Cwolf_f_base.h"
#include "D:\The Werewolves of Miller's Hollow\Cwolf_effects.h"

int main() {
	system("color 0f");
	Start_program_t();
	Before_game_start();
	system("color f0");
	Enter_program_t();
	//-------------------------Game_rule----------------//
	std::cout << "[System.announ][Game_rule] You're in this village in which some people are Werewolves." << std::endl; //====gamerule
	std::cout << "	Every 'night' you guys close your eyes." << std::endl;
	std::cout << "	The people who are Werewolves open their eyes and secretly pick someone to bite." << std::endl;
	std::cout << "	Everyone opens their eyes and I tell you who died." << std::endl;
	std::cout << "	What happens then is that the Villagers have to figure out who amongst them is actually a Werewolf." << std::endl;
	std::cout << "	You guys debate for a while, then on the count of three everyone points at who they think should be Lynched." << std::endl;
	std::cout << "	Whoever has the most fingers pointed at them gets Lynched. Of course, the Villagers can end up lynching innocents instead of Werewolves." << std::endl;
	std::cout << "	Whatever happens, you close your eyes again and the Werewolves pick another victim." << std::endl;
	std::cout << "	The Werewolves want to kill all the Villagers before the Villagers can lynch them." << std::endl;
	system("pause");
	
	for(int i = 1; i <= 9; i++) {//------------default_player_list_setting
		player demo;
		Player_list.push_back(demo);
	}
	if(user == 1) all_sit_check();
	system("pause");
	std::cout << "[System.announ] Start dealing!" << std::endl;
	dealing();
	
	//----------------------dealing result
	
	if(user == 1) all_sit_check();
	else {
		std::cout << "[System.announ] Your occupation is ";
		de_acro(Player_list[8].card);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
	if(user == 1) all_player_career();
	
	system("pause");
	system("cls");
	std::cout << "[System.announ] Game Start!" << std::endl;
	short day_count = 1;
	while(1) {
		system("color 0f");
		System_announ_t();
		std::cout << "[System.announ] <Day " << day_count  << " night"<< ">" << std::endl;
		std::cout << "[System.announ] Night is falling in the village. Everyone is going to sleep. Shut your eyes and don't peek." << std::endl;
		
		
		//=====================================================================Were_wolf=======//
		std::cout << "[System.announ] Werewolves, open your eyes." << std::endl;
		std::cout << "		Werewolves, make sure you know who the other werewolves are." << std::endl;
		std::cout << "		Werewolves, pick someone to be tonight's victim." << std::endl;
		 
		if(Player_list[8].card == 'w') {
			if(user_exist_check() == false) goto werewolf_skip;
			User_werewolf_kill();
		}
		else {
			short Werewolf_exist = 0;
			for(int i = 0; i < 3; i++) {
				if(Player_list[Werewolf_player[i] - 1].exist == true) Werewolf_exist++;
			}
			if(Werewolf_exist == 0) goto werewolf_skip;
			Comp_kill();
		}
		werewolf_skip:
		System_announ_t();
		std::cout << "[System.announ] Werewolves, close your eyes." << std::endl;
		if(user == 1) all_sit_check();
		//=====================================================================Were_wolf=======//end//
		
		//=====================================================================Prognosticator=======//
		System_announ_t();
		std::cout << "[System.announ] Prognosticator, open your eyes." << std::endl;
		std::cout << "		Prognosticator, who would you like to know about?" << std::endl;
		if(Player_list[8].card == 'p') {
			if(user_exist_check() == false) goto prognosticator_skip;
			User_Prognosticator_check();
		}
		else {
			if(Player_list[Prognosticator_player[0] - 1].exist == false) goto prognosticator_skip;
			Comp_check();
		}
		prognosticator_skip:
		System_announ_t();
		std::cout << "[System.announ] Prognosticator, close your eyes." << std::endl;
		if(user == 1) all_sit_check();
		//=====================================================================Prognosticator=======//end//
		
		//=====================================================================Witch=======//
		System_announ_t();
		std::cout << "[System.announ] Witch, open your eyes." << std::endl;
		if(day_count == 1) std::cout << "		Remember, you can use each of your potions only once in a game." << std::endl;
		std::cout << "		Witch, I will show you who was killed tonight." << std::endl;
		if(Player_list[8].card == 'i') {
			if(user_exist_check() == false) goto witch_skip;
			if(Witch_revive_potion_use == true) {
				System_abnormal_t();
				std::cout << "[System.warning] You can't use the revival potion twice, thus skipping." << std::endl;
				goto user_skip_revive_potion;
			}
			User_witch_revival(); 
			
			user_skip_revive_potion:
				
			if(Witch_poison_potion_use == true) {
				System_abnormal_t();
				std::cout << "[System.warning] You can't use the poison potion twice, thus skipping." << std::endl;
				goto witch_skip;
			}
			User_witch_poison();
		}
		else {
			if(Player_list[Witch_player[0] - 1].exist == false) goto witch_skip;
			if(Witch_revive_potion_use == true) goto comp_skip_revive_potion;
			comp_witch_revival();
			
			comp_skip_revive_potion:
				
			if(Witch_poison_potion_use == true) goto witch_skip;
			comp_witch_poison();
		}
		witch_skip:
		System_announ_t();
		std::cout << "[System.announ] Witch, close your eyes." << std::endl;
		if(user == 1) all_sit_check();
		//=====================================================================Witch=======//end//
		system("pause");
		//===============================================================================================night//end//
		
		for(short i = 0; i < PDTN.size(); i++) {
			player_dead.push_back(PDTN[i]);
		}
		death_until_now();
		
		system("color f0");
		System_announ_t();
		std::cout << "[System.announ] <Day " << day_count << " morning"<< ">" << std::endl;
		
		std::sort(PDTN.begin(), PDTN.end());
		
		
		//-------------------------Last_word--------------//
		
		if(PDTN.empty() != 1) {
			if(day_count == 1) {
				System_announ_t();
				std::cout << "[System.announ] Unfortunately, " << PDTN.size() << " player was dead." << std::endl;
				if(PDTN.size() == 1) std::cout << "[System.anoun] -player" << PDTN[0] << std::endl;
				else if(PDTN.size() == 2) {
					std::cout << "[System.anoun] -player " << PDTN[0] << " & " << PDTN[1] << std::endl;
				}
				for(int i = 0; i < PDTN.size(); i++) {
					std::cout << "		Do you have any last word? player " << PDTN[i] << std::endl;
					if(PDTN[i] == 9) user_last_word_f();
					else comp_sub_last_word_f(PDTN[i]);
					if(PDTN[i] == 9 && Player_list[8].card == 'h') {
						System_announ_t();
						std::cout << "[System.announ] Also, hunter can choose to kill a player." << std::endl;
						User_hunter_kill();
						if(hunter_will_kill != -1) {
							std::cout << "		Do you have any last word? player " << hunter_will_kill << std::endl;
							comp_sub_last_word_f(hunter_will_kill);
						}
					}
					if(Player_list[PDTN[i] - 1].card == 'h') {
						System_announ_t();
						std::cout << "[System.announ] Also, hunter has chose to kill a player, which is player " << hunter_will_kill << "." << std::endl;
						std::cout << "		Do you have any last word? player " << hunter_will_kill << std::endl;
						if(hunter_will_kill == 9) user_last_word_f();
						else comp_sub_last_word_f(hunter_will_kill);
					}
				}
			}
			else if(day_count == 2) {
				if(PDTN.size() >= 2) {
					System_announ_t();
					std::cout << "[System.announ] Unfortunately, 2 player was dead." << std::endl;
					std::cout << "		They are player " << PDTN[0] << " & " << PDTN[1] << std::endl;
					System_abnormal_t();
					std::cout << "[System.alert] According to gamerule, last word skipping(deathtoal > 1 on day 2)." << std::endl;
					goto last_word_skip;
				}
				else {
					System_announ_t();
					std::cout << "[System.announ] Unfortunately, 1 player was dead." << std::endl;
					std::cout << "		He is player " << PDTN[0] << std::endl;
					if(PDTN[0] == 9) user_last_word_f();
					else comp_sub_last_word_f(PDTN[0]);
					if(PDTN[0] == 9 && Player_list[8].card == 'h') {
						System_announ_t();
						std::cout << "[System.announ] Also, hunter can choose to kill a player." << std::endl;
						User_hunter_kill();
						if(hunter_will_kill != -1) {
							std::cout << "		Do you have any last word? player " << hunter_will_kill << std::endl;
							comp_sub_last_word_f(hunter_will_kill);
						}
					}
					if(Player_list[PDTN[0] - 1].card == 'h') {
						System_announ_t();
						std::cout << "[System.announ] Also, hunter has chose to kill a player, which is player " << hunter_will_kill << "." << std::endl;
						std::cout << "		Do you have any last word? player " << hunter_will_kill << std::endl;
						if(hunter_will_kill == 9) user_last_word_f();
						else comp_sub_last_word_f(hunter_will_kill);
					}
				}
			}
			else if(day_count >= 3) {
				System_announ_t();
				std::cout << "[System.announ] Unfortunately, " << PDTN.size() << " player was dead." << std::endl;
				std::cout << "		-player ";
				for(int i = 0; i < PDTN.size(); i++) {
					std::cout << PDTN[i];
				}
				std::cout << std::endl;
				System_abnormal_t();
				std::cout << "[System.alert] According to gamerule, last word skipping(no player been killed durning night can speak last word after day 2)." << std::endl;
				goto last_word_skip;
			}
		}
		else {
			System_announ_t();
			std::cout << "[System.announ] Last night was a peaceful night." << std::endl;
		}
		
		//-------------------------Last_word--------------//end//
		
		last_word_skip:
		
		//----------------------------Day_speak-----------//
		System_announ_t();
		std::cout << "[System.announ] Let's speak in turns." << std::endl;
		if(Day_s_mod1_c() == 1) goto speak_skip;
		else if(Day_s_mod2_c() == 1) goto speak_skip;
		else if(Day_s_mod3_c() == 1) goto speak_skip;
		else if(Day_s_mod4_c() == 1) goto speak_skip;
		//----------------------------Day_speak-----------//end//
		speak_skip:
		//----------------------------Day_vote------------//
		System_announ_t();
		std::cout << "[System.announ] Every thing okay? Then, let's vote." << std::endl;
		short day_dead_p = -1;
		if(Player_list[8].card == 'w') {
			werewolf_as_random = random(10);
			std::cout << werewolf_as_random << std::endl;
			if(werewolf_as_random < 6) {
				day_dead_p = Day_comp_vote();
				System_announ_t();
				std::cout << "[System.announ] Player " << day_dead_p << ", you are dead. What's your last word?" << std::endl;
				if(day_dead_p == 9) user_last_word_f();
				else comp_sub_last_word_f(day_dead_p);
				
			}
			else {
				short day_dead_p = Day_vote();
				System_announ_t();
				std::cout << "[System.announ] Player " << day_dead_p << ", you are dead. What's your last word?" << std::endl;
				if(day_dead_p == 9) user_last_word_f();
				else comp_sub_last_word_f(day_dead_p);
			}
		}
		else {
			short day_dead_p = Day_vote();
			System_announ_t();
			std::cout << "[System.announ] Player " << day_dead_p << ", you are dead. What's your last word?" << std::endl;
			if(day_dead_p == 9) user_last_word_f();
			else comp_sub_last_word_f(day_dead_p);
		}
		
		PDTN.clear();
		//----------------------------Day_vote------------//end//
		
		//------------------------------------------game_situation_checking-----//
		if(game_situ_check() == 0) goto lose;
		else if(game_situ_check() == 1) goto win;
		system("pause");
		//===============================================================================================morning//end//
		day_count++;
	}
	
	//------------------game_result-----------//
	lose:
		Game_ended_t();
		std::cout << "[System.announ] The werewolves win the game!" << std::endl;
		all_sit_check();
		system("pause");
		return 0;
	win:
		Game_ended_t();
		std::cout << "[System.announ] The villagers and the gods win the game!" << std::endl;
		all_sit_check();
		system("pause");
		return 0;
}