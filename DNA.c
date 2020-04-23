#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DNA_Molecule
{
 char Alpha;
 char Beta;
 struct  DNA_Molecule* next;
};
typedef struct DNA_Molecule DNA_Molecule;    
int Counter;
DNA_Molecule*DNA_Molecule_IDS[10000];    
//pairing
char ATCG(char m)  
{
  if (m =='A')
   return 'T';
  if (m == 'T')      
   return 'A';
  if (m == 'C')  
   return 'G';
  if (m == 'G')    
   return 'C';
  else
   return m;
}
//function for creating the DNA Molecule
void Create_Molecule(char str[] )        
{
int length = strlen(str);
for (int i=0; i<length; i++)
{
if (str[i]!='A'&& str[i] != 'T' && str[i] != 'C' && str[i] != 'G' )
 printf("Not a valid input\n");
return;
}
DNA_Molecule* node = (DNA_Molecule*)malloc(sizeof(DNA_Molecule));
DNA_Molecule* K = node;
DNA_Molecule_IDS[Counter++] = node;
K -> Alpha = str[0];
K -> Beta = ATCG(str[0]);
K -> next = NULL;
for (int i; i<length; i++)
     {
       K -> next = (DNA_Molecule*)malloc(sizeof(DNA_Molecule)) ;
       K = K -> next;
       K -> Alpha = str[i];
       K ->Beta = ATCG(str[i]);
       K ->next = NULL;
     }
}
//function for inserting
void Insert (int DNA_Molecule_ID, int DNA_Chain_ID, char Nucleotide, int Position )
{
if ( DNA_Molecule_ID > Counter )
{
printf("Incorrect Molecule ID\n");
return;
}

if (DNA_Chain_ID!= 1 && DNA_Chain_ID!= 2)
{
printf("Incorrect Chain ID\n");
return;
}
DNA_Molecule* K = DNA_Molecule_IDS[DNA_Molecule_ID -1];
DNA_Molecule* K2 = (DNA_Molecule*)malloc(sizeof(DNA_Molecule));
DNA_Molecule* K1 = DNA_Molecule_IDS[DNA_Molecule_ID -1];
int Pos;
if ( Position == 1 )
{
if ( DNA_Chain_ID == 1 )    
{
K2 -> Alpha = Nucleotide;
K2 -> Beta = ATCG( Nucleotide);
}
else      
{
K2 -> Beta = Nucleotide;
K2 -> Alpha =ATCG(Nucleotide);
}  
K2-> next = K;  
DNA_Molecule_IDS[DNA_Molecule_ID - 1] = K2;  
   return;
    }
        while (K != NULL)
{
           if (Pos == Position-1)
  {
K1 = K;
  }
  else if (Pos == Position)
  {
K1 -> next = K2;
if (DNA_Chain_ID == 1)
{
  K2 -> Alpha = Nucleotide;
  K2 -> Beta = ATCG(Nucleotide);
}
else  
{
   K2 -> Beta = Nucleotide;
K2 -> Alpha = ATCG(Nucleotide);
}
K2 -> next = K;
break;
}
  K = K -> next;
  Pos++;
}
if (K == NULL)
printf("Incorrect Position \n");
return;
}
//function for delete
void Delete ( int DNA_Molecule_ID, int Position )
{
if ( DNA_Molecule_ID > Counter )
{
printf("Incorrect Molecule ID\n");
return;
}
DNA_Molecule* K = DNA_Molecule_IDS[DNA_Molecule_ID-1];
DNA_Molecule* K1 = K ;
int Pos = 1;
if (Position == 1)
{
if (K -> next == NULL)
{
 Counter--;
 printf("Successfully deleted a molecule\n");
 return;
}
 DNA_Molecule_IDS[DNA_Molecule_ID-1] = K -> next;
      return;
}
while (K != NULL)    
{
        if (Pos == Position - 1)      
        {
            K1 = K;
        }
        else if (Pos == Position)
        {
            K1 -> next = K -> next;
            break;
        }
        K = K -> next;
        Pos++;  
    }
    if (K == NULL)
    printf("Incorrect position \n");
    return;
}
//function for splitting the chain
void Split (int DNA_Molecule_ID)
{
char str[10000];
int length =0;
DNA_Molecule* K = DNA_Molecule_IDS[DNA_Molecule_ID-1];
while(K -> next !=NULL)
     {
 str[length++] = K -> Beta;
 K = K -> next;
     }
   str[length] = '\0';
   Create_Molecule(str);
}
//function for printing the chain
void PrintChain(int DNA_Molecule_ID)
{
if (DNA_Molecule_ID > Counter)
{
printf("Incorrect Molecule ID\n");
return;
}
DNA_Molecule*K = DNA_Molecule_IDS [DNA_Molecule_ID -1];
int N_Count = 0;
printf("\n");
while(K -> next != NULL)
{
printf("%c-",K -> Alpha );
K = K -> next;
N_Count++;
}
printf("%c", K -> Alpha);
N_Count++;
printf("\n");
for (int i=0; i< N_Count; i++)
{
printf("| ");
printf("\n");
K = DNA_Molecule_IDS[DNA_Molecule_ID-1];
while(K -> next != NULL)
{
          printf("%c-", K -> Beta);
          K  = K -> next;
        }
   printf("%c", K -> Beta);
   printf("\n\n");
   return;
     }
}
//Function to print all the chains
void Print_AllChains()
{
if (Counter == 0)  
{
        printf("No chains to print \n");
        return;
    }

    for (int i=1; i <= Counter; i++)  
    {
        PrintChain(i);
        printf("\n");
    }
    return;
}
//allfunctions
void Create_Molecule(char str[]);
void Insert(int DNA_MoleculeID, int DNA_ChainID, char Nucleotide, int Position);
void Delete(int DNA_MoleculeID, int Position);
void Split(int DNA_MoleculeID);
void PrintChain(int DNA_MoleculeID);
void Print_AllChains();
char ATCG (char m);

//The Execution Of The Program
int main()
{
  while (1)
{
printf("What should be done? \n");
printf(" 1. Create a Molecule \n 2. Insert \n 3. Delete \n 4. Split \n 5. Print the chain \n 6. Print all the chains \n 7. Exit \n \n");
int Choice;
scanf("%d",&Choice);

if (Choice == 1)
{
char str[10000];
printf("Enter the string: \n");
scanf("%s", str);

Create_Molecule(str);
   }
else if (Choice == 2)
{
int DNA_Molecule_ID,DNA_Chain_ID,Position;
char Nucleotide;
printf("Enter the DNA molecule ID: \n");
scanf("%d", &DNA_Molecule_ID);
printf("Enter the chain ID: \n");
scanf("%d", &DNA_Chain_ID);
printf("Enter the position of node to insert: \n");
scanf("%d", &Position);
printf("Enter the nucleotide to be inserted: \n");
scanf("%c", &Nucleotide);

Insert(DNA_Molecule_ID, DNA_Chain_ID, Nucleotide, Position);
}
else if (Choice == 3 )
{
int DNA_Molecule_ID, Position;
printf("Enter the molecule ID: \n");
scanf("%d", &DNA_Molecule_ID);
printf("Enter the position of nucleotide that is to be deleted: \n" );
scanf("%d", &Position);
Delete(DNA_Molecule_ID, Position);
}
else if (Choice == 4 )
{
int DNA_Molecule_ID;
printf("Enter the DNA molecule ID that is to be split: \n");
scanf("%d", &DNA_Molecule_ID);
Split(DNA_Molecule_ID);
}
else if  ( Choice == 5 )
{
int DNA_Molecule_ID;
printf("Enter the DNA molecule ID that is to be printed: \n");
scanf("%d", &DNA_Molecule_ID);
PrintChain(DNA_Molecule_ID);
}
else if ( Choice == 6 )
{
Print_AllChains();
}
else if ( Choice == 7)
{
printf("Program ended. \n");
break;
}
else
{
printf("Incorrect choice. Select a valid function.\n");
}

}
return 0;

}
