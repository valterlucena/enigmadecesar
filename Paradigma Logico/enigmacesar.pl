/* 	
	ENIGMA DE CESAR
	APLICACOES DE PARADIGMAS DE LINGUAGEM DE PROGRAMACAO - 2017.2 - UFCG
	EQUIPE: ALICE FERNANDES
			ITALO MENEZES
			IVYNA ALVES
			THAIS TOSCANO
			VALTER LUCENA
*/

:- [textos].

/* alfabeto */
alfabeto(_,X) :- X = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'].

/* acessa o elemento associado a um indice */
getElement(0,[H|_], H).
getElement(I,[_|T], R) :- X is I-1, getElement(X,T,R).

:- initialization(main).

main :-
	telaInicial(),nl,
	desenhaEsfinge(),nl,
	regras(),nl,
	halt(0).
