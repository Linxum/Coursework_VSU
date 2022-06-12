/*
Смехнев Иван Юрьевич, 61 группа
Условие 3: с динамическими массивами и функциями
С клавиатуры вводится информация об итогах последней экзаменационной сессии. Эта информация включает в себя: 1) целое число n – количество студентов; 2) n объединенных в структуру данных: где , ― символьные строки, содержащие не более 20 символов, оценка за экзамен ― десятичная цифра из диапазона ‘2’..’5’. Требуется сформировать массив структур, в котором каждый элемент массива содержит фамилию студента и его средний балл, причем вначале размещаются данные о студентах, не имеющих отличных оценок, затем об остальных студентах, при этом в каждой части сохраняется взаимный порядок следования данных, определенный вводом, и вывести этот массив на экран. Вывести также фамилии и оценки студентов, имеющих наибольшее количество отличных оценок.

*/


#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

struct student //структура, в которой будет храниться входная информация о студенте (имя, фамилия, оценки)
{
    string name;
    string surname;
    string marks;
};

struct student_output //структура, в которой будет храниться выходнная информация о студенте (фамилия) и его средняя оценка
{
    string surname;
    double average_mark = 0.0;
};

//Функция подсчета среднего балла
double AverMark(string& marks)
{
    double sum_marks = 0.0;
    for (int i = 0; i < marks.size(); i++)
    {
        sum_marks += (marks[i] - '0');
    }
    return sum_marks / marks.size();
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    int max_good = 0;

    //ввод данных
    cout << "Введите количество студентов: "; cin >> n;
    student* studs = new student[n]; //входной массив структур
    for (int i = 0; i < n; i++)
    {
        cout << "Введите данные " << i + 1 << "-го студента (имя, фамилия, оценки подряд без пробелов): " << endl;
        cin >> studs[i].name;
        cin >> studs[i].surname;
        cin >> studs[i].marks;
        int counter = 0; // счетчик отличных оценок
        for (int j = 0; j < studs[i].marks.size(); j++)
        {
            if (studs[i].marks[j] == '5')
            {
                counter++;
            }
        }
        if (counter > max_good)
        {
            max_good = counter;
        }
    }

    student_output* studs_output = new student_output[n]; //выходной массив структур
    int counter_1; //счетчик оценок без отлично
    int counter_2 = 0; //счетчик студентов, не имеющих отличных студентов

    //заполение и вывод выходного массива студентами, не имеющих отличных оценок
    cout << endl << "Фамилии и средние баллы студентов: " << endl;
    for (int i = 0; i < n; i++)
    {
        counter_1 = 0;
        for (int j = 0; j < studs[i].marks.size(); j++)
        {
            if (studs[i].marks[j] != '5')
            {
                counter_1++;
            }
            else break;
        }
        if (counter_1 == 5)
        {
            studs_output[counter_2].surname = studs[i].surname;
            studs_output[counter_2].average_mark = AverMark(studs[i].marks);
            cout << studs_output[counter_2].surname << " " << studs_output[counter_2].average_mark << endl;
        }
    }
    //заполение и вывод выходного массива остальными студентами
    int counter_3 = 0;
    for (int i = 0; i < n; i++)
    {
        counter_1 = 0;
        for (int j = 0; j < studs[i].marks.size(); j++)
        {
            if (studs[i].marks[j] != '5')
            {
                counter_1++;
            }
        }
        if (counter_1 != 5)
        {
            studs_output[counter_2 + counter_3].surname = studs[i].surname;
            studs_output[counter_2 + counter_3].average_mark = AverMark(studs[i].marks);
            cout << studs_output[counter_2 + counter_3].surname << " " << studs_output[counter_2 + counter_3].average_mark << endl;
        }
    }

    //вывод дополнительного условия
    cout << endl << "Студенты с наибольшим количеством отличных оценок: " << endl;
    for (int i = 0; i < n; i++)
    {
        int counter = 0;
        for (int j = 0; j < studs[i].marks.size(); j++)
        {
            if (studs[i].marks[j] == '5')
            {
                counter++;
            }
        }
        if (counter == max_good)
        {
            cout << studs[i].surname << " " << studs[i].marks << endl;
        }
    }
}
