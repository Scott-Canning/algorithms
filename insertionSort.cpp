#include <iostream>
#include <vector>

using namespace std;

template <class T>
void insertionSort(vector<T>& v);
template <class T>
void printVector(vector<T> v);

int main(){
    srand(time(0));
    vector<double> testV;

    // create random vector to test mergeSort
    double random;
    double randomTens = 0;
    double randomDigs = 0.00;
    rand();
    for (int i = 0; i < 8; ++i) {
        randomTens = (rand() % 19 + 1);
        randomDigs = (double)(rand() % 99 + 1) / 100;
        random = randomTens + randomDigs;
        testV.push_back(random);
    }

    cout<<"Original vector: "<<endl;
    printVector(testV);

    insertionSort(testV);
    cout<<"Insertion sorted vector: "<<endl;
    printVector(testV);

    return 0;
}


template <class T>
void insertionSort(vector<T>& v){
    int size = v.size();

    int i, j;
    double key;

    for(i = 1; i < size; i++){

        key = v[i];
        j = i - 1;

        while(j >= 0 && v[j] > key){
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}

template <class T>
void printVector(vector<T> v){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    for (int i = 0; i < v.size(); i++) {
        if(i < v.size() - 1) {
            cout << v[i] <<", ";
        } else
            cout<< v[i]<<endl;
    }
}