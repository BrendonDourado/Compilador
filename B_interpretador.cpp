#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>

using namespace std;

// Mapa para armazenar as variáveis e seus valores
unordered_map<string, int> variaveis;

// Função para remover espaços extras
string trim(const string &str) {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    return (start == string::npos) ? "" : str.substr(start, end - start + 1);
}

// Função para processar uma linha de código BASIC
void processarLinha(const string &linha) {
    // Se a linha contém PRINT
    if (linha.substr(0, 5) == "PRINT") {
        string var = trim(linha.substr(6)); // Nome da variável a ser impressa
        if (variaveis.find(var) != variaveis.end()) {
            cout << variaveis[var] << endl; // Imprime o valor da variável
        } else {
            cerr << "Erro: Variável " << var << " não foi definida!" << endl;
        }
    }
    // Processar atribuições A = B + C
    else if (linha.find('=') != string::npos) {
        stringstream ss(linha);
        string varEsq, varDir;
        char operacao;
        int valorDir1, valorDir2;

        ss >> varEsq >> operacao;
        varEsq = trim(varEsq); // Variável à esquerda da atribuição

        // Verifica se há uma operação na parte direita
        if (ss >> valorDir1 >> operacao >> valorDir2) {
            // Atribuição com operação A = B + C
            if (operacao == '+') {
                variaveis[varEsq] = valorDir1 + valorDir2;
            } else if (operacao == '-') {
                variaveis[varEsq] = valorDir1 - valorDir2;
            } else {
                cerr << "Erro: Operação inválida!" << endl;
            }
        } else {
            // Atribuição simples A = 5
            ss.clear();
            ss.str(linha.substr(linha.find('=') + 1));
            int valor;
            ss >> valor;
            variaveis[varEsq] = valor;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Uso: " << argv[0] << " <arquivo.bas>" << endl;
        return 1;
    }

    // Abrir o arquivo de código BASIC
    ifstream arquivo(argv[1]);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo " << argv[1] << endl;
        return 1;
    }

    string linha;
    // Ler o arquivo linha por linha
    while (getline(arquivo, linha)) {
        linha = trim(linha); // Remover espaços em branco no início e fim da linha
        if (!linha.empty()) {
            processarLinha(linha); // Processar cada linha do arquivo
        }
    }

    arquivo.close();
    return 0;
}
