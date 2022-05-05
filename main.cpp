#include <iostream>
using namespace std;

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
bool game_over(int map [4][4])
{
    int counter = 0;
    int counter1 = 0;
    int counter2 = 0;
    int counter3 = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (map[j][i] == 1)
                counter++;

            if (map[i][j] == 1)
                counter1++;

            if (map [j][j] == 1)
                counter2++;
            if (map [3 - j][j] == 1)
                counter3++;


        }
        if (counter == 4 || counter1 == 4 || counter2 == 4 || counter3 == 4)
        {
            return true;
            break;
        }
        counter = 0;
        counter1 = 0;
        counter2 = 0;
        counter3 = 0;
    }
    return false;
}
int main() {
    int map[4][4] = {0};
    int x = 0, y = 0;
    while(true) {
        cout << "enter coordinates:";
        cin >> x >> y;

        map[x][y] = 1;

        map_show(map);

        if (game_over(map) == true)
        {
            cout << "You have won!" << endl;
            break;
        }
        cout << "computer move:"

    }

}
