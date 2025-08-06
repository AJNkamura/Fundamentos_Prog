/*============================================================================*/
/* ICSF13 - 2023-2 - TRABALHO 1                                               */
/*----------------------------------------------------------------------------*/
/* Amanda Jury Nakamura         RA: 2582686                                   */
/*============================================================================*/

#include "trabalho1.h"
#include <float.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

int calculaInterseccao (int n_retangulos){
    int xSE, ySE, xID, yID, ret, retA, retB, xSEa, ySEa, xIDa, yIDa, xSEb, ySEb, xIDb, yIDb;
    int base, altura, area;
    int maiorYid = 0, menorYse = INT_MAX, menorXid = INT_MAX, maiorXse = 0;

    //verificar se ha interseccao
     for (retA = 0; retA < n_retangulos; retA++){
        xSEa = pegaXSE ( retA );
        ySEa = pegaYSE ( retA );
        xIDa = pegaXID ( retA );
        yIDa = pegaYID ( retA );

        for (retB = retA + 1; retB < n_retangulos; retB++){
            xSEb = pegaXSE ( retB );
            ySEb = pegaYSE ( retB );
            xIDb = pegaXID ( retB );
            yIDb = pegaYID ( retB );

            if (xSEa < xSEb && xIDa <= xSEb) // Casos em que retA eh o mais a esquerda
                return 0;                     // Se NAO ha interseccao do X lado direito do retA com o do lado esquerdo do retB

            else if(xSEb < xSEa && xIDb <= xSEa) // Contrário do primeiro
                return 0;


            if (ySEa > ySEb && yIDa >= ySEb) //Caso em que retA eh o mais alto
                return 0;                     // Se NAO ha interseccao do Y do lado de cima do retA com o do lado de baixo do retB

            else if(ySEb > ySEa && yIDb >= ySEa)
                return 0;

        }
    }

    //recolher as coordenadas SE e ID de todos os retangulos
    for (ret = 0; ret < n_retangulos; ret++){
        xSE = pegaXSE ( ret );
        ySE = pegaYSE ( ret );
        xID = pegaXID ( ret );
        yID = pegaYID ( ret );

            //armanzenar coordenadas do retangulo da intersec.
            if (ySE < menorYse)
                menorYse = ySE;
            if (xSE > maiorXse)
                maiorXse = xSE;
            if (yID > maiorYid)
                maiorYid = yID;
            if (xID < menorXid)
                menorXid =  xID;
        }
    //calcular a area do retangulo
    base = menorXid - maiorXse;
    altura = menorYse - maiorYid;
    area = base * altura;

    return (area);

}

//----------------------------------------------------------------------------------------------------//
unsigned int encontraParMaisProximo (int n_retangulos){
    int retA, retB;
    int retProx1, retProx2, altura, base;
    float coordenadaXcentroA, coordenadaYcentroA, coordenadaXcentroB, coordenadaYcentroB;
    int xSE, ySE, xID, yID;
    float menor_dist = FLT_MAX, dist;

    //coletar centro retanguloA
    for (retA = 0; retA <  n_retangulos; retA++){
        xSE = pegaXSE ( retA );
        ySE = pegaYSE ( retA );
        xID = pegaXID ( retA );
        yID = pegaYID ( retA );

        base = (xID - xSE);
        altura = (ySE - yID);

        coordenadaXcentroA = xSE + (base)/2.0;
        coordenadaYcentroA = yID + (altura)/2.0;

        //coletar centro retB
        for (retB = retA + 1; retB < n_retangulos; retB++){
            xSE = pegaXSE ( retB );
            ySE = pegaYSE ( retB );
            xID = pegaXID ( retB );
            yID = pegaYID ( retB );


            base = (xID - xSE);
            altura = (ySE - yID);

            coordenadaXcentroB = xSE + (base)/2.0;
            coordenadaYcentroB = yID + (altura)/2.0;

            //calcula distancia entre centros
            dist = sqrt((coordenadaXcentroB - coordenadaXcentroA)*(coordenadaXcentroB - coordenadaXcentroA) + (coordenadaYcentroB - coordenadaYcentroA)*(coordenadaYcentroB - coordenadaYcentroA)) ;

            //salvar dados
            if (dist < menor_dist){
                menor_dist =  dist;
                retProx1 = retA;
                retProx2 = retB;
            }
        }
    }
    //printf ("\n %d %d\n", retProx1, retProx2);    Foi utilizado para excluir a conversão dos numeros dos retangulos como erro

    if (retProx1 < retProx2)
        return ((retProx1 << 16)+ retProx2);
    else
        return ((retProx2 << 16)+ retProx1);
}

