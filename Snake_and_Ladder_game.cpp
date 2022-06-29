// 1. Implementing queue
// 2. ladders for implementing ladders and snakes
// 3. Number required on dice to complete minimum 

#include<bits/stdc++.h>
using namespace std;

class queueEntry{
public:
    int vertex;
    int steps;
};

int snake_and_ladder(int move[], int n){
    bool visited[n] = {0};
    queue<queueEntry> q;

// INITIAL STEP : First visiting first node
    queueEntry qe;
    qe.vertex = 1;
    qe.steps = 0;
    visited[1] = 1;
    q.push(qe);

// REPEATING STEP 
    while(!q.empty()){
        qe = q.front();
        q.pop();
        int v = qe.vertex;

        if(v == n-1)
            break;

        for(int i = v+1 ; (i <= v+6) && i<n ; i++){
            
            if(!visited[i]){
                visited[i] = 1;

                queueEntry a; 
                a.steps = qe.steps + 1;

                if(move[i] != -1)
                    a.vertex = move[i];
                else
                    a.vertex = i;

                q.push(a);
            }
        }
    }
    return qe.steps;
}

int main()
{
    int row, col;
    cout << "Enter Rows : ";
    cin >> row;
    cout << "Enter COlumns : ";
    cin >> col;

    int size = row*col + 1;

    int move[size];
    for(int i=0 ; i<size ; i++){
        move[i] = -1;
    }

    int ladders, snakes;
    cout << "\nEnter Number Of Ladders : ";
    cin >> ladders;

// Setting Up ladders
    int src, dst;
    cout << "Set up your Ladders : \n";
    for(int i=0 ; i<ladders ; i++){
        cin >> src >> dst;
        move[src] = dst;
    }
    // move[3] = 22;
    // move[5] = 8;
    // move[11] = 26;
    // move[20] = 29;


// Setting Up Snakes
    cout << "\nEnter Number Of snakes : ";
    cin >> snakes;
    cout << "Set up your Snakes : \n";
    for(int i=0 ; i<snakes ; i++){
        cin >> src >> dst;
        move[src] = dst;
    }
    // move[27] = 1;
    // move[21] = 9;
    // move[17] = 4;
    // move[19] = 7;

// Printing MINIMUM Moves
    int min_moves = snake_and_ladder(move, size);
    cout << "\nMin Steps Required to win the game : " << min_moves << endl;

    return 0;
}