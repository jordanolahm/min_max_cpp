#include "MinMax.hpp"
#include <iostream>

void imprimirTabuleiro(const std::vector<int>& tabuleiro) {
    for (int i = 0; i < tabuleiro.size(); ++i) {
        if (i % 3 == 0 && i != 0) {
            std::cout << std::endl;
        }
        if (tabuleiro[i] == 0) {
            std::cout << " - ";
        } else if (tabuleiro[i] == 1) {
            std::cout << " X ";
        } else {
            std::cout << " O ";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> tabuleiro = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    MinMax minmax;
    int jogadorAtual = 1; // 1 para 'X', -1 para 'O'

    for (int rodada = 0; rodada < 9; ++rodada) {
        imprimirTabuleiro(tabuleiro);

        int movimento;

        if (jogadorAtual == 1) {
            std::cout << "Vez do jogador 'X'. Informe o movimento (0-8): ";
            std::cin >> movimento;
        } else {
            movimento = minmax.melhorMovimento(tabuleiro);
            std::cout << "Jogador 'O' escolheu o movimento " << movimento << std::endl;
        }

        if (tabuleiro[movimento] == 0) {
            tabuleiro[movimento] = jogadorAtual;
            jogadorAtual *= -1; // Alternar jogador
        } else {
            std::cout << "Posição ocupada. Tente novamente." << std::endl;
            --rodada; // Repetir a mesma rodada
        }

        if (minmax.avaliarTabuleiro(tabuleiro) == 10) {
            imprimirTabuleiro(tabuleiro);
            std::cout << "Jogador 'X' ganhou!" << std::endl;
            break;
        } else if (minmax.avaliarTabuleiro(tabuleiro) == -10) {
            imprimirTabuleiro(tabuleiro);
            std::cout << "Jogador 'O' ganhou!" << std::endl;
            break;
        } else if (minmax.tabuleiroCheio(tabuleiro)) {
            imprimirTabuleiro(tabuleiro);
            std::cout << "Empate!" << std::endl;
            break;
        }
    }

    return 0;
}