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

void arr_sorting_bubble(int arr[], int n){
    bool bub = true;
    while(bub){
        bub = false;
        for (int i = 0; i < n ; i++){
            if (arr[i] > arr[i + 1]) {
                swap(arr[i],arr[i + 1]);
                bub = true;
            }
        }
        n--;
    }

}

void arr_sorting_shaker(int arr[],int end, int begin){
    bool shaker = true;
    while(shaker){
        shaker = false;
        for (int i = begin; i < end; i++){
            if (arr[i] > arr[i + 1]){
                swap(arr[i],arr[i + 1]);
                shaker = true;
            }
        }
        end--;
        for(int j = end ; j > begin; j--){
            if (arr[j] < arr[j - 1]){
                swap(arr[j], arr[j - 1]);
                shaker = true;
            }
        }
        begin++;
    }
}

void arr_sorting_comb (int arr[], int end){
    int s = end;
    while (s >= 1){
        for (int i = 0; i + s <= end; i++){
            if (arr[i] > arr[i + s]) swap(arr[i], arr[i + s]);
        }
        s -= 1;
    }

}

void arr_sorting_insert(int arr[], int n){
    for (int i = 1; i <= n; i++){
        for (int j = i; j > 0; j--){
            if (arr[j] < arr[j - 1]) swap(arr[j], arr[j - 1]);
        }
    }
}

void arr_sorting_quick(int arr[],int end, int begin){ // функция сортировки массива
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
    if (begin < r) arr_sorting_quick(arr, r, begin);
    if (l < end) arr_sorting_quick(arr, end, l);
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

void arr_exchange(int arr[], int a, int b ){ // функция для поиска времени перестановок
    arr_out(arr);
    auto start_4 = chrono::high_resolution_clock::now();
    swap(arr[a],arr[b]);
    auto finish_4 = chrono::high_resolution_clock::now();
    chrono :: duration <float> duration_4 = finish_4 - start_4;
    arr_out(arr);
    cout << "Time to exchange = " << duration_4.count() << " s" <<'\n';
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc51-cpp"
int main() {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout.setf(ios_base::fixed);
    srand(time(nullptr));
    int arr[100],arr_1[100], first_value, last_value, key_sort;
    for(int &i : arr){
        i = -99 + rand() % 199; // заполнение массива рандомными числами
    }
    copy_n(arr, 100, arr_1); // создание копии массива

    SetConsoleTextAttribute(hConsole, 12);
    cout <<'\t' <<"Unsorted array :" << '\n';
    SetConsoleTextAttribute(hConsole, 15);

    arr_out(arr);

    max_min_value(arr_1);

    SetConsoleTextAttribute(hConsole, 14);
    cout << "Choose sorting type :"<< '\n';
    SetConsoleTextAttribute(hConsole, 10);
    repeat:
    cout <<"1) Bubble sort" <<'\n'<< "2) Shaker sort" <<'\n'<<"3) Comb sort" <<'\n'<<"4) Insert sort" <<'\n'<<"5) Quick sort" <<'\n'<< "enter sort number"<<'\n';
    cin >> key_sort;
    switch (key_sort) {
        case 1:
        {
            auto start_1_1 = chrono::high_resolution_clock::now();
            arr_sorting_bubble(arr, 99);
            auto finish_1_1 = chrono::high_resolution_clock::now();
            chrono :: duration <float> duration_1_1 = finish_1_1 - start_1_1;
            SetConsoleTextAttribute(hConsole, 13);
            cout << "Time spent sorting : " << duration_1_1.count() << " s" <<endl;
            SetConsoleTextAttribute(hConsole, 15);
            break;
        }
        case 2:
        {
            auto start_1_2 = chrono::high_resolution_clock::now();
            arr_sorting_shaker(arr, 99, 0);
            auto finish_1_2 = chrono::high_resolution_clock::now();
            chrono :: duration <float> duration_1_2 = finish_1_2 - start_1_2;
            SetConsoleTextAttribute(hConsole, 13);
            cout << "Time spent sorting : " << duration_1_2.count() << " s" <<endl;
            SetConsoleTextAttribute(hConsole, 15);
            break;
        }
        case 3:
        {
            auto start_1_3 = chrono::high_resolution_clock::now();
            arr_sorting_comb(arr, 99);
            auto finish_1_3 = chrono::high_resolution_clock::now();
            chrono :: duration <float> duration_1_3 = finish_1_3 - start_1_3;
            SetConsoleTextAttribute(hConsole, 13);
            cout << "Time spent sorting : " << duration_1_3.count() << " s" <<endl;
            SetConsoleTextAttribute(hConsole, 15);
            break;
        }
        case 4:
        {
            auto start_1_4 = chrono::high_resolution_clock::now();
            arr_sorting_insert(arr, 99);
            auto finish_1_4 = chrono::high_resolution_clock::now();
            chrono :: duration <float> duration_1_4 = finish_1_4 - start_1_4;
            SetConsoleTextAttribute(hConsole, 13);
            cout << "Time spent sorting : " << duration_1_4.count() << " s" <<endl;
            SetConsoleTextAttribute(hConsole, 15);
            break;
        }
        case 5:
        {
            auto start_1_5 = chrono::high_resolution_clock::now();
            arr_sorting_quick(arr, 99,0);
            auto finish_1_5 = chrono::high_resolution_clock::now();
            chrono :: duration <float> duration_1_5 = finish_1_5 - start_1_5;
            SetConsoleTextAttribute(hConsole, 13);
            cout << "Time spent sorting : " << duration_1_5.count() << " s" <<endl;
            SetConsoleTextAttribute(hConsole, 15);
            break;
        }
        default :
            goto repeat;
    }

    SetConsoleTextAttribute(hConsole, 10);
    cout <<'\t' <<"Sorted array :" << '\n';
    SetConsoleTextAttribute(hConsole, 15);

    arr_out(arr);
    auto start_0 = chrono :: high_resolution_clock :: now();
    first_value = arr[0];
    last_value = arr[99];
    auto finish_0 = chrono :: high_resolution_clock :: now();
    chrono :: duration <float> duration_0 = finish_0 - start_0;
    cout << "Minimum value in the array = "<< first_value << '\n' << "Maximum value in the array = " << last_value <<'\n';
    cout << "Time to search for items in array = " << duration_0.count() << " s"<< '\n';

    mean(arr_1, first_value, last_value);

    int a, b, count = 0;
    bool b1 = true;
    while(b1){
        SetConsoleTextAttribute(hConsole, 14);
        cout << '\t' <<"Enter the number a (task 5)"<< '\n';
        SetConsoleTextAttribute(hConsole, 15);
        cin >> a;
        if (cin){
            for(int i = 0; i < 100; i++){
                if (arr[i] < a){
                    count++;
                }
            }
            cout << "Amount of elements which are less " << a << " = " << count <<'\n';
            count = 0;
        }
        else b1 = false;
    }
    count = 0;
    cin.clear();
    while(cin.get() != '\n');
    b1 = true;
    while(b1){
        SetConsoleTextAttribute(hConsole, 14);
        cout << '\t' <<"Enter the number b (task 6)"<< '\n';
        SetConsoleTextAttribute(hConsole, 15);
        cin >> b;
        if (cin){
            for(int i = 0; i < 100; i++){
                if (arr[i] > b){
                    count++;
                }
            }
            cout << "Amount of elements which are less " << b << " = " << count <<'\n';
            count = 0;
        }
        else b1 = false;
    }
    cin.clear();
    while(cin.get() != '\n');
    b1 = true;
    while(b1){
        int a_1, l = 0, r = 99, mid = 0;
        bool b_1 = false;
        SetConsoleTextAttribute(hConsole, 14);
        cout << '\t' << "Enter the number (task 7)"<< '\n';
        SetConsoleTextAttribute(hConsole, 15);
        cin >> a_1;
        if(cin){
            auto start_2 = chrono ::high_resolution_clock :: now();
            while((not(b_1)) && (l <= r)){
                mid = (l + r) / 2;
                if (arr[mid] == a_1) b_1 = true;
                if (arr[mid] > a_1) r = mid - 1;
                else l = mid + 1;
            }
            if (b_1){
                SetConsoleTextAttribute(hConsole,10);
                cout <<"Binary search :" <<'\t'<<  "Value found"<< '\n';
                SetConsoleTextAttribute(hConsole,15);
            }
            else {
                SetConsoleTextAttribute(hConsole,12);
                cout <<"Binary search :" << '\t' << "Value not found"<< '\n';
                SetConsoleTextAttribute(hConsole,15);
            }
            auto finish_2 = chrono ::high_resolution_clock :: now();
            chrono :: duration <float> duration_2 = finish_2 - start_2;
            SetConsoleTextAttribute(hConsole,9);
            cout <<"Binary search time = " << duration_2.count() << " s" << '\n';
            SetConsoleTextAttribute(hConsole,15);
            b_1 = false;
            auto start_3 = chrono ::high_resolution_clock :: now();
            for(int i = 0; i < 100;i ++){
                if (arr[i] == a_1){
                    b_1 = true;
                }
            }
            if (b_1){
                SetConsoleTextAttribute(hConsole,10);
                cout <<  "Enumiration search :" <<" Value found"<< '\n';
                SetConsoleTextAttribute(hConsole,15);
            }
            else {
                SetConsoleTextAttribute(hConsole, 12);
                cout << "Enumiration search :" << " Value not found"<< '\n';
                SetConsoleTextAttribute(hConsole, 15);
            }
            auto finish_3 = chrono ::high_resolution_clock :: now();
            chrono :: duration <float> duration_3 = finish_3 - start_3;
            SetConsoleTextAttribute(hConsole,9);
            cout <<"Enumeration time = " << duration_3.count() << " s" << '\n';
            SetConsoleTextAttribute(hConsole,15);
        }
        else b1 = false;
    }
    cin.clear();
    while(cin.get() != '\n');
    b1 = true;
    while(b1){
        int i1, i2;
        SetConsoleTextAttribute(hConsole, 14);
        cout << '\t' << "Enter numbers (task 8)"<< '\n';
        SetConsoleTextAttribute(hConsole, 15);
        cin >> i1 >> i2;
        if(cin) arr_exchange(arr, i1, i2);
        else b1 = false;
    }
    return 0;
}
#pragma clang diagnostic pop