#Defina uma função somaQuad(x,y) que calcule a soma dos quadrados de dois números x e y.
def somaQuad (x, y):
    return x*x+y*y

#Crie uma função hasEqHeads(l1,l2) que verifique se as listas l1 e l2 possuem o mesmo primeiro elemento.
def hasEqHeads(l1,l2):
    return l1[0] == l2[0]

#Escreva uma função que receba uma lista de nomes e retorne uma lista com a string "Sr. " adicionada ao início de cada nome.
#Defina uma função auxiliar para ajudar neste exercício.
def addSenhor_aux (texto):
    return "Sr. "+texto

def addSenhor(lista):
    return list(map(addSenhor_aux, lista))

#Crie uma função que receba uma string e retorne o número de espaços nela contidos.
#Defina uma função auxiliar para ajudar neste exercício.
def contaEspaco_aux(texto):
    return texto == ' '

def contaEspaco(lista):
    return sum(list(map(contaEspaco_aux, lista)))

#Escreva uma função que, dada uma lista de números, calcule 3n*2 + 2/n + 1 para cada número n da lista.
#Defina uma função auxiliar para ajudar neste exercício.
def func_aux(x):
    return 3*x*2 + 2/x + 1

def func_princ(lista):
    return list(map(func_aux, lista))

#Escreva uma função que, dada uma lista de números, retorne uma lista com apenas os que forem negativos.
#Defina uma função auxiliar para ajudar neste exercício.
def negativos(x):
    return x<0

def listNegativos(lista):
    return list(filter(negativos, lista))

#Escreva uma função que receba uma lista de números e retorne somente os que estiverem entre 1 e 100, inclusive.
#Defina uma função auxiliar para ajudar neste exercício.
def range(x):
    return x>0 and x<=100

def numeros(lista):
    return list(filter(range, lista))

#Escreva uma função que receba uma lista de números e retorne somente aqueles que forem pares.
#Defina uma função auxiliar para ajudar neste exercício.
def pares(x):
    return x%2==0

def listPar(lista):
    return list(filter(pares, lista))

#Escreva uma função que receba uma lista de strings e retorne uma nova lista com adição de marcações HTML (p.ex.: <B> e </B>) antes e depois de cada string.
def html_aux (texto):
    return "<B> "+texto+" </B>"

def html(lista):
    return list(map(html_aux, lista))
