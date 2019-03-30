/*

Ques. 7.  Design a scheduling program to implements a Queue with two levels:
Level 1 : Fixed priority preemptive Scheduling 
Level 2 : Round Robin Scheduling For a Fixed priority preemptive Scheduling (Queue 1), the Priority 0 is highest priority.
If one process P1 is scheduled and running , another process P2 with higher priority comes. 
The New process (high priority) process P2 preempts currently running process P1 and process P1 will go to second level queue. 
Time for which process will strictly execute must be considered in the multiples of 2.. 
All the processes in second level queue will complete their execution according to round robin scheduling.
Consider: 1. Queue 2 will be processed after Queue 1 becomes empty.
		  2. Priority of Queue 2 has lower priority than in Queue 1. 

*/
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
//#include<array>
using namespace std;
struct process
{
	int aT,bT,copy_bT,pN,cT,wT;            //aT=ArrivalTime,bT=BurstTime,pN=PriorityNumber,cT=CompletionTime,wT=WaitingTime
	string processId;                      //processId=ProcessName
};
int findMin(process [],int);
int findminprioritySelector(vector<int>);
class Scheduling
{
	int noprocess,var,var1,timer,minPriority,m=0,cTsetter=0,pPI,pIvar,checker=0;
	process pro[100]; 
	int previousminpriority;
	string previouspro;
	vector<string> q1,q2;
	vector<int> indexSelector,prioritySelector;
	//int g=0;           
	public:
		
		void getData()
		{
			cout<<"please enter a unique process name for each process"<<endl;
			cout<<"Enter the number of processes "<<endl;
			cin>>noprocess;
			for(int i=0;i<noprocess;i++)
			{	
				cout<<"Enter the name of the process"<<endl;
				cin>>pro[i].processId;
				cout<<"Enter  Arrival time  ||   Burst Time   ||   Priority for process   ["<<pro[i].processId<<"]  respectively"<<endl;
				cin>>pro[i].aT;
				cin>>pro[i].bT;
				pro[i].copy_bT=pro[i].bT;
				cin>>pro[i].pN;
				pro[i].cT=0;
			}
		}
		
		void findMinInArrivalTime()
		{
			int minval;
			minval=findMin(pro,noprocess);
			cout<<"minimum element in pro array is "<<minval<<endl;
			for(int i=0;i<noprocess;i++)
			{
				if(pro[i].aT==minval)
				{
					indexSelector.push_back(i);
				}
			}
			for(int i=0;i<indexSelector.size();i++)
			{
				q1.push_back(pro[indexSelector.at(i)].processId);
				prioritySelector.push_back(pro[indexSelector.at(i)].pN);
			}
		}
		
		
		
		void processSelector()
		{
	
			minPriority=findminprioritySelector(prioritySelector);
			for(int i=0;i<prioritySelector.size();i++)
			{
				if(minPriority==prioritySelector.at(i))
				{
					var=i;
					break;
				}
			}
			cout<<"["<<q1[var]<<"] "<<" is my selected process"<<endl;
			if(m>=1)
			{
		
				if(q1[var]!=previouspro)
				{
					//cout<<"process ["<<q1[var]<<"] is premptioned"<<endl;
					q1.erase(std::remove(q1.begin(),q1.end(),previouspro),q1.end());
					if(checker==0)
					{
						prioritySelector.erase(prioritySelector.begin()+pIvar,prioritySelector.begin()+(pIvar+1));
					}
					else
					{
						checker=0;
					}
					if(pro[pPI].bT!=0)
					{
						q2.push_back(previouspro);	
					}
					
				}
			}
			m+=1;
			pIvar=var;
			previouspro=q1[var];
			previousminpriority=minPriority;
			for(int i=0;i<noprocess;i++)
			{
				if(pro[i].processId==q1[var])
				{
					var1=i;
				}	
			}
			pPI=var1;
	
		}
	
		void startQ1Process()
		{
			while(q1.size()!=0)
			{
				int con=0;
				//finalResult();
				if(pro[var1].bT==0)
				{
					q1.erase(std::remove(q1.begin(),q1.end(),pro[var1].processId),q1.end());
					prioritySelector.erase(prioritySelector.begin()+var,prioritySelector.begin()+(var+1));
					checker=1;
					if(q1.size()==0)
					{
						break;
					}
					
					processSelector();
				}
				
				if(cTsetter==0)
				{
					pro[var1].cT=pro[var1].aT;
					cTsetter=1;	
				}
				else
				{
					pro[var1].cT=timer;
				}
				
				pro[var1].bT-=1;
				pro[var1].cT+=1;
				timer=pro[var1].cT;
				//cout<<"timer: "<<timer<<endl;
				for(int i=0;i<noprocess;i++)
				{
					if(timer==pro[i].aT)
					{
						q1.push_back(pro[i].processId);
						prioritySelector.push_back(pro[i].pN);
						con=1;
					}
				}
				if(con==1)
				{
					processSelector();
				}
			}
		}
		
		void startQ2process()
		{
			int TQ=2;
			
			
			
			
			
			
			//............
		}
		
		void display()
		{
			cout<<"Data set given by User"<<endl;
			cout<<"ProcessID \t\t\tArrival Time\t\t\tBurst Time\t\t\tPriority"<<endl;
			for(int i=0;i<noprocess;i++)
			{
				cout<<pro[i].processId<<"\t\t\t\t"<<pro[i].aT<<"\t\t\t\t"<<pro[i].bT<<"\t\t\t\t"<<pro[i].pN<<endl;
			} 
		}
		void inQ2()
		{
			cout<<"processes in q2"<<endl;
			for(int i=0;i<q2.size();i++)
			{
				cout<<q2.at(i)<<endl;
			}
		}
		void finalResult()
		{
			cout<<"completion time of processes"<<endl<<endl;
			cout<<"PId"<<"\t\t||\t\t"<<"AT"<<"\t\t||\t\t"<<"BT"<<"\t\t||\t\t"<<"CT"<<endl<<endl;
			for(int i=0;i<noprocess;i++)
			{
				cout<<pro[i].processId<<"\t\t||\t\t"<<pro[i].aT<<"\t\t||\t\t"<<pro[i].bT<<"\t\t||\t\t"<<pro[i].cT<<endl;
			}
		}
		
};
int main()
{
	Scheduling sc;
	sc.getData();
	sc.display();
	sc.findMinInArrivalTime();
	sc.processSelector();
	sc.startQ1Process();
	//sc.inQ2();
	//sc.startQ2process();
	sc.finalResult();
}
int findMin(process pro[], int noprocess) 
{
    int mn=pro[0].aT; 
    for(int i=0;i<noprocess;i++)
	{ 
        int temp=pro[i].aT; 
        mn=std::min(mn,temp); 
    } 
    return mn;
}
int findminprioritySelector(vector<int> prioritySelector)
{
	int minP=prioritySelector.at(0);
	for(int i=0;i<prioritySelector.size();i++)
	{
		if(prioritySelector.at(i)<minP)
		{
			minP=prioritySelector.at(i);
		}
	}
	return minP;
}