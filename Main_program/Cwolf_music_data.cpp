#include <iostream>
#include <windows.h>
#include <mmsystem.h>

void Start_program() {
	PlaySound(TEXT("D:\\Program_e.project\\Sound_track\\Start_program.wav"), NULL, SND_FILENAME || SND_ASYNC);
}

void Enter_program() {
	PlaySound(TEXT("D:\\Program_e.project\\Sound_track\\Enter_program.wav"), NULL, SND_FILENAME || SND_ASYNC);
}

void Start_dealing() {
	PlaySound(TEXT("D:\\Program_e.project\\Sound_track\\Start_dealing.wav"), NULL, SND_FILENAME || SND_ASYNC);
}

void Dealing_finished() {
	PlaySound(TEXT("D:\\Program_e.project\\Sound_track\\Dealing_finished.wav"), NULL, SND_FILENAME || SND_ASYNC);
}

void System_announ() {
	PlaySound(TEXT("D:\\Program_e.project\\Sound_track\\System_announ.wav"), NULL, SND_FILENAME || SND_ASYNC);
}

void System_abnormal() {
	PlaySound(TEXT("D:\\Program_e.project\\Sound_track\\System_abnormal.wav"), NULL, SND_FILENAME || SND_ASYNC);
}

void System_murmur() {
	PlaySound(TEXT("D:\\Program_e.project\\Sound_track\\System_murmur.wav"), NULL, SND_FILENAME || SND_ASYNC);
}

void Game_ended() {
	PlaySound(TEXT("D:\\Program_e.project\\Sound_track\\Game_ended.wav"), NULL, SND_FILENAME || SND_ASYNC);
}
