#include<iostream>
#include<string>
using namespace std;

bool message(int c,int n,int s)
{
	int count=0;
	if(c<1)
	{
		cout<<"\n\t\t\t\t Atleast 1 Capital letter is Mandatory!\n\n";
		count++;
	}
	if(n<1)
	{
		cout<<"\n\t\t\t\t Atleast 1 Numeric is Mandatory!\n\n";
		count++;
	}
	if(s<1)
	{
		cout<<"\n\t\t\t\t Atleast 1 Symbol is Mandatory!\n\n";
        count++;
	}
	if(count==0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int complexity_analysis(int c,int n,int s)
{
	//each factors c, n, s each 1 unit is equal to 16.665
	//case 1
	if(c==2) //c==33.33
	{
		if(n==1)// n==16.665
		{
			if(s==1)// s==16.665
			{
				return 66;
			}
		}
	}
	//alternative
	if(c==1)
	{
		if(n==2)
		{
			if(s==1)
			{
				return 66;
			}
		}
	}
	//alternative
	if(c==1)
	{
		if(n==1 )
		{
			if(s==2)
			{
				return 66;
			}
		}
	}
	//case 2
	if(c==2) // c==33.33
	{
		if(n==2 ) // n==33.33
		{
			if(s==1)// s==16.665
			{
				return 83;
			}
		}
	}
	//alternative
	if(c==2) // c==33.33
	{
		if(n==1 ) // n==16.665
		{
			if(s==2)// s==33.33
			{
				return 83;
			}
		}
	}
	//alternative
	if(c==1) // c==16.665
	{
		if(n==2) // n==33.33
		{
			if(s==2)// s==33.33
			{
				return 83;
			}
		}
	}
	//case 3
	if(c>=2) // c==33.33
	{
		if(n>=2) // n==33.33
		{
			if(s>=2)// s==33.33
			{
				return 99;
			}
		}
	}
	
    //when n=s=c=1
    if(c==1) // c==16.665
	{
		if(n==1) // n==16.665
		{
			if(s==1)// s==16.665
			{
				return 49.99;
			}
		}
	}
}
	
void feedback(int complexity)
{
	if(complexity==49)
	{
		cout<<"\n\t\t\t\t 49.99% Complexity\n";
		cout<<"\t\t\t\t Moderate Password\n";
	}
	if(complexity==66)
	{
		cout<<"\n\t\t\t\t 66.66% Complexity\n";
		cout<<"\t\t\t\t Medium Strong Password\n";
	}
	else if(complexity==83)
	{
		cout<<"\n\t\t\t\t 83.32% Complexity\n";
		cout<<"\t\t\t\t Strong Password\n";
	}
	else if(complexity==99)
	{
		cout<<"\n\t\t\t\t 99.99% Complexity\n";
		cout<<"\t\t\t\t Very Strong Password\n";
	}		
}
bool check(string u,string p)
{
	int l=p.length();
	if(l<8)
	{
		cout<<"\n \t\t\t\t Increase Length of Password, Minimum 8 \n\n";
		return false;
	}
	
	int count_capitalletter=0;
	int count_numbers=0;
	int count_symbol=0;

	for(int i=0;i<l;i++)
	{
		if(p[i]>=65 && p[i]<=90)
		{
			count_capitalletter++;
		}
		if(p[i]>=33 && p[i]<=47 || p[i]>=58 && p[i]<=64)
		{
			count_symbol++;
		}
		if(p[i]>=48 && p[i]<=57)
		{
			count_numbers++;
		}
	}

	if(message(count_capitalletter,count_numbers,count_symbol))
	{
		return false;
	}
	int complexity_percentage;
	complexity_percentage=complexity_analysis(count_capitalletter,count_numbers,count_symbol);
	feedback(complexity_percentage);
	
	return true;
}

void startmenu()
{
	cout<<"\t\t\t\t    |         PASSWORD MANAGEMENT     |\n\n\n";
	string username;
	string password;
	char choice;
	cout<<"\t\t\t\t Username: ";
	cin>>username;
	cout<<endl;
	while(true)
	{
	    cout<<"\t\t\t\t Password: ";
	    cin>>password;
	    cout<<endl;
	    if(check(username,password))
		{
			cout<<"\nDo you want to test more passwords:(y|n) ";
			cin>>choice;
			if(choice=='y' || choice=='Y')
			{
				cout<<"\n";
			}
			else if(choice=='n' || choice=='N')
			{
				break;
			}
		}	
	}
	
}



int main()
{
	startmenu();
}