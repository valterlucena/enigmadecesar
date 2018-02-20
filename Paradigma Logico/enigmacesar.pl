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

:- [textos].
:- [charadas].
:- [palavras].

/* Predicado que criptografa uma string a partir do deslocamento D */
crip(L1, D, L2) :-
    string_to_list(L1, R),
	maplist(cifra(D), R, Y),
	string_to_list(L2, Y).

/* Aplica o deslocamento D */
cifra(X, D, Y) :- Y is ((((X - 97) + D) mod 26) + 97). 

/* acessa o elemento associado a um indice */
getElement(0, [E|_], E).
getElement(I, [_|T], R) :- X is I-1, getElement(X, T, R).
    
numero(X) :- random(1, 4, X).

iniciaJogo() :-
	write('Pressione 1 para as regras ou 2 para jogar.'), nl,
	read(Opcao), nl,
	selecao(Opcao). 
	
selecao(1) :- regras().
selecao(2) :- jogar().
selecao(_) :- write('Voce nao leu direito as instrucoes. Reinicie o jogo!'), nl, halt(0).

jogar() :- write('Buceta').

:- initialization(main).

main :-
	telaInicial(),nl,
	desenhaEsfinge(),nl,
	iniciaJogo(), nl,
	halt(0).
