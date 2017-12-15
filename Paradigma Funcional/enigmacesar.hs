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
    putStrLn $ "Pressione 1 para as regras, 2 para jogar agora!"
    opcao <- getLine
    if (read opcao) == 1
        then do
            Textos.regras
            putStrLn $ "Digite 1 para jogar agora, ou 0 para sair"
            novaOpcao <- getLine
            if (read novaOpcao) == 1
                then jogar
            else
                return ()
    else
        jogar

jogar = do
    let nivel = 1
    mostraCharada nivel

-- falta inserir a parte de mostrar as palavras e
mostraCharada nivel = do
    if nivel > 3 then return ()
    else do    
        indexCharada <- geraIndice 0 (length listaCharadas - 1)
        chave <- geraIndice 1 limiteChave
        let charada = fst (listaCharadas !! indexCharada)
        let resposta = snd (listaCharadas !! indexCharada)
        let cifrada = cifra charada chave        
        putStrLn $ "\n" ++ cifrada ++ " " ++ resposta
        putStrLn $ "Resposta: "
        respostaUsuario <- getLine
        let resultado = respostaUsuario == resposta
        if resultado
            then mostraCharada (nivel+1)
        else do
            putStrLn $ "Você perdeu :/" 

    
-- funcao que gera um indice aleatorio    
geraIndice :: Int -> Int -> IO Int
geraIndice inicio limite = randomRIO(inicio, limite)

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
