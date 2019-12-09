#include<iostream>
using namespace std;
int input_matrix_num;
int p[100];
int m_Matrix(int i, int j);
void print_optimal(int i, int j);
int m[100][100];
int a = 0;
int b = 0;
int c = 0;
int d = 0;
int s[100][100];
int main() {
    cout << "�������ĸ�����";
    cin >> input_matrix_num;
    cout << "������" << input_matrix_num + 1 << "�����������ֱ��Ǹ��������������" << endl;
 
    for (int i = 0;i < input_matrix_num + 1;i++) {
        cin >> p[i];
    }
 
    cout << "ԭʼ����Ϊ���¾���" << endl;
    for (int i = 0;i < input_matrix_num;i++) {
        cout << "\t" << p[i] << " * " << p[i + 1] << endl;
    }
 
    cout << "m����" << endl;
    for (int i = 1;i <= input_matrix_num;i++) {
        for (int j = 1;j <= input_matrix_num;j++) {
            m[i][j] = m_Matrix(i, j);
        }
    }
 
    for (int i = 1;i <= input_matrix_num;i++) {
        for (int j = 1;j <= input_matrix_num;j++) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
 
    cout << endl;
    cout << "s����" << endl;
    for (int i = 1;i <= input_matrix_num;i++) {
        for (int j = 1;j <= input_matrix_num;j++) {
            cout << s[i][j] << "\t";
        }
        cout << endl;
    }
 
    cout << endl;
    cout << "���ŵ����㷽ʽ�ĳ˷�����Ϊ��" << m_Matrix(1, 6) << endl;
 
    cout << "�����ŵķ�ʽΪ��" << endl;
 
    print_optimal(1, input_matrix_num);
    cout << endl << endl;
 
}
 
int m_Matrix(int i, int j) {
    int small;
    int sum[100];
    if (j - i == 1) {
        s[i][j] = i;
    }
    while (j - i == 1) {
        return p[i - 1] * p[i] * p[j];
        break;
    }
    while (i >= j) {
        return 0;
        break;
    }
    //�����еĶε�k�浽һ�����飬������������бȽϣ�ɸѡ����С���Ǹ�          
    for (int k = i;k <= j - 1;k++) {
        sum[k] = m_Matrix(i, k) + m_Matrix(k + 1, j) + p[i - 1] * p[k] * p[j];
    }
 
    int a = i;
    int b = i + 1;
 
    //ɸѡ������������ٵ��Ǹ�
    while (b <= j - 1) {
        if (sum[a] <= sum[b]) {
            small = sum[a];
            b++;
            s[i][j] = a;
        }
        else {
            small = sum[b];
            a = b;
            b++;
            s[i][j] = a;
        }
    }
 
    return small;
}
 
 
void print_optimal(int i, int j) {
    if (i == j) {
        cout << " A[" << p[i - 1] << "," << p[i] << "]";
    }
    else {
        cout << " ( ";
        print_optimal(i, s[i][j]);
        print_optimal(s[i][j] + 1, j);
        cout << " ) ";
    }
}
