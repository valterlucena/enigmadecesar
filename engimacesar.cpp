#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

/**
    ENIGMA DE CESAR
    APLICACOES DE PARADIGMAS DE LINGUAGEM DE PROGRAMACAO - 2017.2 - UFCG
    EQUIPE: ALICE FERNANDES
            ITALO MENEZES
            IVYNA ALVES
            THAIS TOSCANO
            VALTER LUCENA
**/

string alfa = "abcdefghijklmnopqrstuvwxyz";

string perguntasFacil[10] = {"mantem sempre o mesmo tamanho, nao importa o peso?",
                             "o que detestamos na praia e adoramos na panela?",
                             "o que eh que anda com os pe na cabeca?",
                             "o que eh, o que eh? que eh irma de minha tia e nao eh minha tia?",
                             "o que eh, o que eh? de dia tem quatro pes e de noite tem seis?",
                             "o que eh, o que eh? anda deitado e dorme em pe?",
                             "qual o sobrenome que todo mundo tem?",
                             "quem morre em pe?",
                             "tem cabeca e nao eh gente, tem dente e nao eh pente?",
                             "o que eh que nasce grande e morre pequeno?"
                            };
string respostasFacil[10] = {"balanca", "caldo", "piolho", "mae", "cama", "pe", "costa", "vela", "alho", "lapis"};
string palavrasFacil[10] = {"sob", "vil", "fel", "ceu", "mal", "ver", "ser", "reu", "vao", "paz"};

string perguntasMedio[10] = { "eh nome de mulher e nome de homem. ia mas acabou nao indo?",
                              "quem inventou a fila?",
                              "na televisao cobre um pais; no futebol, atrai a bola; em casa incentiva o lazer. O que eh?",
                              "o que eh que se poes na mesa, parte, reparte mas nao se come?",
                              "dois vizinhos. um nao vai a casa do outro e os dois nao se veem por causa de um morrinho? Quem sao eles?",
                              "o que eh, o que eh? do tamanho de uma bolota e enche a casa ate a porta?",
                              "o que e que quanto mais rugas tem mais novo eh?",
                              "o que eh, o que eh,se voce mudar uma letra em meu nome, ira aparecer o nome do animal que eh meu maior inimigo",
                              "qual a coisa mais veloz do mundo?",
                              "o que eh que corre em volta do pasto inteiro sem se mexer?"
                              };
string respostasMedio[10] = {"isaias","formiga","rede","baralho","olhos","luz","pneu","rato","pensamento","cerca"};
string palavrasMedio[10] = {"empafia", "sensato", "preciso", "morbido", "despota", "alegria", "mitigar", "exilado", "ansioso", "ambicao"};

string perguntasDificil[10] = { "qual a cidade sulamericana que pende nos galhos da arvore?",
                                "tem coroa, mas nao eh rei, tem raiz, mas nao eh planta?",
                                "o que eh, o que eh, nao tem pe e corre, tem leito e nao dorme, quando para,morre?",
                                "o que eh o que eh, uma caixinha de bom parecer, nao ha carpinteiro que saiba fazer?",
                                "o que eh, o que eh? que nao se come, mas eh bom para se comer?",
                                "o que eh, o que eh? que mesmo atravessando o rio, consegue nao se molhar?",
                                "o que eh o que eh: nao tem olhos, mas pisca, nao tem boca, mas comanda?",
                                "o que eh o que eh: quanto mais eu tiro mais eu tenho?",
                                "o que eh que anda com a barriga para tras?",
                                "o que eh, o que eh? me diga se for capaz. me diga quem eh aquele que num instante se quebra se alguem diz o nome dele?"
                              };
string respostasDificil[10] = {"lima","dente","rio","noz","talher","ponte","semaforo","fotografias","perna","silencio"};
string palavrasDificil[10] = {"perspectiva", "significado", "dissimulado", "complacente", "vicissitude", "compreensao", "resiliencia", "contundente", "contingente", "expectativa"};

void telaInicial();
void regras();
void jogar();
int indiceRandomico();
int limiteIndice();
int nivel = 0;
string escolheFrase();
void imprimeCharada();
string crip(string frase, int chave);
string descrip(string frase, int chave);
void mostrarPalavras();
int escolhePalavraFacil();
int escolhePalavraMedio();
int escolhePalavraDificil();
bool verificarResposta(string str1, string str2);
string exibirParteFrase(string fraseCrip, int comeco, int fim);
void imprimePalavrasCrip(int i, int j, string charada, int chave);
string recebeEntradaUsuario(string resposta);
void verificaRespostaDaCharada(string respostaUsuario, string respostaCharada);

int lim = limiteIndice();
string fraseCrip = escolheFrase();
int main()
{
    telaInicial();
    int opcao;
    cin >> opcao;

    if (opcao == 1)
    {
        regras();
    }

    if (opcao == 2)
    {
        jogar();
    }
    return 0;
}

void telaInicial()
{
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

int indiceRandomico()
{
    srand(time(NULL));
    return rand()%29;
}

int limiteIndice()
{
    int indice = indiceRandomico();
    while (indice >= 10)
    {
        indice = indiceRandomico();
    }
    return indice;
}

/* verificacao de nivel para escolha de frases
vini sugeriu deixar o conjunto de frases como um so
*/
string escolheFrase()
{
    string saida = "";
    if(nivel == 0){
        saida = perguntasFacil[lim];
    }else if(nivel == 1){
        saida = perguntasMedio[lim];
    }else if (nivel == 2){
        saida = perguntasDificil[lim];
    }
    return saida;
}

int limiteChave()
{
    int chave = indiceRandomico();
    while (chave >= 26)
    {
        chave = indiceRandomico();
    }
    return chave;
}

void imprimeCharada()
{
    int ch = limiteChave();
    cout << crip(fraseCrip, ch) << endl;

}

void regras()
{
    cout << "Escrever regras";
}

string crip(string frase, int chave)
{

    string rest = "";
    for (int i = 0; i < frase.size(); i++)
    {
        for (int j = 0; j < alfa.size(); j++)
        {
            if (alfa[j] == frase[i])
            {
                if (j + chave >= 26)
                {
                    frase[i] = alfa[j + chave - 26];
                }
                else
                {
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


string descrip(string frase, int chave)
{
    string rest = "";
    for (int i = 0; i < frase.size(); i++)
    {
        for (int j = 0; j < alfa.size(); j++)
        {
            if (alfa[j] == frase[i])
            {
                if (j - chave < 0)
                {
                    frase[i] = alfa[j + chave + 26];
                }
                else
                {
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

void jogar()
{
    imprimeCharada();
    mostrarPalavras();
}

//verificacao de nivel, tentar reduzir o codigo
void mostrarPalavras()
{
    if(nivel == 0){
        string respostaPalavraUsuario;
        string respostaDaCharadaUsuario;
        int chave = limiteChave();
        int j = escolhePalavraFacil();
        int comeco = 0;
        int divisao = fraseCrip.size() / 3;
        int fim = divisao;

        cout << "Descifre as palavras abaixo! (Dica: chave = " << chave << ")" << endl;

        int i = 1;
        int k = 0;
        while(i <= 3){
            string palavra = palavrasFacil[j];
            imprimePalavrasCrip(i, j, palavra,chave);
            cout << descrip(palavra, chave) << endl;
            respostaPalavraUsuario = recebeEntradaUsuario(respostaPalavraUsuario);

            int k = 0;
            int decisao = 0;
            bool respostaCorreta = verificarResposta(descrip(palavra, chave), respostaPalavraUsuario);
            while(k < 3){
                if(respostaCorreta){
                    cout << "Acertou!" << endl;
                    cout << exibirParteFrase(fraseCrip, comeco, fim) << endl;
                    break;
                }else{
                    cout << "Tente outra vez!!!" << endl;
                    respostaPalavraUsuario = recebeEntradaUsuario(respostaPalavraUsuario);
                    respostaCorreta = verificarResposta(descrip(palavra, chave), respostaPalavraUsuario);
                    k++;
                }

                if( k == 3 && !respostaCorreta){
                    cout << "Deseja jogar novamente?(1-Sim, 0-Nao)" << endl;
                    cin >> decisao;
                    if(decisao == 1){
                            jogar();
                    }else{
                        exit(0);
                    }
                }
            }
        }

        comeco = fim + 1;
        fim = comeco + divisao;
        if(fim >= fraseCrip.size()){
            fim = fraseCrip.size() - 1;
        }
        if(comeco >= fraseCrip.size()){
            comeco = fraseCrip.size() - 1;
        }
        i++;
        j++;

        cout << fraseCrip << endl;
        respostaDaCharadaUsuario = recebeEntradaUsuario(respostaDaCharadaUsuario);
        verificaRespostaDaCharada(respostaDaCharadaUsuario, respostasFacil[lim]);

    }else if(nivel == 1){
        string respostaPalavraUsuario;
        string respostaDaCharadaUsuario;
        int chave = limiteChave();
        int j = escolhePalavraMedio();
        int comeco = 0;
        int divisao = fraseCrip.size() / 3;
        int fim = divisao;

        cout << "Descifre as palavras abaixo! (Dica: chave = " << chave << ")" << endl;

        int i = 1;
        int k = 0;
        while(i <= 3){
            string palavra = palavrasMedio[j];
            imprimePalavrasCrip(i, j, palavra,chave);
            cout << descrip(palavra, chave) << endl;
            respostaPalavraUsuario = recebeEntradaUsuario(respostaPalavraUsuario);

            int k = 0;
            int decisao = 0;
            bool respostaCorreta = verificarResposta(descrip(palavra, chave), respostaPalavraUsuario);
            while(k < 3){
                if(respostaCorreta){
                    cout << "Acertou!" << endl;
                    cout << exibirParteFrase(fraseCrip, comeco, fim) << endl;
                    break;
                }else{
                    cout << "Tente outra vez!!!" << endl;
                    respostaPalavraUsuario = recebeEntradaUsuario(respostaPalavraUsuario);
                    respostaCorreta = verificarResposta(descrip(palavra, chave), respostaPalavraUsuario);
                    k++;
                }

                if( k == 3 && !respostaCorreta){
                    cout << "Deseja jogar novamente?(1-Sim, 0-Nao)" << endl;
                    cin >> decisao;
                    if(decisao == 1){
                            jogar();
                    }else{
                        exit(0);
                    }
                }
            }
        }

            comeco = fim + 1;
            fim = comeco + divisao;
            if(fim >= fraseCrip.size()){
                fim = fraseCrip.size() - 1;
            }
            if(comeco >= fraseCrip.size()){
                comeco = fraseCrip.size() - 1;
            }
            i++;
            j++;

            cout << fraseCrip << endl;
            respostaDaCharadaUsuario = recebeEntradaUsuario(respostaDaCharadaUsuario);
            verificaRespostaDaCharada(respostaDaCharadaUsuario, respostasMedio[lim]);
    }else if(nivel == 2){

        string respostaPalavraUsuario;
        string respostaDaCharadaUsuario;
        int chave = limiteChave();
        int j = escolhePalavraDificil();
        int comeco = 0;
        int divisao = fraseCrip.size() / 3;
        int fim = divisao;

        cout << "Descifre as palavras abaixo! (Dica: chave = " << chave << ")" << endl;

        int i = 1;
        int k = 0;
        while(i <= 3){
            string palavra = palavrasDificil[j];
            imprimePalavrasCrip(i, j, palavra,chave);
            cout << descrip(palavra, chave) << endl;
            respostaPalavraUsuario = recebeEntradaUsuario(respostaPalavraUsuario);

            int k = 0;
            int decisao = 0;
            bool respostaCorreta = verificarResposta(descrip(palavra, chave), respostaPalavraUsuario);
            while(k < 3){
                if(respostaCorreta){
                    cout << "Acertou!" << endl;
                    cout << exibirParteFrase(fraseCrip, comeco, fim) << endl;
                    break;
                }else{
                    cout << "Tente outra vez!!!" << endl;
                    respostaPalavraUsuario = recebeEntradaUsuario(respostaPalavraUsuario);
                    respostaCorreta = verificarResposta(descrip(palavra, chave), respostaPalavraUsuario);
                    k++;
                }

                if( k == 3 && !respostaCorreta){
                    cout << "Deseja jogar novamente?(1-Sim, 0-Nao)" << endl;
                    cin >> decisao;
                    if(decisao == 1){
                            jogar();
                    }else{
                        exit(0);
                    }
                }
            }
        }

            comeco = fim + 1;
            fim = comeco + divisao;
            if(fim >= fraseCrip.size()){
                fim = fraseCrip.size() - 1;
            }
            if(comeco >= fraseCrip.size()){
                comeco = fraseCrip.size() - 1;
            }
            i++;
            j++;

            cout << fraseCrip << endl;
            respostaDaCharadaUsuario = recebeEntradaUsuario(respostaDaCharadaUsuario);
            verificaRespostaDaCharada(respostaDaCharadaUsuario, respostasDificil[lim]);
    }
}

int escolhePalavraFacil()
{
    int i = limiteIndice();
    if(i > 7)
    {
        i = limiteIndice();
    }
    return i;
}
// esta igual ao palavra facil pois nao entendi como faz
int escolhePalavraMedio()
{
    int i = limiteIndice();
    if(i > 7)
    {
        i = limiteIndice();
    }
    return i;
}
// esta igual ao palavra facil pois nao entendi como faz
int escolhePalavraDificil()
{
    int i = limiteIndice();
    if(i > 7)
    {
        i = limiteIndice();
    }
    return i;
}

bool verificarResposta(string str1, string str2)
{
    if(str1.compare(str2) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//nao entendi essa parte,onde ta sendo usado string frase?
string exibirParteFrase(string frase, int comeco, int fim)
{
    string parteCrip = "";
    for(int i = comeco; i <= fim; i ++)
    {
        parteCrip = parteCrip + fraseCrip[i];
    }
    return parteCrip;
}

/*
    verificacao de chamada de nivel
    antes era apenas com palavrasFacil
*/
void imprimePalavrasCrip(int i, int j, string charada, int chave)
{
    if(nivel == 0){
        cout << i <<")" << crip(palavrasFacil[j],chave)<< endl;
    }else if(nivel == 1){
        cout << i <<")" << crip(palavrasMedio[j],chave)<< endl;
    }else if(nivel == 2){
        cout << i <<")" << crip(palavrasDificil[j],chave)<< endl;
    }

}

string recebeEntradaUsuario(string resposta)
{
    cout << "Resposta:" << endl;
    cin >> resposta;
    return resposta;
}


//incrementando nivel

void verificaRespostaDaCharada(string respostaUsuario, string respostaCharada){
    int k = 0;
    bool respostaCorreta = verificarResposta(respostaUsuario,respostaCharada);
    while(k < 3){
        if(respostaCorreta){
            nivel += 1;
            cout << "Passar nivel" << endl;
            break;
        }else{
            cout << "Tente outra vez!!!" << endl;
            respostaUsuario = recebeEntradaUsuario(respostaUsuario);
            respostaCorreta = verificarResposta(respostaUsuario,respostaCharada);
            k++;
        }

        int decisao = 0;
        if(k == 3 && !respostaCorreta){
            cout << "Deseja jogar novamente?(1-Sim, 0-Nao)" << endl;
            cin >> decisao;
        if(decisao == 1){
                jogar();
        }else{
            exit(0);
        }
    }
    }
}





