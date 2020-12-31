#include <iostream>
#include <vector>

using namespace std;

template <class T>
void mergeSort(vector<T>& v, vector<T>& temp, int start, int end);
template <class T>
void merge(vector<T>& v, vector<T>& temp, int start, int mid, int end);
template <class T> // driver
void mergeSort(vector<T>& v);
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

    mergeSort(testV);
    cout<<"Merge sorted vector: "<<endl;
    printVector(testV);

    return 0;
}


template <class T>
void mergeSort(vector<T>& v, vector<T>& temp, int start, int end){
    int mid;

    if(start == end){
        return;
    }
    else{
        mid = (start + end) / 2;
        mergeSort(v, temp, start, mid);
        mergeSort(v, temp, mid + 1, end);
        merge(v, temp, start, mid, end);
    }
}


template <class T> // driver
void mergeSort(vector<T>& v) {
    vector<T> temp;
    temp.resize(v.size());
    mergeSort(v, temp, 0, v.size() - 1);
}

template <class T>
void merge(vector<T>& v, vector<T>& temp, int start, int mid, int end){
    int leftStart = start;
    int rightStart = mid + 1;
    int tempPos = start;

    while(leftStart <= mid && rightStart <= end){
        if(v[leftStart] < v[rightStart])
            temp[tempPos++] = v[leftStart++];
        else
            temp[tempPos++] = v[rightStart++];
    }

    while(leftStart <= mid){
        temp[tempPos++] = v[leftStart++];
    }
    while(rightStart <= end){
        temp[tempPos++] = v[rightStart++];
    }

    for (int i = start; i <= end; i++) {
        v[i] = temp[i];
    }
}

template <class T>
void printVector(vector<T> v){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    for (int i = 0; i < v.size(); i++) {
        if(i < v.size() - 1) {
            cout << v[i] <<", ";
        } else
            cout<< v[i]<<endl;
    }
}
