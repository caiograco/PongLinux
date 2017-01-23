#include "game.h"

//-------------------------------
// Variaveis globais
//-------------------------------

SDL_Window* _janela = NULL;
SDL_Event _event;
SDL_Renderer* _gRenderer;

// Imagens
SDL_Surface* _gPad1;
SDL_Surface* _gPad2;
SDL_Surface* _gBola;
SDL_Surface* _gDemo;
SDL_Surface* _gMenu;
SDL_Surface* _gTitle;

// Textura para onde desenhar
SDL_Texture* _gTexturepad1;
SDL_Texture* _gTexturepad2;
SDL_Texture* _gTexturebola;
SDL_Texture* _gTexturedemo;
SDL_Texture* _gTexturemenu;
SDL_Texture* _gTexturetitle;

// Area da textura do pad
SDL_Rect _gPad1rect;
SDL_Rect _gPad2rect;
SDL_Rect _gBolarect;
SDL_Rect _gBolaMenurect;
SDL_Rect _gDemorect;
SDL_Rect _gMenurect;
SDL_Rect _gTitlerect;

struct bola _gDirecaoBolaStruct;

bool _Running;
bool MenuOn = true;
bool DemoMode = false;

// Tela
const int _screenWidth = 1024;
const int _screenHeight = 768;

// Inteiro que sera usado no delay para determinar velocidade do jogo
int _gameSpeed = 5;

int main(int argc, char* argv[])
{
    _gRenderer = NULL;

    _Running = true;
    MenuOn = true;

    // Inicializa sistemas basicos
    if (OnInit() == false)
        return -1;

    // Loop do Jogo
    while (MenuOn)
    {
        // Pega eventos e os processa
        while( SDL_PollEvent(&_event))
        {
            OnMenuEvent(&_event);
        }

        drawMenu();
        drawBolaMenu();

        // Renderiza imagem
        OnRender();
    }


    // Loop do Jogo
    while (_Running)
    {
        // Pega eventos e os processa
        while( SDL_PollEvent(&_event))
        {
            OnEvent(&_event);
        }

        moveBola();
        movePadComputer();
        // Se em demo
        if(DemoMode)
            movePadPlayer();

        // Renderiza imagem
        OnRender();
    }


    // Encerra todo o subsistema
    OnExit();

    return 0;
}
