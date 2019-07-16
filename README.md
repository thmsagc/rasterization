# Primeira atividade de Introdução a Computação Gráfica
# Professor: Christian Azambudja Pagot
# Júlio Cesar Basílio Alves	20180007631
# Thomás Augusto Gouveia Chaves 20180002671

---

### Introdução
O objetivo principal desta é compreender e desenvolver algorítmos
de rasterização de pontos e linhas. Para linhas, foi implementado
o Algorítmo de Bresenham, que tem como diferencial do cálculo com
números inteiros, poupando memória e processamento.

### Rasterização
Uma tela é basicamente uma matriz. É formada por colunas e linhas
de pixels (a menor unidade de uma tela), onde a origem é o canto
superior esquerdo da tela.

A rasterização consiste em transformar uma imagem vetorial em uma 
imagem de pixels em uma tela. 

<p align="center">
	<br>
	<img src="./img/pixels.png"/ width=655px height=632px>
	<h5 align="center"></h5>
	<br>
</p>

### Pontos
Para rasterizar um ponto basta "pintar" o pixel referente
a sua posição matricial em uma tela.

<p align="center">
	<br>
	<img src="./img/putpixel.png"/ width=691px height=258px>
	<h5 align="center"></h5>
	<br>
</p>

---

### Implementação do Algorítimo de Bresenham

O Algorítimo de Bresenham é notoriamente um dos mais populares.
Como dito anteriormente, ele trabalha apenas com números inteiros,
sendo este o seu maior diferencial.

Para este algorítimo, o coeficiente angular da reta é definido
em um intervalo de [-1,1]. Por este motivo, divide-se a implementação
para cada octante de uma circunferência. Além do mais, este algorítimo
trabalha com base em variações de x e y.

<p align = "center">
<br>
<img src = "./img/octantes.png" / width=619px altura=593px>
<h5 align = "center"></ h5>
<br>
</ p>

E esta é a implementação para o primeiro e segundo octante:

<p align = "center">
<br>
<img src = "./img/bresenham.png" / width=655px altura=522px>
<h5 align = "center"></ h5>
<br>
</ p>

A implementação dos demais é análoga.


## Rasterização de Triângulo
A rasterização de um triângulo ABC, nada mais é do que a rasterização
de linhas entre os vertices AB,BC e CA, utilizando o próprio algorítimo
descrito anteriormente.

<p align="center">
	<br>
	<img src="./img/triangulo.png"/ width=689px height=135px>
	<h5 align="center"></h5>
	<br>
</p>

## Preenchimento de um triângulo
Para o preenchimento do triângulo, foi utilizado um algorítimo
simples, que pode ser entendido facilmente ao ser observado.

<p align="center">
	<br>
	<img src="./img/pintar.png"/ width=744px height=617px>
	<h5 align="center"></h5>
	<br>
</p>

---

## Problemas encontrados
Como afirmado anteriormente, o Algorítimo de Bresenham trabalha com
base nas variações de x e y. Por este motivo, quando a variação de x
ou a de y é nula, o algorítimo não era capaz de esboçar uma linha
reta. Este problema foi corrigido criando uma extensão da função
DrawLine, que permitiu a rasterização de linhas retas.

<p align="center">
	<br>
	<img src="./img/linhasretas.png"/ width=446px height=418px>
	<h5 align="center"></h5>
	<br>
</p>

---

## Conclusão final
A implementação do Algorítimo de Bresenham foi bem sucedida, gerando
resultados satisfatórios, rasterizando linhas para todos octantes. E
também rasterizando polígonos preenchidos.

<p align="center">
	<br>
	<img src="./img/pixelss.png"/ width=86px height=86px>
	<h5 align="center">Rasterização de Pixels</h5>
	<br>
</p>

<p align="center">
	<br>
	<img src="./img/octantesresult.png"/ width=400px height=403px>
	<h5 align="center">Rasterização de linhas nos octantes</h5>
	<br>
</p>

<p align="center">
	<br>
	<img src="./img/resultado1.png"/ width=471px height=478px>
	<h5 align="center">Rasterização de triângulos e linhas</h5>
	<br>
</p>

<p align="center">
	<br>
	<img src="./img/resultado2.png"/ width=450px height=384px>
	<h5 align="center">Preenchimento de Triângulo</h5>
	<br>
</p>

---

### Referências

https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
https://www.cs.helsinki.fi/group/goa/mallinnus/lines/bresenh.html

---


## Autores

* Thomás Augusto Gouveia Chaves
* Julio Cesar Basilio Alves

---
