#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* fichier = NULL;

typedef struct Tile{
	char couleur[6];
	char piece[10];
	int used;
	int valeurID;
	char charID;
};

void CreateBoard() { //Création du plateau
	//Clear Board.txt
	fichier = fopen("Board.txt", "w");
	fclose(fichier);

	int a_taille = 0;
	printf("Quelle taille souhaitez vous pour le tableau ?\n");
	scanf("%d", &a_taille);
	fichier = fopen("Board.txt", "a");
	if (fichier != NULL) {
		fprintf(fichier, "%d\n", a_taille);
	}
	fclose(fichier);
	Tile** board = (Tile**)malloc(sizeof(Tile*) * a_taille);

	for (int i = 0; i < a_taille; i++)
	{
		board[i] = (Tile*)malloc(sizeof(Tile) * a_taille);
	}

	for (int i = 0; i < a_taille; i++)
	{
		for (int j = 0; j < a_taille; j++)
		{
			if ((i % 2 == 0) && (j % 2 == 0)) {
				fichier = fopen("Board.txt","a");
				if (fichier != NULL) {
					fprintf(fichier, "noir\n");
				}
				fclose(fichier);
			}
			else if ((i % 2 == 0) && (j % 2 != 0)) { //B
				fichier = fopen("Board.txt", "a");
				if (fichier != NULL) {
					fprintf(fichier, "blanc\n");
				}
				fclose(fichier);
			}
			else if ((i % 2 != 0) && (j % 2 == 0)) { //B
				fichier = fopen("Board.txt", "a");
				if (fichier != NULL) {
					fprintf(fichier, "blanc\n");
				}
				fclose(fichier);
			}
			else if ((i % 2 != 0) && (j % 2 != 0)) { //N
				fichier = fopen("Board.txt", "a");
				if (fichier != NULL) {
					fprintf(fichier, "noir\n");
				}
				fclose(fichier);
			}
		}
	}
}

void basicSituation() {
	int count = 0;

	fichier = fopen("Board.txt", "a");

	fprintf(fichier, "B_Tower\nB_Horse\nB_Bishop\nB_Queen\nB_King\nB_Bishop\nB_Horse\nB_Tower\n");
	count += 8;
	for (int i = 0; i < 8; i++)
	{
		count++;
		fprintf(fichier, "B_Pawn\n");
	}
	for (int i = 0; i < 32; i++)
	{
		count++;
		fprintf(fichier, "Tiles\n");
	}
	for (int i = 0; i < 8; i++)
	{
		count++;
		fprintf(fichier, "W_Pawn\n");
	}
	fprintf(fichier, "W_Tower\nW_Horse\nW_Bishop\nW_Queen\nW_King\nW_Bishop\nW_Horse\nW_Tower\n");
	count += 8;

	fclose(fichier);

}


int main(int argc,char* argv[]) {
	//Create New Board
	CreateBoard();
	//Create basic situation
	basicSituation();
	Tile tab[9][9] = { NULL };

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			tab[i][0].valeurID = i;
			tab[i][0].charID = 65 + i;
			tab[0][j].valeurID = j;
			tab[0][j].charID = 65 + j;
			if (i >= 1 && j >= 1) {
				tab[i][j].valeurID = 0;
				tab[i][j].charID = 0;
			}
			printf("%c", tab[i][j].valeurID);
		}
		printf("\n");
	}
}