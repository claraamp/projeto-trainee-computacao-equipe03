# Projeto Trainee Computação OxeBots - Equipe 03

## Equipe:

1. Ivens Joris
2. Lucy Silva
3. Maria Clara Andrade

## Execução

> sudo apt install libsdl2-dev libsdl2-2.0-0 -y
> sudo apt install libprotobuf-dev -y
> make && ./simulator

## Objetivos:

- Desenvolver um simulador que tenha um robô e uma bola que interagem -> Robô irá seguir e chutar a bola em direção ao gol

## Realização:

### realizado

- implementação da campo, robô e bola em SDL
- movimentação usando o teclado
- colisão usando matemática vetorial
- reação simples usando matemática vetorial
- modelo básico de dados com protobuf

### não realizado

- integração via socket para transporte de dados
- threads para rodar o sdl e o socket ao mesmo tempo
- envio da velocidade recebida pelo socket com o dado do protobuf para o objeto do robô

### Observação

a conexão seria feita via socket udp, tentando utilizar alguma biblioteca que não precisa de instalação externa (algo do próprio sistema linux)
Assim no fim eu iria enviar o buffer do protobuf via socket com outro binario, e receber no binario principal
Na conexão, eu enviaria um evento, o qual o simulador receberia e faria o movimento do robô

## Referências:

[SDL tutorial](https://lazyfoo.net/tutorials/SDL/index.php)
[PROTOBUF C++ DOWNLOAD and tutorial](https://protobuf.dev/reference/cpp/cpp-generated/)
[PROTOBUF install ubuntu Geeks4Geeks](https://www.geeksforgeeks.org/how-to-install-protobuf-on-ubuntu/)
[Conexão socket udp Gist](https://gist.github.com/sunmeat/02b60c8a3eaef3b8a0fb3c249d8686fd)
[Conexão socket udp Geeks4Geeks](https://www.geeksforgeeks.org/udp-server-client-implementation-c/)
