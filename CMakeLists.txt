cmake_minimum_required(VERSION 3.17)
project(jogo_xadrez C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(jogo_xadrez
        bispo.h
        cavalo.h
        main.c
        partida_xadrez.h
        peao.h
        pecas.h
        rainha.h
        rei.h
        tela.h
        torre.h)
