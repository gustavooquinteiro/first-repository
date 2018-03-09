-- phpMyAdmin SQL Dump
-- version 4.0.4
-- http://www.phpmyadmin.net
--
-- Máquina: localhost
-- Data de Criação: 14-Fev-2017 às 13:51
-- Versão do servidor: 5.6.12-log
-- versão do PHP: 5.4.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de Dados: `test`
--
CREATE DATABASE IF NOT EXISTS `test` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `test`;

-- --------------------------------------------------------

--
-- Estrutura da tabela `departamento`
--

CREATE TABLE IF NOT EXISTS `departamento` (
  `nome` varchar(100) NOT NULL,
  `numerodep` int(11) NOT NULL,
  `nssgerente` decimal(5,0) DEFAULT NULL,
  PRIMARY KEY (`numerodep`),
  KEY `nssgerente` (`nssgerente`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `departamento`
--

INSERT INTO `departamento` (`nome`, `numerodep`, `nssgerente`) VALUES
('departamento de pesquisa', 1, NULL),
('departamento financeiro', 2, '12345');

-- --------------------------------------------------------

--
-- Estrutura da tabela `dependente`
--

CREATE TABLE IF NOT EXISTS `dependente` (
  `nome` varchar(50) NOT NULL,
  `nssemp` decimal(5,0) NOT NULL DEFAULT '0',
  `datanasc` date DEFAULT NULL,
  `parentesco` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`nssemp`,`nome`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `dependente`
--

INSERT INTO `dependente` (`nome`, `nssemp`, `datanasc`, `parentesco`) VALUES
('joãozinho da silva', '12345', '2016-06-01', 'Filho');

-- --------------------------------------------------------

--
-- Estrutura da tabela `funcionario`
--

CREATE TABLE IF NOT EXISTS `funcionario` (
  `nome` varchar(60) NOT NULL,
  `nss` decimal(5,0) NOT NULL,
  `datanasc` date DEFAULT NULL,
  `endereco` varchar(100) DEFAULT NULL,
  `salario` float DEFAULT NULL,
  `numdep` int(11) DEFAULT NULL,
  PRIMARY KEY (`nss`),
  KEY `numdep` (`numdep`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `funcionario`
--

INSERT INTO `funcionario` (`nome`, `nss`, `datanasc`, `endereco`, `salario`, `numdep`) VALUES
('João da Silva', '12345', '1960-05-02', 'avenida x, n07, centro', 3000, 1);

-- --------------------------------------------------------

--
-- Estrutura da tabela `projeto`
--

CREATE TABLE IF NOT EXISTS `projeto` (
  `nome` varchar(50) NOT NULL,
  `numero` int(11) NOT NULL,
  `localização` varchar(50) DEFAULT NULL,
  `numdep` int(11) DEFAULT NULL,
  PRIMARY KEY (`numero`),
  KEY `numdep` (`numdep`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `projeto`
--

INSERT INTO `projeto` (`nome`, `numero`, `localização`, `numdep`) VALUES
('projeto rio de ondas', 10, 'Barreiras', 1);

-- --------------------------------------------------------

--
-- Estrutura da tabela `trabalha_em`
--

CREATE TABLE IF NOT EXISTS `trabalha_em` (
  `nssemp` decimal(5,0) NOT NULL DEFAULT '0',
  `numproj` int(11) NOT NULL DEFAULT '0',
  `horas` int(11) DEFAULT NULL,
  PRIMARY KEY (`nssemp`,`numproj`),
  KEY `numproj` (`numproj`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Constraints for dumped tables
--

--
-- Limitadores para a tabela `departamento`
--
ALTER TABLE `departamento`
  ADD CONSTRAINT `departamento_ibfk_1` FOREIGN KEY (`nssgerente`) REFERENCES `funcionario` (`nss`);

--
-- Limitadores para a tabela `dependente`
--
ALTER TABLE `dependente`
  ADD CONSTRAINT `dependente_ibfk_1` FOREIGN KEY (`nssemp`) REFERENCES `funcionario` (`nss`);

--
-- Limitadores para a tabela `funcionario`
--
ALTER TABLE `funcionario`
  ADD CONSTRAINT `funcionario_ibfk_1` FOREIGN KEY (`numdep`) REFERENCES `departamento` (`numerodep`);

--
-- Limitadores para a tabela `projeto`
--
ALTER TABLE `projeto`
  ADD CONSTRAINT `projeto_ibfk_1` FOREIGN KEY (`numdep`) REFERENCES `departamento` (`numerodep`);

--
-- Limitadores para a tabela `trabalha_em`
--
ALTER TABLE `trabalha_em`
  ADD CONSTRAINT `trabalha_em_ibfk_2` FOREIGN KEY (`numproj`) REFERENCES `projeto` (`numero`),
  ADD CONSTRAINT `trabalha_em_ibfk_1` FOREIGN KEY (`nssemp`) REFERENCES `funcionario` (`nss`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
