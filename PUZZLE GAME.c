//number reodering puzzle
// by NAGULESH N CSE(I) DEPT
//IQUBE task 2

#include<stdio.h>
#include<time.h>

int mat[3][3];

void create()
{
    printf("\n***** WELCOME TO SLIDING PUZZLE GAME ****\t\n\n\t**** IQUBE ******\n");
    int found,a[9],R,C,i,j,t;
    srand(time(0));
for(i=0;i<9;)
{
t=rand()%9;
found=0;
for(j=0;j<i;j++)
{
    if(t==a[j]){

       found=1;
       break;
}
}
if(found==0)
{
    a[i]=t;
    R=i/3;
    C=i%3;
    mat[R][C]=t;
    i++;
}
}
}
void display(){
    printf("\n------------------------\n");
    int i,j,count;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
        if(mat[i][j]==0)
        printf("| %3c \t",' ');
        else
        printf("| %3d \t",mat[i][j]);
        }
        printf("|\n------------------------\n");
    }

}

void play(){
int swap,i,j;
display();

if(mat[2][2]==0&&mat[2][1]==8&&mat[2][0]==7&&mat[1][2]==6&&mat[1][1]==5&&mat[1][0]==4&&mat[0][2]==3&&mat[0][1]==2&&mat[0][0]==1)
{

     printf("\nCONGRATION YOU WON THE GAME\n");

}

else{
printf("\nENTER THE ADJACENT VALUE YOU NEED TO MOVE: \n");
scanf("%d",&swap);
if(swap>=1&&swap<=8){
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){

            if(mat[i][j]==swap){
                    printf("\nNumber found \n");
                    goto a;
        }
        }
    }

    a://left
    if(j>0){
        if(mat[i][j-1]==0){
            mat[i][j-1]=mat[i][j];
            mat[i][j]=0;
        }
    }//right
    if(j<2){
        if(mat[i][j+1]==0){
            mat[i][j+1]=mat[i][j];
            mat[i][j]=0;
        }
    }
    //up
    if(i>0){
        if(mat[i-1][j]==0){
            mat[i-1][j]=mat[i][j];
            mat[i][j]=0;
        }
    }//down
    if(i<2){
        if(mat[i+1][j]==0){
            mat[i+1][j]=mat[i][j];
            mat[i][j]=0;
        }
    }
    if(mat[i][j]!=0){
        printf("\n!! swap is not possible !!");
    }

}
else{
    printf("\n wrong input ");
}
printf("\n   tap to continue....    ");
getch();
system("cls");
play();
}
}

int main()
{
    printf("\tGame instruction\t\n 1.move the numbers adjacent to the gap space \n 2.enter the adjacent number values\n 3.arrange the numbers in order to complete the game[r1= 1 2 3 r2= 4 5 6 r3= 7 8]\n");
create();
play();
}
