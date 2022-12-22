// DynamicMamery.cpp : 

#include <iostream>
#include<Windows.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n------------------------------------------\n"

//#define Dynamic_mamory_1
#define Dynamic_mamory_2

void FillRand(int arr[], const int n,const int minrand,const int maxreand);
void FillRand(double arr[], const int n, const int minrand, const int maxreand);

template<typename T>void Print(T* arr, const int n);

void FillRand(int**arr, const int rows, const int cols);
void FillRand(double** arr, const int rows, const int cols);

template<typename T>void Print(T**arr, const int rows, const int cols);
template<typename T>T* push_back(T* arr,int& n, int value);
template<typename T>T* push_front(T* arr, int& n, int value);
template<typename T>T* insert(T* mas, int& n, T value, int index);
template<typename T>T* pop_back(T* mas, int& n);
template<typename T>T* pop_front(T* mas, int& n);
int* erase(int* mas, int& n, int index);
bool Proverk_index(int index,int n);

template<typename T>T** pusch_row_back(T** arr, int& rows, const int cols);

template<typename T>T** pusch_row_front(T** arr, int& rows, const int cols);
template<typename T>T** insert_row(T** arr, int& rows, const int cols, int index);
template<typename T>T** pop_row_back(T** arr, int& rows, const int cols);
template<typename T>T** pop_row_front(T** arr, int& rows, const int cols);
template<typename T>T** erase_row(T** arr, int& rows, const int cols, int index);
template<typename T>T** alocale(const int rows, const int cols);
template<typename T>void clear(T** arr, const int rows);

template<typename T>void pusch_col_back(T**, const int rows, int& cols);
int main()
{
    setlocale(LC_ALL, "RUS");
    #ifdef Dynamic_mamory_1



   int n;
    //Динамические массивы 
    //Динамическим называеться массив кол-во эллементов которого может быть заданна переменным значением 
    //на этапе выполения программы.Это переменное значение предворительно можно вычеслить или ввести с клавиатуры
    //для того что бы объъявить динамичемский массив нужно объявить указатель
    //и выделить память при помощи опероатора "new" след образом
    //оператор new выделяет непрерывный блок памяти для n эллементов заданного типа и 
    // возхвращает адрес выделенный памяти
    //обращение к элементам динамичсекого массива
    //к элелементам дин массива можно обращаться так же как и к эллементам статического массива через
    //  арифметику укахателей и оператора разыминование
    //или же через опрератор индексирование 

    //Динамический массив передаеться в функцию точно так же как и статический массив
    //массив в функцию можно передать как обычный указатель и не важно как синтаксически мы его передаем
    //через [] или * в функцию скопируеться указатель на массив
    //
    //оператор new запрашивает память у ОС на временное пользование и эту память нужно вернуть
    //после того как она будет не нужна для того что бы вернуть память, массив нгужно удалить 
    //delete[] arr; освобождает память по заданному адресу и возвращает ее операционной системе
    //если только выделять память оператором new и не удалять ее то рано или поздно свободная память в ОС
    //закончиться что приведет к аварийному завершению нашей программы
    //операторов delete должно быть ровно столько сколько операторов new
    //ситуация при которой память была выделенная new но не была очищенна оператором delete называеться утечкой памяти 
    //Memory leak
    do{
    
    system("cls");
     cout << "Введите кол-во эллементов Массива" << endl;
    
    cin >> n;
    if (n < 2)
    {
        cout << "Введите значение больше 2 \n";system("pause");   
    }
    } while (n<2);
    system("cls");
    int* arr = new int[n];
    
    FillRand(arr, n);
    Print(arr, n);
    
    int value;
    int index;
    cout << "Ввдите значение которое нужно внести в масив\n"; cin >> value;
    cout << "---------push_back---------\n";
    arr=push_back(arr, n, value);
    Print(arr, n);
    cout << "Ввдите значение которое нужно внести в масив\n"; cin >> value;
    cout << "---------push_front---------\n";
    arr = push_front(arr, n, value);
    Print(arr, n);
    system("pause");
    system("cls");
    cout << "Введите значение которое нужно внести в массив\n" << endl;
    cin >> value;
    do 
    { 
        
        system("cls");
        Print(arr, n);
       cout << "\nВведите индекс куда вставить значение" << endl; cin >> index;
       if (Proverk_index(index, n) == 0)
       {
           cout << "Вы вышли за придела массива ввдеит другой индекс\n";
           system("pause");
       }
       if (Proverk_index(index, n) == 0&&index==0)
       {
           index++;
       }
        
    } while (Proverk_index(index, n) != 1);
    index--;
    system("cls");
    cout << "---------insert-----------\n";
    Print(arr, n);
    arr = insert(arr, n, value, index);
    cout << "--------------------------\n";
    Print(arr, n);
    cout << "---------pop_back---------\n";
    arr = pop_back(arr, n);
    Print(arr, n);
    cout << "---------pop_front----------\n";
    arr = pop_front(arr, n);
    Print(arr, n);
    cout << "--------------------------\n";
    system("pause");
    system("cls");
    do
    {
        system("pause");
        system("cls");
        cout << "\nВведите индекс куда вставить значение" << endl; cin >> index;
        if (Proverk_index(index, n) == 0)
        {
            cout << "Вы вышли за придела массива ввдеит другой индекс\n";
        }
        if (Proverk_index(index, n) == 0 && index == 0)
        {
            index++;
        }

    } while (Proverk_index(index, n) != 1);
    index--;
    system("cls");
    cout << "-----------erase--------\n"; 
    Print(arr, n);
    arr=erase(arr, n, index);
    Print(arr, n);
    #endif // Dynamic_mamory_1
    //двумерный динамические массивы
    //для того что бы объявить двумерный динамический массив нужно объявить указатель на указатель
    //и сохранить в него адрес в массивы указателей, каждый эллемент массивы указателей будет хранить 
    //адрес одномерного динамического массива.
    //эти одномерныйе динамические массивы являються строками двумерного динамического массива

    int rows;//кол-во строк
    int cols;//кол-во столбцов(кол-во эллементов строки
    cout << "Введите кол-во строк "; cin >> rows;
    cout << "Введите кол-во эллементов строки "; cin >> cols;
    double** arr1 = alocale<double>(rows, cols);
    

    FillRand(arr1, rows, cols);
    Print(arr1, rows, cols);
    cout << delimiter << endl;
    //для того что быпередать двумерные динамический массив в функцию
    //достаточно что бы функция принмала указатель на указатель и размер массива
    //
    
    arr1 = pusch_row_back(arr1, rows, cols);
    Print(arr1, rows, cols);
    cout << delimiter << endl;
    arr1 = pusch_row_front(arr1, rows, cols);
    Print(arr1, rows, cols);
    cout << delimiter << endl;
    cout << "Введите индекс куда вставить строку " << endl;
    int index; cin >> index;
    arr1 = insert_row(arr1, rows, cols,index);
    Print(arr1, rows, cols);
    cout <<"back" delimiter << endl;
    arr1=pop_row_back(arr1, rows, cols);
    
    Print(arr1, rows, cols);
    cout <<"front" <<delimiter << endl;
    arr1 = pop_row_front(arr1, rows, cols);
    FillRand(arr1[rows-1],  cols,900,1000);
    Print(arr1, rows, cols);
    cout << "erease" << delimiter << endl;
    cout << "Введите индекс какую строку удалить строку " << endl;
     cin >> index;
    arr1 = erase_row(arr1, rows, cols,index);
    Print(arr1, rows, cols);
    cout <<"pusch cool" delimiter << endl;
    pusch_col_back(arr1, rows, cols);
    Print(arr1, rows, cols);


    clear(arr1, rows);
    
}

void FillRand(int* arr, const int n, const int minrand, const int maxreand)
{
    cout << typeid(arr).name() << endl;

    for (int i = 0; i < n; i++)
    {
        *(arr + i) = rand() % (maxreand-minrand)+minrand;
    }
}
void FillRand(int**arr, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)//i нумироет строки
    {
        for (int j = 0; j < cols; j++)//j нумирует эллементы строки
        {
            arr[i][j] = rand() % 100;
        }

    }
}
void FillRand(double** arr, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)//i нумироет строки
    {
        for (int j = 0; j < cols; j++)//j нумирует эллементы строки
        {
            arr[i][j] = rand() % 100*1.1;
        }

    }
}
void FillRand(double arr[], const int n, const int minrand, const int maxreand)
{
    cout << typeid(arr).name() << endl;

    for (int i = 0; i < n; i++)
    {
        *(arr + i) = rand() % (maxreand - minrand) + minrand*1.1;
    }
}
template<typename T>void Print(T**arr, const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)//i нумироет строки
    {
        for (int j = 0; j < cols; j++)//j нумирует эллементы строки
        {
            cout << arr[i][j] << tab;
        }
        cout << endl;

    }
}
template<typename T>void Print(T arr[], const int n)
{
    cout << typeid(arr).name() << endl;
    for (int i = 0; i < n; i++)
    {
        //через оператор индексирования
        //[]- оператор индексирования
        cout << arr[i] << tab;
    }
    cout << endl;
}
template<typename T>T* push_back(T* arr,int& n, T value)
{
    T* bufer = new T[n + 1];
    for (int i = 0; i < n; i++)
    {
        bufer[i] = arr[i];
    }
    delete[]arr;
    arr = bufer;

    arr[n] = value;
    n++;
    return arr;

}
template<typename T>T* push_front(T* arr, int& n, T value)
{
    T* bufer = new T[n + 1];
    for (int i = 0; i < n; i++)
    {
        bufer[i + 1] = arr[i];
    }
    delete[]arr;
    arr = bufer;
    arr[0] = value;
    n++;
    return arr;
}

template<typename T>T* insert(T* mas, int& n, T value, int index)
{
    T* bufer = new T[n + 1];
    for (int i = 0,k=0; i < n; i++,k++)
    {
        if (i == index&&i==k)
        {
            i--;
            continue;
        }
        bufer[k] = mas[i];
    }
    bufer[index] = value;
    delete[]mas;
    mas = bufer;
    n++;

    return mas;
}
template<typename T>T* pop_back(T* mas, int& n)
{
    T* bufer = new T[n - 1];
    n--;
    for (int i = 0; i < n; i++)
    {
        bufer[i] = mas[i];
    }
    delete[] mas;
    mas = bufer;
    return mas;

}
template<typename T>T* pop_front(T* mas, int& n)
{
    T* bufer = new T[n - 1];

    for (int i = 1; i < n; i++)
    {
        bufer[i-1] = mas[i];
    }
    delete[] mas;
    mas = bufer;
    n--;
    return mas;
}
int* erase(int* mas, int& n, int index)
{
    int* bufer = new int[n - 1];

    for (int i = 0, kol = 0; i < n; i++)
    {
        if (i == index)
        {
            kol = 1;
            continue;
        }
        if (kol == 1)
        {
            bufer[i - 1] = mas[i];
        }
        else
        {
            bufer[i] = mas[i];
        }
    }
    delete[]mas;
    mas = bufer;
    n--;
    return mas;

}

bool Proverk_index(int index,int n)
{
    if (index > n||index<0)
    {
        return false;
    }
    
    return true;
    
    
}

template<typename T>T** pusch_row_back(T** arr,  int& rows, const int cols)
{

    T** bufer = new T* [rows + 1];
    for (int i = 0; i < rows; i++)
    {

        bufer[i] = arr[i];
    }
    delete[]arr;
    arr = bufer;
    bufer[rows] = new T[cols] {};
    rows++;
    return arr;
}
template<typename T>T** pusch_row_front(T** arr, int& rows, const int cols)
{
    T** bufer = new T* [rows + 1];

    for (int i = 0; i < rows; i++)
    {
        bufer[i+1] = arr[i];
    }
    delete[]arr;
    arr = bufer;
    bufer[0] = new T[cols] {};
    rows++;
    return arr;

}
template<typename T>T** insert_row(T** arr, int& rows, const int cols,int index)
{
    T** bufer = new T* [rows + 1];
    for (int i = 0, k = 0; i < rows; i++, k++)
    {
        if (i == index && i == k)
        {
            i--;
            continue;
        }
        bufer[k] = arr[i];
    }
    
    delete[]arr;
    arr = bufer;
    bufer[index] = new T[cols] {};
    rows++;
    return arr;
}
template<typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
    
    T** bufer = new T* [rows-1];
    for (int i = 0; i < rows-1; i++)
    {
        bufer[i] = arr[i];
    }
    delete[]arr[rows-1];
    delete[]arr;
    arr = bufer;
    rows--;

    return arr;
}
template<typename T>T** pop_row_front(T** arr, int& rows, const int cols)
{
    T** bufer = new T* [rows - 1];
    for (int i = 1; i < rows; i++)
    {
        bufer[i-1] = arr[i];

    }
    delete[]arr[0];
    delete[]arr;
    arr = bufer;
    rows--;
    return arr;



}
template<typename T>T** erase_row(T** arr, int& rows, const int cols, int index)
{
    T** bufer = new T* [rows - 1];
    for (int i = 0,kol=0; i < rows; i++)
    {

        if (i == index)
        {
            kol = 1;
            continue;
        }
        if (kol == 1)
        {
            bufer[i - 1] = arr[i];
        }
        else
        {
            bufer[i] = arr[i];
        }

    }

    delete[]arr[index];
    delete[]arr;
    arr = bufer;
    rows--;
    return arr;


}
template<typename T>T** alocale(const int rows, const int cols)
{
    T** arr1 = new T* [rows];
    for (int i = 0; i < rows; i++)
    {
        //создаем строки двумерного массива:
        arr1[i] = new T[cols];
    }
    return arr1;
}
template<typename T>void clear(T** arr,const int rows)
{
    //1)сначало удаляем стороки
    for (int i = 0; i < rows; i++)
    {
        delete[]arr[i];
    }
    delete[]arr;//2)потом удаляем сам массив
}

template<typename T>void pusch_col_back(T**arr, const int rows, int& cols)
{
    for (int i = 0; i < rows; i++)
    {
        T* bufer = new T[cols + 1]{};
        for (int j = 0; j < cols; j++)
        {
            bufer[j] = arr[i][j];
        }
        delete[]arr[i]; 
        arr[i] = bufer;
    }
    cols++;
}