#include <iostream>
using namespace std;

const int columns = 6;
const int rows = 6;

void dots()
{
    cout << endl << " " ;

    for (int i = 0; i < (2 * columns + 1); i++)
    { cout << "-"; }
}

bool inbounds(int row, int column)
{
    if ((row < 0) || (row > 5) || (column < 0) || (column > 5)) { return false; }
    else { return true; }
}

void printarray(char array[rows][columns])
{

    cout << " ";
    for (int i = 0; i < columns; i++)
    {
        cout << " " << i + 1;
    }
    char letter = 'a';
    for (int j = 0; j < rows; j++)
    {
        dots();
        cout << endl << letter++ << "|";

        for (int i = 0; i < columns; i++)
        {
            cout << array[j][i] << "|";
        }
    }

    dots();
    cout << endl;
}

void initial(char array[rows][columns])
{
    for (int j = 0; j < rows; j++)
    {
        for (int i = 0; i < columns; i++)
        {
            array[i][j] = ' ';
        }
    }
    array[2][2] = array[3][3] = 'O';
    array[2][3] = array[3][2] = 'X';
}

int checkanynear(char c, char array[rows][columns])
{
    int z;
    int counter = 0;
    for (int x = 0; x < columns; x++)
    {
        for (int y = 0; y < rows; y++)
        {
			
            if (array[x][y] == ' ')
            {
				
            for (int j = -1; j < 2; j++) //direction of check
            {
                for (int i = -1; i < 2; i++)
                {
					
                    if (i * i + j * j)
                    {
						
                     z=1;
                     while ((array[x+z*(i)][y+z*(j)]!=c) && (array[x+z*(i)][y+z*(j)]!=' ') && inbounds( x+z*(i) , y+z*(j) ) )
                            {
		            	    z++;
                            if (array[x+(z)*(i)][y+(z)*(j)]==c && inbounds( x+z*(i) , y+z*(j) ))
                                 {  
                                    counter++;
                                    break ;
                                 }
                            }
         
                    }
				}
                        
            }
            }
            
        }
    }
    
    return counter;
}

char swapplayer(char c)
{ 
    if      (c == 'O')  {return 'X';}
    else if (c == 'X')  {return 'O';}
}

int main()
{
    char a[rows][columns];
    int rw, co;
    char letter_rw;
    
    int countX = 0;
    int countO = 0;

    bool gameon = true;
    int boxes=4;
    char player = 'O';
    initial(a);

    system("CLS");
    cout << "---- REVERSI ----" << endl << "Game Begins" << endl << endl;
    printarray(a);

    while (gameon)
    {
        if (boxes >= (rows*columns)) 
            { gameon = false; }

        else 
        {
            if ( checkanynear(player,a) )
            {
              cout << endl << "Player " << player ;
              cout << ", enter row and column (eg, e3) :  ";
              cin >> letter_rw >> co; //ask position

              rw = int(letter_rw) - 97; //modify the cordnates from human to machine
              co--;
              
              if (!inbounds(rw,co))
                { //check if it is out of bounds
                  cout << endl <<"The disk must be placed on the board" << endl;
                   
                }

              else if (a[rw][co] != ' ')
                { //if it is already taken
                    cout << endl << "Disk must be placed on an empty spot." << endl; 
                } 

               else
               {
                     int y = 0;
                     for (int j = -1; j < 2; j++)
                        { //direction of check
                            for (int i = -1; i < 2; i++)
                            {
                                if (i * i + j * j)
                                {
                                    int z=1;
                                    while (inbounds( rw+z*(i) , co+z*(j) ) && (a[rw+z*(i)][co+z*(j)]!=player) && (a[rw+z*(i)][co+z*(j)]!=' ') )
                                    {
		            	                z++;
                                        if (inbounds( rw+z*(i) , co+z*(j)) && a[rw+(z)*(i)][co+(z)*(j)]==player )
                                            {
                                                for (int flip = 0; flip < z; flip++)
                                                    {
                                                        a[rw + flip * (i)][co + flip * (j)] = player;
                                                        y++;
                                                    }
                                            }
                                    }
                                
                            
                        
                                }
                            }
                        }

                if (y)
                    {   
                        system("CLS");
                        printarray(a);
                        cout << endl;
                        boxes++;
                        player = swapplayer(player);
                    }

                else
                    {
                        cout << "Disk must be able to flip an opponent' s disk."<< endl ;
                        
                    }
               
            }
        }


            else
            {
                cout << endl << "Player " << player << " does not have a move to play." << endl;
                if (checkanynear(swapplayer(player),a))
                {
                    player=swapplayer(player);
                }
                else
                {
                     cout << endl << "Player " << swapplayer(player) << " does not have a move to play." << endl;
                    gameon=false;
                }
            }

        }
    }

 //end of game count x and o
 for (int j = 0; j < rows; j++)
 {
   for (int i = 0; i < columns; i++)
    {  
      if (a[i][j] == 'O'){countO++;} 
      else if (a[i][j] == 'X'){countX++;}
    }
 }

 //results
 cout << endl << "End Of Game" << endl << endl;
 cout << "----- SCORE -----" << endl;
 cout << "Player X: "<< countX << endl << "Player O: " << countO << endl;

 return 0 ;
}