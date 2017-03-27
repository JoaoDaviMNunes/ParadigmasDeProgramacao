#1- Defina uma função addSuffix(suf,nomes) que retorne a lista de nomes com o sufixo suf adicionado.
def addSuffix(suf, nomes):
    return [x+suf for x in nomes]

#2- Escreva uma função countShorts(words), que receba uma lista de palavras e retorne a quantidade de palavras dessa lista que possuem menos de 5 caracteres.
def countShorts(words):
    return len(list(filter(lambda k: k<5 ,[len(x) for x in words])))

#3- Defina uma função stripVowels(s) que receba uma string e retire suas vogais
def stripVowels(string):
    return ''.join([c for c in string if c not in "aeiouAEIOU"])

#4- Defina uma função hideChars(s) que receba uma string, possivelmente contendo espaços
#Retorne outra string substituindo os demais caracteres por '-', mas mantendo os espaços.
def hideChars(string):
    return ''.join(["-" if x not in " " else " " for x in string])

#5- Defina uma função que receba um número n e retorne uma tabela de números de 1 a n e seus quadrados
def n_e_seuquad(n):
    lis = range(1, n+1)
    return [(n, n*n) for n in lis]

#6- Defina uma função que receba uma lista de palavras e retorne uma string contendo o primeiro e o último caracter de cada palavra da lista.
def inic_e_finais(lista):
    return ''.join([x[0]+x[-1] for x in lista])

#7- Defina uma função myZip(l1,l2) que reproduza o comportamento da função zip do Python
def myZip (l1, l2):
    lis = range(len(l1))
    return [(l1[n], l2[n]) for n in lis]

#8- Escreva uma função enumerate(words) que numere cada palavra da lista recebida
def enumerate(words):
    lis = range(len(words))
    return [(n+1, words[n]) for n in lis]

#9- Escreva uma função isBin(s) que verifique se a string recebida representa um número binário
def isBin(string):
    return len([c for c in string if c in "01"]) == len(string)

#10- Escreva uma função bin2dec(digits), que receba uma lista de dígitos representando um número binário e retorne seu equivalente em decimal.
def bin2dec(digits):
    return int(''.join(str(x) for x in digits), 2)
