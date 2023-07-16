#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//���������� ������� ������� ����������� ������� �������� ���������
//5x1 +      4x3 + x4  = 10
//3x1 +8x2             = 11
//     2x2 + 4x3 + 3x4 = 9
//2x1 +            6x4 = 8
//������ ������� �������: x1 = x2 = x1 = x2 = 1
 
int main( )
{
    
    vector<double> a[4];//������ �������� ��� ������ ��������� ������������� ������� �������� ���������
    double *x;//��������� �� ������ ���������� ������� �������� ���������
    vector<int> icol[4];//������ �������� ��� ������ ������� �������� ��������� ������������� ������� �������� ���������
    double eps = 10E-7;//�������� �������� �������
    int i, iter;
    int n = 4;//������� ������� �������� ���������
    int maxiter = 100;//������������ ����� �������� 
    int Seidelmethod2(vector<double> [],double [], double *, int n, vector<int>[], double eps, int maxiter);
    
    x = new double[4];//�������� ������ ��� ������� ���������� ������� �������� ���������
    
    for(i = 0; i<4; i++)x[i] = 0.0;//���������� ��������� �������� ���������� ������� �������� ���������
    //���������� ��������� ������������ ������� �������� ��������� � ������ ��������
    a[0].push_back(5.0); a[0].push_back(4.0); a[0].push_back(1.0);
    a[1].push_back(3.0); a[1].push_back(8.0);   
    a[2].push_back(2.0); a[2].push_back(4.0); a[2].push_back(3.0);
    a[3].push_back(2.0); a[3].push_back(6.0);
    
    double b[4] = {10, 11, 9, 8};//������ ������ ����� ������� �������� ��������� 
    //���������� ������ �������� ��������� ������������� ������� �������� ��������� � ������ ��������
    icol[0].push_back(0); icol[0].push_back(2); icol[0].push_back(3);
    icol[1].push_back(0); icol[1].push_back(1);
    icol[2].push_back(1); icol[2].push_back(2); icol[2].push_back(3);
    icol[3].push_back(0); icol[3].push_back(3);
    //������ ������� �������� ���������   
    iter = Seidelmethod2( a, b, x, n, icol, eps, maxiter);
    for(i = 0; i<4; i++)cout << x[i] << endl;
    delete []x;
    cout << "iter = " << iter << endl;
    cout << "Press the enter key to continue ...";
    cin.get();
    return 0;
}

//��������� ������� ������� �������� ��������� � ������������ ����������� ����������� �������� �������������,
//��������� � ������ ������������� ��������
int Seidelmethod2(vector<double> a[], double b[], double *x, int n, vector<int> icol[], double eps, int maxiter)
{
    int i, j, k, ind, iter, nicoli, jx;
    double sum, aij, x1;
     
    for(iter = 1; iter <= maxiter; iter++)
    {
        for(k = i = 0, ind = 1; i < n; i++)
        {
            for(j = 0, sum = 0.0, nicoli = a[i].size(); j < nicoli; j++)
            {
                jx = icol[i][j];
                if(i != jx)sum += a[i][j]*x[jx];
                else aij = a[i][j];
            }
            x1 = x[i];
            x[i] = (b[i] - sum)/aij;
            if(abs(x1 - x[i]) > eps)ind = 0;
        }
        if(ind)break;
    }
    return iter;
}
