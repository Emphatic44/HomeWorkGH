// HomeWork2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;



int main()
{
    {
        // 1 задание: Создать и инициализировать переменные пройденных типов данных (short int, int, long long, char, bool, float, double)

        short int A = 32;
        int B = 2147;
        long long C = 2100;
        char D = 'y';
        bool E = true;
        float F = 3.14f;
        double G = 3.15;
        cout << A << "\n" << B << "\n" << C << "\n" << D << "\n" << E << "\n" << F << "\n" << G << endl; //проверил корректно ли выводятся данные
    }

    // 2 задание: Создать перечисление (enum) с возможными вариантами символов для игры в крестики-нолики

    {
        enum game { Cross, Null, Empty };

        // 3 задание: Создать массив, способный содержать значения такого перечисления и инициализировать его.
        {

            game ValueField[9] = { Cross, Null, Empty, Empty, Null, Empty, Cross, Empty, Empty };

            cout << "field 1: " << ValueField[6] << endl;

            return 0;
        }
    }
    // 4 задание : Создать структуру (struct) данных «Для игры в крестики-нолики» и снабдить его всеми необходимыми свойствами 
   
    
    enum StageGame { StartGame, Endgame, FirstPlayerWin, SecondPlayerWin, Draw };
    enum Players { Player1, Player2 };
    enum FieldValue { Cross, Null, Empty };
    enum PlayerNames {Andy, Anita};
    
    
    struct Game
    {
        Players FirstMove;
        FieldValue GameField[9];
        StageGame WhatHappened;
        PlayerNames FirstPlayer;
        PlayerNames SecondPlayer;  
    };
   
    
    {
        Game FirstGame;
        FirstGame.FirstMove = Player2;
        FirstGame.WhatHappened = Draw;
        FirstGame.GameField[0] = Cross;
        FirstGame.FirstPlayer = Anita;
        FirstGame.SecondPlayer = Andy;

        

    }
 
}

