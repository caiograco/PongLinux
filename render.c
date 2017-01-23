#include "game.h"

// Funcao em init.c
extern void clearScreen();

//==================================
// Funcao OnRender
//----------------------------------
// Realiza os desenhos na tela
//===================================
int OnRender(void)
{
    if (MenuOn)
    {
        clearScreen();
        drawTitle();
        drawMenu();
        SDL_RenderPresent(_gRenderer);
    }
    else
    {
        clearScreen();
        drawPads();
        drawBola();

        if(DemoMode)
            drawDemo();


        // Atualiza a tela
        SDL_RenderPresent(_gRenderer);

        SDL_Delay(_gameSpeed);
    }

    return 0;
}


//==================================
// Funcao drawPads(void)
//----------------------------------
// Desenha os pads na tela
//===================================
void drawPads(void)
{
    // Renderiza a superficie da memoria RAM(CPU) para memoria do video(GPU RAM)
    SDL_RenderCopy(_gRenderer, _gTexturepad1, NULL, &_gPad1rect);
    SDL_RenderCopy(_gRenderer, _gTexturepad2, NULL, &_gPad2rect);
}


//==================================
// Funcao drawBola(void)
//----------------------------------
// Desenha a bola na tela
//===================================
void drawBola(void)
{
    // Renderiza a superficie da memoria RAM(CPU) para memoria do video(GPU RAM)
    SDL_RenderCopy(_gRenderer, _gTexturebola, NULL, &_gBolarect);
}


//==================================
// Funcao drawBolaMenu(void)
//----------------------------------
// Desenha a bola do menu na tela
//===================================
void drawBolaMenu(void)
{
    // Renderiza a superficie da memoria RAM(CPU) para memoria do video(GPU RAM)
    SDL_RenderCopy(_gRenderer, _gTexturebola, NULL, &_gBolarect);
}



//==================================
// Funcao drawDemo(void)
//----------------------------------
// Mostra texto de demo
//===================================
void drawDemo(void)
{
    // Renderiza a superficie da memoria RAM(CPU) para memoria do video(GPU RAM)
    SDL_RenderCopy(_gRenderer, _gTexturedemo, NULL, &_gDemorect);
}


//==================================
// Funcao drawTitle
//----------------------------------
// Desenha o titulo
//===================================
void drawTitle(void)
{
    SDL_RenderCopy(_gRenderer, _gTexturetitle, NULL, &_gTitlerect);
}


//==================================
// Funcao drawMenu
//----------------------------------
// Desenha o menu
//===================================
void drawMenu(void)
{
    SDL_RenderCopy(_gRenderer, _gTexturemenu, NULL, &_gMenurect);
    SDL_RenderCopy(_gRenderer, _gTexturebola, NULL, &_gBolaMenurect);
}
