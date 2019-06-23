#include <iostream>
#include <iomanip>



using namespace std;
int main() {

    int n,k;
    while(cin >> n && n!=0){

        cin >> k;
        int win[n]={0},total[n]={0};
        int pl1,pl2;
        string move1,move2;
        for(int i=0;i<(k*n*(n-1))/2;i++){
        cin >> pl1 >> move1 >> pl2 >> move2;
        if(move1!=move2){
            if(move1=="scissors" && move2=="paper"){

                ++win[pl1-1];
                ++total[pl1-1];
                ++total[pl2-1];

            }
            if(move1=="rock" && move2=="scissors"){

                ++win[pl1-1];
                ++total[pl1-1];
                ++total[pl2-1];
            }
            if(move1=="paper" && move2=="rock"){

                ++win[pl1-1];
                ++total[pl1-1];
                ++total[pl2-1];

            }
            if(move1=="paper" && move2=="scissors"){

                ++win[pl2-1];
                ++total[pl1-1];
                ++total[pl2-1];

            }
            if(move1=="scissors" && move2=="rock"){

                ++win[pl2-1];
                ++total[pl1-1];
                ++total[pl2-1];
            }
            if(move1=="rock" && move2=="paper"){
                ++win[pl2-1];
                ++total[pl1-1];
                ++total[pl2-1];
            }
        } 
    }

    for(int i=0;i<n;i++){
        if(total[i]==0)
            cout << "-" << endl;
        else{

            double d = (double)win[i]/(double)total[i];
            cout << fixed << setprecision(3) << d << endl;
        }
    }

    cout << endl;

    } 
    return 0;
}