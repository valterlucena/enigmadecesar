{-
    ENIGMA DE CESAR
    APLICACOES DE PARADIGMAS DE LINGUAGEM DE PROGRAMACAO - 2017.2 - UFCG
    EQUIPE: ALICE FERNANDES
            ITALO MENEZES
            IVYNA ALVES
            THAIS TOSCANO
            VALTER LUCENA

-}

-- imports
import System.Random
import Charadas
import Textos
import Data.Char

-- botar aqui as constantes --
listaCharadas = Charadas.charadas
limiteChave = 4


-- funcao principal
main = do
    Textos.telaInicial
    Textos.desenhaEsfinge
    putStrLn "Pressione 1 para as regras, 2 para jogar agora!"
    opcao <- getLine
    if (read opcao) == 1
        then do
            Textos.regras
            putStrLn "Digite 1 para jogar agora, ou 0 para sair"
            novaOpcao <- getLine
            if (read novaOpcao) == 1
                then jogar
            else
                return ()
    else
        jogar

jogar = do
    mostraCharada

-- ta sebozinho ainda mas funciona, depois modifico
mostraCharada = do
    aleatorio <- geraIndice (length listaCharadas - 1)
    let charada = fst (listaCharadas !! aleatorio)
    chave <- geraIndice limiteChave
    let cifrada = cifra charada chave
    print $ cifrada
    print $ cifra cifrada (0-chave)

    
-- funcao que gera um indice aleatorio    
geraIndice :: Int -> IO Int
geraIndice limite = randomRIO(0, limite)

-- funcoes para nao deixar que os caracteres saiam do escopo [a..z]
letraPNum :: Char -> Int
letraPNum letra = ord letra - ord 'a'

numPLetra :: Int -> Char
numPLetra num = chr (num + ord 'a')

-- funcao para fazer o descolamento de uma letra
desloca :: Char -> Int -> Char
desloca letra desloc
    | (isAlpha letra) = numPLetra (( letraPNum (toLower letra) + desloc) `mod` 26)
    | otherwise = letra

-- cifra de cesar
cifra :: String -> Int -> String
cifra palavra desloc = [desloca palav desloc | palav <- palavra]
