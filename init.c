#include "game.h"

bool OnInit(void)
{
    // Inicializa o video
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return OnError("Nao pode inicializar o modo de video", SDL_GetError());

    if (SDL_Init(SDL_INIT_AUDIO) < 0)
        return OnError("Nao pode inicializar o som!", SDL_GetError());

    // Inicializa sistema de fontes
    // a fazer...

    // Titulo da janela
    createWindow("PONGX - PONG FOR LINUX (SDL2)");


    // Inicializa biblioteca de imagens PNG
    IMG_Init(IMG_INIT_PNG);
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image nao pode inicializar! SDL_image Erro: %s\n", IMG_GetError() );
    }


    //loadSounds();
    loadImages();
    gameReady();

    // Limpa a tela toda
    clearScreen();

    return true;
}

//==========================================
// Funcao createWindow(void)
//------------------------------------------
// Inicializa uma nova janela
//==========================================
bool createWindow(char *titulo)
{
    // Titulo da janela
    //char titulo[30];
    //snprintf(titulo, 30, "Pongx - Pong for Linux (SDL2)");

    // Cria a janela
    if ((_janela = SDL_CreateWindow(titulo, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _screenWidth, _screenHeight,  SDL_WINDOW_SHOWN)) == NULL)
    //if ((_janela = SDL_CreateWindow(titulo, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _screenWidth, _screenHeight,  SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP)) == NULL)
        return OnError("Nao pode criar janela SDL!", SDL_GetError() );
    else
    {
        // Contexto Renderizador
        _gRenderer = SDL_CreateRenderer( _janela, -1, SDL_RENDERER_ACCELERATED);
        if (_gRenderer == NULL)
            return OnError("Contexto Renderizador nao pode ser criado!", SDL_GetError());
        else
        {
            //SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
            //SDL_RenderSetLogicalSize(_gRenderer, _screenWidth, _screenHeight);
            return true;
        }
    }

    return true;

}
//==========================================
// Funcao gameReady(void)
//------------------------------------------
// Prepara as condições iniciais do jogo
//==========================================
void gameReady(void)
{
    // Direcao da bola (inicial)
    _gDirecaoBolaStruct.DirecaoHorizontal = ESQUERDA;
    _gDirecaoBolaStruct.DirecaoVertical = BAIXO;
}



//==================================
// Funcao loadImages(void)
//----------------------------------
// Carrega todas as imagens
//===================================
bool loadImages(void)
{
 //------------------------------
    // Carrega imagens
    //------------------------------
     _gPad1 = NULL;
     _gPad2 = NULL;
     _gBola = NULL;
     _gDemo = NULL;
     _gMenu = NULL;
     _gTitle = NULL;

    _gPad1 = IMG_Load("img/pad.png");
    if(!_gPad1)
        return OnError("Imagem nao pode ser carregada!", IMG_GetError());

    _gPad2 = IMG_Load("img/pad.png");
    if(!_gPad2)
        return OnError("Imagem nao pode ser carregada!", IMG_GetError());

    _gBola = IMG_Load("img/bola.png");
    if(!_gBola)
        return OnError("Imagem nao pode ser carregada!", IMG_GetError());

    _gDemo = IMG_Load("img/demo.png");
    if(!_gBola)
        return OnError("Imagem nao pode ser carregada!", IMG_GetError());

    _gMenu = IMG_Load("img/menu.png");
    if(!_gMenu)
        return OnError("Imagem nao pode ser carregada!", IMG_GetError());

    _gTitle = IMG_Load("img/title.png");
    if(!_gTitle)
        return OnError("Imagem nao pode ser carregada!", IMG_GetError());

    // Textura
    _gTexturepad1 = SDL_CreateTextureFromSurface(_gRenderer, _gPad1);
    _gTexturepad2 = SDL_CreateTextureFromSurface(_gRenderer, _gPad2);
    _gTexturebola = SDL_CreateTextureFromSurface(_gRenderer, _gBola);
    _gTexturedemo = SDL_CreateTextureFromSurface(_gRenderer, _gDemo);
    _gTexturemenu = SDL_CreateTextureFromSurface(_gRenderer, _gMenu);
    _gTexturetitle = SDL_CreateTextureFromSurface(_gRenderer, _gTitle);

    // Area do pad1
    _gPad1rect.x = 0;
    _gPad1rect.y = 0;
    _gPad1rect.h = 150;
    _gPad1rect.w = 30;

    // Area do pad2
    _gPad2rect.x = (_screenWidth-34);
    _gPad2rect.y = 0;
    _gPad2rect.h = 150;
    _gPad2rect.w = 30;

    // Area do bola
    _gBolarect.x = (_screenWidth-524);
    _gBolarect.y = -30;
    _gBolarect.h = 26;
    _gBolarect.w = 28;


    // Area do bola menu
    _gBolaMenurect.x = 350;
    _gBolaMenurect.y = 240;
    _gBolaMenurect.h = 26;
    _gBolaMenurect.w = 28;


    // Area do demo
    _gDemorect.x = (_screenWidth/7); //160;
    _gDemorect.y = 50;
    _gDemorect.h = 118;
    _gDemorect.w = 700;


    // Area do Menu
    _gMenurect.x = 350;
    _gMenurect.y = 220;
    _gMenurect.h = 461;
    _gMenurect.w = 332;

    // Titulo
    _gTitlerect.x = 0;
    _gTitlerect.y = 50;
    _gTitlerect.h = 150;
    _gTitlerect.w = 1024;


    return true;
}


//==================================
// Funcao loadSounds(void)
//----------------------------------
// Carrega sons e musica
//===================================
void loadSounds(void)
{
    //Inicializa o SDL_mixer para MP3
    Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);

     //Inicializa SDL_mixer
    static const char *intro_mp3 = "music/intro.mp3";

    Mix_Music *musica_intro = Mix_LoadMUS(intro_mp3);
    Mix_PlayMusic(musica_intro, -1);
}



//==================================
// Funcao clearScreen(void)
//----------------------------------
// Limpa a tela toda
//===================================
void clearScreen(void)
{
    // Limpa a tela
    SDL_SetRenderDrawColor( _gRenderer, 0x00, 0x00, 0x00, 0xFF );
    SDL_RenderClear( _gRenderer );
}
