#include <iostream>
#include <vector>

using namespace std;

template <class T>
void selectionSort(vector<T>& v, int size);
template <class T>
int findMinInd(vector<T> v, int low, int high);
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

    selectionSort(testV, testV.size()-1);
    cout<<"Selection sorted vector: "<<endl;
    printVector(testV);

    return 0;
}

template <class T>
void selectionSort(vector<T>& v, int size){
    int midInd;

    for(int i = 0; i < size; i++){
        midInd = findMinInd(v, i, size);
        swap(v[i], v[midInd]);
    }
}

template <class T>
int findMinInd(vector<T> v, int low, int high){
   int minInd;
   T min;

   min = v[low];
    minInd = low;
   for (int i = low + 1; i <= high; i++) {
        if(v[i] < min){
            min = v[i];
            minInd = i;
        }
    }
   return minInd;
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
