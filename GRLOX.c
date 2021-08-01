/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
void delayMS(int delay);
void Sequence(char Str_Req[5]);
void Found_Function(char Sequence_Attempt[20]);
void TimeoutFunction(char Sequence_Attempt[20]);
int main()
{
 
   for(int i = 0; i < 20; i++)
   {
       printf("%d Attempt:\n",i);
       Sequence("GRLOX");
   }
    return 0;
}
void Sequence(char Str_Req[5])
{
    char Sequence_Attempt[20];
    char letter;
    int i;
    int j =0;
   for(i = 0; i < 20; i++)
    {
        
        letter = rand() % 128;
        if(letter<=64) letter = letter + 64;
        Sequence_Attempt[i] = letter;
        if(Sequence_Attempt[i] == Str_Req[j])
        {
            j++;
        }
        if(j==5)
        {
            Found_Function(Sequence_Attempt);
            i=20;
            
        }
        delayMS(100);
    } 
    if(j != 5 && i == 20 )
    {
    TimeoutFunction(Sequence_Attempt);
    }
    
}
void TimeoutFunction(char Sequence_Attempt[20])
{
    printf("The word is not found");
    printf(" INPUT : ");
    printf("{ ");
    for(int i = 0; i < 20; i++)
    printf("%c ",Sequence_Attempt[i]);
    printf("}\n");
}
void Found_Function(char Sequence_Attempt[20])
{
    printf("The word is found");
    printf(" INPUT : ");
    printf("{ ");
    for(int i = 0; i < 20; i++)
    printf("%c ",Sequence_Attempt[i]);
    printf("}\n");
}

void delayMS(int delay)
{
	volatile int i;
	for(;delay>0;delay--)
	{
		for(i = 0;i<3195;i++);
	}
}
