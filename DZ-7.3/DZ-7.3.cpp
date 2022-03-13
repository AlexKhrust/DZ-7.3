#include <iostream>
using namespace std;

void veritas (int a[], int size) {      //проверка на правильность ввода оценки
    for (int i = 0; i < size; i++) {
        if (a[i] <= 0 || a[i] >= 13) {
            cout << "Оценка за занятие № " << i + 1 << " введена с ошибкой" << endl;
        }
    }
}

void show(int a[], int size) {          //вывод оценок в консоль
    for (int i = 0; i < size; i++) {
        cout << "Оценка за занятие № " << i + 1 << " = " << a[i] << endl;
        }
}

void retake(int a[], int size, int lesson, int estimation) {

    for (int i = 0; i < size; i++) {
        if (i + 1 == lesson) {
            a[i] = estimation;
            break;
        }
    }

}

void scholarship(int a[], int size) {   //достоин ли стипендии?
    int sum = 0;
    double average_score;

    for (int i = 0; i < size; i++) {
        sum = +a[i];
    }
    average_score = sum / size;

    if (average_score >= 10.7) {
        cout << "Студент достоин стипендии." << endl;
    }
    else {
        cout << "Студент не достоин стипендии." << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int menu, lesson, estimation;
    const int size = 10;
    int arr[size];

    cout << "Последовательно введите оценки студента за последние 10 занятий (12-ти балльная система):" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    veritas(arr, size);
    
    for (;;) {
        cout << endl;
        cout << "Укажите номер необходимой вам операции из списка ниже: " << endl;
        cout << "1 - Вывести в консоль оценки." << endl;
        cout << "2 - Заменить оценку в связи с пересдачей." << endl;
        cout << "3 - Вычислить по результатам успеваемости право на стипендию." << endl;
        cout << "0 - Выйти из программы." << endl;
        cin >> menu;

        switch (menu)
        {
        case 1:
            show(arr, size);
            break;

        case 2:
            cout << "Введите номер занятия: " << endl;
            cin >> lesson;
            cout << "Введите оценку за занятие: " << endl;
            cin >> estimation;

            retake(arr, size, lesson, estimation);
            veritas(arr, size);
            break;

        case 3:
            scholarship(arr, size);
            break;

        case 0:
            exit(0);
            break;
        }
    }
    
}
