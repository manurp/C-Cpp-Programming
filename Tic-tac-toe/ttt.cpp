#include <iostream>
#include<cstdlib>
#include<conio.h>
using namespace std;

void draw(int* p,int low) {
    if (low>6) {
        return;
    }
    // Gives space before any picture
    if (low==0) {
        cout << "----Tic Tac Toe---\n\n";
        cout << "\n\n\n\n\n\n\n";
    }

    cout << "   ";
    if (p[low] == 0)
        cout << "0  ";
    else if(p[low] == 1)
        cout<<"X  ";
    else
        cout<<"   ";

    cout << "|  ";
    if (p[low+1] == 0)
        cout << "0  ";
    else if(p[low+1] == 1)
        cout<<"X  ";
    else
        cout<<"   ";

    cout << "|  ";
    if (p[low+2] == 0)
        cout << "0  ";
    else if(p[low+2] == 1)
        cout<<"X  ";
    else
        cout<<"   ";
    if(low<6){
    cout << "\n   ---- ---- ----";
    }
    cout << endl;
    // Gives space before any picture
    if (low==6) {
        cout << "\n\n\n\n\n\n\n";
    }

    draw(p, low+3);

}

bool winner(int* p, int n=0) {

            //Row
            if(n%3==0) {
                if(p[n]+p[n+1]+p[n+2]==0) {
                        cout << "----Player 1 Wins----\n";
                        return true;
                    }
                    if(p[n]+p[n+1]+p[n+2]==3) {
                        cout << "----Player 2 Wins----\n";
                        return true;
                    }
            }

            //Column
            if(n==0 || n == 1 || n==2) {
                if(p[n]+p[n+3]+p[n+6]==0) {
                    cout << "----Player 1 Wins----\n";
                    return true;
                }
                if(p[n]+p[n+3]+p[n+6]==3) {
                    cout << "----Player 2 Wins----\n";
                    return true;
                }
            }

            //Principle Diagonal
            if(n==0) {
                if(p[n]+p[n+4]+p[n+8]==0) {
                    cout << "----Player 1 Wins----\n";
                    return true;
                }
                if(p[n]+p[n+4]+p[n+8]==3) {
                    cout << "----Player 2 Wins----\n";
                    return true;
                }
            }

             //Secondary Diagonal
            if(n==2) {
                if(p[n]+p[n+2]+p[n+4]==0) {
                    cout << "----Player 1 Wins----\n";
                    return true;
                }
                if(p[n]+p[n+2]+p[n+4]==3) {
                    cout << "----Player 2 Wins----\n";
                    return true;
                }
            }


        if(n==0) {
            if (winner(p,1)||winner(p, 2)||winner(p, 3)||winner(p, 6))
                return true;
        }
        return false;

}

bool askP1(int* arr) {
    int ind;
    cout << "Player 1 : Where you want to place  'O' ? ";
        cin >> ind ;
        ind--;
        if(arr[ind]==-10) {
        arr[ind] = 0;
        }
        else{
            cout << "Wrong Choice!! The place is already occupied or its out of range\n\n";
            return false;
        }
        system("cls");
        draw(arr,0);
        return true;
}

bool askP2(int* arr) {
    int ind;
    cout << "Player 2 : Where you want to place  'X' ? ";
        cin >> ind ;
        ind--;
        if(arr[ind]==-10) {
        arr[ind] = 1;
        }
        else{
            cout << "Wrong Choice!! The place is already occupied or its out of range\n\n";
            return false;
        }
        system("cls");
        draw(arr,0);
        return true;
}

int main() {


    while(1) {
    int arr[9] = {-10,-10,-10,-10,-10,-10,-10,-10,-10};
    int count = 0;
    bool flag;

    system("cls");
   // cout << "----Tic Tac Toe---\n\n";
    draw(arr,0);
    while(count < 9) {

        for(int i=0;i<3;i++) {
            if(askP1(arr))
                break;
            if(i==2)
                cout<<"Your Chance is over\n\n";
        }

        flag = winner(arr);

         if(flag)
             break;
        count++;
        if(count==9)
            break;
        for(int i=0;i<3;i++) {
            if(askP2(arr))
                break;
            if(i==2)
                cout<<"Your Chance is over\n\n";
        }
        flag = winner(arr);

         if(flag)
             break;
        count++;
    }

    if(count == 9)
        cout<<"-----Match Drawn-----";
    cout << "\nPress q to stop playing and any other character to continue playing\n";
    char c;
    cin >> c;
    if(c=='q' || c=='Q')
        break;

    }
    //getch();
    return 0;
}
