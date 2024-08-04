#include<stdio.h>

int main(){

    printf("FOR 2D ARRAY");

    int A[3][2]={{2,3},{3,4},{4,6}};
    int *p= &A[0][0];

    
    
    
     int i,j,add,add1;

    printf("Enter the value of row and column as i(not greater than 2) and j(same as i condition): ");
    scanf("%d%d",&i,&j);

    int *q = &A[i][j];

    printf("the actual address of array  formula is: %d\n",&A[i][j]);

    add = (int)p + (i * 2 * sizeof(int)) +( j* sizeof(int));

    printf("Calculated Address of array for above mentioned i and j %d  ", add);

    printf("\nThe  actual difference %d",(int)q - (int)p);

    add1 =  (i * 2 * sizeof(int)) +( j* sizeof(int));
     printf("\nThe calculated difference %d",add1);

      int B[6],l,m;

    for(l=0;l<3;l++)
        {
            for(m=0;m<2;m++)
            B[l*2 + m]=A[l][m];
        }
    printf("\nConverted to 1D matrix    ");
    for(l=0;l<6;l++)
    {
        printf("%d\t",B[l]);
    }
    

 /* printf("**********************************************************************\n");

    printf("FOR 3D ARRAY\n");

    int B[2][3][4]={
        {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
        },
        {
            {13, 14, 15, 16},
            {17, 18, 19, 20},
            {21, 22, 23, 24}
        }
    };
    int *q= &B[0][0][0];
     int i,j,k,add;

    printf("Enter the value of row and column as i(not greater than 2) and j(same as i condition) and k: ");
    scanf("%d%d%d",&i,&j,&k);

    printf("the address of array without formula is: %d\n",&B[i][j][k]);

    add = (int)q+ (i * 3 * sizeof(int)* 4) +( j* sizeof(int) * 4)+ (k * sizeof(int));  // 3 is numbern of column and 4 is number of depth

    printf("Address of array with formula for above mentioned i,j and k %d  ", add);*/


    return 0;
}