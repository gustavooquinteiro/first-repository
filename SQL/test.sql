-- phpMyAdmin SQL Dump
-- version 4.0.4
-- http://www.phpmyadmin.net
--
-- Máquina: localhost
-- Data de Criação: 14-Fev-2017 às 15:57
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
  `nome` varchar(50) NOT NULL,
  `numeroDep` int(11) NOT NULL,
  `NSSGerente` decimal(5,0) DEFAULT NULL,
  PRIMARY KEY (`numeroDep`),
  KEY `NSSGerente` (`NSSGerente`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estrutura da tabela `dependente`
--

CREATE TABLE IF NOT EXISTS `dependente` (
  `nome` varchar(50) NOT NULL,
  `nssEmp` decimal(5,0) NOT NULL DEFAULT '0',
  `dataNasc` date DEFAULT NULL,
  `parentesco` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`nome`,`nssEmp`),
  KEY `nssEmp` (`nssEmp`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

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

-- --------------------------------------------------------

--
-- Estrutura da tabela `projeto`
--

CREATE TABLE IF NOT EXISTS `projeto` (
  `nome` varchar(50) NOT NULL,
  `numero` int(11) NOT NULL,
  `localizacao` varchar(80) DEFAULT NULL,
  `numDep` int(11) DEFAULT NULL,
  PRIMARY KEY (`numero`),
  KEY `numDep` (`numDep`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Estrutura da tabela `trabalha_em`
--

CREATE TABLE IF NOT EXISTS `trabalha_em` (
  `nssEmp` decimal(5,0) NOT NULL DEFAULT '0',
  `numProj` int(11) NOT NULL DEFAULT '0',
  `horas` int(11) DEFAULT NULL,
  PRIMARY KEY (`nssEmp`,`numProj`),
  KEY `numProj` (`numProj`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Constraints for dumped tables
--

--
-- Limitadores para a tabela `departamento`
--
ALTER TABLE `departamento`
  ADD CONSTRAINT `departamento_ibfk_1` FOREIGN KEY (`NSSGerente`) REFERENCES `funcionario` (`NSS`);

--
-- Limitadores para a tabela `dependente`
--
ALTER TABLE `dependente`
  ADD CONSTRAINT `dependente_ibfk_1` FOREIGN KEY (`nssEmp`) REFERENCES `funcionario` (`NSS`);

--
-- Limitadores para a tabela `funcionario`
--
ALTER TABLE `funcionario`
  ADD CONSTRAINT `funcionario_ibfk_1` FOREIGN KEY (`NumDep`) REFERENCES `departamento` (`numeroDep`);

--
-- Limitadores para a tabela `projeto`
--
ALTER TABLE `projeto`
  ADD CONSTRAINT `projeto_ibfk_1` FOREIGN KEY (`numDep`) REFERENCES `departamento` (`numeroDep`);

--
-- Limitadores para a tabela `trabalha_em`
--
ALTER TABLE `trabalha_em`
  ADD CONSTRAINT `trabalha_em_ibfk_2` FOREIGN KEY (`numProj`) REFERENCES `projeto` (`numero`),
  ADD CONSTRAINT `trabalha_em_ibfk_1` FOREIGN KEY (`nssEmp`) REFERENCES `funcionario` (`NSS`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
