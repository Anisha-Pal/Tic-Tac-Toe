#include <iostream>

using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };

char current_marker;
int current_player;

void drawBoard()
{
    cout<<"\n";
    cout<< " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2]<< endl;
    cout<< "-----------\n";
    cout<< " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2]<< endl;
    cout<< "-----------\n";
    cout<< " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2]<< endl;
    cout<<"\n";

}

bool placeMarker(int slot){

    // int row;
    // if(slot % 3 == 0) slot = (slot/3) - 1;
    // else row = slot/3;

    // int col;
    // if(slot % 3 == 0) col = 2;
    // else col = (slot % 3) - 1;

    int row = slot / 3;
    int col;
    
    if(slot % 3 == 0)
    {
        row = row - 1;
        col = 2;
    }
    else col = (slot % 3) - 1;

    if(board[row][col] != 'X' && board[row][col] != 'O') 
    {
        board[row][col] = current_marker;
        return true;
    }
    else return false;
}

int win()
{
    for(int i = 0; i < 3; i++)
    {
        //rows
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) return current_player;
        
        //col
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) return current_player;

    }

    //diagnol
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return current_player;

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return current_player;

    return 0; //nobody won
}

void change_player_and_marker()
{
    if(current_marker == 'X') current_marker = 'O';
    else current_marker = 'X';

    if(current_player == 1) current_player = 2;
    else current_player = 1;
}

void game()
{
    cout<< "Player 1, Choose your marker('X' or 'O'): ";
    char marker_p1;
    cin>> marker_p1;

    current_player = 1;
    current_marker = marker_p1;

    drawBoard();

    int player_won;

    for(int i = 0; i < 9; i++)
    {
        cout<< "It's player " << current_player << "'s turn. Enter your slot: ";
        int slot;
        cin>> slot;

        if(slot < 1 || slot > 9)
        {
            cout<< "This slot is Invalid! Try another slot"; 
            i--; 
            continue;
        }

        if(!placeMarker(slot)) 
        { 
            cout<< "This slot is Occupied! Try another slot"; 
            i--; 
            continue;
        }
        drawBoard();

        player_won = win();

        if(player_won == 1) 
        { 
            cout<< "----------------------------------\n";
            cout<< "| Player 1 WON! Congratulations! |\n"; 
            cout<< "----------------------------------\n";
            break;
        }
        if(player_won == 2) 
        { 
            cout<< "----------------------------------\n";
            cout<< "| Player 2 WON! Congratulations! |\n";
            cout<< "----------------------------------\n"; 
            break; 
        }

        change_player_and_marker();
        
    }

    if(player_won == 0) 
    {
        cout<< "---------------\n";
        cout<< "| It's a Tie! |\n";
        cout<< "---------------\n";
    }

}


int main(){
    
    cout<< "-------------------\n";
    cout<< "|   Tic-Tac-Toe   |\n";
    cout<< "-------------------\n";
    cout<< "Press 1 -> Start Game.\n";
    cout<< "Press 2 -> Quit.\n\n";

    int op;
    cout<<"Select Option: ";
    cin >>op;
    cout<<endl;

    if(op == 1) game();
    else exit(0);

    return 0;
}