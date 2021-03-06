#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "includes.h"

// Macros
#define VERSAO "0.01"


// Posicoes bola
#define CIMA 1
#define BAIXO 2
#define ESQUERDA 3
#define DIREITA 4

//==================================
// VARIAVEIS GLOBAIS
//==================================

// Dispositivos de Janela e Superficie
extern SDL_Window* _janela;
extern SDL_Event _event;
extern SDL_Renderer* _gRenderer;

// Imagens
extern SDL_Surface* _gPad1;
extern SDL_Surface* _gPad2;
extern SDL_Surface* _gBola;
extern SDL_Surface* _gDemo;
extern SDL_Surface* _gMenu;
extern SDL_Surface* _gTitle;

// Textura para onde desenhar
extern SDL_Texture* _gTexturepad1;
extern SDL_Texture* _gTexturepad2;
extern SDL_Texture* _gTexturebola;
extern SDL_Texture* _gTexturedemo;
extern SDL_Texture* _gTexturemenu;
extern SDL_Texture* _gTexturetitle;

// Retangulo para textura do pad
extern SDL_Rect _gPad1rect;
extern SDL_Rect _gPad2rect;
extern SDL_Rect _gBolarect;
extern SDL_Rect _gBolaMenurect;
extern SDL_Rect _gDemorect;
extern SDL_Rect _gMenurect;
extern SDL_Rect _gTitlerect;

// Resolucao de tela
extern const int _screenWidth;
extern const int _screenHeight;

// Velocidade
extern int _gameSpeed;

bool DemoMode;
bool MenuOn;

// Direcao Bola
extern struct bola
{
    int DirecaoVertical, DirecaoHorizontal;
} _gDirecaoBolaStruct;


// Variavel de controle da execucao do jogo
extern bool _Running;

#endif // GAME_H_INCLUDED
