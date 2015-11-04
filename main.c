#include <stdio.h>
#include <stdlib.h>
#include "OutilsLib.h"
#include "BmpLib.h"
#include <string.h>
#include "imageIO.h"


int main (int argc, char *argv[] ) {
	DonneesImageRGB *image;
    int i;     
	//char nomImage[50];
    char nomFichier[50];
    
    strcpy(nomFichier, argv[1]);
    strcat(nomFichier,".bmp");
    printf("lecture\n");
	image = lisBMPRGB(nomFichier);
	
    short int **rouge=malloc(sizeof(short int*)*image->hauteurImage);
    short int **vert=malloc(sizeof(short int*)*image->hauteurImage);
    short int **bleu=malloc(sizeof(short int*)*image->hauteurImage);
    
    for(i=0; i<image->hauteurImage; i++) {
        *(rouge+i)=malloc(sizeof(int short)*image->largeurImage);
        *(vert+i)=malloc(sizeof(int short)*image->largeurImage);
        *(bleu+i)=malloc(sizeof(int short)*image->largeurImage);
	}
    printf("j'ai mon fichier\n");
    if (image == NULL)
        return 0;
	printf("La taille de l'image est %d de hauteur par %d de largeur mdr lol xD\n", image->hauteurImage, image->largeurImage);
	cree3matrices(image,rouge, vert, bleu);  
	printf("%d", *(*(rouge+4)+4));
	matricesVersImage(image,rouge, vert, bleu);
	ecrisBMPRGB_Dans(image, "copieFichier.bmp");
	
	
	for(i=0; i<image->hauteurImage; i++) {
		free(*(rouge+i));
		*(rouge+i)=NULL;
		free(*(vert+i));
		*(vert+i)=NULL;
		free(*(bleu+i));
		*(bleu+i)=NULL;
	}
	free(rouge);
	rouge=NULL;
	free(vert);
	vert=NULL;
	free(bleu);
	bleu=NULL;
	libereDonneesImageRGB(&image);
if(rouge==NULL)
printf("rouge est null");
	
	return 0;
	
	  
}
