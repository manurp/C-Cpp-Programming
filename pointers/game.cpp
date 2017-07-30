#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int cash = 100;

void play(int bet) {
    char* C = new char[3]; //OR simply use character array
    C[0] = 'J'; C[1] = 'Q'; C[2] = 'K';
    cout<<"Shuffling..................\n";
    srand(time(NULL));
    for(int i =0; i<5;i++) {
       int x = rand()%3;int y = rand()%3;
       int temp = C[x];
       C[x] = C[y];
       C[y] = temp;
    }
    int playersGuess;
    cout<<"What is the position of queen - 1, 2 or 3? ";
    cin>>playersGuess;

    if(C[playersGuess-1] == 'Q') {
        cash += 3*bet;
        cout<<"You win! Res = \" "<<C[0]<<" "<<C[1]<<" "<<C[2]<<" \" Total Cash = $ "<<cash<<endl;
    }
    else {
        cash -= bet;
        cout<<"You Lose! Res = \" "<<C[0]<<" "<<C[1]<<" "<<C[2]<<" \" Total Cash = $ "<<cash<<endl;
    }

    delete []C;
}

int main() {
    int bet;
    cout<<"************WELCOME TO VIRTUAL CASINO******************\n";
    cout<<"Initial cash = $ "<<cash<<endl<<endl;
    while(cash > 0) {
        cout<<"What's your bet? $";
        cin>>bet;
        if(bet == 0 || bet>cash) break;
        play(bet);
        cout<<"\n*********************************************************************************************************\n";
    }
    return 0;
}
