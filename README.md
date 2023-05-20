# Edge Computing: Challenge, Sprint 2 - Sensor de peso 

### Introdução
Como andamento ao projeto iniciado no Sprint 1 (https://github.com/Projetos-Fiap/EdgeComputing-Challenge-Sprint1), agora nesta continuação do projeto temos a implementação de novos componentes, como um buzzer, led, botão seletor e também a implementação de uma célula de carga e um conversor a/d.

### Funcionamento
O projeto utiliza como plataforma principal o microcontrolador Arduino Uno R3. Conectada nela temos o módulo HX711, um conversor analógico/digital, no qual conectamos uma célula de carga. Dessa forma conseguimos realizar medições de peso com o Arduino. Adicionamos ao circuito um buzzer e um led que ativam quando o limite de peso é atingido. Também temos um botão que faz a função de seletor do tipo de material escolhido para pesagem. E finalmente temos o LCD para exibir as informações de peso e tipo. 

### Sensor de peso e Tinkercad
Devido ao fato de o Tinkercad (site onde construímos o protótipo) não possuir integração com o módulo HX711 e célula de carga, resolvemos utilizar um potenciômetro para funcionar como a balança, como já feito previamente na sprint 1.

### Grupo
<li>Alessandra Vaiano (RM551497)</li>  
<li>André Lambert (RM99148)</li>  
<li>Bryan Willian (RM551305)</li>
<li>Lucas Feijó (RM99727)</li>
<li>Vitor Maia (RM99658)</li>

### Simulação do Protótipo
[Link para o Tinkercad, montagem com um LCD I2C](https://www.tinkercad.com/things/iWG12Au9C4a?sharecode=7OuKyPT-MoJO6bdyMhFwCjKuZHhQZRjSGi-lMjVyCS4)

[Link para o Tinkercad, montagem com um LCD Serial](https://www.tinkercad.com/things/7msyRJChKDJ?sharecode=PU4CeosgJpSXETlzYTIAJ6y6ewrCRuf7yqVo72o1oIs)

### Componentes utilizados
<li>Arduino Uno R3</li>
<li>LCD 16x2</li>
<li>Módulo HX711</li>
<li>Célula de carga</li>
<li>Protoboard</li>
<li>1 LED</li>
<li>1 Potênciometro</li>
<li>Resistores</li>
<li>1 Buzzer</li>
<li>1 Botão</li>
<li>Cabos Jumper</li>

### Imagem do circuito
![Imagem](https://github.com/Projetos-Fiap/EdgeComputing-Challenge-Sprint2/blob/main/circuit_LCDi2c_potentiometer.png?raw=true)

