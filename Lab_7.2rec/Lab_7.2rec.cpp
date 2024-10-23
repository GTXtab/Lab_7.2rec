#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo);
void CreateRows(int** a, const int N, const int Low, const int High, int rowNo);
void PrintRow(int** a, const int rowNo, const int N, int colNo);
void PrintRows(int** a, const int N, int rowNo);
int Search(int* row, const int N, int colNo, int minIndex);
void Swap(int** a, const int N, int rowNo);

int main()
{
    srand((unsigned)time(NULL));

    int N;
    cout << "N = "; cin >> N;

    int** a = new int* [N];
    for (int i = 0; i < N; i++)
        a[i] = new int[N];

    int Low = 0, High = 9;

    cout << "Main Matrix:" << endl;
    CreateRows(a, N, Low, High, 0);
    PrintRows(a, N, 0);

    Swap(a, N, 0);

    cout << "Changed matrix:" << endl;
    PrintRows(a, N, 0);

    for (int i = 0; i < N; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

void CreateRows(int** a, const int N, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, N, Low, High, 0);
    if (rowNo < N - 1)
        CreateRows(a, N, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int N, int rowNo)
{
    PrintRow(a, rowNo, N, 0);
    if (rowNo < N - 1)
        PrintRows(a, N, rowNo + 1);
    else
        cout << endl;
}

int Search(int* row, const int N, int colNo, int minIndex)
{
    if (row[colNo] < row[minIndex])
        minIndex = colNo;
    if (colNo < N - 1)
        return Search(row, N, colNo + 1, minIndex);
    else
        return minIndex;
}

void Swap(int** a, const int N, int rowNo)
{
    if (rowNo < N) {
        int minIndex = Search(a[rowNo], N, 0, 0);
        int secondaryDiagIndex = N - 1 - rowNo;

        if (minIndex != secondaryDiagIndex) {
            int temp = a[rowNo][minIndex];
            a[rowNo][minIndex] = a[rowNo][secondaryDiagIndex];
            a[rowNo][secondaryDiagIndex] = temp;
        }

        Swap(a, N, rowNo + 1);
    }
}