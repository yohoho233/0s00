#pragma once

/*
 *Node class 
 * */

#include<iostream>
#include<string>

using namespace std;


class xnode
{
private:
	unsigned int layer;

	Reversi reversi;

	unsigned int steps[64];
	unsigned int map[64];


public:
xchoise choise[28];
	
	
	unsigned int nextwinner;
	unsigned int choisenum;
	unsigned int nextmap[64];

	unsigned int lastplayer;
	unsigned int nextplayer;


	/*
	0 unknow
	1 player1
	2 player2
	3 drawn
	*/
	unsigned int winner;
	//unsigned int nextwinner;

	xnode();
	void set(unsigned int  * map,unsigned int nextplayer,unsigned int  * steps,unsigned int layer);
	void print();
	unsigned int refresh();
	unsigned int winnerget();

};
