% Prova da OBI2016 - Iniciação Nível 2 - Fase 1

% Código para descobrir o número de quadrados, determinado o número do diagrama.

% Nq = numero de quadrados
% Nd = numero do diagrama

% Fato
quadradosDiag(0, 0).

% Regra
quadradosDiag(Nq, Nd) :-
		Nd > 0,
		Nq is 1+(Nd-1)*4.

% Consulta questão nº 1
% ?- quadradosDiag(X, 4).
% X = 13.

% Consulta questão nº 2
% ?- quadradosDiag(X, 25).
% X = 97.
