
#include<bits/stdc++.h>
using namespace std;

void WaitingTime(int processes[], int n, int bt[], int wt[])
{
	wt[0] = 0;

	for (int  i = 1; i < n ; i++ )
		wt[i] =  bt[i - 1] + wt[i - 1] ;
}

void TurnAroundTime( int processes[], int n,
                     int bt[], int wt[], int tat[])
{

	for (int  i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}
void avgTime( int processes[], int n, int bt[])
{
	int wt[n], tat[n], twt = 0, ttat = 0;

	WaitingTime(processes, n, bt, wt);
	TurnAroundTime(processes, n, bt, wt, tat);
	cout << "Processes  " << " Burst time  "
	     << " Waiting time  " << " Turn around time\n";
	for (int  i = 0; i < n; i++)
	{
		twt = twt + wt[i];
		ttat = ttat + tat[i];
		cout << "   " << i + 1 << "\t\t" << bt[i] << "\t    "
		     << wt[i] << "\t\t  " << tat[i] << endl;
	}

	cout << "Average waiting time = "
	     << (float)twt / (float)n;
	cout << "\nAverage turn around time = "
	     << (float)ttat / (float)n;
}

int main()
{
	int processes[] = { 1, 2, 3, 4, 5, 6};
	int n = sizeof processes / sizeof processes[0];

	int  burst_time[] = {15, 2, 3, 2, 4, 7};

	avgTime(processes, n,  burst_time);
	return 0;
}