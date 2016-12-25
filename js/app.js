function AlteraRele1(){
    var estado_1 = document.getElementById("estado_1").innerHTML;
    if(estado_1 === "0"){
        document.getElementById("estado_1").innerHTML="1";
        document.getElementById("rele_1").innerHTML="<div class='rele1_ligado'></div>";
		document.getElementById("botao_1").innerHTML="<a href='/?1_desligar' class='botao'>Desliga</a>";
    } else {
        document.getElementById("estado_1").innerHTML="0";
        document.getElementById("rele_1").innerHTML="<div class='rele1_desligado'></div>";
        document.getElementById("botao_1").innerHTML="<a href='/?1_ligar' class='botao'>Liga</a>";
    }
}

function AlteraRele2(){
    var estado_2 = document.getElementById("estado_2").innerHTML;
    if(estado_2 === "0"){
        document.getElementById("estado_2").innerHTML="1";
        document.getElementById("rele_2").innerHTML="<div class='rele2_ligado'></div>";
		document.getElementById("botao_2").innerHTML="<a href='/?2_desligar' class='botao_2'>Desliga</a>";
    } else {
        document.getElementById("estado_2").innerHTML="0";
        document.getElementById("rele_2").innerHTML="<div class='rele2_desligado'></div>";
        document.getElementById("botao_2").innerHTML="<a href='/?2_ligar' class='botao_2'>Liga</a>";
    }
}