#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<vector>

#include"Reversi.h"
#include"Node.h"

using namespace std;

#define MAX_CHOISE 28
xnode::xnode()
{
	for(int i=0;i<MAX_CHOISE;i++)
	{
		choise[i].x=0;
		choise[i].y=0;
	}

	choisenum=0;

	lastplayer=0;
	nextplayer=0;

	for(int i=0;i<64;i++)
	{
		map[i]=0;
	}
}

void xnode::print()
{
	cout<<"=======node"<<setfill('0')<<setw(2)<<layer<<"======="<<endl;

	cout<<"choise_num:" <<choisenum <<endl;
	cout<<"last_player:"<<lastplayer<<endl;
	cout<<"next_player:"<<nextplayer<<endl;
	cout<<"winner:"		<<winner 	<<endl;

	for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				cout<<map[i*8+j]<<" ";
			}
			cout<<endl;
		} 
	cout<<"===================="<<endl;
}
unsigned int xnode::refresh()
{
	for(int i=0;i<choisenum;i++)
	{
		//loss
		if(nextwinner==3-nextplayer)
		{
			winner=nextwinner;
		}
		//drawn
		if(nextwinner==3)
		{
			winner==0;
		}
		if(nextwinner==nextplayer)
		{
			winner=nextplayer;
		}
	}
}

unsigned int xnode::winnerget()
{
/*
debug
*/
	debug_i++;


/*
Set class Reversi & class choise
*/
	reversi.set(map,lastplayer);
	reversi.AvaList(&choisenum,choise,&winner,&nextplayer);
	cout<<"num"<<choisenum<<endl;
	if(choisenum==0)
	{
		return winner;
	}

/*
Initialize the next nodes
*/
	xnode *nextnode=new xnode[choisenum];
	for(int i=0;i<choisenum;i++)
	{
		cout<<"for"<<endl;
		reversi.set(map,lastplayer);
		reversi.AvaList(&choisenum,choise,&winner,&nextplayer);
		reversi.RevPlay(choise[i].x,choise[i].y);
		reversi.mapget(nextmap);
		steps[layer]=choise[i].x*10+choise[i].y;
		nextnode[i].set(nextmap,nextplayer,steps,layer+1);
	}
	if(debug_i>4)
return 0;
print();
cout<<"st1"<<endl;
/*
return present node winner
*/
	int score=-1;
	for(int i=0;i<choisenum;i++)
	{
		nextwinner=nextnode[i].winnerget();

		if(nextwinner==nextplayer)//win
		{
			winner=nextplayer;
			break;
		}
		else if(nextwinner==1&&score<1)//drawn
		{
			winner=nextwinner;
			score=1;
		}
		else if(nextwinner==3-nextplayer)//loss
		{
			if(score==-1)
				{
					score=0;
					winner=nextwinner;
				}
		}
		else
		{
			delete nextnode;
			return 0;
		}

		delete nextnode;
		return winner;
	}
}

void xnode::set(unsigned int *inmap,unsigned int inlastplayer,unsigned int *insteps,unsigned int inlayer)
{
	for(int i=0;i<64;i++)
		{
			map[i]=inmap[i];
		}

	lastplayer=inlastplayer;

	for(int i=0;i<64;i++)
	{
		steps[i]=insteps[i];
	}

	layer=inlayer;
}
xchoise::xchoise()
{
	x=0;
	y=0;
}
