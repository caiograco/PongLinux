#include "game.h"

int velocidadeBola = 2;
int velocidadePC = 3;
int velocidadePlayer = 2;

//==================================
// Funcao moveBola(void)
//----------------------------------
// Movimenta a bola pela área da tela
//===================================
void moveBola(void)
{
    checaColisao();
    checaPad();

    if (_gDirecaoBolaStruct.DirecaoHorizontal == ESQUERDA)
        _gBolarect.x -= velocidadeBola;
    else if (_gDirecaoBolaStruct.DirecaoHorizontal == DIREITA)
        _gBolarect.x += velocidadeBola;

    if (_gDirecaoBolaStruct.DirecaoVertical == CIMA)
        _gBolarect.y -= velocidadeBola;
    else if (_gDirecaoBolaStruct.DirecaoVertical == BAIXO)
        _gBolarect.y += velocidadeBola;

}



//==================================
// Funcao checaColisao(void)
//----------------------------------
// Checa colisoes com as paredes
//===================================
void checaColisao(void)
{
    // Vertical
    if (_gBolarect.y >= 750)
        _gDirecaoBolaStruct.DirecaoVertical = CIMA;

    else if (_gBolarect.y <= 0)
        _gDirecaoBolaStruct.DirecaoVertical = BAIXO;

    // Horizontal
    if (_gBolarect.x >= 1000)
        resetBola();

    else if (_gBolarect.x <= 0)
        resetBola();

}




//==================================
// Funcao sorteiaNumero(void)
//----------------------------------
// Cria ilusao de randomicidade
//===================================
int sorteiaNumero(void)
{
  srand ((unsigned)time(NULL));
  int random_number = 1 + ( rand() % 2 );

  return random_number;
}



//=======================================================
// Funcao checaPad(void)
//----------------------------------
// Checa se o Pad esta no caminho de colisao com a bola
//=======================================================
void checaPad(void)
{
    // Usuario
    if( (_gBolarect.y >= _gPad1rect.y) && (_gBolarect.y <= (_gPad1rect.y+_gPad1rect.h) ))
        if ( _gBolarect.x <= _gPad1rect.w)
            _gDirecaoBolaStruct.DirecaoHorizontal = DIREITA;

    // Computador
    if( (_gBolarect.y >= _gPad2rect.y) && (_gBolarect.y <= (_gPad2rect.y+_gPad2rect.h) ))
        if ( _gBolarect.x >= (_gPad2rect.x - _gPad2rect.w) )
            _gDirecaoBolaStruct.DirecaoHorizontal = ESQUERDA;

}

//=======================================================
// Funcao resetBola(void)
//----------------------------------
// Devolve a bola pra posicao inicial
//=======================================================
void resetBola(void)
{
    // Area do bola
    int lado = sorteiaNumero();
    if (lado>=2)
        _gDirecaoBolaStruct.DirecaoHorizontal = DIREITA;
    else
        _gDirecaoBolaStruct.DirecaoHorizontal = ESQUERDA;

    _gBolarect.x = 500;
    _gBolarect.y = -30;
    _gBolarect.h = 26;
    _gBolarect.w = 28;
}


//=======================================================
// Funcao movePadComputer(void)
//----------------------------------
// Movimento do computador
//=======================================================
void movePadComputer(void)
{
    if (_gBolarect.x >= 512)
    {
    // Area do pad2
        if (( _gBolarect.y <= _gPad2rect.y) && (_gPad2rect.y >= 0))
                _gPad2rect.y -= velocidadePC;
        else if ( (_gBolarect.y >= _gPad2rect.y) && (_gPad2rect.y <= 618) )
                _gPad2rect.y += velocidadePC;
        else
        {
            if ( (_gBolarect.y <= (( _gPad2rect.y+_gPad2rect.h)/2) ) && (_gPad2rect.y >=0 ) )
                    _gPad2rect.y -= velocidadePC;
            else
                if (_gPad2rect.y <= 618)
                    _gPad2rect.y += velocidadePC;
        }
    }
}

//=======================================================
// Funcao movePadPlayer(void)
//----------------------------------
// Automatiza movimento do jogador (para demos)
//=======================================================
void movePadPlayer(void)
{
    if (_gBolarect.x <= 512)
    {
    // Area do pad1
        if (( _gBolarect.y <= _gPad1rect.y) && (_gPad1rect.y >= 0))
                _gPad1rect.y -= velocidadePlayer;
        else if ( (_gBolarect.y >= _gPad1rect.y) && (_gPad1rect.y <= 618) )
                _gPad1rect.y += velocidadePlayer;
        else
        {
            if ( (_gBolarect.y <= (( _gPad1rect.y+_gPad1rect.h)/2) ) && (_gPad1rect.y >=0 ) )
                    _gPad1rect.y -= velocidadePlayer;
            else
                if (_gPad1rect.y <= 618)
                    _gPad1rect.y += velocidadePlayer;
        }
    }
}
