#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "I17.h"
//gcc -Wall -o I17 I17.c


/**
    A=PLUQ
Where:
    P is a permutation matrix.
    L is a lower triangular matrix.
    U is an upper triangular matrix.
    Q is another permutation matrix.

The determinant of matrix A can be expressed as:
det(A)=det(P)⋅det(L)⋅det(U)⋅det(Q)

**/

double** creer_Matrice(n){
    double** matrice = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        matrice[i] = (double*)malloc(n * sizeof(double));
    }
    return matrice;
}

void liberer_matrice(double** A, int n){
    for(int i=0; i<n; i++){
        free(A[i]);
    }
    free(A);
}

void afficheMatrice(double**A, int n){
    for(int i=0; i<n ;i++){
        for(int j = 0; j<n; j++){
            printf("%0.2lf ",A[i][j]);
        }
        printf("\n");
    }
}
/**
Algorithm 1: UpperTriangularSystemAlgorithm
    Input: An upper triangular matrix = (a_i,j 0<=i,j<=n-1 with coefficients in IK, with
    nonzero diagonal coefficients, and a vector b = (b_i)0<=i<=n-1, with coefficients in IK.
    Output: The vector x = (x_i)0<=i<=n-1, with coefficients in IK, such that Ax = b.
    For i from =  n-1 to 0 do x_i:= b_i;
    For i from =  n-1 to 0 do
        x_i:= x_i/a_i,i;
        For j from i-1 to 0 do x_j:=x_j-a_j,i
    Return x
 */

void UpperTriangularSystemAlgorithm(double** A, double* b, double* x, int n) {
    for(int i=n-1; i>=0;i--){
        x[i]=b[i];

        x[i]=x[i]/A[i][i];

        for(int j=i-1; j>=0; j--){
            x[j]-=x[i]* A[j][i];
        }

    }
}

/**
Algorithm 2: GaussianEliminationAlgorithm
    Input: A matrix = (a_i,j 0<=i,j<=n-1 with coefficients in IK, and a vector b = (b_i)0<=i<=n-1, with coefficients in IK.
    Output: An upper triangular matrix and a vector yielding an equivalent system as the input or “No unique solution”.
    For i from 0 to n-1 do
        j:=i
        While j < n Λ aj,i = 0 do j:=j+1
        If j=n then Return “No unique solution”.
        t_i..n-1 :=a_i,i..n-1, u:=b_i;
        a_i,i..n-1 :=a_j,i..n-1, b_i:=b_j;
        a_j,i..n-1 :=t_i..n-1, b_j:=u;
        For j from i + 1 to n - 1 do
            b_j:=b_j - a_j,ib_i/a_i,i
            a_j,i..n-1 :=a_j,i..n-1 - a_j,ia_i,i/a_i,i
    Return A, b
 */

void GaussianElimination(double** A, double* b, int n){
    for(int i=0; i<n; i++){
        int j=i;

        while(j<=n && A[j][i]=0){
            j++;
        }
        if (j=n){
            printf("No unique solution.\n");
        }

        // Step 3: Swap the rows if necessary
        if (j != i) {
            // Swap row i and row j in A
            double* temp = A[i];
            A[i] = A[j];
            A[j] = temp;

            // Swap corresponding entries in b
            double temp_b = b[i];
            b[i] = b[j];
            b[j] = temp_b;
        }

        // Step 4: Eliminate entries below the pivot
        for (int j = i + 1; j < n; j++) {
            double factor = A[j][i] / A[i][i];

            // Update the corresponding row in matrix A
            for (int k = i; k < n; k++) {
                A[j][k] -= factor * A[i][k];
            }

            // Update the right-hand side vector b
            b[j] -= factor * b[i];
        }
    }


}

// Fonction pour échanger des lignes pour la matrice de permutation
void echange_ligne(double** mat, int l1, int l2, int n){
    for (int i=0; i<n; i++){
        double tmp = mat[l1][i];
        mat[l1][i]= mat[l2][i];
        mat[l2][i]= tmp;
    }
}

// Fonction pour échanger des colonne pour la matrice de permutation
void echange_colonne(double** mat, int c1, int c2, int n){
    for (int i=0; i<n; i++){
        double tmp = mat[i][c1];
        mat[i][c1]= mat[i][c2];
        mat[i][c2]= tmp;
    }
}

double abs_x(double x){
    if(x>=0){
        return x;
    }else{
        return -x;
    }
}

// Fonction pour calculer la décomposition et le déterminant PLUQ
double pluq(int n, double** A/*, double** res*/){
    int *P = malloc(n * sizeof(int)); //用来表示矩阵 P（行置换矩阵）。矩阵 P 的每一行是通过行交换来记录的。, P 是一个指向动态分配内存的指针。我们用这个数组来记录高斯消元时每次行交换的结果。
    int *Q = malloc(n * sizeof(int)); //Q 数组是用来存储列置换矩阵 Q 的置换信息（列置换）
    
    //这些变量初始化为1，用于存储置换矩阵 P 和 Q 的行列式。置换矩阵的行列式 det⁡(P) 和 det(Q) 是 1 或 −1，这取决于行和列的交换次数（即奇偶性）。
    //如果进行了奇数次交换，行列式为 −1；如果进行了偶数次交换，行列式为 1。 Chaque fois multiplie -1
    double detP = 1, detQ = 1;

    //这个变量用于存储上三角矩阵 U 的行列式。由于 U 是上三角矩阵，它的行列式是对角线上所有元素的乘积。
    //初始化为1，在 PLUQ 分解过程中，我们会遍历上三角矩阵 U，将对角线元素相乘，得到 U 的行列式。
    double detU = 1;

    // Initialisation permutation  P et Q
    //P[i] = i 和 Q[i] = i 的意思是，初始化时，行和列还没有发生任何交换。也就是说，矩阵中的每一行和每一列保持其原始顺序。
    //记录了在分解过程中，矩阵行和列的交换情况
    //如果在某一步需要交换第1行和第3行，就会更新 P 数组，使 P[0]=2 和 P[2]=0，表示第1行和第3行交换了
    for (int i= 0; i<n; i++) {
        P[i]=i;
        Q[i]=i;
    }

    for (int j=0; j<n; j++){
        // trouver pivot de PLUQ
        
        //表示当前认为的主元位于子矩阵的第 k 行、第 k 列。
        int lpivot = j;
        int cpivot = j;

        //j 是当前进行分解的步骤。例如，第一次循环时 j=0，我们在整个矩阵中寻找主元；第二次循环时 j=1，我们在剩下的子矩阵中寻找主元，以此类推。
        for(int i=j; i<n; i++){
            for(int k=j; k<n; k++){
                //寻找最大主元 chercher le pivot absolu max
                if(fabs(A[i][k])>fabs(A[lpivot][cpivot])){
                    lpivot = i;
                    cpivot = k;
                }
            }
        }

        // Échanger les lignes de la matrice A pour la décomposition PLUQ
        if (lpivot != j) {
            echange_ligne(A, j, lpivot, n);
            detP *= -1; // 行交换改变detP的符号
        }
        // Échanger les colonnes de la matrice A pour la décomposition PLUQ
        if (cpivot != j) {
            echange_colonne(A, j, cpivot, n);
            detQ *= -1; // 行交换改变detQ的符号
        }

        //Mise à jour des P et Q
        int tmpP = P[j];
        P[j]=P[lpivot];
        P[lpivot]= tmpP;

        int tmpQ = Q[j];
        Q[j]=Q[cpivot];
        Q[cpivot]= tmpQ;

        //Étape d'élimination gaussienne

        //从当前处理的行 j 的下一行开始，遍历到矩阵的最后一行。目的是处理所有在当前列 j 下面的行（即第 j 列的元素）
        for(int i = j+1; i < n; i++){
            A[i][j] /=A[j][j]; // 计算消元因子,将第 i 行的第 j 列元素（当前列）除以第 j 行的第 j 列元素，计算出消元因子（或称比例因子）。
            for(int k=j+1; k<n; k++){
                //通过从当前行中减去合适的倍数，以消去第 j 列的元素。最终使得第 j 列下方的元素变为零，从而将矩阵变成上三角形的形式。
                A[i][k] -=A[i][j] * A[j][k];
            }
        }

        // 计算U的行列式，通过对角线元素相乘
        detU *= A[j][j];

    }

    // 将分解后的矩阵结果保存到res中
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = A[i][j];
        }
    }*/

    // 最终的行列式计算
    double determinant = detP * detU * detQ;

    // Free allocated memory
    free(P);
    free(Q);

    return determinant;
}

int main() {
    int n = 3;
    // Define a 3x3 matrix
    double *matrix[] = {
        (double[]){1, 2, 3},
        (double[]){4, -6, 6},
        (double[]){7, 8, 9}
    };

    afficheMatrice(matrix,3);
    // Compute determinant using PLUQ decomposition
    double det = pluq(n, matrix);
    printf("Determinant: %lf\n", det);

    return 0;
}