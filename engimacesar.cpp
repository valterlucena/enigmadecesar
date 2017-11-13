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


// Falta ver se aceita chave 0 de deslocamento!
// Falta banco de perguntas-charadas medio e dificil!

// Banco de perguntas-charadas
string perguntasFacil[10] = {"mantem sempre o mesmo tamanho, nao importa o peso?",
"o que detestamos na praia e adoramos na panela?",
"o que eh que anda com os pe na cabeca?",
"o que eh, o que eh? que eh irma de minha tia e nao eh minha tia?",
"o que eh, o que eh? de dia tem quatro pes e de noite tem seis?",
"o que eh, o que eh? anda deitado e dorme em pe?",
"qual o sobrenome que todo mundo tem?",
"quem morre em pe?",
"tem cabeca e nao eh gente, tem dente e nao eh pente?",
"o que eh que nasce grande e morre pequeno?"};

// Respostas das perguntas-charadas
string respostasFacil[10] = {"balanca", "caldo", "piolho", "mae", "cama", "pe", "costa", "vela", "alho", "lapis"};
string alfa = "abcdefghijklmnopqrstuvwxyz";

void telaInicial();
void regras();
void jogar();
int indiceRandomico();
int limiteIndice();
string escolheFraseFacil();
void imprimeCharadaFacil();
string crip(string frase, int chave);
string descrip(string frase, int chave);

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
	cout << crip(escolheFraseFacil(), limiteIndice());
	//cout << escolheFraseFacil();
}

void regras() {
	cout << "Escrever regras";
}

// Refatorar o codigo crip e descrip
string crip(string frase, int chave) {
	
	string rest = "";
	for (int i = 0; i < frase.size(); i++) {
		for (int j = 0; j < alfa.size(); j++) {
			if (alfa[j] == frase[i]) {
				if (j + chave >= 26) {
					frase[i] = alfa[j + chave - 26];
				} else {
					frase[i] = alfa[j + chave];
				}
				
				j = 0;
				break;
			}
		}
		rest += frase[i];
	}
	
	return rest;
} 


string descrip(string frase, int chave) {
	string rest = "";
	for (int i = 0; i < frase.size(); i++) {
		for (int j = 0; j < alfa.size(); j++) {
			if (alfa[j] == frase[i]) {
				if (j - chave < 0) {
					frase[i] = alfa[j + chave + 26];
				} else {
					frase[i] = alfa[j - chave];
				}
				
				j = 0;
				break;
			}
		}
		rest += frase[i];
	}
	
	return rest;
}

void jogar() {
	imprimeCharadaFacil();
}

