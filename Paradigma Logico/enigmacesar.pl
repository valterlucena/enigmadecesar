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
cifra(X, D, Y) :-
	Y is X+D. 
    
numero(X) :- random(1, 4, X).

:- initialization(main).

main :-
	telaInicial(),nl,
	desenhaEsfinge(),nl,
	regras(),nl,
    numero(X), write(X), nl,
    crip(teste, X, Y), write(Y), nl,
	halt(0).
