#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<cstring>
using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int flag=1;
class Game
{
	private:
	 
	char ch,name[20];
	char sign;
	int x,row,col,i;
	static int turn;
	
	public:
		
static void display()
{
	cout<<"\t--------------------------------------------------\t"<<endl;
	cout<<"\t|\t"<<board[0][0]<<"\t|\t"<<board[0][1]<<"\t|\t"<<board[0][2]<<"\t|\t"<<endl;
	
	cout<<"\t--------------------------------------------------\t"<<endl;
	cout<<"\t|\t"<<board[1][0]<<"\t|\t"<<board[1][1]<<"\t|\t"<<board[1][2]<<"\t|\t"<<endl;
	
	cout<<"\t--------------------------------------------------\t"<<endl;
	cout<<"\t|\t"<<board[2][0]<<"\t|\t"<<board[2][1]<<"\t|\t"<<board[2][2]<<"\t|\t"<<endl;
	
	cout<<"\t--------------------------------------------------\t"<<endl;
	}
	
	Game(char *che)
	{
		i=0;
	while(*che!='\0')
	{
	name[i]=*che;
	che++;
	i++;	
		}	
	}
	Game()
	{
	strcpy(name,"computer");
	}
	void playerName()
	{
		fflush(stdin);
		cout<<name<<":";
	}
	void chooseSign()
	{
	fflush(stdin);
	cout<<"Now choose your sign x or 0:";
	cin>>sign;
		
	}
	int checkSign()
	{
		if(sign=='x')
		{
			return 1;
			
		}
		else
		{
			if(sign=='0')
			{
				return 0;
			}
			else
			{
				return -1;
			}
		}
	}
	
	static int  determineTurn()
	{
		turn++;
	if(turn%2==0)
	{
		
		return 1;
		
		}
		else
		{
			
			return 0;
			
			}
			
	}
	
int getInput()
{
	if(flag==0)
	{
	
	cout<<name<<":Enter the place where you want to insert the sign";
	cin>>i;
	return i;
}
if(flag==1)
{
	srand(time(NULL));
	i=rand()%10;
	return i;
}
	}
	
	
	int place(int x)
	{
		
		switch(x)
		{
			case 1:
				if(board[0][0]=='1')
				{
				
				board[0][0]=sign;
				row=0;
				col=0;
				return 0;
			}
			else
			{
				
				
				return -1;
			}
				break;
				case 2:
					if(board[0][1]=='2')
					{
					row=0;
				col=1;
					board[0][1]=sign;
					return 0;
				}
				else
			{
			
				
				return -1;
				
			}
					break;
			case 3:
				if(board[0][2]=='3')
				{
				row=0;
				col=2;
					board[0][2]=sign;
					return 0;
				}
				else
			{
			
				
				return -1;
			}
					break;	
			case 4:
				if(board[1][0]=='4')
				{
				row=1;
				col=0;
					board[1][0]=sign;
					return 0;
				}
				else
			{
				
				
				return -1;
			}
					break;
			case 5:
				if(board[1][1]=='5')
				{
				row=1;
				col=1;
					board[1][1]=sign;
					return 0;
				}
					else
			{
				
				
				return -1;
			}
			break;
				
			case 6:
				if(board[1][2]=='6')
				{
				row=1;
				col=2;
					board[1][2]=sign;
					return 0;
				}
					else
			{
			
				
				return -1;
			}
					break;
			case 7:
				if(board[2][0]=='7')
				{
				row=2;
				col=0;
					board[2][0]=sign;
					return 0;
				}
					else
			{
				
				
				return -1;
			
			}
					break;
					case 8:
						if(board[2][1]=='8')
						{
							row=2;
				col=1;
						
					board[2][1]=sign;
					return 0;
				}
					else
			{
		
				
				return -1;
				
			}
					break;
					case 9:
						if(board[2][2]=='9')
						{
						row=2;
				col=2;
					board[2][2]=sign;
					return 0;
				}
					else
			{
				
				
				return -1;
				
			}
					break;
					default:
						if(flag==0)
		            cout<<"Enter correct choice from 1-9";	
					return -1;
														
		}
	}
void computerSign(int x)
{
	if(x==1)
	{
		sign='0';
	}
	if(x==0)
	{
		sign='x';
	}
	cout<<"Computers sign:"<<sign;
	}	
	
int checkRow()
{
if((board[row][0]==board[row][1])&&(board[row][1]==board[row][2]))
{
	return 1;
	
	}
	else
	{
		return -1;
		}	
	}
	
int checkCol()
{
	if((board[0][col]==board[1][col])&&(board[1][col]==board[2][col]))
	{
	return 1;
	}
	else
	{
		return -1;
		}	
	}
int leftdiagonal()
{
	if(row==col)
	{
		
		if((board[0][0]==board[1][1])&&(board[1][1]==board[2][2]))
		{
			return 1;
	
	}
	else
	{
		return -1;
	}
		}
		else
		{
			return -1;
		}
		
	}
int rightdiagonal()
{
	
		
		if((board[0][2]==board[1][1])&&(board[1][1]==board[2][0]))
		{
			return 1;
	
	}
	else
	{
		return -1;
	}
		
		
		}		
int empty()
{
	if(board[0][0]!='1'&&board[0][1]!='2'&&board[0][2]!='3'&&board[1][0]!='4'&&board[1][1]!='5'&&board[1][2]!='6'&&board[2][0]!='7'&&board[2][1]!='8'&&board[2][2]!='9')
	{
		return 1;
	}
	else
	{
		return -1;
	}
		}		
void winner()
{
	fflush(stdin);
	cout<<"Player:"<<name<<"won congratulations"<<endl;
		}
				
		
};
int Game::turn;
int main()
{
	char pn[30],x,y,u;
	cout<<"\t\t\tWELCOME TO TIC-TAC-TOE"<<endl;
    int a=-1,b=-1,c=-1,d=-1,e=-1,f,h,choice;
    cout<<"Press 1 to play with computer"<<endl;
    cout<<"Press 2 to start 2 player tic tac toe"<<endl;
    cin>>choice;
    switch(choice)
    {
    	case 1:
    		{
    			cout<<"Enter player name"<<endl;
    			fflush(stdin);
    			cin.getline(pn,20);
    			Game g(pn);
    			g.playerName();
    			g.chooseSign();
    			x=g.checkSign();
    			while(x==-1)
    			{
    				cout<<"You can choose only one sign choose again"<<endl;
    				g.playerName();
    				g.chooseSign();
    				x=g.checkSign();
				}
    			Game m;
    				cout<<"Player-2:";
    			m.playerName();
    		cout<<endl;
    			m.computerSign(x);
    			cout<<endl;
    			Game::display();
    			while(a==-1&&b==-1&&c==-1&&d==-1&&e==-1)
    			{
    			u=Game::determineTurn();
				if(u==1)
				{
					flag=0;
					
					x=g.getInput();
					y=g.place(x);
					while(y==-1)
					{
					x=g.getInput();
					y=g.place(x);	
					}
					Game::display();
					a=g.checkRow();
					b=g.checkCol();
					c=g.leftdiagonal();
					d=g.rightdiagonal();
					e=g.empty();
					if(a==1||b==1||c==1||d==1)
					{
						g.winner();
					}
					}
					else
					{
						flag=1;
						cout<<"Computers turn"<<endl;
						x=m.getInput();
						y=m.place(x);
						while(y==-1)
						{
						x=m.getInput();
						y=m.place(x);
						}
						Game::display();
						a=m.checkRow();
						b=m.checkCol();
						c=m.leftdiagonal();
						d=m.rightdiagonal();
						e=m.empty();
						if(a==1||b==1||c==1||d==1)
						{
							m.winner();
						}
						}
						if(e==1)
						{
							cout<<"No player won";
							}	
				}
    			break;
			}
	case 2:
		{
		flag=0;
	Game::display();
    cout<<"Enter player-1 name"<<endl;
    fflush(stdin);
    cin.getline(pn,20);
    Game g(pn);
    g.playerName();
    g.chooseSign();
    x=g.checkSign();
    cout<<"Enter player-2 name"<<endl;
    fflush(stdin);
    cin.getline(pn,20);
    Game p(pn);
    p.playerName();
    p.chooseSign();
    y=p.checkSign();
    while(x==-1||y==-1)
    {
    	cout<<"You can choose sign as x or 0 only Choose again!!"<<endl;
    	if(x==-1)
    	{
    		g.playerName();
    		g.chooseSign();
    		x=g.checkSign();
		}
		if(y==-1)
		{
			p.playerName();
			p.chooseSign();
			y=p.checkSign();
		}
	}
	while(x==y)
	{
		cout<<"Both players entered same sign enter different sign"<<endl;
		g.playerName();
		g.chooseSign();
		x=g.checkSign();
		p.playerName();
		p.chooseSign();
		y=p.checkSign();
	}
    
    while(a==-1&&b==-1&&c==-1&&d==-1&&e==-1)
    {
    	
    	u=Game::determineTurn();
    	if(u==1)
    	{
    	y=g.getInput();	
    	x=g.place(y);
    	while(x==-1)
    	{
    		cout<<"Enter again"<<endl;
    		y=g.getInput();
    		x=g.place(y);
		}
		Game::display();
		a=g.checkRow();
		b=g.checkCol();
		c=g.leftdiagonal();
		d=g.rightdiagonal();
		e=g.empty();
		if(a==1||b==1||c==1||d==1)
		{
			g.winner();
		}
		}
		else
		{
		y=	p.getInput();
		x=p.place(y);
		while(x==-1)
    	{
    		cout<<"Enter again!!you cannot insert value at this place"<<endl;
    		y=p.getInput();
    		x=p.place(y);
		}
		Game::display();
		a=p.checkRow();
		b=p.checkCol();
		c=p.leftdiagonal();
		d=p.rightdiagonal();
		e=p.empty();
		if(a==1||b==1||c==1||d==1)
		{
			p.winner();
		}
		}
		if(e==1&&a==-1&&b==-1&&c==-1&&d==-1)
		{
			cout<<"No player won"<<endl;
		}
		
    	
    }
    break;
}
}
    
	return 0;
}
