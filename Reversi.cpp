#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<vector>

#include"Reversi.h"
#include"Node.h"

using namespace std;
/*
 *Kernal start
 * */
Reversi::Reversi()
{
	WillFinishFlag=0;
	nextplayer=1;
	oldplayer=0;
	winner = 0;
	AvaFlag=1;
	
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			map[i][j]=0;

	map[3][3]=1;
	map[3][4]=2;
	map[4][3]=2;
	map[4][4]=1;
}

unsigned int Reversi::list(unsigned int player)
{
	unsigned int oldplayer=player;

	unsigned int choisenum=0;

	unsigned int chess[8][8];
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			chess[i][i]=map[i][j];

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (chess[i][j] == 0)
			{
				//left forward
				if (i > 1&&chess[i-1][j]==oldplayer)
				{
					for (int ii = i-2; ii >=0; ii--)
					{
						if (chess[ii][j] == nextplayer)
						{
							chess[i][j] = 3;

							choise[choisenum].x=i;
							choise[choisenum].y=j;
							choisenum++;

							break;
						}
						if (chess[ii][j] == 0 || chess[ii][j] == 3)
						{
							break;
						}
					}
				}
				//right
				if (i <6 && chess[i + 1][j] == oldplayer)
				{
					for (int ii = i+2; ii <=7; ii++)
					{
						if (chess[ii][j] == nextplayer)
						{
							chess[i][j] = 3;


							choise[choisenum].x=i;
							choise[choisenum].y=j;
							choisenum++;

							break;
						}
						if (chess[ii][j] == 0 || chess[ii][j] == 3)
						{
							break;
						}
					}
				}
				//up
				if (j > 1 && chess[i][j-1] == oldplayer)
				{
					for (int jj = j-2; jj>=0 ; jj--)
					{
						if (chess[i][jj] == nextplayer)
						{
							chess[i][j] = 3;


							choise[choisenum].x=i;
							choise[choisenum].y=j;
							choisenum++;

							break;
						}
						if (chess[i][jj] == 0 || chess[i][jj] == 3)
						{
							break;
						}
					}
				}
				//down
				if (j <6 && chess[i][j + 1] == oldplayer)
				{
					for (int jj = j+2; jj<=7; jj++)
					{
						if (chess[i][jj] == nextplayer)
						{
							chess[i][j] = 3;


							choise[choisenum].x=i;
							choise[choisenum].y=j;
							choisenum++;

							break;
						}
						if (chess[i][jj] == 0 || chess[i][jj] == 3)
						{
							break;
						}
					}
				}

				//left up
				if (j >1 &&i>1&& chess[i-1][j - 1] == oldplayer)
				{
					int jj;
					int ii;
					for ( jj = j - 2,ii=i-2; jj >=0&&ii>=0; jj--,ii--)
					{
						if (chess[ii][jj] == nextplayer)
						{
							chess[i][j] = 3;


							choise[choisenum].x=i;
							choise[choisenum].y=j;
							choisenum++;

							break;
						}
						if (chess[ii][jj] == 0 || chess[ii][jj] == 3)
						{
							break;
						}
					}
				}
				//left down
				if (j <6 && i>1 && chess[i - 1][j + 1] == oldplayer)
				{
					int jj;
					int ii;
					for (jj = j + 2, ii = i - 2; jj <=7 && ii >= 0; jj++, ii--)
					{
						if (chess[ii][jj] == nextplayer)
						{
							chess[i][j] = 3;


							choise[choisenum].x=i;
							choise[choisenum].y=j;
							choisenum++;

							break;
						}
						if (chess[ii][jj] == 0 || chess[ii][jj] == 3)
						{
							break;
						}
					}
				}
				//right down
				if (j <6 && i<6 && chess[i + 1][j + 1] == oldplayer)
				{
					int jj;
					int ii;
					for (jj = j + 2, ii = i + 2; jj <= 7 && ii <=7; jj++, ii++)
					{
						if (chess[ii][jj] == nextplayer)
						{
							chess[i][j] = 3;


							choise[choisenum].x=i;
							choise[choisenum].y=j;
							choisenum++;

							break;
						}
						if (chess[ii][jj] == 0 || chess[ii][jj] == 3)
						{
							break;
						}
					}
				}
				//right up
				if (j >1 && i<6 && chess[i + 1][j - 1] == oldplayer)
				{
					int jj;
					int ii;
					for (jj = j - 2, ii = i + 2; jj >=0 && ii <= 7; jj--, ii++)
					{
						if (chess[ii][jj] == nextplayer)
						{
							chess[i][j] = 3;


							choise[choisenum].x=i;
							choise[choisenum].y=j;
							choisenum++;

							break;
						}
						if (chess[ii][jj] == 0 || chess[ii][jj] == 3)
						{
							break;
						}
					}
				}
			}
		}

	if (AvaFlag == 1)
	{
		AvaFlag = 0;
		WillFinishFlag = 0;

		xnextplayer=nextplayer;

		return choisenum;
	}
	else if(WillFinishFlag==0)
	{
	/*
	 Can do nothing,exchange player
	 */
		if (nextplayer == 1||nextplayer==2)
		{
			WillFinishFlag = 1;
			oldplayer = nextplayer;
			nextplayer = 3 - oldplayer;
			choisenum=AvaList(choise,retwinner,retnextplayer);
			return choisenum;
		}
			
		else
			cout << "Player error" << endl;
		return 0;
	}
	else
	{
	/*
	Game over
	*/
		int play1 = 0;
		int play2 = 0;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
			{
				if (chess[i][j] == 1)
					play1++;
				if (chess[i][j] == 2)
					play2++;
			}
		if (play1 > play2)
			winner = 1;
		else if (play2 > play1)
			winner = 2;
		else if(play2==play1)
			winner=3;
		else
			winner = 0;

		xwinner=winner;

		return 0;
	}
}

int Reversi::play(xchoise choise)
{
	unsigned int chess[8][8];
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			chess[i][j]=map[i][j];

	if (chess[i][j] != 3)
	{
		cout << "Chess error" << endl;
		return 0;
	}
		
	//left forward
	if (i > 1 && chess[i - 1][j] == oldplayer)
	{
		for (int ii = i - 2; ii >= 0; ii--)
		{
			if (chess[ii][j] == nextplayer)
			{
				for (ii++; ii <= i; ii++)
					chess[ii][j] = nextplayer;
				break;
			}
		}
	}
	//right
	if (i <6 && chess[i + 1][j] == oldplayer)
	{
		for (int ii = i + 2; ii <= 7; ii++)
		{
			if (chess[ii][j] == nextplayer)
			{
				for (ii--; ii >= i; ii--)
					chess[ii][j] = nextplayer;
				break;
			}
		}
	}
	//up
	if (j > 1 && chess[i][j - 1] == oldplayer)
	{
		for (int jj = j - 2; jj >= 0; jj--)
		{
			if (chess[i][jj] == nextplayer)
			{
				for (jj++; jj <= j; jj++)
					chess[i][jj] = nextplayer;
				break;
			}
		}
	}
	//down
	if (j <6 && chess[i][j + 1] == oldplayer)
	{
		for (int jj = j + 2; jj <= 7; jj++)
		{
			if (chess[i][jj] == nextplayer)
			{
				for (jj--; jj >= j; jj--)
					chess[i][jj] = nextplayer;
				break;
			}
		}
	}
	//left up
	if (j >1 && i>1 && chess[i - 1][j - 1] == oldplayer)
	{
		int jj;
		int ii;
		for (jj = j - 2, ii = i - 2; jj >= 0 && ii >= 0; jj--, ii--)
		{
			if (chess[ii][jj] == nextplayer)
			{
				for (ii++, jj++; ii <= i&&jj <= j; ii++, jj++)
					chess[ii][jj] = nextplayer;
				break;
			}
		}
	}
	//left down
	if (j <6 && i>1 && chess[i - 1][j + 1] == oldplayer)
	{
		int jj;
		int ii;
		for (jj = j + 2, ii = i - 2; jj <= 7 && ii >= 0; jj++, ii--)
		{
			if (chess[ii][jj] == nextplayer)
			{
				for (jj--, ii++; jj >= j, ii <= i; jj--, ii++)
					chess[ii][jj] = nextplayer;
				break;
			}
		}
	}
	//right down
	if (j <6 && i<6 && chess[i + 1][j + 1] == oldplayer)
	{
		int jj;
		int ii;
		for (jj = j + 2, ii = i + 2; jj <= 7 && ii <= 7; jj++, ii++)
		{
			if (chess[ii][jj] == nextplayer)
			{
				for (jj--, ii--; jj >= j, ii >= i; jj--, ii--)
					chess[ii][jj] = nextplayer;
				break;
			}
		}
	}
	//right up
	if (j >1 && i<6 && chess[i + 1][j - 1] == oldplayer)
	{
		int jj;
		int ii;
		for (jj = j - 2, ii = i + 2; jj >= 0 && ii <= 7; jj--, ii++)
		{
			if (chess[ii][jj] == nextplayer)
			{
				for (jj++, ii--; jj<=j, ii>=i; jj++, ii--)
					chess[ii][jj] = nextplayer;
				break;
			}
		}
	}

	oldplayer = nextplayer;
	nextplayer = 3 - oldplayer;

	refresh();
	
	players_save[steps+1] = oldplayer;
	cout << "play player  " << oldplayer << endl;

	return 1;
}
/*
 * Kernal end
 * */
void Reversi::set(unsigned int *inmap,unsigned int player)
{

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			map[i][j]=inmap[i*8+j];
		}

	nextplayer=player;
}

unsigned int Reversi::check(xchoise choise,unsigned int nextplayer,unsigned int winner)
{
	unsigned int choisenum=retnum;
	unsigned int xwinner=retwinner;
	unsigned int xnextplayer=retnextplayer;

	unsigned int choisenum=0;

	xwinner=0;

	unsigned int chess[8][8];
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			chess[i][i]=map[i][j];

	ava_ways_save_x[steps][0] = 0;
	ava_ways_save_y[steps][0] = 0;

	ava_ways[steps] = 0;

	unsigned int i=choise.x;
	unsigned int j=choise.y;

	if(chess[i][j]!=0)
		return 0;
	else
	{
				//left forward
				if (i > 1&&chess[i-1][j]==oldplayer)
				{
					for (int ii = i-2; ii >=0; ii--)
					{
						if (chess[ii][j] == nextplayer)
						{
							return 1;
						}
						if (chess[ii][j] == 0 || chess[ii][j] == 3)
						{
							break;
						}
					}
				}
				//right
				if (i <6 && chess[i + 1][j] == oldplayer)
				{
					for (int ii = i+2; ii <=7; ii++)
					{
						if (chess[ii][j] == nextplayer)
						{
							return 1;
						}
						if (chess[ii][j] == 0 || chess[ii][j] == 3)
						{
							break;
						}
					}
				}
				//up
				if (j > 1 && chess[i][j-1] == oldplayer)
				{
					for (int jj = j-2; jj>=0 ; jj--)
					{
						if (chess[i][jj] == nextplayer)
						{
							return 1;
						}
						if (chess[i][jj] == 0 || chess[i][jj] == 3)
						{
							break;
						}
					}
				}
				//down
				if (j <6 && chess[i][j + 1] == oldplayer)
				{
					for (int jj = j+2; jj<=7; jj++)
					{
						if (chess[i][jj] == nextplayer)
						{
							return 1;
						}
						if (chess[i][jj] == 0 || chess[i][jj] == 3)
						{
							break;
						}
					}
				}
				//left up
				if (j >1 &&i>1&& chess[i-1][j - 1] == oldplayer)
				{
					int jj;
					int ii;
					for ( jj = j - 2,ii=i-2; jj >=0&&ii>=0; jj--,ii--)
					{
						if (chess[ii][jj] == nextplayer)
						{
							return 1;
						}
						if (chess[ii][jj] == 0 || chess[ii][jj] == 3)
						{
							break;
						}
					}
				}
				//left down
				if (j <6 && i>1 && chess[i - 1][j + 1] == oldplayer)
				{
					int jj;
					int ii;
					for (jj = j + 2, ii = i - 2; jj <=7 && ii >= 0; jj++, ii--)
					{
						if (chess[ii][jj] == nextplayer)
						{
							return 1;
						}
						if (chess[ii][jj] == 0 || chess[ii][jj] == 3)
						{
							break;
						}
					}
				}
				//right down
				if (j <6 && i<6 && chess[i + 1][j + 1] == oldplayer)
				{
					int jj;
					int ii;
					for (jj = j + 2, ii = i + 2; jj <= 7 && ii <=7; jj++, ii++)
					{
						if (chess[ii][jj] == nextplayer)
						{
							return 1;
						}
						if (chess[ii][jj] == 0 || chess[ii][jj] == 3)
						{
							break;
						}
					}
				}
				//right up
				if (j >1 && i<6 && chess[i + 1][j - 1] == oldplayer)
				{
					int jj;
					int ii;
					for (jj = j - 2, ii = i + 2; jj >=0 && ii <= 7; jj--, ii++)
					{
						if (chess[ii][jj] == nextplayer)
						{
							return 1;
						}
						if (chess[ii][jj] == 0 || chess[ii][jj] == 3)
						{
							break;
						}
					}
				}
				return 0;
			}
		
}
