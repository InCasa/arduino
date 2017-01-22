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

function AlteraRele3(){
    var estado_3 = document.getElementById("estado_3").innerHTML;
    if(estado_3 === "0"){
        document.getElementById("estado_3").innerHTML="1";
        document.getElementById("rele_3").innerHTML="<div class='rele3_ligado'></div>";
		document.getElementById("botao_3").innerHTML="<a href='/?3_desligar' class='botao'>Desliga</a>";
    } else {
        document.getElementById("estado_3").innerHTML="0";
        document.getElementById("rele_3").innerHTML="<div class='rele3_desligado'></div>";
        document.getElementById("botao_3").innerHTML="<a href='/?3_ligar' class='botao'>Liga</a>";
    }
}

function AlteraRele4(){
    var estado_4 = document.getElementById("estado_4").innerHTML;
    if(estado_4 === "0"){
        document.getElementById("estado_4").innerHTML="1";
        document.getElementById("rele_4").innerHTML="<div class='rele4_ligado'></div>";
		document.getElementById("botao_4").innerHTML="<a href='/?4_desligar' class='botao'>Desliga</a>";
    } else {
        document.getElementById("estado_4").innerHTML="0";
        document.getElementById("rele_4").innerHTML="<div class='rele4_desligado'></div>";
        document.getElementById("botao_4").innerHTML="<a href='/?4_ligar' class='botao'>Liga</a>";
    }
}