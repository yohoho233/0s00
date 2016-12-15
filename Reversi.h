#pragma once

#include<iostream>
#include<string>

using namespace std;

extern int debug_i;

class xchoise
{
public:
	xchoise();
	unsigned int x;
	unsigned int y;

};
class xplay
{
public:
	xplay();
	unsigned int x;
	unsigned int y;
	unsigned int player;
};
class Reversi {
public:
	Reversi();
	unsigned int play(xchoise);
	void set(unsigned int*, unsigned int);
	int list(unsigned int);
	void mapget(unsigned int*);
	unsigned int check(xchoise choise,unsigned int nextplayer,unsigned int winner);
private:
	unsigned int winner;//0 unknow ;1 player1;2 player 2;3 draw
	unsigned int map[8][8]; //0,1,2 out put
	unsigned int nextplayer;//return or output
	unsigned int oldplayer;
	unsigned char AvaFlag;
	unsigned char WillFinishFlag;
};
