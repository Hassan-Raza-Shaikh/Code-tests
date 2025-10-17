#include <iostream>
using namespace std;

class Stack
{
private:
    int data[100];
    int topIndex;

public:
    Stack()
    {
        topIndex = -1;
    }

    bool isEmpty()
    {
        return topIndex == -1;
    }

    bool isFull()
    {
        return topIndex == 99;
    }

    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack overflow. Cannot push " << val << endl;
            return;
        }
        data[++topIndex] = val;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow. Nothing to pop." << endl;
            return;
        }
        topIndex--;
    }

    int top()
    {
        if (isEmpty())
            return -1;
        return data[topIndex];
    }

    void display(int num)
    {
        cout << "H" << num << " : ";
        if (isEmpty())
        {
            cout << "empty";
        }
        else
        {
            for (int i = 0; i <= topIndex; i++)
            {
                cout << data[i] << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
    int n, k;
    cout << "Enter number of cars (n): ";
    cin >> n;
    cout << "Enter number of holding tracks (k): ";
    cin >> k;

    int cars[n];
    bool used[n];

    cout << "\nEnter the order of " << n << " cars (each between 1 and " << n << ") from left to right : " << endl;
    cout << "(Enter from left to right as seen on screen, where rightmost car is processed first)" << endl;

    for (int i = 0; i < n;)
    {
        int car;
        cout << "Car " << i + 1 << ": ";
        cin >> car;

        if (car < 1 || car > n)
        {
            cout << "Invalid! Number must be between 1 and " << n << endl;
        }
        else if (used[car])
        {
            cout << "Repetition not allowed. Enter a different number." << endl;
        }
        else
        {
            cars[i] = car;
            used[car] = true;
            i++;
        }
    }

    cout << "Cars from left to right: ";
    for (int i = 0; i < n; i++)
    {
        cout << cars[i] << " ";
    }
    cout << "\n\n";

    Stack holding[k];
    int outputArr[n];
    int outputCount = 0;

    int nextExpected = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        int car = cars[i];

        if (car == nextExpected)
        {
            cout << "Move car " << car << " from Input -> Output Track." << endl;
            outputArr[outputCount++] = car;
            nextExpected++;

            bool moved = true;
            while (moved)
            {
                moved = false;
                for (int j = 0; j < k; j++)
                {
                    if (!holding[j].isEmpty() && holding[j].top() == nextExpected)
                    {
                        cout << "Move car " << holding[j].top()<< " from Holding Track " << j + 1 << " -> Output Track." << endl;
                        outputArr[outputCount++] = holding[j].top();
                        holding[j].pop();
                        nextExpected++;
                        moved = true;
                    }
                }
            }
        }
        else
        {
            int bestTrack = -1;
            int bestTop = n + 1;

            for (int j = 0; j < k; j++)
            {
                if (!holding[j].isEmpty())
                {
                    int topCar = holding[j].top();
                    if (car < topCar && topCar < bestTop)
                    {
                        bestTop = topCar;
                        bestTrack = j;
                    }
                }
                else if (bestTrack == -1)
                {
                    bestTrack = j;
                }
            }

            if (bestTrack == -1)
            {
                cout << "No suitable holding track found. Rearrangement failed." << endl;
                return 0;
            }

            holding[bestTrack].push(car);
            cout << "Move car " << car
                 << " from Input -> Holding Track " << bestTrack + 1 << "." << endl;
        }

        cout << "\nCurrent state of holding tracks:" << endl;
        for (int j = 0; j < k; j++)
        {
            holding[j].display(j + 1);
        }
        cout << endl;
    }

    cout << "\nFinal Output Sequence : ";

    for (int i = outputCount-1; i >= 0; i--)
    {
        cout << outputArr[i] << " ";
    }

    return 0;
}