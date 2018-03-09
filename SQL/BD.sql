INSERT INTO projeto values ('Projeto Auditoria', 20, 'Salvador', 2); 
insert into trabalha_em values (12345, 10, 30);

select p.NOME from departamento d, projeto p, funcionario f 
where f.Nome = 'João da Silva' and d.NUMERODEP=p.NUMDEP and f.NSS=d.NSSGERENTE; 

select p.NOME from departamento d, projeto p, funcionario f 
where f.Nome = 'João da Silva' and p.NumDep=d.NumeroDep and f.NumDep=p.NUMDEP;

(select p.NOME from departamento d, projeto p, funcionario f 
where f.Nome = 'João da Silva' and d.NUMERODEP=p.NUMDEP and f.NSS=d.NSSGERENTE)
UNION
(select p.NOME from departamento d, projeto p, funcionario f 
where f.Nome = 'João da Silva' and p.NumDep=d.NumeroDep and f.NumDep=p.NUMDEP); 

select NSSEMP from dependente;

select Nome FROM funcionario where NSS NOT IN (SELECT NSSEMP FROM dependente);

SELECT nome FROM funcionario where endereco LIKE '%CENTRO%';

SELECT f.salario*1.1 from funcionario f, trabalha_em t, projeto p 
where p.nome='Projeto Rio de Ondas' and t.nssemp=f.nss and t.numproj=p.numero;

select nome from funcionario where salario >3000;

select nome from funcionario where Salario between 2000 and 30000;

select nome, salario from funcionario order by nome desc;


