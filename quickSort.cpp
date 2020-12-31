#include <iostream>
#include <vector>

using namespace std;

template <class T>
void quickSort(vector<T>& v, int left, int right);
template <class T>
int partition(vector<T>& v, int left, int right);
template <class T>
void printVector(vector<T> v);

int main(){
    srand(time(0));
    vector<double> testV;

    // create random vector to test quickSort
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

    quickSort(testV, 0, testV.size() - 1);
    cout<<"Quick sorted vector: "<<endl;
    printVector(testV);

    return 0;
}

template <class T>
int partition(vector<T>& v, int left, int right){
    T pivot = v[left];
    int from_left = left + 1;
    int from_right = right;

    while(from_left != from_right){
        if(v[from_left] <= pivot){
            from_left++;
        }
        else{
            while((from_left != from_right) && (pivot <= v[from_right])){
                from_right--;
            }
            swap(v[from_left], v[from_right]);
        }
    }
    if(v[from_left] > pivot){
        from_left--;
    }
    v[left] = v[from_left];

    v[from_left] = pivot;

    return from_left;
}

template <class T>
void quickSort(vector<T>& v, int left, int right){
    if(left < right){
        int pivot = partition(v, left, right);
        quickSort(v, left, pivot - 1);
        quickSort(v, pivot + 1, right);
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
