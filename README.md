## Enigma de César

Projeto desenvolvido para a disciplina de aplicações de paradigmas de programação na UFCG, no qual o objetivo é mostra o jogo enigma de césar funcionando da mesma forma, em três paradigmas diferentes, sendo eles com suas respectivas linguagens:

  - Imperativo: C++
  - Funcional: Haskell
  - Lógico: Prolog

### Como funciona:
O jogo enigma de césar tem o objetivo de estimular o jogador a acertas charadas que a esfinge propôe. No entanto, para dificultar estas charadas estão criptografas, utilizando criptografia de césar. 
##### Mas como faço para descriptografar a charadas? 
Ao longo de cada nível, é fornecido aleatoriamente ao jogador, palavras criptografas com sua respectiva chave para descriptografá-la e a cada acerto, é liberada uma parte da frase criptografada. E ao final, quando o enigma está totalmente descriptografado o jogador tem a chance de responder ao enigma que a esfinge propôs.

### Como executar:
##### C++
##
```sh
cd 'Paradigma Imperativo'/
g++ enigmacesar.cpp -o enigmacesar
./enigmacesar
```
##### Haskell
##
```sh
cd 'Paradigma Funcional'/
g++ enigmacesar.hs
./enigmacesar
```
##### Prolog
##
```sh
cd 'Paradigma Logico'/
swipl enigmacesar.pl
```

