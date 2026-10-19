
#include <iostream>
using namespace std;

#define SIZE 5

class Patient
{
public:
    int id;
    int priority;
};

class PriorityQueue
{
    Patient arr[SIZE];
    int count;

public:
    PriorityQueue()
    {
        count = 0;
    }

    void enqueue(int id, int priority)
    {
        if (count == SIZE)
        {
            cout << "Queue is full!" << endl;
            return;
        }

        arr[count].id = id;
        arr[count].priority = priority;
        count++;

        cout << "Patient P" << id << " added." << endl;
    }

    void treatPatient()
    {
        if (count == 0)
        {
            cout << "No patients waiting!" << endl;
            return;
        }

        int highest = 0;

        for (int i = 1; i < count; i++)
        {
            if (arr[i].priority < arr[highest].priority)
            {
                highest = i;
            }
        }

        cout << "Treating patient P"
             << arr[highest].id
             << " with priority "
             << arr[highest].priority << endl;

        for (int i = highest; i < count - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        count--;
    }

    void display()
    {
        if (count == 0)
        {
            cout << "No patients waiting." << endl;
            return;
        }

        cout << "Waiting patients:" << endl;

        for (int i = 0; i < count; i++)
        {
            cout << "Patient P" << arr[i].id
                 << " - Priority "
                 << arr[i].priority << endl;
        }
    }
};

int main()
{
    PriorityQueue q;

    q.enqueue(101, 3);
    q.enqueue(102, 1);
    q.enqueue(103, 2);

    q.display();

    q.treatPatient();

    q.display();

    return 0;
}

