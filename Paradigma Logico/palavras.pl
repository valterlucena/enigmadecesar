

facil(_, A) :- A = ["sob","vil","fel","ceu","mal","ver","ser","reu","vao","paz","boi","pau","des","fim","mes","fez","sal","jaz","seu","rei","jus","via","veu","pai","van","asa","som","rir"].

medio(_, B) :- B = ["empafia","sensato","preciso","morbido","despota","alegria","mitigar","exilado","ansioso","ambicao","legado","formal","dadiva","difuso","escusa","idiota","gentil","comico","habito", "ocioso","remoto","sobrio","asseio","etereo","objeto","agonia","acesso","vulgar","buscar", "esteio"].

dificil(_, C) :- C = ["perspectiva", "significado", "dissimulado","complacente","vicissitude","compreensao","resiliencia","contundente","contingente","expectativa","prudencia","sapiencia","excelente","excedente","individuo","suplantar","arcabouco","discorrer","mesquinho","restricao","espontaneo","pernostico","transeunte","proposicao","inferencia","consolidar","sintetizar","constituir","restringir","maturidade"].

:- initialization(main).

main :- 
	facil(0,A),
	write(A).
