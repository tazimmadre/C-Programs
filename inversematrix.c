#include<stdio.h>
   #include<math.h>
   #include<conio.h>
float determin(float** [][40], float);
void cofac(float** [][40], float);
void trans(float** [][40], float** [][40], float);

int main(){
                float **matrix[40][40], deter;
                int a, b, row, col;
                
                printf("Enter size of the Matrix : ");
                scanf("%d %d", &row, &col);
                if(row==col){
                printf("Enter the elements of %d X %d matrix : \n", row, col);
                for(a=0;a<row;++a){
                for(b=0;b<col;++b){
                scanf("%f",&matrix[a][b]);
                }
                }
               deter = determin(matrix, row);
               printf("\n The Determinant of the Matrix is : %f", deter);
               if(deter == 0)
               printf("\n Inverse of Matrix is not possible for the matrices having 0 Determinant value !!\n");
               else
               cofac(matrix, row);
               }
               else
               printf("\n Inverse of Matrix is possible for Square matrix !! Kindly give same number of rows and columns \n");
               return(0);
               }

   float determin(float** matrix[40][40], float k){
               float deter=0.0, z=1.0, **mt[40][40];
               int a, b, c, x, y;
               if(k==1)
               {
               return 1;
               }
               else
               {
               deter=0;
               for(a=0;a<k;++a){
               x=0;
               y=0;
               for(b=0;b<k;++b){
               for(c=0;c<k;++c){
               mt[b][c]=0;
               if((b != 0) && (c != a))
               {
               mt[x][y]=matrix[b][c];
               if(y<(k-2))
               y++;
               else
               {
               y=0;
               x++;
               }
               }
               }
               }
               deter=deter + z * (**matrix[0][a] * determin(mt,k-1));
               z=-1 * z;
               }
               }
               return(deter);
               }

// This function is to find cofactors of matrix . . .

   void cofac(float** comatr[40][40], float f){
               float** matr[40][40], **cofact[40][40];
               int a, b, c, d, x, y;
               for(c=0; c<f; ++c){
               for(d=0; d<f; ++d){
               x=0;
               y=0;
               for(a=0;a<f; ++a){
               for(b=0; b<f; ++b){
               if(a != c && b != d)
               {
               matr[x][y]=comatr[a][b];
               if(y<(f-2))
               y++;
               else
               {
               
               y=0;
               x++;
               }
               }
               }
               }
               **cofact[c][d] = pow(-1,c + d) * determin(matr,f-1);
               }
               }
               trans(comatr, cofact, f);
               }

// This function is to transpose of matrix . . .

   void trans(float** matr[40][40], float** m1[40][40], float r){
              float inv_matrix[40][40], **tran[40][40], d;
              int a,b;
              for(a=0;a<r;++a){
              for(b=0;b<r;++b){
              tran[a][b]=m1[b][a];
              }
              }
              d=determin(matr, r);
              for(a=0;a<r;++a){
              for(b=0;b<r;++b){
              inv_matrix[a][b]=**tran[a][b] / d;
              }
              }
              printf("\n\n\n The Inverse of matrix is . . . \n\n");
              for(a=0;a<r;++a){
              for(b=0;b<r;++b)
              printf("\t%f", inv_matrix[a][b]);
              printf("\n\n");
              }
              }

     
// This function is to find the determinant value of matrix . . .
