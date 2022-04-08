#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;


struct process{
	int id;
	int arrivetime;
	int brust;
	int size;
};



//my variables
int memosize,pagesize,q,cs;
process a[5];



   
//MY FUNCTIONS
void read();
void pagetable();


int main(){


read();
cout<<"part 2 memory mangment :"<<endl;
 pagetable();
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
		
	;
	
		 for(int i=0;i<5;i++){
		 
		 	processes>>a[i].id>>a[i].arrivetime>>a[i].brust>>a[i].size;
		 }
	

				
	}	
}




void pagetable(){
	int physical_mem[99999];
	int k;
	int s=0;
	int tab1[1000];
	int tab2[1000];
	int tab3[1000];
	int tab4[1000];
	int tab5[1000];
	int memo[99999];
	int num_frames;
	int pagenum1;
	int pagenum2;
	int pagenum3;
	int pagenum4;
	int pagenum5;
    srand(time(0));
	 num_frames=memosize/pagesize;
	 bool used[9999]= {false};
	 
	 
	 int refreeFR;
  refreeFR = num_frames ;
  	
  
	cout<<"number of frames:"<<num_frames<<endl;
	
	//table for first proccess
			pagenum1=a[0].size/pagesize;
if ( pagenum1 <= refreeFR)
{
cout<<"table 1"<<endl;

    
		   for(int j=0;j<pagenum1 ; j++){
		int h=rand()%num_frames;

              if(used[h] == true)
              {
                           j--;
                           continue;
              }
              
	
		cout<<"page "<<j<<"  : frame "<<h<<endl;
		memo[h]=1; //MAPPING
     tab1[j]=h; //PAGE TABLE
	used[h]=true;
	
	}
	refreeFR -= pagenum1;	
	
	// mapping	the content of proccess 1 is represnted by "1"


 
 for(int j =0;j<pagenum1;j++)
 {
    
    for(int i=tab1[j]*pagesize;i<tab1[j]*pagesize+pagesize;i++)
    physical_mem[i]=1;
 }
}

else
cout<<"number of process pages is bigger than the number of frames"<<endl;






//table for seconed proccess
			pagenum2=a[1].size/pagesize;
if (pagenum2 <= refreeFR)
{
	
cout<<"table 2"<<endl;
    
		   for(int j=0;j<pagenum2 ; j++){
		   int h=rand()%num_frames;

              if(used[h] == true)
              {
                           j--;
                           continue;
              }
              
		
		cout<<"page "<<j<<"  : frame "<<h<<endl;
	used[h]=true;
	memo[h]=2;
    tab2[j]=h;

	}
	refreeFR -= pagenum2;	
	// mapping	the content of proccess 2 is represnted by "2"
	 
 
 for(int j =0;j<pagenum2;j++)
 {
    
    for(int i=tab2[j]*pagesize;i<tab2[j]*pagesize+pagesize;i++)
    physical_mem[i]=2;
 }
}

else
cout<<"number of process pages is bigger than the number of frames"<<endl;




//table for third proccess
	pagenum3=a[2].size/pagesize;
if (pagenum3 <= refreeFR)
{
cout<<"table 3"<<endl;

		   for(int j=0;j<pagenum3 ; j++){
		   	
	       int h=rand()%num_frames;

              if(used[h] == true)
              {
                           j--;
                           continue;
              }
              
	    	cout<<"page "<<j<<"  : frame "<<h<<endl;
	        used[h]=true;
	         memo[h]=3;
	         tab3[j]=h;
   
	
}

	
refreeFR -= pagenum3 ;	
		
	// mapping	the content of proccess 3 is represnted by "3"
	
 
 for(int j =0;j<pagenum3;j++)
 {
   
    for(int i=tab3[j]*pagesize;i<tab3[j]*pagesize+pagesize;i++)
    physical_mem[i]=3;
 }
	
}

else
cout<<"number of process pages is bigger than the number of frames"<<endl;



 
 //table for forth proccess
		pagenum4 =a[3].size/pagesize;
if (pagenum4 <= refreeFR)
{
cout<<"table 4"<<endl;
    
		   for(int j=0;j<pagenum4 ; j++){
		 int h=rand()%num_frames;

              if(used[h] == true)
              {
                           j--;
                           continue;
              }
              
	
		cout<<"page "<<j<<"  : frame "<<h<<endl;
	used[h]=true;
	memo[h]=4;
	tab4[j]=h;
    
	

	}
	refreeFR -= pagenum4;
	
	
	// mapping	the content of proccess 4 is represnted by "4"
		
 
 for(int j =0;j<pagenum4;j++)
 {
    
    for(int i=tab4[j]*a[3].size;i<tab4[j]*pagesize+pagesize;i++)
    physical_mem[i]=4;
 }
}

else
cout<<"number of process pages is bigger than the number of frames"<<endl;





//table for proccess number 5
	pagenum5=a[4].size/pagesize;
			
if (pagenum5 <= refreeFR)
{
cout<<"table 5"<<endl;
    
		   for(int j=0;j<pagenum5 ; j++){
             int h=rand()%num_frames;

              if(used[h] == true)
              {
                           j--;
                           continue;
              }
              	
	
		
		cout<<"page "<<j<<"  : frame "<<h<<endl;
	used[h]=true;
	memo[h]=5;
   tab5[j]=h;
	
	}
	refreeFR -= pagenum4;	
	
	// mapping	the content of proccess 5 is represnted by "5"

 for(int j =0;j<pagenum4;j++)
 {
    
    for(int i=tab5[j]*pagesize;i<tab5[j]*pagesize+pagesize;i++)
    physical_mem[i]=5;
 }
	
	
}

else
cout<<"number of process pages is bigger than the number of frames"<<endl;
cout<<endl;
cout<<"empty frames representad with 0"<<endl;
cout<<"proccess 1 frames representad with 1"<<endl;
cout<<"proccess 2 frames representad with 2"<<endl;
cout<<"proccess 3 frames representad with 3"<<endl;
cout<<"proccess 4 frames representad with 4"<<endl;
cout<<"proccess 5 frames representad with 5"<<endl;



 
 
 for(int i= 0; i<num_frames ;i++)
{
    cout<<" ___"<<endl;
    cout<<"| "<<memo[i]<<"  |"<<"frame"<<i<<endl;
     
}
 cout<<" ___"<<endl;

int pid;
cout<<"enter process id"<<endl;
cin>>pid;
int logad;
int pn;
int physical_add;
int offset;
cin>>logad;
if(pid==0)
{
    
if(logad<pagenum1* pagesize)
  { pn=logad/pagesize;
   offset=logad%pagesize;
   cout<<"pagenum"<<pn<< "           "<<"offset"<<offset<<endl;
   cout<<"frame"<<tab1[pn]<<"    offset "<<offset<<endl;
   physical_add=tab1[pn]*pagesize+offset;
   cout<<"physical_add= "<<physical_add<<endl;
      
  }
}
else  if(pid==1){
    
      if(logad<pagenum1* pagesize)
  { pn=logad/pagesize;
   offset=logad%pagesize;
   cout<<"pagenum"<<pn<< "           "<<"offset"<<offset<<endl;
   cout<<"frame"<<tab2[pn]<<"    offset "<<offset<<endl;
   physical_add=tab2[pn]*pagesize+offset;
   cout<<"physical_add= "<<physical_add<<endl;
      
  }
      
    }

else if(pid==2){
    
    if(logad<pagenum1* pagesize)
  { pn=logad/pagesize;
   offset=logad%pagesize;
   cout<<"pagenum"<<pn<< "           "<<"offset"<<offset<<endl;
   cout<<"frame"<<tab3[pn]<<"    offset "<<offset<<endl;
   physical_add=tab3[pn]*pagesize+offset;
   cout<<"physical_add= "<<physical_add<<endl;
      
  }
      
    }

else if(pid==3)
{
    
      if(logad<pagenum1* pagesize)
  { pn=logad/pagesize;
   offset=logad%pagesize;
   cout<<"pagenum"<<pn<< "           "<<"offset"<<offset<<endl;
   cout<<"frame"<<tab4[pn]<<"    offset "<<offset<<endl;
   physical_add=tab4[pn]*pagesize+offset;
   cout<<"physical_add= "<<physical_add<<endl;
      
  }
      
  }

else if(pid==4)
{
    
if(logad<pagenum1* pagesize)
  { pn=logad/pagesize;
   offset=logad%pagesize;
   cout<<"pagenum"<<pn<< "           "<<"offset"<<offset<<endl;
   cout<<"frame"<<tab5[pn]<<"    offset "<<offset<<endl;
   physical_add=tab5[pn]*pagesize+offset;
   cout<<"physical_add= "<<physical_add<<endl;
      
  }

}


}




