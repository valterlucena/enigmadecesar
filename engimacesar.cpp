#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*
    ENIGMA DE CESAR
    APLICACOES DE PARADIGMAS DE LINGUAGEM DE PROGRAMACAO - 2017.2 - UFCG
    EQUIPE: ALICE FERNANDES
            ITALO MENEZES
            IVYNA ALVES
            THAIS TOSCANO
            VALTER LUCENA
*/


// Banco de perguntas-charadas
string perguntasFacil[10] = {"Mantem sempre o mesmo tamanho, nao importa o peso?",
"O que detestamos na praia e adoramos na panela?",
"O que eh que anda com os pe na cabeça?",
"O que eh, o que e? Que é irma de minha tia e nao eh minha tia?",
"O que eh, o que eh? De dia tem quatro pes e de noite tem seis?",
"O que eh, o que eh? Anda deitado e dorme em pe?",
"Qual o sobrenome que todo mundo tem?",
"Quem morre em pe?",
"Tem cabeça e nao eh gente, tem dente e nao eh pente?",
"O que eh que nasce grande e morre pequeno?"};

// Respostas das perguntas-charadas
string respostasFacil[10] = {"balanca", "caldo", "piolho", "mae", "cama", "pe", "costa", "vela", "alho", "lapis"};


void telaInicial();
void regras();
void jogar();
int indiceRandomico();
int limiteIndice();
string escolheFraseFacil();
void imprimeCharadaFacil();

int main() {
    telaInicial();
    int opcao;
	cin >> opcao;
	
	if (opcao == 1) {
		regras();
	} 
	
	if (opcao == 2) {
		jogar();
	}
    return 0;
}

void telaInicial() {
    cout << ".------------------------------------------------------------------------." << endl;
    cout << "|                                                                        |" << endl;
    cout << "|                             Enigma de Cesar                            |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|       A historia conta que, para se comunicar com seus generais, Julio |" << endl;
    cout << "| Cesar utilizava um sistema simples de substituicao, no qual cada letra |" << endl;
    cout << "| da mensagem original era trocada pela letra que se situa tres posicoes |" << endl;
    cout << "| a sua frente. Esse metodo e popularmente conhecido como Cifra de Cesar.|" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|           A B C D E F G H I J K L M N O P Q R S T U V W X Y Z          |" << endl;
    cout << "|           - - - - - - - - - - - - - - - - - - - - - - - - - -          |" << endl;
    cout << "|           D E F G H I J K L M N O P Q R S T U V W X Y Z A B C          |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Utilize a Cifra de Cesar para descobrir o que a Esfinge esta falando! |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "| Pressione 1 para as regras, 2 para jogar agora!                        |" << endl;
    cout << "'------------------------------------------------------------------------'" << endl;
}

int indiceRandomico() {
	srand(time(NULL));
	//numero provisorio
	return rand()%29;
}

int limiteIndice() {
	int indice = indiceRandomico();
	while (indice >= 10) {
		indice = indiceRandomico();
	}
	
	return indice;
}

string escolheFraseFacil() {
	string saida = perguntasFacil[limiteIndice()];
	return saida;
}

void imprimeCharadaFacil() {
	cout << escolheFraseFacil();
}

void regras() {
	cout << "Escrever regras";
}

void jogar() {
	imprimeCharadaFacil();
}

