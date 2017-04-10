# 1º trace

```
?- avo(joao,Y).
false.
?- avo(roberto,Y).
Y = jose ;
Y = marcos ;
Y = mario.
```

<p>
Regra:<br/>
avo(X, Z) :- pai(X, Y), pai(Y, Z).
</p>
<p>
Objetivo: confirmar que existe um avo X com Z neto(s).
</p>


<p><strong>Primeira questão</strong></p>

```
=> Primeira verificação:
Objetivo: pai(joao, Y).
Y = jose.
1 solução.
=> Segunda verificação:
Objetivo: pai(jose, Z).
Z = [].
0 solução. Falso.
Resultado: False.
(joao não tem netos e, consequentemente, não é avô)
```

<p><strong>Segunda questão</strong></p>

```
=> Primeira verificação:
Objetivo: pai(roberto, Y).
Y = joao;
Y = julio.
2 soluções.
=> Segunda verificação:
Objetivo: pai(joao, Z).
Z = jose.
1 solução.
=> Terceira verificação:
Objetivo: pai(julio, Z).
Z = marcos;
Z = mario.
2 soluções.
Resultado: Y = jose;
Y = marcos;
Y = mario.
(roberto é avô e tem 3 netos - jose, marcos e mario)
```

# 2º trace

```
?- azulejos(120,A).
```

<p>
Regra:<br/>

azulejos(0,0).<br/>
azulejos(Na,Nq) :
   Na > 0,
   Q is floor(sqrt(Na)),
   R is Na - Q*Q,
   azulejos(R,C),
   Nq is 1 + C.
</p>   
<p>
Objetivo: descobrir quantos quadrados eu faço com X azulejos.
</p>

```
=> 1a verificação:
Objetivo: Na > 0.
120 > 0. (true)
=> 2a verificação:
Objetivo: Q is floor(sqrt(Na)).
Q is 10. (numero inteiro da raiz quadrada de Na)
=> 3a verificação:
Objetivo: R is Na - Q*Q.
R is 120-100. R is 20.
=> 4a verificação:
Objetivo: azulejos(R,C).
azulejos(20, C). (recursão)
=> 5a verificação:
Objetivo: Na > 0.
20 > 0. (true)
=> 6a verificação:
Objetivo: Q is floor(sqrt(Na)).
Q is 4. (numero inteiro da raiz quadrada de Na)
=> 7a verificação:
Objetivo: R is Na - Q*Q.
R is 20-16. R is 4.
=> 8a verificação:
Objetivo: azulejos(R,C).
azulejos(4, C). (recursão)
=> 9a verificação:
Objetivo: Na > 0.
4 > 0. (true)
=> 10a verificação:
Objetivo: Q is floor(sqrt(Na)).
Q is 2. (numero inteiro da raiz quadrada de Na)
=> 11a verificação:
Objetivo: R is Na - Q*Q.
R is 4-4. R is 0.
=> 12a verificação:
Objetivo: azulejos(R,C).
azulejos(0, C). (recursão)
=> 13a verificação:
Objetivo: Na > 0.
0 > 0. (false).
=> 14a verificação:
Objetivo: Nq is 1+0. Nq is 1. (volta pra função anterior)
=> 15a verificação:
Objetivo: Nq is 1+1. Nq is 2. (volta pra função anterior)
=> 16a verificação:
Objetivo: Nq is 1+2. Nq is 3. (volta pra função anterior)
Resultado: Nq = 3.
(120 azulejos formam 3 quadrados)
```

# 3º trace

```
?- sum([1,2,3,4],S).
S = 10.
```

<p>
Regra:<br/>
sum([],0).<br/>
sum([H|T], S) :-
sum(T, S1),
S is H + S1.
</p>
<p>
Objetivo: calcular a soma dos elementos da lista.
</p>

```
=> 1a verificação:
Objetivo: sum([2, 3, 4], S1). (recursão)
=> 2a verificação:
Objetivo: sum([3, 4], S1). (recursão)
=> 3a verificação:
Objetivo: sum([4], S1). (recursão)
=> 4a verificação:
Objetivo: sum([], S1).
Regra -> sum([], 0). S1 = 0.
=> 5a verificação:
Objetivo: S is 4+0. S is 4. (volta pra função anterior)
=> 6a verificação:
Objetivo: S is 3+4. S is 7. (volta pra função anterior)
=> 7a verificação:
Objetivo: S is 2+7. S is 9. (volta pra função anterior)
=> 8a verificação:
Objetivo: S is 1+9. S is 10. (volta pra função anterior)
Resultado: S = 10.
(a soma dos elementos da lista é 10)
```
