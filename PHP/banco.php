<html>
<body>
<table> 
<tr>
	<th>Aluno</th>
	<th>Matrícula</th>
	<th>Turma</th>
	<th>Curso</th>
</tr>
<?php
$bdServidor = '127.0.0.1';
$bdUsuario = 'root';
$bdSenha = 'auditore';
$bdBanco = 'ProjetoLP';

$conexao = mysql_connect($bdServidor, $bdUsuario, $bdSenha, $bdBanco);

$resul = mysql_query("SELECT * FROM aluno"); 
$num = mysql_num_rows($resul);

for ($i=0;$i<$num;$i++){
$aluno = mysql_result($resul, $i, 0);
$matricula = mysql_result($resul, $i, 1);
$turma = mysql_result($resul, $i,2);
$curso = mysql_result($resul, $i, 3);
echo "<tr>";
echo "<td>$aluno</td>";
echo "<td>$matricula</td>";
echo "<td>$turma</td>";
echo "<td>$curso</td>";
echo "</tr>";
}

mysql_close($conexao);
?>
</table>
</body>
</html>
