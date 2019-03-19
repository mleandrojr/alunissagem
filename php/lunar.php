<?php

$input = fopen('php://stdin', 'r');

$x    = 500;
$v    = -50;
$g    = -5;
$t    = 1;
$comb = 120;

print("Simulação de alunissagem\n\n");
print("(Digite a quantidade de combustível a queimar)\n");

$fmt = "Alt: %6.2f  Vel: %6.2f  Comb: %3d";

while ($x > 0) {

    $msg = sprintf($fmt, $x, $v, $comb);

    if ($comb > 0) {

        print($msg . " Queima = ");
        $resp = fgets($input);

        $queima = floatval($resp);

        if ($queima > $comb) {
            $queima = $comb;
        }

        $comb -= $queima;
        $a = $g + $queima;

    } else {
        print($msg . "\n");
        $a = $g;
    }

    $x0 = $x;
    $v0 = $v;
    $x  = $x0 + $v0 * $t + $a * $t * $t / 2;
    $v  = $v0 + $a * $t;
}

fclose($input);

$vf = sqrt($v0 * $v0 + 2 * -$a * $x0);
printf(">>>CONTATO! Velocidade final: %6.2f\n", -$vf);

if ($vf == 0) {
    $msg = 'Alunissagem perfeita!';

} elseif ($vf <= 2) {
    $msg = 'Alunissagem dentro do padrão.';

} elseif ($vf <= 10) {
    $msg = 'Alunissagem com avarias leves.';

} elseif ($vf <= 20) {
    $msg = 'Alunissagem com avarias severas.';

} else {
    $msg = 'Modulo lunar destruído no impacto.';
}

print('>>>' . $msg . "\n");