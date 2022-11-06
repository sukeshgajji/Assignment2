#include <iostream>
using namespace std;
 
int main()
{
    int sparseMatrix[4][5] =
    {
        {0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {1 , 2 , 0 , 0 , 5 },
        {0 , 2 , 6 , 0 , 0 }
    };
 
    int size = 0, nonzeros = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 5; j++){
            size++;
            if (sparseMatrix[i][j] != 0){
                nonzeros++;
            }
        }
    }
    cout << "The matrix is:\n";
    for (int i = 0; i < 4; i++)
    {
    for (int j = 0; j < 5; j++)
    {
        cout << sparseMatrix[i][j] << " ";
    }
    cout << endl;
    }
    if ((size - nonzeros) > size/2)
        {
            cout << "This is a sparse Matrix. It's array representation is shown below:\n";
            int compactMatrix[3][nonzeros];
            int k = 0;
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 5; j++)
                    if (sparseMatrix[i][j] != 0)
                    {
                        compactMatrix[0][k] = i;
                        compactMatrix[1][k] = j;
                        compactMatrix[2][k] = sparseMatrix[i][j];
                        k++;
                    }
            for (int i=0; i<3; i++)
            {
                for (int j=0; j<nonzeros; j++)
                    cout << compactMatrix[i][j] << " ";
        
                cout <<"\n";
            }
        }
        else {
            cout << "This is not a sparse matrix.";
        }
    
    return 0;
}