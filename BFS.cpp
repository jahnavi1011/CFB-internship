#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct node
{
    int vertex;
    int steps;
};

struct Queue
{
    node enQ;
    Queue *link;

    Queue(node item)
    {
        enQ.vertex = item.vertex;
        enQ.steps = item.steps;
        link = NULL;
    }
};

int size = 0;

Queue *rear = NULL;

Queue *push(Queue *head, node item)
{
    Queue *temp = new Queue(item);

    if (head == NULL)
    {
        head = rear = temp;
        return head;
    }

    rear->link = temp;
    rear = temp;
    return head;
}

bool isEmpty(Queue *head)
{
    return head == NULL;
}

node front(Queue *head)
{
    if (head == NULL)
    {
        node temp;
        temp.vertex = 1;
        temp.steps = 1;
        return temp;
    }
    return head->enQ;
}

Queue *pop(Queue *head)
{
    Queue *temp = head;

    if (head != NULL && head == rear)
    {
        head = rear = NULL;
    }
    else
    {
        head = temp->link;
    }

    free(temp);
    return head;
}

void count(int board[], int m[], int n)
{
    for (int i = 0; i < size-1; i++)
    {
        if (board[i + 1] > 0)
        {
            continue;
        }

        bool visited[n] = {0};
        Queue *Q = NULL;

        // INITIAL STEP : First visiting first node
        node enQ;
        enQ.vertex = i + 1;
        enQ.steps = 0;
        visited[1] = 1;
        Q = push(Q, enQ);

        // REPEATING STEP
        while (!isEmpty(Q))
        {
            enQ = front(Q);
            Q = pop(Q);
            int v = enQ.vertex;

            if (v == n - 1)
                break;

            for (int i = v + 1; (i <= v + 6) && i < n; i++)
            {

                if (!visited[i])
                {
                    visited[i] = 1;

                    node temp;
                    temp.steps = enQ.steps + 1;

                    if (board[i] != -1)
                        temp.vertex = board[i];
                    else
                        temp.vertex = i;

                    Q = push(Q, temp);
                }
            }
        }

        m[i + 1] = enQ.steps;
    }
}

int roll(int board[], int m[], int pos)
{
    int n = rand() % 6 + 1;
    if (pos + n > size - 1)
    {
        cout << "Dice: " << n << endl;
        cout << "Position: " << pos << endl;
        cout << "Minimum moves required to win the game: " << m[pos] << "\n\n";
        return pos;
    }

    else
    {
        pos = pos + n; 
        if((pos - board[pos]) < 0){
            cout << "Yay! it is a ladder" << endl;
            pos = board[pos];
        }

        else if(board[pos] != -1 && (pos - board[pos]) > 0){
            cout << "Ohh! it is a snake" << endl;
            pos = board[pos];
        }

        cout << "Dice: " << n << endl;
        cout << "Position: " << pos << endl;
        cout << "Minimum moves required to win the game: " << m[pos] << "\n\n";
        return pos;
    }
}

int main()
{
    srand(time(0));
menu:
    cout << "1. Play Game" << endl;
    cout << "2. Create your own snake and ladder board" << endl;
    cout << "3. Exit";
    int choice;
    cin >> choice;

    int ladders, snakes, src, dst, i, row, col;

    if (choice == 1)
    {
        size = 101;
    }

    else if (choice == 2)
    {
        cout << "Enter Rows : ";
        cin >> row;
        cout << "Enter COlumns : ";
        cin >> col;
        size = row * col + 1;
    }

    else
    {
        return 0;
    }

    int board[size], m[size] = {0};

    for (i = 0; i < size; i++)
    {
        board[i] = -1;
    }

    switch (choice)
    {
    case 1:
        board[5] = 25;
        board[13] = 19;
        board[35] = 57;
        board[50] = 85;
        board[77] = 96;

        board[21] = 7;
        board[38] = 27;
        board[62] = 44;
        board[31] = 20;
        board[98] = 73;
        break;

    case 2:
        cout << "\nEnter Number Of Ladders : ";
        cin >> ladders;

        // Setting Up ladders
        cout << "Set up your Ladders : \n";
        for (i = 0; i < ladders; i++)
        {
            cin >> src >> dst;
            board[src] = dst;
        }

        // Setting Up Snakes
        cout << "\nEnter Number Of snakes : ";
        cin >> snakes;
        cout << "Set up your Snakes : \n";
        for (i = 0; i < snakes; i++)
        {
            cin >> src >> dst;
            board[src] = dst;
        }
        break;

    default:
        break;
    }

    count(board, m, size);

    // for(i=0; i<size; i++){
    //     cout<<i<<") " << m[i]<<endl;
    // }
    system("clear");

menu2:
    cout << "Select total number of players: " << endl;
    cout << "1) 2 players" << endl;
    cout << "2) 3 players" << endl;
    cout << "3) 4 players" << endl;
    int num;
    cin >> num;

    int player1, player2, player3, player4;
    player1 = player2 = player3 = player4 = 1;

    char ch;

    bool flag, check;
    flag = check = true;

    while (1)
    {
        if (num == 1)
        {
            if (flag)
            {
                cout << "Player-1: " << endl;
                cout << "To roll dice Enter Y: ";
                cin >> ch; 
                if(ch == 'Y'){
                    player1 = roll(board, m, player1);
                    flag = false;
                }
            }

            else
            {
                cout << "Player-2: " << endl;
                cout << "To roll dice Enter Y: ";
                cin >> ch; 
                if(ch == 'Y'){
                player2 = roll(board, m, player2);
                flag = true;
                }
            }
        }

        else if (num == 2)
        {
            if (flag && check)
            {
                cout << "To roll dice Enter Y: ";
                cin >> ch; 
                if(ch == 'Y'){
                player1 = roll(board, m, player1);
                flag = false;
                }
            }

            else if (!flag && check)
            {
                cout << "To roll dice Enter Y: ";
                cin >> ch; 
                if(ch == 'Y'){
                player2 = roll(board, m, player2);
                check = false;
                }
            }

            else
            {
                cout << "To roll dice Enter Y: ";
                cin >> ch; 
                if(ch == 'Y'){
                player3 = roll(board, m, player3);
                check = true;
                flag = true;
                }
            }
        }

        else
        {
            if (flag && check)
            {
                cout << "To roll dice Enter Y: ";
                cin >> ch; 
                if(ch == 'Y'){
                player1 = roll(board, m, player1);
                flag = false;
                }
            }

            else if (!flag && check)
            {
                cout << "To roll dice Enter Y: ";
                cin >> ch; 
                if(ch == 'Y'){
                player2 = roll(board, m, player2);
                check = false;
                flag = true;
                }
            }

            else if (flag && !check)
            {
                cout << "To roll dice Enter Y: ";
                cin >> ch; 
                if(ch == 'Y'){
                player3 = roll(board, m, player3);
                check = false;
                flag = false;
                }
            }

            else
            {
                cout << "To roll dice Enter Y: ";
                cin >> ch; 
                if(ch == 'Y'){
                player4 = roll(board, m, player4);
                check = true;
                flag = true;
                }
            }
        }

        if(player1 == size - 1){
            cout << "Winner player-1";
            break;
        }

        else if(player2 == size - 1){
            cout << "Winner player-2";
            break;
        }

        else if(player3 == size - 1){
            cout << "Winner player-3";
            break;
        }

        else if(player4 == size - 1){
            cout << "Winner player-4";
            break;
        }
    }

    return 0;
}