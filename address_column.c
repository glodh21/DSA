#include<stdio.h>

int main(){

    printf("FOR 2D ARRAY");

    int A[3][3]={{2,3,5},
                {3,4,8},
                {4,6,7}};
   

    int Trans[3][3],l,m;

    for(l=0;l<3;l++){
        for(m=0;m<3;m++)
            Trans[l][m]=A[m][l];
    }

    printf("The Transpose Matrix\n");
     for(l=0;l<3;l++){
        for(m=0;m<3;m++)
            printf("%d\t",Trans[l][m]);
        printf("\n");
    }

     int *p= &Trans[0][0];

     int i,j,add,add1;

    printf("Enter the value of row and column as i(not greater than 2) and j(same as i condition): ");
    scanf("%d%d",&i,&j);

    int *q = &Trans[i][j];

    printf("the address of array without formula is: %d\n",&Trans[i][j]);

    add = (int)p + (i * 3 * sizeof(int)) +( j* sizeof(int));

    printf("Address of array with formula for above mentioned i and j %d  ", add);


    printf("\nThe difference without formula %d",(int)q - (int)p);

    add1 =  (i * 3 * sizeof(int)) +( j* sizeof(int));
     printf("\nThe difference with formula %d",add1);

     printf("\nthe element: %d\n",Trans[i][j]);

     return 0;
}