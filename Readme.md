# EP de Introdução a Ánalise de Algoritmos

## Compilação

Para usar o progra é simples, basta compilar os main.c e o vetor.c, para basta digitar no terminal

```bash
make all
make vetor
make clean
```

Esse comando irá compilar os dois programas.

Para gerar os arquivos csv para fazer a analise primeiro precisa permitir o script shell ser executado, para isso execute:

```bash
chmod +x ./vetor
```

## Gerando os arquivos

Depois de compilar e permitir execução do script shell é só rodar o seguinte comando:

```bash
./vetor [tamanho]
```

Onde o [tamanho] é o tamanho do vetor que sera gerado.
O programa fará 100 iterações, gerando a cada iteração um vetor aleatório e colocando os resultados em um arquivo com o nome dados\_[tamanho].csv para ser gerado os grafico por algum programa depois.
