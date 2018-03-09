<?php
$nome=$_POST["NOME"];
$erro=0;
$senha=$_POST["senha"];
if(empty($nome)){
$erro=1;
$msg="Por favor, digite seu nome, caro sr usuario";

}

if(strstr($senha,' ')!=	FALSE){
echo"Sr usuario, nao seje burro. Nao exixte espaço em branco no campo senha";
}


if($erro){
echo $msg;
echo "<p align=center><a href='javascript:history.back()'>Voltar</a></p>";
}
else
echo "Seu cadastro esta realizado";

?>