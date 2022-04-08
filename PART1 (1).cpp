#include<iostream>
#include<fstream>
#include <vector>
using namespace std;


struct process{
	int id;
	int arrivetime;
	int brust;
	int size;
};

struct result {
	int p_num;
	int waitingt;
	int turnaroundt;

};

//my variables
int memosize,pagesize,q,cs;
 process a[5];
 result res[5];  //an array to put FCFS the result in
 result s[5];  //an array to put SJF the result in
 result RR[5]; // an array to put RR the result in


   
//MY FUNCTIONS
void read();
void fcfs();
void sjf();
void rr(); 



int main(){
	cout<<"part 1 cpu scheduling: "<<endl;
read();
fcfs();
rr();
sjf();

	return 0;
}

void read(){
	ifstream processes;
	char path[]="processes.txt";
	processes.open(path);
		

	while (! processes.eof())
	{
		processes>>memosize;
		processes>>pagesize;
		processes>>q;
		processes>>cs;
		
		cout<<memosize<<endl;
		cout<<pagesize<<endl;
		cout<<q<<endl;
		cout<<cs<<endl;
	
		 for(int i=0;i<5;i++){
		 
		 	processes>>a[i].id>>a[i].arrivetime>>a[i].brust>>a[i].size;
		 }
		cout<<"id"<<"  "<<"arrivetime"<<"  "<<"brust"<<"  "<<"size"<<endl;
	 
 

		for(int r=0;r<5;r++){
		cout<<a[r].id<<" "<<a[r].arrivetime<<" "<<a[r].brust<<" "<<a[r].size;
		cout<<endl;
		
		}
				
	}	
}
void fcfs()
{
	cout<<"First- Come, First-Served  scheduling:"<<endl;
	    for(int i=0;i<5;i++)
	{		
		for(int j=i+1;j<5;j++)
		{
			//arrange Arrival
			if(a[i].arrivetime>a[j].arrivetime)
			{
				
				process temp  =a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}


		res[0].waitingt=0;
		int k;
	    int total_wt=0;
        int total_tat=0;
        float avgwait,avgturnaround ,cpu_utlization;
       int sumburst=0;
	//calculate waiting time 
    for( k=1;k<5;k++)
{
	
	res[k].waitingt=a[k-1].brust+res[k-1].waitingt+a[k-1].arrivetime+cs-a[k].arrivetime;
	sumburst=a[k].brust+sumburst; //to calculate the sum of burst in order to calculate cpu utilization
	}
		int finishing[5];
    //calculate turn around time
	for( k=0;k<5;k++)
{
    //calculating turnaround time by adding burst time + waitingtime
	res[k].turnaroundt=a[k].brust+res[k].waitingt;
	
	finishing[k]=res[k].turnaroundt+a[k].arrivetime; // finshing time=turnaround time+arrivetime
	}	
	//calculate total waiting time and turnaround time
	for ( k = 0; k <5; k++)
    {
        total_wt = total_wt + res[k].waitingt;
        total_tat = total_tat + res[k].turnaroundt;
	}
avgwait=total_wt /5.0;
avgturnaround=total_tat/5.0;
cpu_utlization=(sumburst*1.0)/(sumburst+(cs*4.0));
cout<<"id"<<"    " <<"WaitingTime " <<" "<< " TurnAround Time "<<"  "<<"finishing time\n";
for(k=0;k<5;k++){
res[k].p_num=a[k].id;
		cout<<res[k].p_num<<"         "<<res[k].waitingt<<"             "<<res[k].turnaroundt<<"              "<<finishing[k];
		cout<<endl;
}
cout<<"Average waiting time = "<<avgwait<<endl;
cout<<"Average turn around time = "<<avgturnaround<<endl;
cout<<"cpu utlization="<<cpu_utlization<<endl;
cout<<"grant chart:"<<endl;
for (int x=0;x<5;x++){
	cout<<"___";
		
			cout<<"P["<<res[x].p_num<<"]";
		
		    cout<<"___"<<finishing[x]<<"|";
}

cout<<endl;


cout<<endl;
}
void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
void sjf(){
	cout<<"shortest job first scheduling:"<<endl;
	int i;
	int totwt=0;
	int tottat=0;
	int sum=0;
	float avgwt,avgta,cpuutil;
	//arrange Arrival
	for( i=0; i<4; i++) 
    { 
        
        for(int j=0; j<5-i-1; j++) 
        { 
            if(a[j].arrivetime > a[j+1].arrivetime  ) 
            { 
    
                    swap(a[j], a[j+1]); 
                
            } 
        } 
    }
    int d;
    int finishing[5];
    finishing[0]=a[0].brust+a[0].arrivetime;
for (int k=1;k<5;k++){
    
    d=finishing[k-1];
    for( i=0; i<4; i++) 
    {
        
     for(int i=1;i<5;i++)
	{		
		for(int j=i+1;j<5;j++)
		{
			if(a[i].brust>a[j].brust&& a[j].arrivetime <=d)
			{
				process temp  =a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
    finishing[k]=finishing[k-1]+a[k].brust+cs;
}}
    //calculate waiting time
 s[0].waitingt=0;
	  for( i=1;i<5;i++)
{
	s[i].waitingt=a[i-1].brust+res[i-1].waitingt+a[i-1].arrivetime+cs-a[i].arrivetime;
	sum+=a[i].brust; //to calculate the sum of burst in order to calculate cpu utilization
	}

 //calculate turn around time
	for( i=0;i<5;i++)
{
   
	s[i].turnaroundt=a[i].brust+s[i].waitingt;
	
	}	
	//calculate total waiting time and turnaround time
	for ( i = 0; i <5; i++)
    {
        totwt = totwt + s[i].waitingt;
        tottat = tottat + s[i].turnaroundt;
	}
avgwt=totwt /5.0;
avgta=tottat/5.0;
cpuutil=(sum*1.0)/(sum+(cs*4.0));

cout<<"id"<<"    " <<"WaitingTime " <<" "<< " TurnAround Time "<<"  "<<"finishing time \n";
for(i=0;i<5;i++){
s[i].p_num=a[i].id;
		cout<<s[i].p_num<<"             "<<s[i].waitingt<<"              "<<s[i].turnaroundt<<"              "<<finishing[i];
		cout<<endl;
}
cout<<"Average waiting time = "<<avgwt<<endl;
cout<<"Average turn around time = "<<avgta<<endl;
cout<<"cpu utlization="<<cpuutil<<endl;
cout<<"grant chart:"<<endl;

for (int x=0;x<5;x++){
	cout<<"__";
		
			cout<<"P["<<s[x].p_num<<"]";
		
		    cout<<"__"<<finishing[x]<<"|";
}
cout<<endl;

		
	}

	
	
	
	void rr(){
		cout<<"Round Robin scheduling:"<<endl;
	
	//implement Round Robin
		//Scheduling CPU Algorithm

/*at = Arrival time,
bt = Burst time,
time_quantum= Quantum time
tat = Turn around time,
wt = Waiting time*/

		int i, n=5, time, remain, temps = 0, time_q=q;
		int s = 0;
		int wt = 0, tat = 0;
		int cs = cs;//cs 
		int c = 0;
		remain = 5;
		// assigning the number of process to remain variable
		vector<int>t(5);
		//dynamic array declaration using vector method of (STL)
		//STL standard template library of C++
		
		for (i = 0; i < 5; i++)
		{
			t[i] = a[i].brust;
		}
		for (time = 0, i = 0; remain != 0;)
		{
			if (t[i] <= time_q && t[i] > 0)
			{
				time += t[i];
				//Addition using shorthand operators
				t[i] = 0;
				temps = 1;
				c++;
			}
			else if (t[i] > 0)
			{
				t[i] -= time_q;
				//Subtraction using shorthand operators
				time += time_q;
				c++;
				//Addition using shorthand operators
			}
			if (t[i] == 0 && temps == 1)
			{
				int completion_time;
				remain--;
				//Desplaying the result of wating, turn around time:
				cout << " p[ " << i << "]\t\tTurnaround =" << time - a[i].arrivetime + ((c - 1) * cs) << "   wating = " << time - a[i].arrivetime - a[i].brust + ((c - 1) * cs);
				cout << "  finshing time = " << time - a[i].arrivetime + ((c - 1) * cs) + a[i].arrivetime << endl;
				wt += time - a[i].arrivetime - a[i].brust + ((c - 1) * cs);
				tat += time - a[i].arrivetime + ((c - 1) * cs);
				completion_time = tat + a[i].arrivetime;
				temps = 0;
			}
			if (i == 4)
				i = 0;
			else if (a[i + 1].arrivetime <= time)
				i++;
			else
				i = 0;
		}
		for (int i = 0; i < 5; i++) {
			s += a[i].brust;
			cout << s << "    " << a[i].brust << "        ";
		}
		cout<<endl;
		cout << "Average waiting time " << wt * 1.0 / 5 << endl;
		cout << "Average turn around time " << tat * 1.0 / 5 << endl;;
		cout << "cpu utilization = " << (s / (s + ((c - 1) * cs * 1.0)))<<endl;

}
	
