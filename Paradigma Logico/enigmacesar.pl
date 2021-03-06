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
    
geraChave(X) :- random(1, 4, X).
geraIndice(Limite, Indice) :- random(0, Limite, Indice).

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
			
jogar(Nivel) :- mostraCharada(Nivel,RespostaDaCharada).


mostraCharada(Nivel, _) :- Nivel > 3, writeln('Parabens! Voce finalizou o jogo!'), halt(0).
mostraCharada(Nivel, RespostaDaCharada) :- charadas(D), length(D, Limite),
			geraIndice(Limite, IndiceCharada),
			getElement(IndiceCharada,D,(Charada, RespostaDaCharada)),
			geraChave(Chave),
			crip(Charada, Chave, Criptografada),
			write('Nivel '), write(Nivel), nl, nl,
			writeln(Criptografada),
			mostraPalavra(Nivel, 1, Chave, Charada, RespostaDaCharada).			
			
mostraPalavra(Nivel, Controle, Chave, Charada, RespostaDaCharada) :- Controle > 3, 
			write('Digite resposta: '), 
			read(R1), 
			atom_string(R1, SR),
			atom_string(RespostaDaCharada, SResposta),
			acertouCharada(SResposta, SR),
			NovoNivel is Nivel + 1, 
			mostraCharada(NovoNivel, _).


mostraPalavra(Nivel, Controle, ChaveCharada, Charada, RespostaDaCharada) :- nivel(Nivel,Palavras),
			length(Palavras, Limite),
			geraIndice(Limite, IndicePalavra),
			getElement(IndicePalavra,Palavras,Palavra),
			geraChave(ChavePalavra),
			crip(Palavra, ChavePalavra, PalavraCrip),
			Reverte is (0 - ChavePalavra), crip(PalavraCrip, Reverte, Resp), /*apagar depois, e a resposta v tbm*/
			write(Controle), write(') '), write(PalavraCrip), nl,
			write('Dica: Chave = '), write(ChavePalavra),nl,
			read(R1),
			atom_string(R1, RespostaDaPalavra),
			atom_string(Palavra, SPalavra),
			acertouPalavra(SPalavra, RespostaDaPalavra, Controle, ChaveCharada, Charada),
			NovoControle is Controle + 1,
			mostraPalavra(Nivel, NovoControle, ChaveCharada, Charada, RespostaDaCharada).


result(S1, S2, R) :- atom_string(S1, R1), atom_string(S2, R2), (R1 == R2 -> R = 1; R = 0).

acertouPalavra(S, S, Controle, Chave, Charada) :- 
			crip(Charada, Chave, Criptografada),
			string_length(Charada, Tamanho),
			Pedaco is ceiling(Controle * (Tamanho/3)),
			Resto is (Tamanho - Pedaco),
			sub_string(Charada, 0, Pedaco, Resto, SubCharada),
			sub_string(Criptografada, Pedaco, Resto, 0, SubCrip),
			string_concat(SubCharada, SubCrip, Nova),
			writeln(Nova).
			
acertouPalavra(S, _, _, _, _) :- writeln('Voce perdeu!. Digite 0 para encerrar ou 2 para jogar novamente.'),
			read(Opcao), selecao(Opcao).

acertouCharada(S, S) :- writeln("Parabens!"), nl.
acertouCharada(S, _) :- writeln('Voce perdeu!. Digite 0 para encerrar ou 2 para jogar novamente.'),
			read(Opcao), selecao(Opcao).
			

:- initialization(main).

main :-
	telaInicial(),nl,
	desenhaEsfinge(),nl,
	iniciaJogo(), nl,
	halt(0).
	
	

