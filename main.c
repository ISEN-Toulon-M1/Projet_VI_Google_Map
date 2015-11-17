#include <stdio.h>
#include <stdlib.h>
#include "OutilsLib.h"
#include "BmpLib.h"
#include <string.h>

void couleur_gris(DonneesImageRGB *image, short int **rouge,
                   short int **vert, short int **bleu, short int **gris)
{
	int i,j;
	for(i=0; i<image->hauteurImage; i++)
	{
		for(j=0;j<image->largeurImage;j++)
		{
			gris[i][j]=0.2125*rouge[i][j]+0.7154*vert[i][j]+0.0721*bleu[i][j];
		}
	}
}

void NetB(DonneesImageRGB *image, short int **gris, short int **seuille,int seuil)
{
	int i,j;
	for(i=0;i<image->hauteurImage;i++){
		for(j=0;j<image->largeurImage;j++){
			if(gris[i][j]<seuil)
			{
				seuille[i][j]=0;
			}
			else
			{
				seuille[i][j]=255;
			}
		}
	}
}

void gauche_vide(DonneesImageRGB *image, short int **seuille,short int **gauche)
{
	int i,j;
	for(i=0;i<image->hauteurImage;i++)
	{
		for(j=0;j<image->largeurImage;j++)
		{
			if(seuille[i][j-1]==255 && seuille[i][j]==0)
			{
				if(seuille[i][j]==0 && seuille[i+1][j] && seuille[i+2][j] && seuille[i+3][j] && seuille[i+4][j] && seuille[i+5][j] && seuille[i+6][j] &&
				seuille[i+7][j])
				{
					gauche[i+7][j]=0;
				}
			}
			else
			{
				gauche[i][j]=255;
			}
		}
	}
}

void deux_point(DonneesImageRGB *image, short int **gauche, short int **deux)
{
	int i,j;
	for(i=0;i<image->hauteurImage;i++)
	{
		for(j=0;j<image->largeurImage;j++)
		{
			if(gauche[i][j]==0 && gauche[i+1][j]==0 && gauche[i+2][j]==0 && gauche[i+3][j]==0 && gauche[i+4][j]==0 && gauche[i+5][j]==0 && gauche[i+6][j]==0
			&& gauche[i+7][j]==0 && gauche[i+8][j]==0 && gauche[i+9][j]==0 && gauche[i+10][j]==0 && gauche[i+11][j]==0 && gauche[i+12][j]==0 && gauche[i+13][j]==0
			&& gauche[i+14][j]==0 && gauche[i+15][j])
			{
				deux[i+15][j]=0;
			}
			else
			{
				deux[i][j]=255;
			}
		}
	}
}

/*void point_restant(DonneesImageRGB *image, short int **deux, short int **points)
{
	int i,j;
	for(i=0;i<image->hauteurImage;i++)
	{
		for(j=0;j<image->largeurImage;j++)
		{
			if(deux[i][j]==0 && deux[i+1][j]==0)
			{
				points[i+1][j]=0;
			}
			else
			{
				points[i][j]=255;
			}
		}
	}
}*/

void cree3matrices(DonneesImageRGB *image, short int **rouge,
                   short int **vert, short int **bleu)
// convertit DonneesImageRGB *image en trois matrices rouge, vert, bleu
{
    int i,j,k=0;

    for (i=0; i<image->hauteurImage; i++)
    {
        for (j=0; j<image->largeurImage; j++)
        {
            bleu[i][j]=image->donneesRGB[k];
            k++;
            vert[i][j]=image->donneesRGB[k];
            k++;
            rouge[i][j]=image->donneesRGB[k];
            k++;
        }
	}
}

//void compteur(DonneesImageRGB *iomag

void matricesVersImage(DonneesImageRGB *image, short int **rouge,
                       short int **vert,short int **bleu)
// convertit trois matrices rouge, vert, bleu en DonneesImageRGB *image
// attention : image doit être correctement alloue pour etre utilise
{
    int i,j,k=0;

    for (i=0; i<image->hauteurImage; i++)
        for (j=0; j<image->largeurImage; j++)
        {
            image->donneesRGB[k]=bleu[i][j];
            k++;
            image->donneesRGB[k]=vert[i][j];
            k++;
            image->donneesRGB[k]=rouge[i][j];
            k++;
        }
}

int main (int argc, char *argv[] ) {
	DonneesImageRGB *image;
    int i;     
	//char nomImage[50];
    char nomFichier[50];
    
    strcpy(nomFichier, argv[1]);
    strcat(nomFichier,".bmp");
    
    
    printf("lecture\n");
    image = lisBMPRGB(nomFichier);
    short int **rouge=malloc(sizeof(short int *)*image->hauteurImage);
    short int **vert=malloc(sizeof(short int *)*image->hauteurImage);
    short int **bleu=malloc(sizeof(short int *)*image->hauteurImage);
    short int **gris=malloc(sizeof(short int *)*image->hauteurImage);
    short int **seuille=malloc(sizeof(short int *)*image->hauteurImage);
    short int **gauche=malloc(sizeof(short int *)*image->hauteurImage);
    short int **deux=malloc(sizeof(short int *)*image->hauteurImage);
    //short int **points=malloc(sizeof(short int *)*image->hauteurImage);
    for(i=0; i<image->largeurImage; i++) {
        *(rouge+i)=malloc(sizeof(int short)*image->largeurImage);
        *(vert+i)=malloc(sizeof(int short)*image->largeurImage);
        *(bleu+i)=malloc(sizeof(int short)*image->largeurImage);
        *(gris+i)=malloc(sizeof(int short)*image->largeurImage);
        *(seuille+i)=malloc(sizeof(int short)*image->largeurImage);
        *(gauche+i)=malloc(sizeof(int short)*image->largeurImage);
        *(deux+i)=malloc(sizeof(short int)*image->largeurImage);
        //*(points+i)=malloc(sizeof(short int)*image->largeurImage);
	}
    printf("j'ai mon fichier\n");
    printf("starfoullah\n");
    if (image == NULL)
        return 0;
	printf("La taille de l'image est %d de hauteur par %d de largeur mdr lol xD\nMaillot on te baise \n", image->hauteurImage, image->largeurImage);
	cree3matrices(image,rouge,vert,bleu);
	printf("Matrices créées\n");
	
	couleur_gris(image,rouge,vert,bleu,gris);
	printf("Image en gris !\n");
	NetB(image,gris,seuille,70);
	printf("Image en Noir & Blanc\n");
	matricesVersImage(image, seuille, seuille, seuille);
	gauche_vide(image,seuille,gauche);
	deux_point(image,gauche,deux);
	printf("Flèches gardées\n");
	matricesVersImage(image,deux,deux,deux);
	
	strcpy(nomFichier, argv[1]);
	strcat(nomFichier,"_points.bmp");
	ecrisBMPRGB_Dans(image,nomFichier);
	
	/*for(i=0; i<(image->largeurImage); i++)
	{
		free(*(rouge+i));
		free(*(vert+i));
		free(*(bleu+i));
	}
	free(rouge);
	free(vert);
	free(bleu);*/
	//libereDonneesImageRGB(image);
	return 0;
	
	  
}
