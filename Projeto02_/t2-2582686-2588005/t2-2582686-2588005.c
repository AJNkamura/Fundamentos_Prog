/*============================================================================*/
/* ICSF13 - 2023-2 - TRABALHO 2                                               */
/*----------------------------------------------------------------------------*/
/* Amanda Jury Nakamura             RA:2582686                                */
/* Julia Kamilly de Oliveira        RA: 2588005                               */
/*============================================================================*/

#include "trabalho2.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LIMITE 1

//recebe dados do vetor e multiplica pelo ganho
void mudaGanho (double* dados, int n_amostras, double ganho){
    int i;
    for (i = 0; i < n_amostras; i++){
        dados[i] *= ganho;
    }
}

//conta o numero de amostras que extrapolaram o limite
int contaSaturacoes (double* dados, int n_amostras){
    int i, saturacoes = 0;
    double saturados
    //loop que percorre o vetor e acrescenta +1 a cada dado acima do limite
    for (i = 0; i < n_amostras; i++){
        if (abs(dados) > LIMITE){
            saturacoes++;
        }
    }
    return (saturacoes);
}

//identifica e conta vales e picos fora dos limietes e os transforma em 1 ou -1
int hardClipping (double* dados, int n_amostras, double limite){
    int i, amostras_alteradas = 0;
    //loop que percorre o vetor, identifica e altera os dados para ficarem no limite
    
    for (i = 0; i < n_amostras; i++){
        // para valores > 0
        if (dados[i] > LIMITE){
            dados[i] = LIMITE;
            amostras_alteradas++;
        }
        //para valores < 0
        else
            if (dados[i] < -LIMITE){
                dados[i] = -LIMITE;
                amostras_alteradas++;
        }
    }
    return (amostras_alteradas);
}

//identifica dados fora dos limites e os modifica juntamente com os n_passos laterias (direita e esquerda)
void limitaSinal (double* dados, int n_amostras, int n_passos){
    int i, j, ganho, diferenca_ganho;
    //loop que percorre os dados do vetor
    for (i = 0; i < n_amostras; i++){
        //identifica dados fora dos limites
        if (abs(dados) > LIMITE){
            //descobre o ganho necessário para que o dado fique no limite e o altera
            ganho = LIMITE/dados[i];
            dados[i]*=ganho;
            //descobre a constante que é acrescida a cada n_passos
            diferenca_ganho = (LIMITE - ganho)/n_passos-1;

            //loop para percorrer os n_passos e multiploca-los pelo ganho progressivamente
            for (j = 1; j < n_passos; j++){
                dados[i]*=(ganho + (diferenca_ganho*j));
            }
        }
    }
}
void geraOndaQuadrada (double* dados, int n_amostras, int taxa, double freq){
}