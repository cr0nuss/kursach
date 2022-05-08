#include <iostream>
using namespace std;


int counterD = 0;
bool checkOnDraw() {
    counterD++;
    if (counterD == 8) return false;
    return true;
}

void ai(int map[4][4])
{

    int x,y;

    do {
        x = rand() % 4;
        y = rand() % 4;
    }while(map[x][y] != 0);

    map[x][y] = 2;
}
void map_show(int map[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << map[j][i];
        }
        cout << endl;
    }
}

int game_over(int map [4][4], int val)
{
    int counter = 0;
    int counter1 = 0;
    int counter2 = 0;
    int counter3 = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (map[j][i] == val)
                counter++;

            if (map[i][j] == val)
                counter1++;

            if (map [j][j] == val)
                counter2++;
            if (map [3 - j][j] == val)
                counter3++;


        }
        if (counter == 4 || counter1 == 4 || counter2 == 4 || counter3 == 4)
        {
            return 1;
        }
        counter = 0;
        counter1 = 0;
        counter2 = 0;
        counter3 = 0;
        if (counterD == 8)
        {
            return 2;
        }
    }
    return false;
}
void human(int map[4][4]) {

    int x = 0, y = 0;
    while (true) {
        cout << "player1 is entering the coordinates:";
        cin >> x >> y;

        map[x][y] = 1;

        map_show(map);

        if (game_over(map, 1) == 1) {
            cout << "player1 has won!" << endl;
            break;}

        cout << "player2 is entering the coordinates:";

        cin >> x >> y;

        map[x][y] = 2;

        map_show(map);

        if (game_over(map, 2) == 1) {
            cout << "player2 has won!" << endl;
            break;
        }
        if(!checkOnDraw())
        {
            cout << "It's a draw!" << endl;
            break;
        }
    }
}
void computer(int map[4][4]) {
    int x = 0, y = 0;
    while (true) {
        cout << "enter coordinates:";
        cin >> x >> y;
        map[x][y] = 1;
        map_show(map);
        if (game_over(map, 1) == 1) {
            cout << "You have won!" << endl;
            break;
        }
        if (!checkOnDraw()) {
            cout << "It's a draw!" << endl;
            break;
        }
    srand(time(NULL));
    cout << "computer move:" << endl;

    ai(map);

    map_show(map);

    if (game_over(map, 2) == 1) {
        cout << "You have lost!" << endl;
        break;
    }
        if(game_over(map, 1) == 2)
        {
            cout << "It's draw!" << endl;
        }
        if (game_over(map, 2) == 2)
        {
            cout << "It's draw!" << endl;
        }

    }

}
    int main() {
        int m;
        cin >> m;
        int map[4][4] = {0};
        if (m == 1)
        {
            human((map));
        }
        if (m == 0)
        {
            computer(map);
        }


    }




