#include"Reversi.h"
#include"Node.h"

using namespace std;

int debug_i;

int main()
{
	debug_i=0;

	xnode rnet;
	unsigned int map[64];

	for(int i=0;i<64;i++)
		map[i]=0;

	map[3*8+3]=1;
	map[4*8+4]=1;
	map[3*8+4]=2;
	map[4*8+3]=2;

	unsigned int nextplayer=1;

	unsigned int steps[64];

	for(int i=0;i<64;i++)
		steps[i]=99;

	unsigned int layer;
	layer=4;

	rnet.set(map,nextplayer,steps,layer);
	rnet.print();


rnet.choise[0].x=3;
rnet.choise[0].y=2;
rnet.choisenum=1;


	rnet.winnerget();
	
	return 0;
}
