CREATE table aluno(
nome varchar(50),
matricula numeric(4) primary key,
turma numeric (3),
curso varchar(11),
senha varchar (20) not null
);
CREATE TABLE docente(
nome varchar(100),
siape numeric(7) primary key,
senha varchar(20) not null
);
CREATE table representante_turma(
nome varchar(50),
matricula numeric(4) primary key,
turma numeric (3),
curso varchar(11),
senha varchar (20) not null
);
CREATE table coordernador_curso(
nome varchar(50),
curso varchar(11) primary key,
senha varchar (20) not null
);
CREATE TABLE coordenacao_pedagogica(
nome varchar(100),
siape numeric(7) primary key,
senha varchar(20) not null
);
SELECT * FROM ProjetoLP.aluno;
INSERT INTO aluno VALUES ('Gustavo', 6077, 741, 'Informática','12345678');
INSERT INTO aluno VALUES ('José', 1234, 741, 'Informática','12345678'); 
INSERT INTO aluno VALUES ('João', 6050, 141, 'Edificações','12345678');
INSERT INTO aluno VALUES ('Maria', 5891, 631, 'Alimentos','12345678');
INSERT INTO aluno VALUES ('Fernando', 5292, 732, 'Informática', '1234');
INSERT INTO aluno VALUES ('Maria', 5894, 731, 'Informática', '1234');
INSERT INTO aluno VALUES ('Manoel', 5768, 731, 'Informática', '1234');
