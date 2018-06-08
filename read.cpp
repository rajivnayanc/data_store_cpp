#include<fstream>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<iomanip>
#include<stdlib.h>
#include<vector>
#include<unistd.h>
#include<windows.h>
using namespace std;

int main()
{ 
	fstream file;
	file.open("ap.data",ios::in);
	if(!file)
	 cout<<"File Not Found!";
	else{
		char word[1000];
		file.getline(word,180);
		int atrr=0;
		for(int i=0;word[i]!='\0';i++)
		   if(word[i]==',')
		      atrr++;
		atrr++;
		
		cout<<atrr<<endl;  
		
		char str[400000];
		long long int i=0;
		char c;
		file.seekg(0,file.beg);
		long long int d=0;
		
		while(!file.eof())
		{ 
		  c=file.get();
		  if(c=='\n')
		    d++;
		  str[i++]=c;
		  
		}
		d++;
		str[i]='\0'; 
		//cout<<str<<endl<<endl<<endl;
		long int n=0,k=0,l=0,j;
		char dataset[d][atrr][100];
		
		for(j=0;str[j]!='\0';j++)
		{
	    	if(str[j]=='\n')
		       { dataset[n][k][l]='\0';
			     n++;
				 l=0;
				 k=0; 
			   }
	    	else if(str[j]==',')
		       {
		       	dataset[n][k][l]='\0';
		       	k++;
		       	l=0;
			   }
			else if(str[j]=='\0')
			   continue;   
		    else  
		       dataset[n][k][l++]=str[j];
    	}
	   dataset[n][k][l]='\0';
	   n++;
	  cout<<n<<endl<<endl;
	  #pragma loop(hint_parallel(16))
	  for(long int q=0;q<n;q++)
	    {cout<<q+1<<". ";
		  for(long int z=0;z<atrr;z++)
	      cout<<left<<setw(3)<<dataset[q][z]<<" ";
	     cout<<endl<<endl;
		}
		 
	  cout<<"\n\n"<<d<<endl;  
	}
   file.close();	
}
