<html>
<body>
<h1 align="center">Livros</h1>
<hr>
<table cellspacing="3">
	<tr bgcolor="#d6d6d6">
		<th>Código</th>
		<th>Título</th>
		<th>Autor</th>
		<th>Categoria</th>
	</tr>

<?php
$busca = $_POST['busca'];
$chave = $_POST['chave'];
include "conecta_mysql.inc";

$result=mysql_query("SELECT * FROM livros WHERE $chave like '%$busca%'");
$num_linhas=mysql_num_rows($result);


	for($i=0;$i<$num_linhas;$i++)
	{
	$isbn = mysql_result($result,$i,0);
	$titulo = mysql_result($result,$i,1);
    $autor = mysql_result($result,$i,2);
    $categoria = mysql_result($result,$i,3);
	echo "<tr bgcolor=\"#eeeeee\">";
	echo "<td>$isbn</td>";
	echo "<td>$titulo</td>";
	echo "<td>$autor</td>";
	echo "<td>$categoria</td>";
	echo "</tr>";
	}

mysql_close($con);
?>
</table>
<hr>
<p align="center"><a href="livros.html">Voltar</p>
</body>
</html>