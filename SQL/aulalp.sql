-- phpMyAdmin SQL Dump
-- version 3.4.5
-- http://www.phpmyadmin.net
--
-- Servidor: localhost
-- Tempo de Geração: 14/02/2017 às 14h06min
-- Versão do Servidor: 5.5.16
-- Versão do PHP: 5.3.8

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Banco de Dados: `aulalp`
--

-- --------------------------------------------------------

--
-- Estrutura da tabela `departamento`
--

CREATE TABLE IF NOT EXISTS `departamento` (
  `NOME` varchar(50) NOT NULL,
  `NUMERODEP` int(11) NOT NULL,
  `NSSGERENTE` decimal(5,0) DEFAULT NULL,
  PRIMARY KEY (`NUMERODEP`),
  KEY `NSSGERENTE` (`NSSGERENTE`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `departamento`
--

INSERT INTO `departamento` (`NOME`, `NUMERODEP`, `NSSGERENTE`) VALUES
('DEPARTAMENTO DE PESQUISA', 1, NULL),
('DEPARTAMENTO FINANCEIRO', 2, '12345');

-- --------------------------------------------------------

--
-- Estrutura da tabela `dependente`
--

CREATE TABLE IF NOT EXISTS `dependente` (
  `NOME` varchar(50) NOT NULL,
  `NSSEMP` decimal(5,0) NOT NULL DEFAULT '0',
  `DATANASC` date DEFAULT NULL,
  `PARENTESCO` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`NOME`,`NSSEMP`),
  KEY `NSSEMP` (`NSSEMP`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `dependente`
--

INSERT INTO `dependente` (`NOME`, `NSSEMP`, `DATANASC`, `PARENTESCO`) VALUES
('Joãozinho da Silva', '12345', '2016-06-01', 'Filho');

-- --------------------------------------------------------

--
-- Estrutura da tabela `funcionario`
--

CREATE TABLE IF NOT EXISTS `funcionario` (
  `Nome` varchar(60) NOT NULL,
  `NSS` decimal(5,0) NOT NULL,
  `DataNasc` date DEFAULT NULL,
  `Endereco` varchar(100) DEFAULT NULL,
  `Salario` float DEFAULT NULL,
  `NumDep` int(11) DEFAULT NULL,
  PRIMARY KEY (`NSS`),
  KEY `NumDep` (`NumDep`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `funcionario`
--

INSERT INTO `funcionario` (`Nome`, `NSS`, `DataNasc`, `Endereco`, `Salario`, `NumDep`) VALUES
('Maria Joaquina', '11111', '1980-05-02', 'Avenida Y, Nº 9, Barreirinhas', 24000, 1),
('João da Silva', '12345', '1960-05-02', 'Avenida X, Nº 7, Centro', 3000, 1);

-- --------------------------------------------------------

--
-- Estrutura da tabela `livros`
--

CREATE TABLE IF NOT EXISTS `livros` (
  `isbn` int(11) NOT NULL,
  `titulo` varchar(60) DEFAULT NULL,
  `autor` varchar(40) DEFAULT NULL,
  `categoria` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`isbn`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `livros`
--

INSERT INTO `livros` (`isbn`, `titulo`, `autor`, `categoria`) VALUES
(1, 'Java 7: Ensino Didático', 'Deitel', 'Informática'),
(2, 'Banco de Dados', 'Navathe', 'Informática');

-- --------------------------------------------------------

--
-- Estrutura da tabela `projeto`
--

CREATE TABLE IF NOT EXISTS `projeto` (
  `NOME` varchar(50) NOT NULL,
  `NUMERO` int(11) NOT NULL,
  `LOCALIZAÇÃO` varchar(80) DEFAULT NULL,
  `NUMDEP` int(11) DEFAULT NULL,
  PRIMARY KEY (`NUMERO`),
  KEY `NUMDEP` (`NUMDEP`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `projeto`
--

INSERT INTO `projeto` (`NOME`, `NUMERO`, `LOCALIZAÇÃO`, `NUMDEP`) VALUES
('Projeto Rio de Ondas', 10, 'Barreiras', 1);

-- --------------------------------------------------------

--
-- Estrutura da tabela `trabalha_em`
--

CREATE TABLE IF NOT EXISTS `trabalha_em` (
  `NSSEMP` decimal(5,0) NOT NULL DEFAULT '0',
  `NUMPROJ` int(11) NOT NULL DEFAULT '0',
  `HORAS` int(11) DEFAULT NULL,
  PRIMARY KEY (`NSSEMP`,`NUMPROJ`),
  KEY `NUMPROJ` (`NUMPROJ`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estrutura da tabela `usuarios`
--

CREATE TABLE IF NOT EXISTS `usuarios` (
  `login` varchar(10) NOT NULL,
  `senha` varchar(8) DEFAULT NULL,
  `nome` varchar(60) DEFAULT NULL,
  `email` varchar(20) DEFAULT NULL,
  `cidade` varchar(30) DEFAULT NULL,
  `estado` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`login`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `usuarios`
--

INSERT INTO `usuarios` (`login`, `senha`, `nome`, `email`, `cidade`, `estado`) VALUES
('kari', '', 'Karine do Prado Ribeiro', 'karinepr@gmail.com', 'Barreiras', 'Bahia'),
('rafa', 'rafa', 'Rafael', 'rafael@gmail.com', 'Barreiras', 'Bahia');

--
-- Restrições para as tabelas dumpadas
--

--
-- Restrições para a tabela `departamento`
--
ALTER TABLE `departamento`
  ADD CONSTRAINT `departamento_ibfk_1` FOREIGN KEY (`NSSGERENTE`) REFERENCES `funcionario` (`NSS`);

--
-- Restrições para a tabela `dependente`
--
ALTER TABLE `dependente`
  ADD CONSTRAINT `dependente_ibfk_2` FOREIGN KEY (`NSSEMP`) REFERENCES `funcionario` (`NSS`),
  ADD CONSTRAINT `dependente_ibfk_1` FOREIGN KEY (`NSSEMP`) REFERENCES `funcionario` (`NSS`);

--
-- Restrições para a tabela `funcionario`
--
ALTER TABLE `funcionario`
  ADD CONSTRAINT `funcionario_ibfk_1` FOREIGN KEY (`NumDep`) REFERENCES `departamento` (`NUMERODEP`);

--
-- Restrições para a tabela `projeto`
--
ALTER TABLE `projeto`
  ADD CONSTRAINT `projeto_ibfk_1` FOREIGN KEY (`NUMDEP`) REFERENCES `departamento` (`NUMERODEP`);

--
-- Restrições para a tabela `trabalha_em`
--
ALTER TABLE `trabalha_em`
  ADD CONSTRAINT `trabalha_em_ibfk_3` FOREIGN KEY (`NSSEMP`) REFERENCES `funcionario` (`NSS`),
  ADD CONSTRAINT `trabalha_em_ibfk_1` FOREIGN KEY (`NSSEMP`) REFERENCES `funcionario` (`NSS`),
  ADD CONSTRAINT `trabalha_em_ibfk_2` FOREIGN KEY (`NUMPROJ`) REFERENCES `projeto` (`NUMERO`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
