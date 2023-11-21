#ifndef MINMAX_HPP
#define MINMAX_HPP

#include <vector>

class MinMax {
public:
    MinMax();

    int melhorMovimento(const std::vector<int>& tabuleiro);
    int minMax(const std::vector<int>& tabuleiro, int profundidade, bool maximizando);
    bool tabuleiroCheio(const std::vector<int>& tabuleiro);
    int avaliarTabuleiro(const std::vector<int>& tabuleiro);
    
private:
    short int jogadorMax; 
    short int jogadorMin;
};

#endif // MINMAX_HPP