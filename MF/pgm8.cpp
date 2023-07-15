#include<iostream> 
#define MAX 20
using namespace std; 
void safe(int n,int r,int a[MAX][MAX],int need[MAX][MAX],int avail[MAX]) 
{ 
	int count=0,looping=0,finish[20]={0},work[20]={0},i=1,j,flag=0,p[20]; 
	for(i=0;i<r;i++) 
		work[i]=avail[i]; //assigning available to work
	i=0; 
	while(count<n && looping<5*n) //looping is used to loop for some defenite number of times
	{ 
		flag=0; 
		looping++; 
		if(finish[i]==0) 
		{ 
			for(j=0;j<r;j++) 
				if(need[i][j]>work[j])  //if need is greater than work
				{ 
					flag=1; 
					break; 
				} 
			if(!flag)                       //if need is less than work
			{ 
				for(j=0;j<r;j++) 
				work[j]=work[j]+a[i][j]; 
				finish[i]=1; 
				count++;				 
				p[count]=i;	//p[] will store the process number which has finished execution			 
			} 
		} 
		i=(i+1)%n;                       //increment i for next process
		
	} 
	flag=0; 
	for(i=0;i<n;i++) 
		if(finish[i]==0)        //if some of the processes have not completed
		{ 
			flag=1; 
			break; 
		} 
	if(flag==0) 
	{ 
		cout<<"\n system is in safe state and the sequece is\n"; 
		for(i=1;i<=n;i++) 
			cout<<"P"<<p[i]<<"\t";      //print safe sequence
	} 
	else 
		cout<<"\n system is not in safe state\n"; 
} 

void newreq(int n,int r,int a[MAX][MAX],int need[MAX][MAX],int avail[MAX]) 
{ 
	int p,nr[20],flag=0,j,i; 
	cout<<"\n enter requesting process"<<endl; 
	cin>>p; 
	cout<<"\n enter request in order of resources \n"; 
	for(i=0;i<r;i++) 
		cin>>nr[i];                                //input request array
	for(j=0;j<r;j++) 
		if(nr[j]>need[p][j] && nr[j]>avail[j])   //if reequest is greater than need and if request is greater than available
			flag=1; 
	if(!flag) 
	{ 
		for(i=0;i<r;i++) 
		{ 
			avail[i]-=nr[i];             //update available, need and allocation matrix of process p 
			a[p][i]+=nr[i]; 
			need[p][i]-=nr[i]; 
		} 
		safe(n,r,a,need,avail);              //check if allocation leads to safe state 
	} 
	else 
	{ 
		cout<<"\n the process exceeds its maximum"<<endl; 
	} 
} 
int main() 
{ 
	int i,j,ch; 
	int n,r,a[MAX][MAX],m[MAX][MAX],need[MAX][MAX],avail[MAX]; 
	cout<<"\n enter the number processes"<<endl; 
	cin>>n; 
	cout<<"\n enter the number of resources"<<endl; 
	cin>>r; 
	cout<<"\n enter allocation matrix"<<endl; 
	for(i=0;i<n;i++) 
		for(j=0;j<r;j++) 
			cin>>a[i][j]; 
	cout<<"\n enter max matrix"<<endl; 
	for(i=0;i<n;i++) 
		for(j=0;j<r;j++) 
			cin>>m[i][j]; 
	for(i=0;i<n;i++) 
		for(j=0;j<r;j++) 
			need[i][j]=m[i][j]-a[i][j]; //calculate need matrix
	cout<<"\n need matrix\n"; 
	for(i=0;i<n;i++) 
	{ 
		for(j=0;j<r;j++) 
		{
			cout<<need[i][j]<<" ";
		} 
		cout<<"\n"; 
	} 

	cout<<"\n enter available resources\n"; 
	for(i=0;i<r;i++) 
		cin>>avail[i]; 
	safe(n,r,a,need,avail);               //check if the current state is safe or not
	while(true) 
	{ 
	cout<<"\n 1.new request.\n 2.exit\n enter your choice:"; 
	cin>>ch; 
	switch(ch) 
	{ 
	case 1:newreq(n,r,a,need,avail);         //resource request implementation
		continue; 
	case 2:	return 0; 
	 
	default:cout<<"re-enter"; 
		continue; 
	} 
	} 
return 0; 
	 
}
