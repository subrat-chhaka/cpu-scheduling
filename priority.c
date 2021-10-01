#include<stdio.h>
int main(){
int bt[20], p[20], wt[20], tat[20], pr[20], i, j, n;
int total = 0, pos, temp;
float avg_wt, avg_tat;
printf("\nEnter the number of processes: ");
scanf("%d",&n);
printf("Enter the burst time and priority of processes\n");;
for(i = 0; i < n; i++){
	printf("p%d: \nBurst time: ",i+1);
	scanf("%d", &bt[i]);
	printf("Priority: ");
	scanf("%d", &pr[i]);
	p[i] = i+1;
	
}
for(i = 0; i < n; i++){
	pos = i;
	for(j = 0; j < n; j++){
		if(pr[j] < pr[pos])
			pos = j;
	}
	temp = pr[i];
	pr[i] = pr[pos];
	pr[pos] = temp;
	temp = bt[i];
	bt[i] = bt[pos];
	bt[pos] = temp;
	temp = p[i];
	p[i] = p[pos];
	p[pos] = temp;
}
wt[0] = 0;
for(i = 1; i < n; i++){
	wt[i] = 0;
	for(j = 0; j< i; j++){
		wt[i] += bt[j];
	}	
	total += wt[i];
}
	
avg_wt = total / n;
total = 0;
printf("\nProcess\tBurst time\tWaiting time\tTurn around time");
for(i = 0; i < n; i++){
	tat[i] = bt[i] + wt[i];
	total += tat[i];
	printf("\np[%d]\t\t%d\t\t%d\t\t%d", p[i], bt[i], wt[i], tat[i]);
}
avg_tat = total / n;
printf("\nAverage turn around time = %f", avg_tat);
printf("\nAverage waiting time = %f", avg_wt);
return 0;
}


/*use a swap function using pointers
*/
