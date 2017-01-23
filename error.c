#include "game.h"

//===========================================
// Funcao Error
//-------------------------------------------
// Responsavel por manusear as mensagens de
// erro e dar andamento as mesmas.
//===========================================

bool OnError(char *Mensagem, const char* Erro)
{
    printf("%s SDL_ERROR: %s",Mensagem, Erro);

    return false;
}
