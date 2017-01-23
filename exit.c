#include "game.h"

//=================================================
// void OnExit(void)
//-------------------------------------------------
//.Encerra todos os subsistemas com seguranca
//=================================================
void OnExit(void)
{
    // Libera a fonte
    //TTF_CloseFont( font );
    //font = NULL;
    //TTF_CloseFont( menuMessageFont );
    //menuMessageFont = NULL;

    // Destroi imagens e texturas
    SDL_DestroyTexture(_gTexturepad1);
    SDL_DestroyTexture(_gTexturepad2);
    SDL_DestroyTexture(_gTexturebola);
    SDL_DestroyTexture(_gTexturemenu);
    SDL_DestroyTexture(_gTexturetitle);
    SDL_DestroyTexture(_gTexturedemo);

    SDL_FreeSurface(_gPad1);
    SDL_FreeSurface(_gPad2);
    SDL_FreeSurface(_gBola);
    SDL_FreeSurface(_gDemo);
    SDL_FreeSurface(_gMenu);
    SDL_FreeSurface(_gTitle);

    //Destro janela e renderizador
    SDL_DestroyRenderer( _gRenderer );
    SDL_DestroyWindow( _janela );

    _janela = NULL;
    _gRenderer = NULL;

    //Encerra biblioteca de fonte
    //TTF_Quit();

    // Destroi imagens
    IMG_Quit();

    // Destroi som
    //Mix_FreeMusic(musica_intro);

    //Quit SDL subsystems
    SDL_Quit();

}
