#include<iostream>
#include<limits>
using namespace std;

int index1;
char board[9]= {' ',' ',' ',
                ' ',' ',' ',
                ' ',' ',' '
               };

int isFull()
{
    for(int i =0; i<9; i++)
    {
        if(board[i]!='X' && board[i]!='O')
        {
            return 0;
        }
    }
    return 1;
}

int user_won()
{
    for(int i=0; i<9; i+=3)
    {
        if((board[i]==board[i+1])&&(board[i+1]==board[i+2])&&(board[i]=='X'))
            return 1;
    } //checking horizontally
    for(int i=0; i<3; i++)
    {
        if((board[i]==board[i+3])&&(board[i+3]==board[i+6])&&(board[i]=='X'))
            return 1;
    } // checking vertically
    if((board[0]==board[4])&&(board[4]==board[8])&&(board[0]=='X'))
    {
        return 1;
    } //checking diagonal
    if((board[2]==board[4])&&(board[4]==board[6])&&(board[2]=='X'))
    {
        return 1;
    } //checking diagonal
    return 0;
}

int cpu_won()
{
    for(int i=0; i<9; i+=3)
    {
        if((board[i]==board[i+1])&&(board[i+1]==board[i+2])&&(board[i]=='O'))
            return 1;
    } //checking horizontally
    for(int i=0; i<3; i++)
    {
        if((board[i]==board[i+3])&&(board[i+3]==board[i+6])&&(board[i]=='O'))
            return 1;
    } // checking vertically
    if((board[0]==board[4])&&(board[4]==board[8])&&(board[0]=='O'))
    {
        return 1;
    } //checking diagonal
    if((board[2]==board[4])&&(board[4]==board[6])&&(board[2]=='O'))
    {
        return 1;
    } //checking diagonal
    return 0;
}

void displayBoard()
{
    cout<<"\n-----------------------------TIC TAC TOE------------------------------";
    cout<<"                 ### Created by Fuad Shahmuradov ###";
    cout<<"\n\n\n\n[1][2][3]\n"
        <<"[4][5][6]\n"
        <<"[7][8][9]\n";
    cout<<"\t\t-------------\n"
        <<"\t\t| "<<board[0]<<" | "<<board[1]<<" | "<<board[2]<<" |\n"
        <<"\t\t-------------\n"
        <<"\t\t| "<<board[3]<<" | "<<board[4]<<" | "<<board[5]<<" |\n"
        <<"\t\t-------------\n"
        <<"\t\t| "<<board[6]<<" | "<<board[7]<<" | "<<board[8]<<" |\n"
        <<"\t\t-------------\n";
}

int minimax(bool flag)
{
    int max_val=-1000, min_val=1000;
    int i,j,value=1;
    if (cpu_won() == 1)
    {
        return 10;
    }
    else if (user_won() == 1)
    {
        return -10;
    }
    else if (isFull() == 1)
    {
        return 0;
    }
    int score[9] = {1,1,1,1,1,1,1,1,1}; //if score[i]=1 then it is empty
    for(i=0; i<9; i++)
    {
        if(board[i] == ' ')
        {
            if(min_val>max_val)
            {
                if(flag == true)
                {
                    board[i] = 'O';
                    value = minimax(false);
                }
                else
                {
                    board[i] = 'X';
                    value = minimax(true);
                }
                board[i] = ' ';
                score[i] = value;
            }
        }
    }
    if(flag == true)
    {
        max_val = -1000;
        for(j=0; j<9; j++)
        {
            if(score[j] > max_val && score[j] != 1)
            {
                max_val = score[j];
                index1 = j;
            }
        }
        return max_val;
    }
    if(flag == false)
    {
        min_val = 1000;
        for(j=0; j<9; j++)
        {
            if(score[j] < min_val && score[j] != 1)
            {
                min_val = score[j];
                index1 = j;
            }
        }
        return min_val;
    }
}

int main()
{
    int player,choice;
    cout<<"-----------------------------TIC TAC TOE------------------------------";
    cout<<"                 ### Created by Fuad Shahmuradov ###";
    cout<<endl<<"\nUSER--->(X)      CPU------>(O)";
    cout<<endl<<"\nSELECT:\n1-> Player first \n2-> CPU first\t\t";
    cin>>choice;
    cout<<"\n\n";
    if(choice==1)
    {
        displayBoard();
        up:cout<<endl<<"Enter your move: ";
        cin>>player;
        if(board[player-1]==' '&& cin)
        {
            board[player-1] = 'X';
            displayBoard();
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<endl<<"Invalid move. Try different one.";
            goto up;
        }
    }
    while(true)
    {
        minimax(true);
        board[index1] = 'O';
        displayBoard();
        if(cpu_won()==1)
        {
            cout<<endl<<"CPU won!\n\n\n\n";
            break;
        }
        if(isFull()==1)
        {
            cout<<endl<<"Tie!\n\n\n\n";
            break;
        }
        again:cout<<endl<<"Enter your move: ";
        cin>>player;
        if(board[player-1]==' ')
         {
           board[player-1] = 'X';
           displayBoard();
         }
         else
         {
             cout<<endl<<"Invalid move. Try different one!\n";
             goto again;
         }
         if(user_won()==1)
         {
             cout<<endl<<"You won!\n\n\n\n";
             break;
         }
         if(isFull() == 1)
        {
            cout<<endl<<"Tie!\n\n\n\n";
            break;
        }
    }

}
