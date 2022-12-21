// DynamicMamery.cpp : 

#include <iostream>
#include<Windows.h>
using namespace std;
#define tab "\t"\

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);

int* push_back(int* arr,int& n, int value);
int* push_front(int* arr, int& n, int value);

int* insert(int* mas, int& n, int value, int index);
int* pop_back(int* mas, int& n);
int* pop_front(int* mas, int& n);
int* erase(int* mas, int& n, int index);
bool Proverk_index(int index,int n);
int main()
{
    setlocale(LC_ALL, "RUS");
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
}

void FillRand(int arr[], const int n)
{
    cout << typeid(arr).name() << endl;

    for (int i = 0; i < n; i++)
    {
        *(arr + i) = rand() % 100;
    }
}
void Print(int arr[], const int n)
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
int* push_back(int* arr,int& n, int value)
{
    int* bufer = new int[n + 1];
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
int* push_front(int* arr, int& n, int value)
{
    int* bufer = new int[n + 1];
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

int* insert(int* mas, int& n, int value, int index)
{
    int* bufer = new int[n + 1];
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
int* pop_back(int* mas, int& n)
{
    int* bufer = new int[n - 1];
    n--;
    for (int i = 0; i < n; i++)
    {
        bufer[i] = mas[i];
    }
    delete[] mas;
    mas = bufer;
    return mas;

}
int* pop_front(int* mas, int& n) 
{
    int* bufer = new int[n - 1];

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