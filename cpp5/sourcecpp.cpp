#include <iostream>
#define refarr auto arr=*(double (*)[a.row][a.col])a.parr
#define refbrr auto brr=*(double (*)[b.row][b.col])b.parr
#define refcrr auto crr=*(double (*)[c.row][c.col])c.parr

struct matrix{
int   row;
int   col;
void  *parr;
};
void MatrixPrint(matrix a, std::string s){
    refarr;
    std::cout << a.row << "x" << a.col << " Matrix "<< s << std::endl;
    for(int i=0; i<a.row; i++){
        for(int j=0; j<a.col; j++)
            std::cout << arr[i][j] <<" ";
        std::cout << std::endl;
    }
}
void MatrixMulABtoC(matrix a, matrix b, matrix c){
    refarr;
    refbrr;
    refcrr;
    for(int k=0; k<b.col; k++)
        for(int i=0; i<a.row; i++){
            crr[i][k]=0;
            for(int j=0; j<a.col; j++)
                crr[i][k]=crr[i][k]+arr[i][j]*brr[j][k];
        }
}

int main()
{
double c[3][3]{};
matrix C{3,3,c};

double a[3][3]{4,-1, 3,
               4,-2,-6,
               2, 0, 3};
matrix A{3,3,a};

MatrixPrint(A,"A");

double b[3][3]{5, 3,-7,
              -1, 6,-3,
               2,-4, 1};
matrix B{3,3,b};

MatrixPrint(B,"B");

MatrixMulABtoC(A,B,C);
MatrixPrint(C,"AxB=C");

double m0[2][2]{1,2,3,4};     
double m1[2][2]{1,0,0,1};     
double m2[2][2]{21,22,23,24};     
matrix M[3]{{2,2,m0},{2,2,m1},{2,2,m2}};

for (int i=0; i<3; i++)
    MatrixPrint(M[i],"M["+std::to_string(i)+"]");

MatrixMulABtoC(M[0],M[1],M[2]);
MatrixPrint(M[2],"M[2]=M[0]xM[1]");

    return 0;
}

