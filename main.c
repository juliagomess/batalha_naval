#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void cabecalho(char v)
{
    printf("------------------------------------------\n");
    printf("\tBEM VINDO AO BATALHA NAVAL");
    printf("\n------------------------------------------\n");
    printf("Desenvolvido por: Julia Gomes\tRA:20052387\n");
    printf("\nAperte <enter> para comecar a jogar...");
    scanf("%c",&v);
}

int ** carrega_configuracao(int vez)
{
    int i,j;
    int **tabuleiro;
    tabuleiro=(int **)calloc(10,sizeof (int *));
    if(tabuleiro==NULL) exit(1);
    for(i=0;i<10;i++)
    {
        tabuleiro[i]=(int *) calloc(10,sizeof(int));
        if(tabuleiro[i]==NULL) exit(1);
    }
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            tabuleiro[i][j]=0;
    if(vez%3==0)
    {
        tabuleiro[1][1]=tabuleiro[2][4]=tabuleiro[5][0]=tabuleiro[7][7]=1; ///submarino
        tabuleiro[1][8]=tabuleiro[2][8]=tabuleiro[3][1]=tabuleiro[3][2]=tabuleiro[8][1]=tabuleiro[8][2]=1; ///destroier
        tabuleiro[5][3]=tabuleiro[5][4]=tabuleiro[5][5]=tabuleiro[5][6]=tabuleiro[9][4]=tabuleiro[9][5]=tabuleiro[9][6]=tabuleiro[9][7]=1; ///bombardeiro
        tabuleiro[4][9]=tabuleiro[5][9]=tabuleiro[6][9]=tabuleiro[7][9]=tabuleiro[8][9]=1; ///encouraçado
    }
    else if(vez%5==0)
    {
        tabuleiro[2][4]=tabuleiro[4][9]=tabuleiro[7][3]=tabuleiro[9][1]=1; ///submarino
        tabuleiro[1][1]=tabuleiro[1][2]=tabuleiro[6][0]=tabuleiro[7][0]=tabuleiro[6][6]=tabuleiro[6][7]=1; ///destroier
        tabuleiro[0][7]=tabuleiro[1][7]=tabuleiro[2][7]=tabuleiro[3][7]=tabuleiro[8][6]=tabuleiro[8][7]=tabuleiro[8][8]=tabuleiro[8][9]=1; ///bombardeiro
        tabuleiro[4][1]=tabuleiro[4][2]=tabuleiro[4][3]=tabuleiro[4][4]=tabuleiro[4][5]=1; ///encouraçado
    }
    else if(vez%2==0)
    {
        tabuleiro[4][0]=tabuleiro[3][4]=tabuleiro[2][8]=tabuleiro[8][6]=1; ///submarino
        tabuleiro[1][1]=tabuleiro[2][1]=tabuleiro[6][9]=tabuleiro[7][9]=tabuleiro[7][1]=tabuleiro[8][1]=1; ///destroier
        tabuleiro[0][7]=tabuleiro[0][4]=tabuleiro[0][5]=tabuleiro[0][6]=tabuleiro[4][6]=tabuleiro[4][7]=tabuleiro[4][8]=tabuleiro[4][9]=1; ///bombardeiro
        tabuleiro[9][3]=tabuleiro[5][3]=tabuleiro[6][3]=tabuleiro[7][3]=tabuleiro[8][3]=1; ///encouraçado
    }
    else
    {
        tabuleiro[0][7]=tabuleiro[1][9]=tabuleiro[3][3]=tabuleiro[9][1]=1; ///submarino
        tabuleiro[5][4]=tabuleiro[6][4]=tabuleiro[9][4]=tabuleiro[9][5]=tabuleiro[7][7]=tabuleiro[7][8]=1; ///destroier
        tabuleiro[4][0]=tabuleiro[5][0]=tabuleiro[6][0]=tabuleiro[7][0]=tabuleiro[3][6]=tabuleiro[3][7]=tabuleiro[3][8]=tabuleiro[3][9]=1; ///bombardeiro
        tabuleiro[1][1]=tabuleiro[1][2]=tabuleiro[1][3]=tabuleiro[1][4]=tabuleiro[1][5]=1; ///encouraçado
    }
    return tabuleiro;
}

void desenha_tabuleiro(int** tabuleiro)
{
    int i,j;
    printf("    1   2   3   4   5   6   7   8   9   10   ");
    for(i=0;i<10;i++)
    {
        printf("\n  +---+---+---+---+---+---+---+---+---+---+");
        printf("\n%c |",65+i);
        for(j=0;j<10;j++)
        {
            if(tabuleiro[i][j]==-1)
                printf(" ~ |");
            else if(tabuleiro[i][j]==2)
                printf(" X |");
            else
                printf("   |");
        }
    }
    printf("\n  +---+---+---+---+---+---+---+---+---+---+");
}

int verifica_tiro(int** tabuleiro,int numero,char letra)
{
    numero--;
    switch(tolower(letra))
    {
        case 'a': if(tabuleiro[0][numero]==0) tabuleiro[0][numero]=-1;
                  if(tabuleiro[0][numero]==1) tabuleiro[0][numero]=2;
                  break;
        case 'b': if(tabuleiro[1][numero]==0) tabuleiro[1][numero]=-1;
                  if(tabuleiro[1][numero]==1) tabuleiro[1][numero]=2;
                  break;
        case 'c': if(tabuleiro[2][numero]==0) tabuleiro[2][numero]=-1;
                  if(tabuleiro[2][numero]==1) tabuleiro[2][numero]=2;
                  break;
        case 'd': if(tabuleiro[3][numero]==0) tabuleiro[3][numero]=-1;
                  if(tabuleiro[3][numero]==1) tabuleiro[3][numero]=2;
                  break;
        case 'e': if(tabuleiro[4][numero]==0) tabuleiro[4][numero]=-1;
                  if(tabuleiro[4][numero]==1) tabuleiro[4][numero]=2;
                  break;
        case 'f': if(tabuleiro[5][numero]==0) tabuleiro[5][numero]=-1;
                  if(tabuleiro[5][numero]==1) tabuleiro[5][numero]=2;
                  break;
        case 'g': if(tabuleiro[6][numero]==0) tabuleiro[6][numero]=-1;
                  if(tabuleiro[6][numero]==1) tabuleiro[6][numero]=2;
                  break;
        case 'h': if(tabuleiro[7][numero]==0) tabuleiro[7][numero]=-1;
                  if(tabuleiro[7][numero]==1) tabuleiro[7][numero]=2;
                  break;
        case 'i': if(tabuleiro[8][numero]==0) tabuleiro[8][numero]=-1;
                  if(tabuleiro[8][numero]==1) tabuleiro[8][numero]=2;
                  break;
        case 'j': if(tabuleiro[9][numero]==0) tabuleiro[9][numero]=-1;
                  if(tabuleiro[9][numero]==1) tabuleiro[9][numero]=2;
                  break;
        default: break;
    }
}

void tiro(int *numero,char *letra)
{
    printf("\n\nATIRE!");
    printf("\nLetra + Numero: ");fflush(stdin); scanf("%c%d",letra,numero);
}

char valida_jogo (int** tabuleiro)
{
    int i,j,navios=0;
    char v;
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            if(tabuleiro[i][j]==2)
                navios++;
    if(navios==23)
    {
        printf("\nPARABENS! Voce destruiu todos os navios!");
        printf("\nDeseja jogar novamente?(s/n): "); fflush(stdin); scanf("%c",&v);
        return v;
    }
    else
        return 'x';
}

int main()
{
    int **tabuleiro,vez=0,num;
    char letra,validacao='s',continua;
    cabecalho(continua);
    do
    {
        if(validacao=='s')
        {
            vez++;
            tabuleiro=carrega_configuracao(vez);
            validacao='x';
        }
        system("cls");
        desenha_tabuleiro(tabuleiro);
        tiro(&num,&letra);
        verifica_tiro(tabuleiro,num,letra);
        validacao=valida_jogo(tabuleiro);
    }while(tolower(validacao)!='n');
    printf("\n\n");
    return 0;
}
