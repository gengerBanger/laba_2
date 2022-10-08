#include <iostream>
#include <ctime>
#include <chrono>
#include <math.h>
#include <Windows.h>
#include <algorithm>
HANDLE hConsole;
using namespace std;

void arr_out(int arr[]){ //функция вывода массива
    for(int i = 0; i < 100; i++){
        cout << arr[i] << ' ';
    }
    cout << endl << endl;
}
void arr_sorting(int arr[],int end, int begin){ // функция сортировки массива
    int l = begin, r = end, mid = arr[(r + l) / 2];
    while (l < r){
        for(;arr[l] < mid; l++);
        for(;arr[r] > mid; r--);
        if (l <= r){
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }
    if (begin < r) arr_sorting(arr, r, begin);
    if (l < end) arr_sorting(arr, end, l);
}
void max_min_value(int arr[]){ // функция для поиска максимального и минимального значения в массиве
    int max_value = -1000, min_value = 1000;
    auto start11 = chrono::high_resolution_clock::now();
    for (int i = 0; i < 100; i++){
        if (arr[i] > max_value){
            max_value = arr[i];
        }
        if (arr[i] < min_value){
            min_value = arr[i];
        }
    }
    auto finish11 = chrono::high_resolution_clock::now();
    chrono :: duration <float> duration1 = finish11 - start11;
    cout.precision(8);
    cout << "Minimum value in the array = "<< min_value << '\n' << "Maximum value in the array = " << max_value <<'\n';
    cout << "Time to search for items in array = " << duration1.count() << " s"<< '\n';
}
void mean(int arr[], int a, int b){ // функция для поиска среднего значения массива
    int mean_value = round((a + b)/2), count = 0;
    SetConsoleTextAttribute(hConsole, 11);
    cout << '\n' << "Mean = " << mean_value <<'\n' << "Indexes of elements equal to the mean :" << '\n';
    for(int i = 0; i < 100; i++){
        if(arr[i] == mean_value){
            cout << i <<" ";
            count ++;
        }
    }
    cout << '\n' << "Amount such of elements : " << count <<'\n';
    SetConsoleTextAttribute(hConsole, 15);
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc51-cpp"
int main() {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout.setf(ios_base::fixed);
    srand(time(nullptr));
    int arr[100],arr_1[100], first_value, last_value;
    for(int &i : arr){
        i = -99 + rand() % 199; // заполнение массива рандомными числами
    }
    copy_n(arr, 100, arr_1);

    SetConsoleTextAttribute(hConsole, 12);
    cout <<'\t' <<"Unsorted array :" << '\n';
    SetConsoleTextAttribute(hConsole, 15);

    arr_out(arr);

    max_min_value(arr);

    auto start_1 = chrono::high_resolution_clock::now();
    arr_sorting(arr, 99 , 0);
    auto finish_1 = chrono::high_resolution_clock::now();
    chrono :: duration <float> duration = finish_1 - start_1;

    SetConsoleTextAttribute(hConsole, 13);
    cout << "Time spent sorting : " << duration.count() << " s" <<endl;
    SetConsoleTextAttribute(hConsole, 15);

    SetConsoleTextAttribute(hConsole, 10);
    cout <<'\t' <<"Sorted array :" << '\n';
    SetConsoleTextAttribute(hConsole, 15);

    arr_out(arr);

    max_min_value(arr);

    first_value = arr[0];
    last_value = arr[99];
    mean(arr_1, first_value, last_value);

    int a, b, count = 0;
    SetConsoleTextAttribute(hConsole, 14);
    cout << '\t' <<"Enter the number a (task 5)"<< '\n';
    SetConsoleTextAttribute(hConsole, 15);
    cin >> a;
    for (int i = 0; i < 100; i++){
        if (arr[i] < a){
            count++;
        }
    }
    cout << "Amount of elements which are less \"a\" : " << count <<'\n';
    count = 0;
    SetConsoleTextAttribute(hConsole, 14);
    cout << '\t' <<"Enter the number b (task 6)"<< '\n';
    SetConsoleTextAttribute(hConsole, 15);
    cin >> b;
    for (int i = 0; i < 100; i++){
        if (arr[i] > b){
            count++;
        }
    }
    cout << "Amount of elements which are more \"b\" : " << count <<'\n';
    return 0;
}
#pragma clang diagnostic pop