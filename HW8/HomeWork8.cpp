#include <iostream>
#include <random>
#include <stdlib.h>

using namespace std;


/*int GetRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
*/
inline void ClearSrc()
{
    system("cls");
}

enum CELL : char
{
    Cross = 'X',
    Zero = '0',
    Empty = '_'
};

enum Progress: uint8_t
{
    In_Progress,
    Win_AI,
    Win_Human,
    Draw
};

struct Cord
{
    size_t x{ 0 };
    size_t y{ 0 };
};

#pragma pack(push,1)
struct Game
{
    CELL** ppField = nullptr;
    const size_t SIZE = 3;
    size_t turn = 0;
    CELL human;
    CELL AI;
    Progress progress = In_Progress;
};

#pragma pack(pop)


void _fastcall InitGame(Game& g)
{
    g.ppField = new CELL * [g.SIZE];
    for (size_t i = 0; i < g.SIZE; i++)
    {
        g.ppField[i] = new CELL[g.SIZE];
    }

    for (size_t x = 0; x < g.SIZE; x++)
    {
        for (size_t y = 0; y < g.SIZE; y++)
        {
            g.ppField[x][y] = Empty;
        }
    }

    if (rand() % 1000 > 500)
    {
        g.human = Cross;
        g.AI = Zero;
        g.turn = 0;
    }
    else
    {
        g.human = Zero;
        g.AI = Cross;
        g.turn = 1;
    }

    
}

void DeInitGame(Game& g)
{
    for (size_t i = 0; i < g.SIZE; i++)
    {
        delete[] g.ppField[i];
    }
    delete[] g.ppField;
    g.ppField = nullptr;
}

void _fastcall PrintGame(const Game& g)
{
    cout << "    ";
    for (size_t x = 0; x < g.SIZE; x++)
    {
        cout << x + 1 << "   ";
    }
    cout << endl;
    for (size_t y = 0; y < g.SIZE; y++)
    {
        cout << y + 1 << " | ";
        for (size_t x = 0; x < g.SIZE; x++)
        {
           cout<< g.ppField[x][y]<<  " | ";
        }
        cout << endl;
    }

    cout << endl << "Human: " << g.human << endl;
    cout << "AI: " << g.AI << endl;
}

void _fastcall Congrats(const Game& g)
{
    if (g.progress == Win_Human)
    {
        cout << "Human Win! :)" << endl;
    }
    if (g.progress == Win_AI)
    {
        cout << "Win AI :(" << endl;
    }
    if (g.progress == Draw)
    {
        cout << " Draw :/" << endl;
    }

}

Progress GetWon(const Game& g)
{
    for (size_t x = 0; x < g.SIZE; x++)
    {
        if (g.ppField[x][0] == g.ppField[x][1] && g.ppField[x][0] == g.ppField[x][2])
        {
            if (g.ppField[x][0] == g.human)
                return Win_Human;
            if (g.ppField[x][0] == g.AI)
                return Win_AI;

        }
    }
    for (size_t y = 0; y < g.SIZE; y++)
    {
        if (g.ppField[0][y] == g.ppField[1][y] && g.ppField[0][y] == g.ppField[2][y])
        {
            if (g.ppField[0][y] == g.human)
                return Win_Human;
            if (g.ppField[0][y] == g.AI)
                return Win_AI;

        }
    }

    for (size_t y = 0; y < g.SIZE; y++)
    {
        if (g.ppField[0][0] == g.ppField[1][1] && g.ppField[0][0] == g.ppField[2][2])
        {
            if (g.ppField[0][0] == g.human)
                return Win_Human;
            if (g.ppField[0][0] == g.AI)
                return Win_AI;

        }
    }

    for (size_t y = 0; y < g.SIZE; y++)
    {
        if (g.ppField[2][0] == g.ppField[1][1] && g.ppField[2][0] == g.ppField[0][2])
        {
            if (g.ppField[2][0] == g.human)
                return Win_Human;
            if (g.ppField[2][0] == g.AI)
                return Win_AI;

        }
    }
    bool draw = true;
    for (size_t x = 0; x < g.SIZE; x++)
    {
        for (size_t y = 0; y < g.SIZE; y++)
        {
            if (g.ppField[x][y] == Empty)
            {
                draw = false;
                break;

            }
        }
        if (!draw)
            break;
    }
    if (draw)
        return Draw;


    return In_Progress;
}

Cord GetHumanCord(const Game& g)
{
    Cord c;
    do
    {
        cout << "Enter X: ";
        cin >> c.x;
        cout << "Enter Y: ";
        cin >> c.y;
    } while (c.x == 0 || c.y == 0 || c.x > 3 || c.y > 3 || g.ppField[c.x-1][c.y-1] != Empty);
    c.x--;
    c.y--;

    return c;
}

Cord GetAICord(Game& g)
{
    
    for (size_t y = 0; y < g.SIZE; y++)
    {
        for (size_t x = 0; x < g.SIZE; x++)
        {
            if (g.ppField[x][y] == Empty)
            {
                g.ppField[x][y] == g.AI;
                if (GetWon(g) == Win_AI)
                {
                    g.ppField[x][y] = Empty;
                }
            }
        }
    }

    for (size_t y = 0; y < g.SIZE; y++)
    {
        for (size_t x = 0; x < g.SIZE; x++)
        {
            if (g.ppField[x][y] == Empty)
            {
                g.ppField[x][y] == g.human;
                if (GetWon(g) == Win_Human)
                {
                    g.ppField[x][y] = Empty;
                }
            }
        }
    }

    if (g.ppField[1][1] == Empty)
        return { 1, 1 };
   
    Cord Array[4];
    size_t num{ 0 };

    if (g.ppField[0][0] == Empty)
    {
        Array[num] = { 0,0 };
        num++;
    }
    if (g.ppField[2][0] == Empty)
    {
        Array[num] = { 2,0 };
        num++;
    }
    if (g.ppField[0][2] == Empty)
    {
        Array[num] = { 0,2 };
        num++;
    }
    if (g.ppField[2][2] == Empty)
    {
        Array[num] = { 2,2 };
        num++;
    }

    if (num > 0)
    {
        const size_t index = (rand() % 1000) % num;
        return Array[index];
    }
    num = 0;
    //не углы
    if (g.ppField[1][0] == Empty)
    {
        Array[num] = { 1,0 };
        num++;
    }
    if (g.ppField[0][1] == Empty)
    {
        Array[num] = { 0,1 };
        num++;
    }
    if (g.ppField[2][1] == Empty)
    {
        Array[num] = { 2,1 };
        num++;
    }
    if (g.ppField[1][2] == Empty)
    {
        Array[num] = { 1,2 };
        num++;
    }

    if (num > 0)
    {
        const size_t index = (rand() % 1000) % num;
        return Array[index];
    }
    return{};
}



int main()
{
    srand(time(NULL));
    Game g;
    InitGame(g);
    ClearSrc();
    PrintGame(g);

    do
    {
        if (g.turn % 2 == 0)
        {
            Cord c = GetHumanCord(g);
                g.ppField[c.x][c.y] = g.human;
        }
        else
        {
            Cord c = GetAICord(g);
            g.ppField[c.x][c.y] = g.AI;

        }

        ClearSrc();
        PrintGame(g);
        g.progress = GetWon(g);
        g.turn++;
    } while (g.progress == In_Progress);
    
   
    Congrats(g);
    DeInitGame(g);
}
