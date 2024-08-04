#include<stdio.h>
#include<stdlib.h>
#include<time.h>



float **Matrix(int n1,int n2){
    
    int i;
    float **matrix=(float **)malloc(n1*sizeof(float*));

        for(i=0;i<n1;i++){
            matrix[i]=(float*)malloc(n2*sizeof(float));
        
        }
        return matrix;
}

void Accept(float **matrix, int n1, int n2) {
    
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }
}

void Print(float **matrix,int n1,int n2){

    int i,j;
    for(i=0;i<n1;i++){
        for(j=0;j<n2;j++)
            printf("%f\t",matrix[i][j]);

            printf("\n");
    }
    

}

int main(){

    int i,j,k,n;
    float **mat1,**mat2,**mat3;

     srand(time(NULL));

    printf("enter number of rows and columns: ");
    scanf("%d",&n);

    clock_t t;
    t=clock();


     mat1=Matrix(n,n);
     mat2=Matrix(n,n);
     mat3=Matrix(n,n);

     for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            mat1[i][j] = (float)(rand() % 100); 
        }
    }
    
      for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            mat2[i][j] = (float)(rand() % 100); 
        }
    }

     for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            mat3[i][j]=0;
            for(k=0;k<n;k++){
             mat3[i][j]+=mat1[i][k]*mat2[k][j];
                
            }
        }
    }
     
    t = clock() - t;
    printf("Time taken:  %lf secs\n", (double)t / CLOCKS_PER_SEC);

      for (int i = 0; i < n; i++) {
        free(mat1[i]);
        free(mat2[i]);
        free(mat3[i]);
    }
    free(mat1);
    free(mat2);
    free(mat3);
    return 0;
}

