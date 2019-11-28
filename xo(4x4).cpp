#include<iostream>
#include<limits>
using namespace std;

int index1,tablechoice,size;
char* board= new char[size];

int isFull()
{
    for(int i =0; i<size; i++)
    {
        if(board[i]==' ')
        {
            return 0;
        }
    }
    return 1;
}

int user_won()
{
    if(tablechoice==1)
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
    if(tablechoice==2)
    {
        for(int i=0; i<16; i+=4)
        {
            if((board[i]==board[i+1])&&(board[i+1]==board[i+2])&&(board[i]=='X'))
                return 1;
        } //checking horizontally
        for(int i=0; i<4; i++)
        {
            if((board[i]==board[i+4])&&(board[i+4]==board[i+8])&&(board[i]=='X'))
                return 1;
        } // checking vertically
        if((board[0]==board[5])&&(board[5]==board[10])&&(board[10]==board[15])&&(board[0]=='X'))
        {
            return 1;
        } //checking diagonal
        if((board[3]==board[6])&&(board[6]==board[9])&&(board[9]==board[12])&&(board[3]=='X'))
        {
            return 1;
        } //checking diagonal
    }
}

int cpu_won()
{
    if(tablechoice==1)
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
    if(tablechoice==2)
    {
        for(int i=0; i<16; i+=4)
        {
            if((board[i]==board[i+1])&&(board[i+1]==board[i+2])&&(board[i]=='O'))
                return 1;
        } //checking horizontally
        for(int i=0; i<4; i++)
        {
            if((board[i]==board[i+4])&&(board[i+4]==board[i+8])&&(board[i]=='O'))
                return 1;
        } // checking vertically
        if((board[0]==board[5])&&(board[5]==board[10])&&(board[10]==board[15])&&(board[0]=='O'))
        {
            return 1;
        } //checking diagonal
        if((board[3]==board[6])&&(board[6]==board[9])&&(board[9]==board[12])&&(board[3]=='O'))
        {
            return 1;
        } //checking diagonal
        return 0;
    }
}

void displayBoard()
{
    if(tablechoice==1)
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
    if(tablechoice==2)
    {
        cout<<"\n-----------------------------TIC TAC TOE------------------------------";
        cout<<"                 ### Created by Fuad Shahmuradov ###";
        cout<<"\n[1 ][2 ][3 ][4 ]\n"
              <<"[5 ][6 ][7 ][8 ]\n"
              <<"[9 ][10][11][12]\n"
              <<"[13][14][15][16]\n";
        cout<<"\t\t-----------------\n"
            <<"\t\t| "<<board[0]<<" | "<<board[1]<<" | "<<board[2]<<" | "<<board[3]<<" | \n"
            <<"\t\t-----------------\n"
            <<"\t\t| "<<board[4]<<" | "<<board[5]<<" | "<<board[6]<<" | "<<board[7]<<" | \n"
            <<"\t\t-----------------\n"
            <<"\t\t| "<<board[8]<<" | "<<board[9]<<" | "<<board[10]<<" | "<<board[11]<<" | \n"
            <<"\t\t-----------------\n"
            <<"\t\t| "<<board[12]<<" | "<<board[13]<<" | "<<board[14]<<" | "<<board[15]<<" | \n"
            <<"\t\t-----------------\n";
    }
    else return;
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
    int score[size];
    for(int i=0;i<size;i++)
    {
        score[i]=1; //if score[i]=1 then it is empty
    }
    for(i=0; i<size; i++)
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
        for(j=0; j<size; j++)
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
        for(j=0; j<size; j++)
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

void playGame()
{
        for(int i=0;i<size;i++)
        {
            board[i]=' ';
        }
        int player,choice;
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
                cout<<endl<<"CPU won!\n\n";
                break;
            }
            if(isFull()==1)
            {
                cout<<endl<<"Tie!\n\n";
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
                cout<<endl<<"You won!\n\n";
                break;
            }
            if(isFull() == 1)
            {
                cout<<endl<<"Tie!\n\n";
                break;
            }
        }
}
int main()
{
    cout<<"-----------------------------TIC TAC TOE------------------------------";
    cout<<"                 ### Created by Fuad Shahmuradov ###";
    select:cout<<endl<<"\nSelect game mode:\n1-> 3X3 \n2-> 4X4\t\t\t";
    cin>>tablechoice;
    if(tablechoice==1)
    {
        size=9;
        playGame();
        return 0;
    }
    if(tablechoice==2)
    {
        size=16;
        playGame();
        return 0;
    }
    else
    {
        cout<<"\nInvalid choice!";
        goto select;
    }

}
