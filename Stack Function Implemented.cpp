#include <iostream>

using namespace std;

#define MAX_SIZE 101

class Stack{
    private:
        int A[MAX_SIZE];
        int top;

    public:
            //constructor
            stack() {
                top = -1;
            }

            //Push Operation
            void push(int x){

                if(top==MAX_SIZE-1){
                    cout << "Error: Stack Overflow" << endl;
                    return;
                }

                top++;
                A[top] = x;
                cout << x;
            }

            void pop(){
                if(top==-1) {
                    cout <<"Error: Stack Empty" << endl;
                    return;
                }
                top--;
                cout << top;
            }

            int top(){
                return A[top];
            }

            int Empty(){

                if(top==-1)
                    return 1;
                return 0;
            }
        //Just for Testing
        void print(){

            cout << "Stack: "
            for(int i=0;i<top;i++){
                cout << A[i] << " ";
            }
            cout << "\n";
        }
};

int main() {

    Stack s;
    s.push(2);s.print();
    s.push(10);s.print();
    s.push(100);s.print();
    s.pop();s.print();

    reyurn 0;
}
