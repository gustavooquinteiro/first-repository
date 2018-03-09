<?php
$isbn = $_POST["isbn"];
$titulo = $_POST["titulo"];
$autor = $_POST["autor"];
$categoria = $_POST["categoria"];
include "conecta_mysql.inc";
$sql = mysql_query("insert into livros values ('$isbn', '$titulo', '$autor', '$categoria'"); 


if(!$sql){

die ('Error: ' . mysql_error());

}
echo "Livro adicionado com sucesso";

mysql_close($con); 
?>