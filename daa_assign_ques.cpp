
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

vector<int> getMax(vector<vector<int>> a, int M, int N)
{
    int row = 0;
    int col = 0;
    for (int i = 0; i < M; i++)
    {
        if (a[i][0] > row)  row = a[i][0];
  
        if (a[i][1] > col)  col = a[i][1];
    }
    vector<int> f = {row, col};
    return (f);
}

vector<int> getMin(vector<vector<int>> a, int M, int N)
{
    int row = INT_MAX;
    int col = INT_MAX;
    for (int i = 0; i < M; i++)
    {
        if (a[i][0] < row)  row = a[i][0];
       
        if (a[i][1] < col)  col = a[i][1];       
    }
    vector<int> f = {row, col};
    return (f);
}

void display(vector<vector<int>> a, int M, int N)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
}

bool onSegment(int p1, int p2, int q1, int q2, int r1, int r2)
{
    if (q1 <= max(p1, r1) && q1 >= min(p1, r1) &&
        q2 <= max(p2, r2) && q2 >= min(p2, r2))
        return true;
    return false;
}

int orientation(int p1, int p2, int q1, int q2, int r1, int r2)
{
    int val = (q2 - p2) * (r1 - q1) -
              (q1 - p1) * (r2 - q2);

    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

bool doIntersect(int p1, int p12, int q1, int q12, vector<int> p2, vector<int> q2)
{

    int o1 = orientation(p1, p12, q1, q12, p2[0], p2[1]);
    int o2 = orientation(p1, p12, q1, q12, q2[0], q2[1]);
    int o3 = orientation(p2[0], p2[1], q2[0], q2[1], p1, p12);
    int o4 = orientation(p2[0], p2[1], q2[0], q2[1], q1, q12);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && onSegment(p1, p12, p2[0], p2[1], q1, q12))
        return true;

    if (o2 == 0 && onSegment(p1, p12, q2[0], q2[1], q1, q12))
        return true;

    if (o3 == 0 && onSegment(p2[0], p2[1], p1, p12, q2[0], q2[1]))
        return true;

    if (o4 == 0 && onSegment(p2[0], p2[1], q1, q12, q2[0], q2[1]))
        return true;

    return false;
}

bool isInside(vector<vector<int>> polygon, int n, vector<int> p)
{
    if (n < 3) return false;

    vector<int> extreme = {10000, p[1]};

    int decrease = 0;

    int count = 0, i = 0;
    do
    {
        int next = (i + 1) % n;

        if (polygon[i][1] == p[1])
            decrease++;

        if (doIntersect(polygon[i][0], polygon[i][1], polygon[next][0], polygon[next][1], p, extreme))
        {

            if (orientation(polygon[i][0], polygon[i][1], p[0], p[1], polygon[next][0], polygon[next][1]) == 0)
                return onSegment(polygon[i][0], polygon[i][1], p[0], p[1], polygon[next][0], polygon[next][1]);

            count++;
        }
        i = next;
    } while (i != 0);

    count -= decrease;

    return count & 1;
}

void sumFromMatrix(vector<vector<int>> matrix, vector<vector<int>> polygon)
{
    vector<int> checktill_max = getMax(polygon, polygon.size(), 2);
    vector<int> checktill_min = getMin(polygon, polygon.size(), 2);
    int sum = 0;
    for (int i = checktill_min[0]; i <= checktill_max[0]; i++)
    {
        for (int j = checktill_min[1]; j <= checktill_max[1]; j++)
        {
            vector<int> coordinate;
            coordinate.push_back(i);
            coordinate.push_back(j);

            if (isInside(polygon, polygon.size(), coordinate))
            {
                sum += matrix[i][j];
            }
        }
    }

    cout <<endl<< "Sum of the elements inside the polygon = " << sum;
}

int main()
{
    vector<vector<int>> matrix;
    srand (time(NULL));
    cout << "Enter dimentions :";
    int M, N;
    cin >> M >> N;
    
    for (int i = 0; i < M; i++)
    {
        vector<int> v;
        for (int j = 0; j < N; j++)
        {
            int val = (rand() % 10) + 1;
            if(val==10) val-=1;
            v.push_back(val);
        }
        matrix.push_back(v);
    }

    display(matrix, M, N);

    vector<vector<int>> d1;

    cout << "Enter any five dimentions for calculation :\n";
    for (int i = 0; i < 5; i++)
    {
        int a, b;
        cin >> a >> b;
        vector<int> takein;

        if (((a - 1 < M)) && ((b - 1 < N)))
        {           
            takein.push_back(a);
            takein.push_back(b);
            d1.push_back(takein);
        }
    }

    vector<int> checktill_max = getMax(d1, d1.size(), 2); // max (x,y)
    vector<int> checktill_min = getMin(d1, d1.size(), 2); // min (x,y)

    cout << "MAXIMUM and MINIMUM traversal till :" << endl;
    cout << checktill_max[0] << " " << checktill_max[1] << endl;
    cout << checktill_min[0] << " " << checktill_min[1];    

    sumFromMatrix(matrix, d1);
    return 0;
}

