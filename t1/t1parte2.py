#Escreva uma função que receba uma lista de nomes e retorne uma lista com a string "Sr. " adicionada ao início de cada nome.
def anom_Sr (lista):
    return list(map(lambda x:"Sr. "+x, lista))

#Escreva uma função que, dada uma lista de números, calcule 3n*2 + 2/n + 1 para cada número n da lista.
def anom_func (lista):
    return list(map(lambda x:(3*x*2)+(2/n)+1, lista))

#Crie uma função que receba uma lista de nomes e retorne outra lista com somente aqueles nomes que terminarem com a letra 'a'.
def anom_finalA (lista):
    return list(filter(lambda x:x[-1] == 'a', lista))

#Escreva uma função que, dada uma lista de idades de pessoas no ano atual, retorne uma lista somente com as idades de quem nasceu depois de 1970.
#Para testar a condição, sua função deverá subtrair a idade do ano atual.
def anom_ano (lista):
    return list(filter(lambda x:x<(2017-1970), lista))

#O código abaixo é escrito em Python imperativo. Escreva um código equivalente usando programação funcional.
#numbers = [1, 2, 3, 4]
#new_numbers = []
#for number in numbers:
# new_numbers.append(number * 2)
#print(new_numbers)
def numeros(lista):
    return list(map(lambda x: x*2, lista))
