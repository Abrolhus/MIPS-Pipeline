# Organização de Computadores - Implementação de um Pipeline MIPS
## Equipe

```
Matrícula       Nome:
```
```
201965571C      Alemilson Fabiano Silva
201876043       Deoclécio Porfírio Ferreira Filho
201965568C      Samuel Abreu Pereira
```

## Objetivo:

Projetar e implementar um simulador do pipeline da arquitetura MIPS. O simulador deverá
possibilitar a execução de programas escritos em código binário para esta arquitetura, nos
modos passo-a-passo e execução direta. Durante a execução do programa deverão ser
apresentados os conteúdos dos registradores e memória.
O simulador deverá possibilitar a execução de programas escritos em código binário para esta arquitetura, nosmodos passo-a-passo e execução direta. Durante a execução do programa deverão ser presentados os conteúdos dos registradores e memória.

## Ações

- [X] Leitura e escrita de arquivos
- [ ] Menu funcional e com as opções
- [ ] Simulador do pipeline da arquitetura MIPS. 
- [ ] Definir classes para os barramento
  - [X] IF_ID
  - [X] ID_EX
  - [X] EX_MEM
  - [X] MEM_WB
  - [ ] Criar funções para cada estágio
  - [ ] IF
  - [ ] ID
  - [ ] EX
  - [ ] MEM
  - [ ] WB
- [X] Criar função de leitura de string para binário. 
- [X] Criar funções para as máscaras dos formatos de 32 bits. 
- [ ] Criar classes ALU, BancoDeRegistradores, ...


## Como Compilar?

Utilizando com os comando do Makefile:

Exclui todos os arquivos .o e o arquivo ./auto.exe
Cria o arquivo auto.exe e todos os arquivos .o
```
make
```
## Como rodar?

```
./mips.exe
```
