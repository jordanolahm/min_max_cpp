#include "MinMax.hpp"
#include <climits>
#include <algorithm>
#include <iostream>

MinMax::MinMax() : jogadorMax(1), jogadorMin(-1) {}

MinMax::~MinMax() {}

 int MinMax::melhorMovimento(const std::vector<int>& tabuleiro) {
    int melhorValor = INT_MIN;
    int melhorMov = -1;

    for (int i = 0; i < tabuleiro.size(); ++i) {
        if (tabuleiro[i] == 0) {
            std::vector<int> novoTabuleiro = tabuleiro;
            novoTabuleiro[i] = 1;

            int valorMov = minMax(novoTabuleiro, 0, false);

            if (valorMov > melhorValor) {
                melhorValor = valorMov;
                melhorMov = i;
            }
        }
    }

    return melhorMov;
}

 int MinMax::minMax(const std::vector<int>& tabuleiro, int profundidade, bool maximizando) {
    // Função de avaliação simples para o exemplo (pode ser substituída por uma mais sofisticada)
    int resultado = avaliarTabuleiro(tabuleiro);
    if (resultado != 0) {
        return resultado;
    }

    if (tabuleiroCheio(tabuleiro) || profundidade == 3) {
        return 0; // Substitua por uma função de avaliação mais elaborada
    }

    if (maximizando) {
        int melhorValor = INT_MIN;
        for (int i = 0; i < tabuleiro.size(); ++i) {
            if (tabuleiro[i] == 0) {
                std::vector<int> novoTabuleiro = tabuleiro;
                novoTabuleiro[i] = 1;
                melhorValor = std::max(melhorValor, minMax(novoTabuleiro, profundidade + 1, false));
            }
        }
        return melhorValor;
    } else {
        int melhorValor = INT_MAX;
        for (int i = 0; i < tabuleiro.size(); ++i) {
            if (tabuleiro[i] == 0) {
                std::vector<int> novoTabuleiro = tabuleiro;
                novoTabuleiro[i] = -1;
                melhorValor = std::min(melhorValor, minMax(novoTabuleiro, profundidade + 1, true));
            }
        }
        return melhorValor;
    }
}

bool MinMax::tabuleiroCheio(const std::vector<int>& tabuleiro) {
    return std::find(tabuleiro.begin(), tabuleiro.end(), 0) == tabuleiro.end();
}

int MinMax::avaliarTabuleiro(const std::vector<int>& tabuleiro) {
    // Verifica se algum jogador ganhou
    const int linhas[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8},
                              {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
                              {0, 4, 8}, {2, 4, 6}};

    for (const auto& linha : linhas) {
        if (tabuleiro[linha[0]] == 1 && tabuleiro[linha[1]] == 1 && tabuleiro[linha[2]] == 1) {
            return 10; // O jogador 'X' ganhou
        } else if (tabuleiro[linha[0]] == -1 && tabuleiro[linha[1]] == -1 && tabuleiro[linha[2]] == -1) {
            return -10; // O jogador 'O' ganhou
        }
    }

    return 0; // Ninguém ganhou ainda
}