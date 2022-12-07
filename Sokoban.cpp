#include <iostream>

using namespace std;
/*
char map[5][5] = {
    {'W', 'W', 'W', 'W', 'W'},
    {'W', 'A', 'A', 'A', 'W'},
    {'W', 'A', 'O', 'A', 'W'},
    {'W', 'A', 'A', 'A', 'W'},
    {'W', 'W', 'W', 'W', 'W'}
};
*/

/*
W = ściana
A = puste pole
O = postać
B = box
P = przycisk
*/


char map[7][7] = {
    {'W', 'W', 'W', 'W', 'W', 'W', 'W'},
    {'W', 'A', 'A', 'P', 'A', 'P', 'W'},
    {'W', 'A', 'A', 'A', 'A', 'A', 'W'},
    {'W', 'A', 'A', 'O', 'A', 'A', 'W'},
    {'W', 'A', 'A', '1', 'A', '2', 'W'},
    {'W', 'A', 'A', 'A', 'A', 'A', 'W'},
    {'W', 'W', 'W', 'W', 'W', 'W', 'W'}
};


int size_x = sizeof(map[0]);
int size_y = sizeof(map) / size_x;
char player_hold = 'A';
char box1_hold = 'A';
char box2_hold = 'A';

void show_map()
{
    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            cout << map[i][j];
            cout << " ";
        }
        cout << endl;
    }
}

int get_x(char element) {
    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            if (map[i][j] == element) {
                return i;
            }
        }
    }
}

int get_y(char element) {
    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            if (map[i][j] == element) {
                return j;
            }
        }
    }
}


void swapper(int x1, int y1, int x2, int y2, char znak, char holder) {
    
    map[x1][y1] = holder;
    holder = map[x2][y2];
    map[x2][y2] = znak;
}


void move(char m){
    int x = get_x('O');
    int y = get_y('O');
    switch(m){
        case 'w':
            system("CLS");
            cout << "move up\n";
            if (map[x-1][y] == 'A' || map[x - 1][y] == 'P') { //brak skrzynki
                swapper(x, y, x - 1, y, 'O', player_hold);
            }
            if ((map[x - 1][y] == '1' || map[x - 1][y] == '2') && (map[x - 2][y] == 'A' || map[x - 2][y] == 'P')) { //jest skrzynka
                if (map[x - 1][y] == '1') {
                    swapper(x - 1, y, x - 2, y, '1', box1_hold); //przesuwanie najpierw skrzynki tej
                }
                if (map[x - 1][y] == '2') {
                    swapper(x - 1, y, x - 2, y, '2', box2_hold); //albo tej
                }
                swapper(x, y, x - 1, y, 'O', player_hold); //potem przesuwanie gracza
            }
            show_map();
            break;
        case 's':
            system("CLS");
            cout << "move down\n";
            if (map[x + 1][y] == 'A' || map[x + 1][y] == 'P') { //brak skrzynki
                swapper(x, y, x + 1, y, 'O', player_hold);
            }
            if ((map[x + 1][y] == '1' || map[x + 1][y] == '2') && (map[x + 2][y] == 'A' || map[x + 2][y] == 'P')) { //jest skrzynka
                if (map[x + 1][y] == '1') {
                    swapper(x + 1, y, x + 2, y, '1', box1_hold); //przesuwanie najpierw skrzynki tej
                }
                if (map[x + 1][y] == '2') {
                    swapper(x + 1, y, x + 2, y, '2', box2_hold); //albo tej
                }
                swapper(x, y, x + 1, y, 'O', player_hold); //potem przesuwanie gracza
            }
            show_map();
            break;
        case 'a':
            system("CLS");
            cout << "move left\n";
            if (map[x][y - 1] == 'A' || map[x][y - 1] == 'P') { //brak skrzynki
                swapper(x, y, x, y - 1, 'O', player_hold);
            }
            if ((map[x][y - 1] == '1' || map[x][y - 1] == '2') && (map[x][y - 2] == 'A' || map[x][y - 2] == 'P')) { //jest skrzynka
                if (map[x][y - 1] == '1') {
                    swapper(x, y - 1, x, y - 2, '1', box1_hold); //przesuwanie najpierw skrzynki tej
                }
                if (map[x][y - 1] == '2') {
                    swapper(x, y - 1, x, y - 2, '2', box2_hold); //albo tej
                }
                swapper(x, y, x, y - 1, 'O', player_hold); //potem przesuwanie gracza
            }
            show_map();
            break;
        case 'd':
            system("CLS");
            cout << "move right\n";
            if (map[x][y + 1] == 'A' || map[x][y + 1] == 'P') { //brak skrzynki
                swapper(x, y, x, y + 1, 'O', player_hold);
            }
            if ((map[x][y + 1] == '1' || map[x][y + 1] == '2') && (map[x][y + 2] == 'A' || map[x][y + 2] == 'P')) { //jest skrzynka
                if (map[x][y + 1] == '1') {
                    swapper(x, y + 1, x, y + 2, '1', box1_hold); //przesuwanie najpierw skrzynki tej
                }
                if (map[x][y + 1] == '2') {
                    swapper(x, y + 1, x, y + 2, '2', box2_hold); //albo tej
                }
                swapper(x, y, x, y + 1, 'O', player_hold); //potem przesuwanie gracza
            }
            show_map();
            break;
        default:
            show_map();
            break;
    }
}

void win() { //to nie działa + zmazuje przyciski przy przejściu przez przycisk bezpośrednio skrzynką ORAZ graczem
    if (box1_hold == 'P') {
        cout << "DUPSKO";
        map[get_x('1')][get_y('1')] = '*';
    }
    if (box2_hold == 'P') {
        map[get_x('2')][get_y('2')] = '*';
    }
    if (box1_hold == 'P' && box2_hold == 'P') {
        cout << "WYGRANAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    }
}


int main()
{
    cout << "Witaj w DUPIUUUUU!\n";
    int moves = 20;


    show_map();
    char move_input;
    for (int i = 0; i < moves; i++) {
        win();
        cin >> move_input;
        move(move_input);
    }

    return 0;
}

