/* 	
	ENIGMA DE CESAR
	APLICACOES DE PARADIGMAS DE LINGUAGEM DE PROGRAMACAO - 2017.2 - UFCG
	EQUIPE: ALICE FERNANDES
			ITALO MENEZES
			IVYNA ALVES
			THAIS TOSCANO
			VALTER LUCENA
*/

:- use_module(library(apply)).
:- use_module(library(random)).
:- use_module(library(ctypes)).

:- [textos].
:- [charadas].
:- [palavras].

/* Predicado que criptografa uma string a partir do deslocamento D */
crip(L1, D, L2) :-
    string_to_list(L1, R),
	maplist(cifra(D), R, Y),
	string_to_list(L2, Y).

/* Aplica o deslocamento D */
cifra(D, X, Y) :- string_to_list(C, [X]), (is_alpha(C) -> Y is ((((X - 97) + D) mod 26) + 97) ; Y is X).


/* acessa o elemento associado a um indice */
getElement(0, [E|_], E).
getElement(I, [_|T], R) :- X is I-1, getElement(X, T, R).
    
geraAleatorio(X) :- random(1, 4, X).

iniciaJogo() :-
	write('Pressione 1 para as regras ou 2 para jogar.'), nl,
	read(Opcao), nl,
	selecao(Opcao). 

selecao(0) :- write('Voce encerrou o jogo'), nl, halt(0).
selecao(1) :- regras(), nl, write('Pressione 2 para jogar, ou 0 para sair do jogo'), nl, read(Opcao), selecao(Opcao).
selecao(2) :- jogar(1).
selecao(_) :- write('Voce nao leu direito as instrucoes. Reinicie o jogo!'), nl, halt(0).

nivel(1,X) :- facil(X).
nivel(2,X) :- medio(X).
nivel(3,X) :- dificil(X).

jogar(X) :- X > 3, writeln('Digite 2 para jogar novamente ou 0 para encerrar o jogo.'),
			read(Opcao), selecao(Opcao).
			
jogar(Nivel) :- mostraCharada(Nivel).

mostraCharada(Nivel) :- charadas(D),
			/* parte da charada */
			geraAleatorio(IndiceCharada),
			getElement(IndiceCharada,D,(Charada, Resposta)),
			geraAleatorio(Chave),
			crip(Charada, Chave, Criptografada),
			writeln(Criptografada),
			mostraPalavra(Nivel, 1).
			
			
mostraPalavra(_, Controle) :- Controle > 3, halt(0).
mostraPalavra(Nivel, Controle) :- nivel(Nivel,Palavras),
			geraAleatorio(IndicePalavra),
			getElement(IndicePalavra,Palavras,Palavra),
			geraAleatorio(ChavePalavra),
			crip(Palavra, ChavePalavra, PalavraCrip),
			write(Controle), write(') '), write(PalavraCrip),nl,
			write('Dica: Chave = '), write(ChavePalavra),nl,
			read(Resposta),
			result(Palavra, Resposta, R), writeln(R),
			NovoControle is Controle + 1,
			mostraPalavra(Nivel,NovoControle).


result(S1, S2, R) :- atom_string(S1, R1), atom_string(S2, R2), (R1 == R2 -> R = 'oi'; R = 'cu').

:- initialization(main).

main :-
	telaInicial(),nl,
	desenhaEsfinge(),nl,
	iniciaJogo(), nl,
	halt(0).
