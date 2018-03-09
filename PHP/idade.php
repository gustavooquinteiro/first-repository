<?php

$idade = $_POST["idade"];

if ($idade<=12){
echo "CRIANÇA";
}
if($idade>12 || $idade<=17){
echo "ADOLESCENTE";
}
if($idade>17 || $idade<=59){
echo "ADULTO";
}
if ($idade>60){
echo "IDOSO";
}

?>
