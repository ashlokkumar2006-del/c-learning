#include <iostream>
#include <string.h>
using namespace std;

int main() 
{

        char board[3][3]={
            {' ',' ',' '},
            {' ',' ',' '},
            {' ',' ',' '}
        };
    
        const char playerX='x';
        const char playerO='O';
        char currentPlayer=playerX;
        int r=-1;
        int c=-1;
        char winner = ' ';

    for(int i=0; i<9 ; i++)
    {
        
            // game board
            // printf("\n Game Board\n");

         cout << "   |   |   " << endl;
         cout << " " << board[0][0] << " | " << board[0][1]<< " | " << board[0][2] <<endl;
         cout << "___|___|___" << endl;
         cout << "   |   |    " << endl; 
         cout << " " << board[1][0] << " | " << board[1][1]<< " | " << board[1][2] <<endl;
         cout << "___|___|___" << endl;
         cout << "   |   |  " << endl;
         cout << " " << board[2][0] << " | " << board[2][1]<< " | " << board[2][2] <<endl;
         cout << "   |   |  " << endl;

             // for continue the game
            if( winner != ' ')
            {
                break;
            }
             // gettplayer input
                
            cout<< "Current player is "<< currentPlayer << endl;
            while(true)
            {
                cout<<"enter r c from 0-2 for row and column: ";
                cin >> r >> c;  // A B
                if(r<0 || r>2 || c<0 || c>2)
                {
                    cout<< "Invalid input, Please try again" << endl;
                }
                else if(board[r][c] !=' ') 
                {   
                    cout << "Tile is full, please try again " << endl;
                }
                else
                {
                    break;
                }
                // reset values
                r=-1;
                c=-1;
                cin.clear(); // clear errors flags
                cin.ignore( 100000, '\n' ); // discard values
                // (skips to the next new line \n upto 10000 char ) already in input system 
                
            }

            board[r][c] = currentPlayer ;
            currentPlayer = (currentPlayer==playerX) ? playerO : playerX ;
       
        // chacking winner

        // Row - horizontal
        for(int r=0 ; r<3 ;r++){
            if(board[r][0] !=' ' && board[r][0] == board[r][1] && board[r][1] == board[r][2] )
            {
                winner = board[r][0];
                break;
            }
        }

        // column - horizontal
        for(int c=0 ; c<3; c++){
            if(board[0][c] !=' ' && board[0][c] == board[1][c] && board[1][c] == board[2][c] )
            {
               winner = board[0][c];
                break; 
            }
        } 

        // Diagonally 
        if( board[0][0] !=' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2] ) 
        {
            winner = board[0][2] ;
            break;
        }else if( board[0][2] !=' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0] )
        {
            winner = board[0][2] ;
            break;
        }
       
    }
    cout << " \n" << endl;
    if( winner != ' ' ) 
    {
        cout<< "Player" << winner << " is the winner!" << endl ;
    }else
    {
        cout << " Tie !" << endl;
    }
        
        cout << " \n Final board \n"<< endl;
         cout << "   |   |   " << endl;
         cout << " " << board[0][0] << " | " << board[0][1]<< " | " << board[0][2] <<endl;
         cout << "___|___|___" << endl;
         cout << "   |   |    " << endl; 
         cout << " " << board[1][0] << " | " << board[1][1]<< " | " << board[1][2] <<endl;
         cout << "___|___|___" << endl;
         cout << "   |   |  " << endl;
         cout << " " << board[2][0] << " | " << board[2][1]<< " | " << board[2][2] <<endl;
         cout << "   |   |  " << endl;

    cout << " \n" << endl;
    return 0;
}
