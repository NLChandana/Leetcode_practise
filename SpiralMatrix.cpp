/* C++ code implementation for creating a spiral matrix in clockwise direction
Enter the number of rows: 5
Enter the number of columns: 4
The spiral matrix is: 
1	2	3	4	
14	15	16	5	
13	20	17	6	
12	19	18	7	
11	10	9	8	

Algorithm for this is as follows:

1. Create a vector of n rows and m columns
2. Initialize the variables num=1 (values of the matrix) and layer=0 (Layers of the matrix)
3. while(layer < min(n,m)/2 do 
    fill top row      -> i=layer,     i < m-layer  -- a[layer][i]= num;
    fill right column -> i=layer+1,   i < n-layer  -- a[i][m-layer-1]= num;
    fill bottom row   -> i=m-layer-2, i >= layer   -- a[n-layer-1][i]= num;
    fill left column  -> i=n-layer-2, i > layer    -- a[i][layer]=num;

*/


#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate_spiral_matrix(int n, int m) {
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    int num = 1;
    int layer = 0;
    
    while (layer < min(n, m) / 2) {
        // fill in the top row
        for (int i = layer; i < m - layer; i++) {
            matrix[layer][i] = num;
            num++;
        }
        
        // fill in the right column
        for (int i = layer + 1; i < n - layer; i++) {
            matrix[i][m - layer - 1] = num;
            num++;
        }
        
        // fill in the bottom row
        for (int i = m - layer - 2; i >= layer; i--) {
            matrix[n - layer - 1][i] = num;
            num++;
        }
        
        // fill in the left column
        for (int i = n - layer - 2; i > layer; i--) {
            matrix[i][layer] = num;
            num++;
        }
        
        layer++;
    }
    
    return matrix;
}

int main() {
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;
    
    vector<vector<int>> matrix = generate_spiral_matrix(n, m);
    
    cout << "The spiral matrix is: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    return 0;
}
