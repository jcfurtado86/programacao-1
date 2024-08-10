#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define FLAPPY_CHAR '8'
#define CANO_CHAR '|'
#define VAZIO_CHAR ' '
#define ALTURA 20
#define LARGURA 100
#define LARGURA_CANO 2
#define ALTURA_ESPACO 8
#define GRAVIDADE 1
#define ALTURA_PULO 3
#define DELAY 100

typedef struct
{
    int x;
    int y;
} Flappy;

typedef struct
{
    int x, espaco;
} Cano;

Flappy flappy;
Cano canos[2];
int score;
int velocidade_cano = 1;
int velocidade_flappy = 0;
int game_over = 0;
int aguardando_comecar = 1;

// TESTE PRA VER SE PISCA MENOS. CHATGPT QUE FEZ ESSA PARTE
HANDLE hConsole;
CHAR_INFO consoleBuffer[LARGURA * ALTURA];
COORD bufferSize = {LARGURA, ALTURA};
COORD characterPos = {0, 0};
SMALL_RECT consoleWriteArea = {0, 0, LARGURA - 1, ALTURA - 1};

void reset()
{
    flappy.x = 5;
    flappy.y = ALTURA / 2;
    canos[0].x = LARGURA - 1;
    canos[0].espaco = rand() % (ALTURA - ALTURA_ESPACO);
    canos[1].x = LARGURA + LARGURA / 2;
    canos[1].espaco = rand() % (ALTURA - ALTURA_ESPACO);
    score = 0;
    velocidade_flappy = 0;
    game_over = 0;
    aguardando_comecar = 1;
}

void desenha_tela()
{
    for (int i = 0; i < LARGURA * ALTURA; ++i)
    {
        consoleBuffer[i].Char.AsciiChar = VAZIO_CHAR;
        consoleBuffer[i].Attributes = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
    }

    consoleBuffer[flappy.y * LARGURA + flappy.x].Char.AsciiChar = FLAPPY_CHAR;

    for (int i = 0; i < 2; i++)
    {
        for (int y = 0; y < ALTURA; y++)
        {
            if (y < canos[i].espaco || y > canos[i].espaco + ALTURA_ESPACO)
            {
                for (int x = 0; x < LARGURA_CANO; x++)
                {
                    int pipe_x = canos[i].x + x;
                    if (pipe_x >= 0 && pipe_x < LARGURA)
                    {
                        consoleBuffer[y * LARGURA + pipe_x].Char.AsciiChar = CANO_CHAR;
                    }
                }
            }
        }
    }

    WriteConsoleOutputA(hConsole, consoleBuffer, bufferSize, characterPos, &consoleWriteArea);

    SetConsoleCursorPosition(hConsole, (COORD){0, ALTURA});

    printf("Score: %d\n", score);
    if (game_over)
    {
        printf("Fim do jogo! Aperte R para reiniciar.\n");
    }
    else if (aguardando_comecar)
    {
        printf("Aperte espaço para iniciar!\n");
    }
}

void atualiza_tela()
{
    if (!aguardando_comecar)
    {
        velocidade_flappy += GRAVIDADE;
        flappy.y += velocidade_flappy;

        for (int i = 0; i < 2; i++)
        {
            canos[i].x -= velocidade_cano;
            if (canos[i].x < 0)
            {
                canos[i].x = LARGURA - 1;
                canos[i].espaco = rand() % (ALTURA - ALTURA_ESPACO);
                score++;
            }
        }

        for (int i = 0; i < 2; i++)
        {
            if (flappy.x == canos[i].x || flappy.x == canos[i].x + 1)
            {
                if (flappy.y < canos[i].espaco || flappy.y > canos[i].espaco + ALTURA_ESPACO)
                {
                    game_over = 1;
                }
            }
        }

        if (flappy.y < 0 || flappy.y >= ALTURA)
        {
            game_over = 1;
        }
    }
}

void comandos()
{
    if (GetAsyncKeyState(VK_SPACE) & 0x8000)
    {
        if (game_over)
        {
            reset();
        }
        else if (aguardando_comecar)
        {
            aguardando_comecar = 0;
            velocidade_flappy = -ALTURA_PULO;
        }
        else
        {
            velocidade_flappy = -ALTURA_PULO;
        }
    }
}

int main()
{
    srand(time(NULL));
    reset();

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    while (1)
    {
        if (!game_over)
        {
            atualiza_tela();
        }
        desenha_tela();
        comandos();
        Sleep(DELAY);
    }

  
    return 0;
}