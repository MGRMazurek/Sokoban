#include <iostream>

using namespace std;


char base_map[20][20]; //'stół roboczy' na który nanosimy mapy

void base_map_cleaner() { //funkcja do kompletnego wyczyszczenia stołu roboczego
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            base_map[i][j] = ' ';
        }
    }
}


void load_map_a() { //funkcja do załadowania pierwszej mapy na stół roboczy
    base_map_cleaner();
    char map[7][7] = {
    {'a', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', 'P', ' ', 'P', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', 'M', ' ', ' ', '#'},
    {'#', ' ', ' ', '1', ' ', '2', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#'}
    };

    int size_x = sizeof(map[0]);
    int size_y = sizeof(map) / size_x;

    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            base_map[i][j] = map[i][j];
        }
    }

}

void load_map_b() { //funkcja do załadowania drugiej mapy na stół roboczy
    base_map_cleaner();
    char map[8][8] = {
    {'b', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', 'P', '2', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', 'M', ' ', ' ', ' ', '#'},
    {'#', 'P', '1', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#'}
    };

    int size_x = sizeof(map[0]);
    int size_y = sizeof(map) / size_x;

    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            base_map[i][j] = map[i][j];
        }
    }
}

void load_map_c() { //funkcja do załadowania trzeciej mapy na stół roboczy
    base_map_cleaner();
    char map[8][8] = {
    {'c', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '2', ' ', ' ', ' ', 'P', '#'},
    {'#', ' ', 'M', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '1', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', 'P', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#'}
    };

    int size_x = sizeof(map[0]);
    int size_y = sizeof(map) / size_x;

    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            base_map[i][j] = map[i][j];
        }
    }
}






int size_x = sizeof(base_map[0]);
int size_y = sizeof(base_map) / size_x;
char player_hold = ' ';
char box1_hold = ' ';
char box2_hold = ' ';
int moves = 30;
int map_id = 1;



int get_x(char element) { //znajdowanie koordynatu x dowolnego unikalnego elementu (gracz/skrzynia)
    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            if (base_map[i][j] == element) {
                return i;
            }
        }
    }
}

int get_y(char element) { //znajdowanie koordynatu y dowolnego unikalnego elementu (gracz/skrzynia)
    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            if (base_map[i][j] == element) {
                return j;
            }
        }
    }
}

void win() { //funkcja sprawdzająca, czy skrzynia jest na przycisku, zmieniająca poziom po jego przejściu, oraz rozpoznająca wygraną gry i jej zamknięcie
    if (box1_hold == 'P') {
        base_map[get_x('1')][get_y('1')] = '*';
    }
    if (box2_hold == 'P') {
        base_map[get_x('2')][get_y('2')] = '*';
    }
    if (box1_hold == 'P' && box2_hold == 'P') {
        if (map_id == 1) { //przejście z poziomu 1 na 2
            load_map_b();
            box1_hold = ' ';
            box2_hold = ' ';
            moves = 41;
            map_id = 2;
        }
        else {
            if (map_id == 2) { //przejście z poziomu 2 na 3
                load_map_c();
                box1_hold = ' ';
                box2_hold = ' ';
                moves = 51;
                map_id = 3;
            }
            else {
                if (map_id == 3) { // rozpoznanie wygranej
                    cout << "YOU WON\n";
                    exit(0);
                }
            }
        }
        
    }
}

void show_map() { //funkcja rysująca mapę
    system("CLS");
    win();
    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            cout << base_map[i][j];
            cout << " ";
        }
        cout << endl;
    }
}

char swapper(int x1, int y1, int x2, int y2, char znak, char holder) { // funkcja do przesuwania elementów (graczy/ skrzyń) na inne pole
    
    base_map[x1][y1] = holder;
    holder = base_map[x2][y2];
    base_map[x2][y2] = znak;
    return holder;
}


void move(char m){ //funkcja poruszająca grazcem i skrzyniami na podstawie cin, oraz obsługująca menu
    int x = get_x('M');
    int y = get_y('M');
    switch(m){
        case 'w':
            if (base_map[x-1][y] == ' ' || base_map[x - 1][y] == 'P') { //brak skrzynki
                player_hold = swapper(x, y, x - 1, y, 'M', player_hold);
            }
            if ((base_map[x - 1][y] == '1' || base_map[x - 1][y] == '2') && (base_map[x - 2][y] == ' ' || base_map[x - 2][y] == 'P')) { //jest skrzynka
                if (base_map[x - 1][y] == '1') {
                    box1_hold = swapper(x - 1, y, x - 2, y, '1', box1_hold); //przesuwanie najpierw skrzynki tej
                }
                if (base_map[x - 1][y] == '2') {
                    box2_hold = swapper(x - 1, y, x - 2, y, '2', box2_hold); //albo tej
                }
                swapper(x, y, x - 1, y, 'M', player_hold); //potem przesuwanie gracza
            }
            show_map();
            break;
        case 's':
            if (base_map[x + 1][y] == ' ' || base_map[x + 1][y] == 'P') { //brak skrzynki
                player_hold = swapper(x, y, x + 1, y, 'M', player_hold);
            }
            if ((base_map[x + 1][y] == '1' || base_map[x + 1][y] == '2') && (base_map[x + 2][y] == ' ' || base_map[x + 2][y] == 'P')) { //jest skrzynka
                if (base_map[x + 1][y] == '1') {
                    box1_hold = swapper(x + 1, y, x + 2, y, '1', box1_hold); //przesuwanie najpierw skrzynki tej
                }
                if (base_map[x + 1][y] == '2') {
                    box2_hold = swapper(x + 1, y, x + 2, y, '2', box2_hold); //albo tej
                }
                player_hold = swapper(x, y, x + 1, y, 'M', player_hold); //potem przesuwanie gracza
            }
            show_map();
            break;
        case 'a':
            if (base_map[x][y - 1] == ' ' || base_map[x][y - 1] == 'P') { //brak skrzynki
                player_hold = swapper(x, y, x, y - 1, 'M', player_hold);
            }
            if ((base_map[x][y - 1] == '1' || base_map[x][y - 1] == '2') && (base_map[x][y - 2] == ' ' || base_map[x][y - 2] == 'P')) { //jest skrzynka
                if (base_map[x][y - 1] == '1') {
                    box1_hold = swapper(x, y - 1, x, y - 2, '1', box1_hold); //przesuwanie najpierw skrzynki tej
                }
                if (base_map[x][y - 1] == '2') {
                    box2_hold = swapper(x, y - 1, x, y - 2, '2', box2_hold); //albo tej
                }
                player_hold = swapper(x, y, x, y - 1, 'M', player_hold); //potem przesuwanie gracza
            }
            show_map();
            break;
        case 'd':
            if (base_map[x][y + 1] == ' ' || base_map[x][y + 1] == 'P') { //brak skrzynki
                player_hold = swapper(x, y, x, y + 1, 'M', player_hold);
            }
            if ((base_map[x][y + 1] == '1' || base_map[x][y + 1] == '2') && (base_map[x][y + 2] == ' ' || base_map[x][y + 2] == 'P')) { //jest skrzynka
                if (base_map[x][y + 1] == '1') {
                    box1_hold = swapper(x, y + 1, x, y + 2, '1', box1_hold); //przesuwanie najpierw skrzynki tej
                }
                if (base_map[x][y + 1] == '2') {
                    box2_hold = swapper(x, y + 1, x, y + 2, '2', box2_hold); //albo tej
                }
                player_hold = swapper(x, y, x, y + 1, 'M', player_hold); //potem przesuwanie gracza
            }
            show_map();
            break;
        case 'q': //menu
            system("CLS");
            cout << "Enter level number (1-3) to play, '4' to restart the level or '0', to leave the game:\n";
            int level_picker;
            cin >> level_picker;
            switch (level_picker) {
            case 1:
                load_map_a();
                moves = 31;
                map_id = 1;
                player_hold = ' ';
                box1_hold = ' ';
                box2_hold = ' ';
                break;
            case 2:
                load_map_b();
                moves = 41;
                map_id = 2;
                player_hold = ' ';
                box1_hold = ' ';
                box2_hold = ' ';
                break;
            case 3:
                load_map_c();
                moves = 51;
                map_id = 3;
                player_hold = ' ';
                box1_hold = ' ';
                box2_hold = ' ';
                break;
            case 4:

                switch (map_id)
                {
                case 1:
                    load_map_a();
                    moves = 31;
                    map_id = 1;
                    player_hold = ' ';
                    box1_hold = ' ';
                    box2_hold = ' ';
                    break;
                case 2:
                    load_map_b();
                    moves = 41;
                    map_id = 2;
                    player_hold = ' ';
                    box1_hold = ' ';
                    box2_hold = ' ';
                    break;
                case 3:
                    load_map_c();
                    moves = 51;
                    map_id = 3;
                    player_hold = ' ';
                    box1_hold = ' ';
                    box2_hold = ' ';
                    break;
                default:
                    show_map();
                    break;
                }

                break;
            case 0:
                cout << "Leaving the game";
                exit(0);

            default:
                show_map();
                break;
            }
        default:
            show_map();
            break;
    }
}




int main()
{
    int temp;
    cout << "SOKOBAN\n";
    
    cout << "Press 1 to play\n";
    cin >> temp;
    load_map_a();

    show_map();
    char move_input;
    for (int i = 0; i < moves; moves--) {
        cout << "moves left: ";
        cout << moves;
        cout << endl;
        cin >> move_input;
        move(move_input);
        
    }

    return 0;
}

