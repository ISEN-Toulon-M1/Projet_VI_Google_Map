//
//  transfoPixel.c
//  TD6
//
//  Created by Laurent Gonin on 13/10/15.
//  Copyright © 2015 Laurent Gonin. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "OutilsLib.h"
#include "BmpLib.h"
#include "imageIO.h"
#include <string.h>
#include "transfoPixel.h"
#include <math.h>

void couleur2NG(short int rouge[NBLIG][NBCOL],short int vert[NBLIG][NBCOL],
                short int bleu[NBLIG][NBCOL], short int gris[NBLIG][NBCOL])
{
   /* int i,j;
    for(i=0;i<NBLIG;i++)
    {
        for(j=0;j<NBCOL;j++)
        {
            gris[i][j]=0.2125*rouge[i][j]+0.7154*vert[i][j]+0.0721*bleu[i][j];
        }
    }
    printf("\n couleurNG cree \n");*/
    
}

void negatifImage(short int rouge[NBLIG][NBCOL],short int vert[NBLIG][NBCOL],short int bleu[NBLIG][NBCOL])
{
    int i,j;
    for(i=0;i<NBLIG;i++)
    {
        for(j=0;j<NBCOL;j++)
        {
            bleu[i][j]=255-bleu[i][j];
            vert[i][j]=255-vert[i][j];
            rouge[i][j]=255-rouge[i][j];
        }
    }
    printf("\n negatif cree \n");
}

void couleur2NoirBlanc(short int rouge[NBLIG][NBCOL],short int vert[NBLIG][NBCOL],
                       short int bleu[NBLIG][NBCOL], short int nb[NBLIG][NBCOL])
{

    int i;
    
    int j;
    
    
    
    for(i=0;i<NBLIG;i++)
        
    {
        
        for(j=0;j<NBCOL;j++)
            
        {
            
            if(rouge[i][j]!=255 || vert[i][j]!=255 || bleu[i][j]!=255)
                
            {
                
                nb[i][j]=0;
                
            }
            else
            {
                nb[i][j]=255;
            }
            
        }
        
    }
     printf("\n NoirBlanc cree \n");
    
}
/*
void echantillonnageint N, short int gris[NBLIG][NBCOL])
{
    
    
}
*/

void Surface(short int nb[NBLIG][NBCOL])
{
    
    int i;
    int surface=0;
    int j;
    
    
    
    for(i=0;i<NBLIG;i++)
        
    {
        
        for(j=0;j<NBCOL;j++)
            
        {
            
            if(nb[i][j]==255)
                
            {
                
                surface=surface+1;
                
            }
            else
            {
                
            }
            
        }
        
    }
    printf("La surface est de %d",surface );
    
    //return surface;
}



void quantification(int N, short int gris[NBLIG][NBCOL])
{
    
    int i,j;
    for(i=0;i<NBLIG;i++)
    {
        for(j=0;j<NBCOL;j++)
        {
            gris[i][j]=gris[i][j]/N;
        }
    }
    printf("\n echantillonnage à N niveau de gris cree \n");
}

void statistiques(short int gris[NBLIG][NBCOL])
{
    int i,j,k;
    
    double k2,v,s;
    k=0;
    v=0;
    for(i=0;i<NBLIG;i++)
    {
        for(j=0;j<NBCOL;j++)
        {
            k+=gris[i][j];
            
        }
    }
    
    k2=(k/(NBLIG*NBCOL)); //Moyenne
    
    for(i=0;i<NBLIG;i++)
    {
        for(j=0;j<NBCOL;j++)
        {
            v+=(gris[i][j]-k2)*(gris[i][j]-k2);
            
        }
    }
    
    v=(v/(NBLIG*NBCOL));
    s=sqrt(v);
    printf("la moyenne est %f\n",k2);
    printf("la variance est %f\n",v);
    printf("la ecart type est %f\n",s);
    
    
}
