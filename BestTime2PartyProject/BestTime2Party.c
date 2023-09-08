#include<stdio.h>
#include <string.h>
#include"genlib.h"
#include"simpio.h"
#define BAZAAR 6
#define DIMENSION1 100
//#define DIMENSION2 3

//Function declaration
void Filling(int row, int Ar_T[], int Dep_T[], char *Names[]);
void Best_Time(int rows, int Ar_T[], int Dep_T[], int hours[], int *besttime);
void PrintArrBands(int rows, int Arr[],int Dep[], char *tab[], int besttime);


int main()
{
	int Arriv_T[DIMENSION1], Depart_T[DIMENSION1], hour[BAZAAR]={18,19,20,21,22,23}, num_band, besttime;
	char  *Band_nam[DIMENSION1];


	printf("Give the number of bands that will attend to the bazaar: ");
	scanf("%d%*c", &num_band);


	Filling(num_band, Arriv_T, Depart_T, Band_nam);
	Best_Time(num_band,Arriv_T, Depart_T, hour, &besttime);

	printf("The best time for Stathis to attend the bazaar is %d o'clock\n", besttime);

	PrintArrBands(num_band, Arriv_T,Depart_T, Band_nam, besttime);

	return 0;
}


//Function declaration

void Filling(int row, int Ar_T[], int Dep_T[], char *Names[row])
{

	int i;

	for(i=0; i<row; i++)
	{
		printf("Give the name of the band no%d:", i+1);
	    // scanf("%[^\n]s%*c", Names[i]);
	    Names[i]=GetLine();
		printf("Give the arriving time of the band no%d: ", i+1);
		scanf("%d%*c", &Ar_T[i]);
		printf("Give the departing time of the band no%d: ", i+1);
		scanf("%d%*c", &Dep_T[i]);
	}
}

void Best_Time(int rows, int Ar_T[], int Dep_T[], int hour[], int *besttime)
{
	int i, frequency[BAZAAR], max, index,j;

	for(i=0; i<BAZAAR; i++)
	{
		frequency[i]=0;
		for(j=0; j<rows;j++)
		{
			if(hour[i] >= Ar_T[j] && hour[i] < Dep_T[j]) //Ψάχνω να βρω για κάθε ώρα πόσα συγκροτήματα ήταν άρα είναι η καλύτερη
			{                                                              //Θέλω η ώρα που αναζητώ συχνότητα πχ 7μμ να είναι >= από την ώρα που είπε το συγκρότημα ότι θα είναι και < από την ώρα που θα φύγει άρα εκείνη την ώρα πχ 7μμ το τάδε συγκρότημα ήταν εκεί

				frequency[i]++; //Αυξάνω τον αριθμό των συγκροτημάτων που ήταν εκεί εκείνη την ώρα

			}
		}
	}

	max=frequency[0];
	index=0;

	for(i=1; i<BAZAAR; i++) //αναζητώ την μεγαλύτερη συχνότητα άρα και την καλύτερη ώρα να πας
	{
		if(frequency[i]>max)
		{
			max=frequency[i];
			index=i;
			//*besttime= hour[index];
		}
	}

	*besttime= hour[index];
}


void PrintArrBands(int rows, int Arr[],int Dep[], char *tab[], int besttime)
{
	int i;

	printf("The attending bands at that time will be: \n");
	for( i=0; i<rows; i++)
	{
		if(Arr[i]<= besttime &&  Dep[i]>besttime)
		{
			printf("%s\n", tab[i]);
		}
	}
}
