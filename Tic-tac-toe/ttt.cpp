#include <iostream>
using namespace std;

void draw(int* p,int low) {
    if (low>6) {
        return;
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
    draw(p, low+3);

}

bool winner(int* p, int n=0) {

            bool flag = false;
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
                if(p[n]+p[n+4]+p[n+8]==3) {
                    cout << "----Player 2 Wins----\n";
                    return true;
                }
            }

            if(n==0) {
                flag = winner(p, 1);
                if(flag)
                    return true;
                flag = winner(p, 2);
                if(flag)
                    return true;
                flag = winner(p, 3);
                if(flag)
                    return true;
                flag = winner(p, 6);
                if(flag)
                    return true;
            }
            return flag;
}

int main() {
    int arr[9] = {-10,-10,-10,-10,-10,-10,-10,-10,-10};
    int count = 0, ind;
    bool flag;

    cout << "----Tic Tac Toe---\n\n";
    while(count < 9) {
        draw(arr,0);
        cout << "Player 1 : Where you want to place  'O' ? ";
        cin >> ind ;
        arr[ind] = 0;
        draw(arr,0);

        flag = winner(arr);

         if(flag)
             break;
        cout << "Player 2 : Where you want to place  'X' ? ";
        cin >> ind ;
        arr[ind] = 1;

        flag = winner(arr);

         if(flag)
             break;
        count++;
    }

    if(count == 9)
        cout<<"-----Match Drawn-----";

    return 0;
}
