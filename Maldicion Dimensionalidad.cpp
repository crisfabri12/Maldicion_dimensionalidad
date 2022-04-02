#include <iostream>
#include <random>
#include <cmath>
#include <vector>

using namespace std;

class puntos{
    public:
    vector<int> dim;
};

int main()
{
    std::default_random_engine gen;
    std::uniform_int_distribution<int> distribution(0,100);
    
    int dim, n;
    n = 20000;
    cout << "Numero de Dimensiones" << endl;
    cin >> dim; 
       
    puntos espacio[n];
    for (int i = 0; i < n; i++) {
        espacio[i].dim.push_back(distribution(gen));
    }
    
    float distancias[n];
    float min = 1500, max = 0;

    for (int i = 1; i < n; i++) {
        int sum = 0;

        for (int j = 0; j < dim; j++) {
            sum += (espacio[i].dim[j] - espacio[0].dim[j]) * (espacio[i].dim[j] - espacio[0].dim[j]);
        }
        float dis = sqrt(sum);
        distancias[i] = dis;
    }

    int res[n];    
    for (int i = 0; i < n; i++) {
        ++res[(int)distancias[i]];
    }

    for (int i = 0; i < n; i++) {
        cout << i << " " << res[i] << endl;
    }

    return 0;
}