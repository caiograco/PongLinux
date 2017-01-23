# PongLinux
Pong for Linux
--------------------------------------------------------------------------------------

PONGX - Pong for Linux é um simples jogo de Pong desenvolvido com C e SDL2 para o
sistema operacional Linux.

O objetivo desse jogo é apenas exercitar um pouco o conhecimento com código, já que
a lógica, bem como o próprio código utilizados, são deveras simples. Sendo assim,
deverá ser algo simples de ser compreendido por todos os níveis de programadores, 
dos mais básicos até o mais avançado.

--------------------------------------------------------------------------------------

Esse projeto foi escrito no CodeBlocks, portanto poderá ser aberto facilmente nele.

A estrutura de arquivos também é simples, sendo:

RAIZ  -> Todo o fonte (.C e .H)

IMG   -> Imagens utilizadas no jogo

MUSIC -> Música utilizada no jogo

BIN/DEBUG -> Executável

obj/Debug -> Arquivos Objeto (.O) gerados pelo compilador

--------------------------------------------------------------------------------------

O "engine" do jogo, se podemos chamá-lo assim, está estruturado da seguinte forma:

main.c	 -> Função Main e inicializações gerais

init.c	 -> Inicialização de todas as variáveis globais e funções da biblioteca SDL2

game.c	 -> Loop básico do jogo

error.c	 -> Tratamento de erros

events.c -> Tratamento de eventos (mouse, teclado)

exit.c   -> Responsavel por encerrar as funcoes do jogo e da SDL2

ia.c	   -> "Inteligência Artificial" do jogo

render.c -> Funções de desenho na tela

#######################################################################################

Bibliotecas .H que valem a pena ser destacadas:

includes.H -> Inclui todos os demais cabeçalhos

game.h     -> Inclui a chamada acima, bem como declaração das variáveis globais do
              projeto (extern)

---------------------------------------------------------------------------------------


