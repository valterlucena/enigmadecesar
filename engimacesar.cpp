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

// 0 tbm eh indice do array
int ultimoIndice = -1;

string charadas[100] = {"mantem sempre o mesmo tamanho, nao importa o peso?",
                             "o que detestamos na praia e adoramos na panela?",
                             "o que eh que anda com os pe na cabeca?",
                             "o que eh, o que eh? que eh irma de minha tia e nao eh minha tia?",
                             "o que eh, o que eh? de dia tem quatro pes e de noite tem seis?",
                             "o que eh, o que eh? anda deitado e dorme em pe?",
                             "qual o sobrenome que todo mundo tem?",
                             "quem morre em pe?",
                             "tem cabeca e nao eh gente, tem dente e nao eh pente?",
                             "o que eh que nasce grande e morre pequeno?",
                             "eh nome de mulher e nome de homem. ia mas acabou nao indo?",
                             "quem inventou a fila?",
                             "na televisao cobre um pais; no futebol, atrai a bola; em casa incentiva o lazer. O que eh?",
                             "o que eh que se poe na mesa, parte, reparte mas nao se come?",
                             "dois vizinhos. um nao vai a casa do outro e os dois nao se veem por causa de um morrinho? Quem sao eles?",
                             "o que eh, o que eh? do tamanho de uma bolota e enche a casa ate a porta?",
                             "o que e que quanto mais rugas tem mais novo eh?",
                             "o que eh, o que eh,se voce mudar uma letra em meu nome, ira aparecer o nome do animal que eh meu maior inimigo",
                             "qual a coisa mais veloz do mundo?",
                             "o que eh que corre em volta do pasto inteiro sem se mexer?",
                             "qual a cidade sulamericana que pende nos galhos da arvore?",
                             "tem coroa, mas nao eh rei, tem raiz, mas nao eh planta?",
                             "o que eh, o que eh, nao tem pe e corre, tem leito e nao dorme, quando para,morre?",
                             "o que eh o que eh, uma caixinha de bom parecer, nao ha carpinteiro que saiba fazer?",
                             "o que eh, o que eh? que nao se come, mas eh bom para se comer?",
                             "o que eh, o que eh? que mesmo atravessando o rio, consegue nao se molhar?",
                             "o que eh o que eh: nao tem olhos, mas pisca, nao tem boca, mas comanda?",
                             "o que eh o que eh: quanto mais eu tiro mais eu tenho?",
                             "o que eh que anda com a barriga para tras?",
                             "o que eh, o que eh? me diga se for capaz. me diga quem eh aquele que num instante se quebra se alguem diz o nome dele?",
                             "o que eh, o que eh, que entra na agua e nao se molha?",
							 "o que eh, o que eh, de dia tem quatro pes e de noite tem seis?",
							 "o que eh, o que eh, quanto mais se tira mais aumenta?",
							 "o que eh, o que eh, uma casinha branca sem tranca e sem janela?",
							 "o que eh, o que eh, tem asa mas nao voa, tem bico mas nao bica?",
							 "o que eh, o que eh, quanto mais se seca, mais molhada fica?",
							 "o que eh, o que eh, da um pulo e se veste de noiva?",
							 "o que eh, o que eh, que eh meu, mas meus amigos usam mais do que eu?",
							 "o que eh, o que eh, quanto mais a gente perde, com mais a gente fica?",
							 "o que eh, o que eh, uma comida que liga e desliga?",
							 "o que eh, o que eh, quanto mais se tira mais a gente tem?",
							 "o que eh, o que eh, cai de pe e corre deitado?",
							 "o que eh, o que eh, quanto mais ruga tem, mais novo eh?",
							 "o que eh, o que eh, sempre anda sempre com os pe na cabe?",
							 "o que eh, o que eh, fica cheio de boca para baixo e vazio de boca para cima?",
							 "o que eh, o que eh, nasce grande e morre pequeno?",
							 "o que eh, o que eh, nos matamos quando esta nos matando?",
							 "o que eh, o que eh, se poes na mesa, parte, reparte mas nao se come?",
							 "o que eh, o que eh, irma de minha tia e nao eh minha tia?",
							 "o que eh, o que eh, tem capa mas nao eh superhomem, tem folha mas nao eh arvore, tem orelha mas nao eh gente, e eh surdo mas conta tudo?",
							 "o que eh, o que eh, quando parte uma partem as duas, quando chega uma chegam as duas?",
							 "o que eh, o que eh, que pesa mais no mundo?",
							 "o que eh, o que eh, tem coroa mas nao eh rei, tem espinho mas n?eh peixe?",
							 "qual eh a parte do carro que se originou no antigo egito?",
							 "quem eh que bate na porta sem estar chamando ninguem?",
							 "qual o lugar onde o pescador pode ate escolher o peixe?",
							 "quem eh que se encarrega pessoalmente de transmitir os nossos desabafos, as nossas alegrias, exigencias e consulta sem jamais ter contato conosco?",
							 "qual a protese que vive durante um longo periodo?",
							 "qual o pais que sai pegando tudo?",
							 "qual pais do caribe eh uma explosao?",
							 "qual a planta dos sentimentos imediatos?",
							 "quanto menos luz mais eu apare? quem eu sou?",
							 "qual eh o super heroi preferido dos gordinhos?",
							 "o que se quebra sem nem mesmo tocar?",
							 "o rapaz terminou com a garota e depois voltou com ela, qual eh o nome do filme?",
							 "o que so pode ser usado quebrado?",
							 "o que eh algo e ao mesmo tempo nada?",
							 "qual o pais que distribui cana de acucar?",
							 "quem sempre casa mas continua solteiro?",
							 "o que esta na sua frente mas voce nao ve?",
							 "quais sao as mulheres que vivem mais tempo que os maridos?",
							 "o que tem cara mas nao eh homem, tem coroa mas nao eh rei?",
							 "o que todo mundo precisa, todo mundo pede, todo mundo da, mas ninguem segue?",
							 "o que so cresce para tras?",
							 "qual eh a pedra que danca?",
							 "o que tem uma perna longa e a outra perna curta, mas anda sem parar o dia todo?",
							 "o rio amazonas esta em qual estado?",
							 "o que eh o que eh voa sem ter asas e chora sem ter olhos?"
							 "qual eh o pais que cabe na geladeira?",
							 "o que eh, o que eh, tem pernas, mas nao anda. tem braco, mas nao abraca?",
							 "o que sao duas irmas, uma no lado direito e outra no lado esquerdo, que escutam muito bem?",
							 "o que eh o que eh, duas irmas da mesma idade, mas com diferentes habilidades?",
							 "que tipo de barba tem um tubarao",
							 "qual lugar mais certo do brasil?",
							 "eh um passaro brasileiro e seu nome de tras para frente eh igual.",
							 "mantem sempre o mesmo tamanho, nao importa o peso?",
							 "o que detestamos na praia e adoramos na panela?",
							 "o que eh, o que eh? anda deitado e dorme em pe?",
							 "qual o sobrenome que todo mundo tem?",
							 "quem morre em pe?",
							 "tem cabeca e nao eh gente, tem dente e nao eh pente?",
							 "eh nome de mulher e nome de homem. ia mas acabou nao indo?",
							 "quem inventou a fila?",
							 "na televisao cobre um pais; no futebol, atrai a bola; em casa incentiva o lazer. O que eh?",
							 "dois vizinhos. um nao vai a casa do outro e os dois nao se veem por causa de um morrinho? Quem sao eles?",
							 "o que eh, o que eh? do tamanho de uma bolota e enche a casa ate a porta?",
							 "o que eh, o que eh,se voce mudar uma letra em meu nome, ira aparecer o nome do animal que eh meu maior inimigo",
							 "qual a coisa mais veloz do mundo?",
							 "o que eh que corre em volta do pasto inteiro sem se mexer?",
							 "qual a cidade sulamericana que pende nos galhos da arvore?",
							 "tem coroa, mas nao eh rei, tem raiz, mas nao eh planta?"
                        };

string respostas[101] = {"balanca", "caldo", "piolho", "mae", "cama", "pe", "costa", "vela", "alho", "lapis",
								"isaias","formiga","rede","baralho","olhos","luz","pneu","rato","pensamento","cerca",
                                "lima","dente","rio","noz","talher","ponte","semaforo","fotografias","perna","silencio",
								 "sombra","cama","buraco","ovo","bule","toalha","pipoca","nome","sono","strogonoff","fotografia",
								 "chuva","pneu","piolho","chapeu","lapis","fome","baralho","mae","livro","pernas","balanca",
								 "abacaxi","faraois","marceneiro","peixaria","carteiro","dentadura","catar","granada",
								 "jacinto","escuridao","supermercado","promessa","exterminador","ovo","peixe","canada",
								 "padre","futuro","viuvas","moedas","conselho","fila","arrocha","relogio","liquido","nuvem",
								 "peru","cadeira","orelhas","maos","barbatana","sertao","arara","balanca","caldo","pe","costa",
								 "vela","alho","isaias","formiga","rede","olhos","luz","rato","pensamento","cerca","lima","dente"
								 };


string palavrasFacil[10] = {"sob", "vil", "fel", "ceu", "mal", "ver", "ser", "reu", "vao", "paz"};
string palavrasMedio[10] = {"empafia", "sensato", "preciso", "morbido", "despota", "alegria", "mitigar", "exilado", "ansioso", "ambicao"};
string palavrasDificil[10] = {"perspectiva", "significado", "dissimulado", "complacente", "vicissitude", "compreensao", "resiliencia", "contundente", "contingente", "expectativa"};

void desenhaEsfinge();
void jogar();

void telaInicial();
void regras();
int indiceRandomico();
bool verificaUltimoIndice(int index) {
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
    cout << "'------------------------------------------------------------------------'" << endl;
    
    desenhaEsfinge();
}

void desenhaEsfinge() {
	cout << "			" << "        --------   " << endl;
	cout << "			" << "     --------------" << endl;
	cout << "			" << "   ---------|--------" << endl;
	cout << "			" << "  --- | | | | | | | ---" << endl;
	cout << "			" << " -----| | | | | | |-----" << endl;
	cout << "			" << "-------           -------   " << endl;
	cout << "			" << "-------   0   0   -------  " << endl;
	cout << "			" << "-------     |     -------  " << endl;
	cout << "			" << " ------     ~     ------  " << endl;
	cout << "			" << "  -----   _____   ----- " << endl;
	cout << "			" << "   ---     ___    ---" << endl;
	cout << "			" << "   ---     ___    ---" << endl;
	cout << "			" << "    --      _     --" << endl;
	
}

void regras() {
	cout << ".------------------------------------------------------------------------." << endl;
	cout << "|                                                                        |" << endl;
	cout << "|                                Regras                                  |" << endl;
	cout << "|                                                                        |" << endl;
	cout << "| 1. Para decifrar a mensagem da esfinge, decifre primeiro tres palavras |" << endl;
	cout << "| 2. A cada palavra decifrada, um terco da mensagem original eh revelada |" << endl;
	cout << "| 3. Apos revelada a mensagem, responda a pergunta que a esfinge fez     |" << endl;
	cout << "| 4. Voce possuira apenas tres chances!                                  |" << endl;
	cout << "| 5. Use as dicas a seu favor! Por exemplo, se a palavra a ser decifrada |" << endl;
	cout << "|    for 'xgw', e a chave for igual a 2, troque cada letra pela que esta |" << endl;
	cout << "|    2 posicoes atras       .                                            |" << endl;
	cout << "|    Como resultado, voce obtera 'veu' como resposta.                    |" << endl;
	cout << "| 6. Utilize apenas letras minusculas, sem acentuacao.                   |" << endl;
	cout << "|                                                                        |" << endl;
	cout << "'------------------------------------------------------------------------'" << endl;
 }


int indiceRandomico()
{
    srand(time(NULL));
    return rand()%31;
}

/**
    Verifica se o inteiro passado é igual ao indice referente a ultima charada mostrada
**/
bool verificaUltimoIndice(int index) {
    return index == ultimoIndice;
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

/**
    Criptografa uma string usando o deslocamento definido pela chave
**/
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



/**
    Descriptografa uma string usando o deslocamente definido pela chave
**/
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





