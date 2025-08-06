# Fundamentos de Programação
Este repositório reúne os 3 trabalhos realizados como parte das avaliações da disciplina de Fundamentos de Programação. O principal objetivo dessas atividades foi aplicar conhecimentos de algoritmos e lógica de programação utilizando a linguagem C. Segue um breve resumo contextualizando a problemática de cada projeto.

##  🚛 Trabalho 01 - Interseção e Distância entre Regiões

Este trabalho simula a criação de funcionalidades para um sistema que analisa regiões geográficas com o objetivo de otimizar a localização de pontos de venda e centros de distribuição. As regiões são representadas por retângulos em um plano cartesiano.

Para isso, solicitou-se a criação das 2 funções:

🔹Função 1 – calculaInterseccao: Determinar a área comum (interseção) entre múltiplos retângulos. O desafio envolve calcular a sobreposição dessas regiões e aplicar otimizações para interromper a análise quando não houver interseção possível.

🔹Função 2 – encontraParMaisProximo: Encontrar o par de retângulos mais próximos entre si, considerando seus centros geométricos. O retorno codifica os dois índices em um único valor inteiro, simulando um sistema de análise de proximidade entre fornecedores.


## 🔉Trabalho 02 - Manipulação de Áudio Digital ##

Neste segundo projeto, o buscou-se explorar conceitos de processamento de áudio digital manipulando diretamente os dados de arquivos .wav. As tarefas envolveram alterações no volume, identificação de distorções (clipping), simulação de efeitos sonoros e até a geração de formas de onda a partir do zero. As funções desenvolvidas possibilitam transformar um sinal de áudio por meio de operações matemáticas simples, mas com efeitos perceptíveis no som final.

Funções implementadas:

🔹 mudaGanho: Ajusta o volume multiplicando cada amostra por um fator.

🔹 contaSaturacoes: Detecta quantas amostras ultrapassam os limites normais do sinal.

🔹 hardClipping: Aplica um corte rígido nos picos do sinal, criando distorção proposital.

🔹 limitaSinal: Reduz gradualmente a intensidade de picos e regiões vizinhas para evitar saturação.

🔹 geraOndaQuadrada: Gera um sinal digital de onda quadrada com base na frequência e taxa de amostragem.

## 🎮 Trabalho 03 - Detecção da Sensor Bar
Este projeto focou no processamento digital de imagens em C, simulando o sistema de um  Nintendo Wii. O objetivo foi recriar a capacidade do Wiimote de "enxergar" e interpretar os sinais infravermelhos da Sensor Bar.

A principal função a ser desenvolvida, detectaSensorBar, deve receber uma imagem em tons de cinza que é uma representação do que o sensor do Wiimote capta, e identificar e marcar as coordenadas centrais dos dois focos de luz infravermelha emitidos pela Sensor Bar, e determinar o ângulo exato, em radianos, entre esses dois pontos de luz detectados. 
