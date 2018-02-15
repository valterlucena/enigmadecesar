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

:- initialization(main).

main :-
	telaInicial(),nl,
	regras(),nl,
	desenhaEsfinge,nl,
	halt(0).
