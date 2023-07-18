#include <iostream>
#define MAX 20
#define INF 999
using namespace std;
struct time
{
    float at, bt, tat; // structure variable
    int p;
};

void sjf(struct time a[], int n, int sum)
{
    float ts = 0, diff; // ts=time spent
    int i, j = 1, k = 1;
    while (ts < sum)
    {
        if (j <= n - 1)
        {
            j++;
            diff = a[j].at - a[j - 1].at; // difference of arrival time
            a[k].bt -= diff;
            ts += diff; // adding the difference to time spent

            if (a[k].bt == 0)
                a[k].tat = ts - a[k].at; // if Burst time becomes zero calculate T.A.T
        }
        else
        {
            j = n; // if its last process
            ts += a[k].bt;
            a[k].bt = 0;
            a[k].tat = ts - a[k].at;
        }
        int small = INF;
        for (i = 1; i <= j; i++)
            if (a[i].bt < small && a[i].bt != 0)
            {
                small = a[i].bt; // small holds the smallest burst time
                k = i;           // k holds the index of shortest job
            }
    }
}

void rr(struct time a[], int n, int sum, int q)
{
    float ts = 0;
    int i, count = 0;
    while (count <= n && ts < sum)
    {
        for (i = 1; i <= n; i++)
        {
            if (a[i].bt != 0 && a[i].at <= ts)
            {
                if (a[i].bt < q) // if burst time is less than q
                {
                    ts += a[i].bt;
                    a[i].bt = 0;
                }
                else
                {
                    a[i].bt -= q; // if burst time is greater than q
                    ts += q;
                }
                if (a[i].bt == 0)
                {
                    a[i].tat = ts - a[i].at; // calculate TAT once burst time becomes zero
                    count++;
                }
            }
            if (count == n - 1 && a[i].at > ts)
            {
                ts++;
                sum++;
            }
        }
    }
}

int main()
{
    int i, j, ch, k = 1;
    int n, sum, q;
    struct time a[MAX], temp;

    while (k) // while k remains 1 more p...
    {
        cout << "\n enter the number of processes\n";
        cin >> n;
        sum = 0; //
        for (i = 1; i <= n; i++)
        {
            cout << "\n enter arrival time for process" << i << ":"; // if arrival time is s not given in round robin, give all arrival time as zeros.
            cin >> a[i].at;
            cout << "\n enter burst time for process" << i << ":";
            cin >> a[i].bt;
            a[i].p = i;
            sum = sum + a[i].bt;
        }

        for (i = 1; i <= n; i++) // to sort according to the arrival time;
            for (j = 1; j <= n - i; j++)
                if (a[j].at > a[j + 1].at)
                {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
        cout << "Process\tArrival time\tBurst time\n";
        for (i = 1; i <= n; i++)
            cout << a[i].p << "\t" << a[i].at << "\t\t" << a[i].bt << "\n";
        cout << "1.SJF 2.RR";
        cin >> ch;
        switch (ch)
        {
        case 1:
            sjf(a, n, sum);
            cout << "\n \n SHORTEST REMAINING JOB \n \n";
            break;
        case 2:
            cout << "enter q";
            cin >> q;
            rr(a, n, sum, q);
            cout << "\n \n ROUND ROBIN \n \n";
        }
        cout << "\n \n \n \n"
             << "P.NO"
             << "\t"
             << "T.A.T" << endl;
        for (i = 1; i <= n; i++)
            cout << a[i].p << "\t" << a[i].tat << "\n";
        float avg = 0;
        for (i = 1; i <= n; i++)
        {
            avg += a[i].tat;
        }
        cout << "\n average T.A.T is" << avg / n << endl;
        cout << endl
             << "If you want to continue press 1 or else 0" << endl;
        cin >> k;
    }
    return 0;
}
