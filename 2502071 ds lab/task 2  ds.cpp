
#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue
{
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int packet)
    {
        if ((rear + 1) % SIZE == front)
        {
            cout << "Queue is full!" << endl;
            return;
        }

        if (front == -1)
        {
            front = 0;
        }

        rear = (rear + 1) % SIZE;
        arr[rear] = packet;

        cout << "Packet " << packet << " added." << endl;
    }

    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Transmitting packet: "
             << arr[front] << endl;

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }

    void display()
    {
        if (front == -1)
        {
            cout << "No packets waiting." << endl;
            return;
        }

        cout << "Packets waiting: ";

        int i = front;

        while (true)
        {
            cout << arr[i] << " ";

            if (i == rear)
            {
                break;
            }

            i = (i + 1) % SIZE;
        }

        cout << endl;
    }
};

int main()
{
    CircularQueue q;

    q.enqueue(201);
    q.enqueue(202);
    q.enqueue(203);

    q.display();

    q.dequeue();

    q.enqueue(204);
    q.enqueue(205);
    q.enqueue(206);

    q.display();

    return 0;
}

