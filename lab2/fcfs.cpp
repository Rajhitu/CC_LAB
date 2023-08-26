#include <bits/stdc++.h>
using namespace std;
// procs bt at
//     //    1  6  2
//     //    2  2  5
//     //    3  8  1
//     //    4  3  0
//     //    5  4  4

class Process
{
private:
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int pid;

public:
    int &operator[](string var)
    {
        if (var == "at")
            return at;
        if (var == "bt")
            return bt;
        if (var == "ct")
            return ct;
        if (var == "tat")
            return tat;
        if (var == "wt")
            return wt;
        return pid;
    }

    void update_after_ct()
    {
        tat = ct - at;
        wt = tat - bt;
    }

    void display()
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid, at, bt, ct, tat, wt);
    }
};

float average(vector<Process> P, string var)
{
    int total = 0;
    for (auto temp : P)
    {
        total += temp[var];
    }
    return (float)total / P.size();
}

int main()
{
    /*
    Input description.
    First line contains an integer n
    the next n lines contains 2 space separated integers
    containing values for arrival time and burst time for
    example:
    2
    0 3
    1 2
    */
    int n;
    printf("how many processes you have\n");
    cin >> n;
    int counter = 0;
    vector<Process> P(n);
    printf("enter arrival time and burst time for %d processes\n", n);
    for (Process &temp : P)
    {
        temp["id"] = counter++;
        cin >> temp["at"] >> temp["bt"];
    }
    sort(P.begin(), P.end(),
         [](Process first, Process second)
         {
             return first["at"] < second["at"];
         });
    printf("pid\tat\tbt\tct\ttat\twt\n");
    P[0]["ct"] = P[0]["at"] + P[0]["bt"];
    P[0].update_after_ct();
    P[0].display();
    for (int i = 1; i < P.size(); i++)
    {
        if (P[i]["at"] < P[i - 1]["ct"])
        {
            P[i]["ct"] = P[i - 1]["ct"] + P[i]["bt"];
        }
        else
        {
            printf("curr['at'] : %d, prev['ct'] : %d\n", P[i]["at"], P[i - 1]["ct"]);
            P[i]["ct"] = P[i]["at"] + P[i]["bt"];
        }
        P[i].update_after_ct();
        P[i].display();
    }

    printf("Average waiting time : %f\n", average(P, "wt"));
    printf("Average turn around  time : %f\n", average(P, "tat"));
    return 0;
}
