//***************************************************************************
/**********************PROJECT DEPARTMENTAL STORE******************************/
//***************************************************************************
/**********************INCLUDED HEADER FILES**********************************/
#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
/*****************************************************************************/

int z=-1;
char comments[50];
/******STRUCTURE PURCHASE STORES DETAILS OF ITEMS PURCHASED BY CUSTOMER*****/

struct purchase
{
	char c[3];
	char n[30];
	float p;
	int count;
}it[300];
/******CLASS DETAILS FOR BILLING PURPOSE**************/

class details
{
private:
	char name[30];
	char address[50];
	int phno;

public:
	void getdetails(void)/******FOR TAKING PERSONAL DETAILS FROM THE CUSTOMER*****/
	{
		char ch;
		cout<<"\n\nPlease enter your Personal Details\n";
		cout<<"Your name is : ";
		cin>>ch;
		cin.getline(name,30);
		cout<<"\nYour address : ";
		cin.getline(address,50);
		cout<<"\nYour phone number is : ";
		cin>>phno;
	}
	void putdetails();
}d;
void details::putdetails(void)/*****BILL PROCESSING*****/
{
	int j=0,i=0;
	float tax,disc,check=0,t=0,tot=0;
	int GRT;
	char ch;
	cout<<"\n\nYour name is : ";
	cout.write(name,30);
	cout<<"\nYour address is : ";
	cout.write(address,50);
	cout<<"\nYour phone number is : ";
	cout<<phno;
	cout<<endl;
	i=z;
	for(j=0;j<=i;j++)
	{
		t=it[j].p*it[j].count;
		cout<<"\nItem Code:"<<it[j].c<<" Name:"<<it[j].n; //item nos
		cout<<" Price Rs "<<it[j].p<<" Purchased:"<<it[j].count;
		cout<<" Total Rs "<<t<<endl;
		tot=tot+t;
	}
	cout<<endl;
	if(tot>1000)
	{
		cout<<"\nTotal Amount Rs "<<tot;
		tax=tot*0.125;
		cout<<"\nTotal Tax Rs "<<tax;
		disc=0.2*tot;
		cout<<"\nTotal Discount Rs "<<disc;
		GRT=tot+tax-disc;
		cout<<"\nTotal Amount Payable Rs "<<GRT;
	}
	else
	{
		cout<<"\nTotal Amount Rs "<<tot;
		tax=tot*0.125;
		cout<<"\nTotal Tax Rs "<<tax;
		GRT=tot+tax;
		cout<<"\nTotal Amount Payable Rs "<<GRT;
	}
	if(GRT<0)
	{
		cout<<"\nTHANK YOU SIR,SEE YOU SOON";
		exit(0);
	}

}


int homeutilities(void)/*int departmental_store(int x) invokes this function*/
/*when customer wants to buy from this section*/
{
	char section[30],code[3],name[30],ans='y',c='y',c1='y',i[3],ch;
	float price;
	cout<<"\nWELCOME TO THE HOMEUTILITIES SECTON\n";
	while(c=='y'||c=='Y')
	{
		cout<<"\nHere is the Homeutilities Menu ";
		cout<<"being displayed in the format\n";
		cout<<"\nItemcode.Name Price\n\n";
		ifstream fin("HOMEUTILITIES",ios::in);
		fin.seekg(0);
		while(!fin.eof())
		{
			fin>>code;
			fin>>name;
			fin>>price;
			cout<<code<<"."<<name<<" Rs "<<price<<"\n";
		}
		fin.close();
		cout<<"\nWant to buy any item?(y/n)";
		cin>>c1;
		if(c1=='n'||c1=='N')
		return 0;
		++z;
		cout<<"\nEnter item code:";
		cin>>i;
		fin.open("HOMEUTILITIES",ios::in);
		fin.seekg(0);
		while(fin)
		{
			fin>>code;
			fin>>name;
			fin>>price;
			if(strcmp(i,code)==0)
			{
				strcpy(it[z].c,code);
				strcpy(it[z].n,name);
				it[z].p=price;
				cout<<"\nHow many "<<it[z].n<<" do you want to buy?\n";
				cin>>it[z].count;
				break;
			}
		}
		fin.close();
		cout<<"\nWant to buy more items from Homeutilities section?(y/n)";
		cin>>c;
		if(c=='n'||c=='N')
		return 0;
	}
}
int fooditems(void)/*int departmental_store(int x) invokes this function when*/
/*customer wants to buy from this section*/
{
	char section[30],code[3],name[30],ans='y',c='y',c1='y',i[3],ch;
	float price;
	cout<<"\nWELCOME TO THE FOODITEMS SECTON\n";
	while(c=='y'||c=='Y')
	{
		cout<<"\nHere is the Fooditems Menu ";
		cout<<"being displayed in the format\n";
		cout<<"\nItemcode.Name Price\n\n";
		ifstream fin("FOODITEM",ios::in);
		fin.seekg(0);
		while(!fin.eof())
		{
			fin>>code;
			fin>>name;
			fin>>price;
			cout<<code<<"."<<name<<" Rs "<<price<<"\n";

		}
		fin.close();
		cout<<"\nWant to buy any item?(y/n)";
		cin>>c1;
		if(c1=='n'||c1=='N')
		return 0;
		++z;
		cout<<"\nEnter item code:";
		cin>>i;
		fin.open("FOODITEM",ios::in);
		fin.seekg(0);
		while(fin)
		{
			fin>>code;
			fin>>name;
			fin>>price;
			if(strcmp(i,code)==0)
			{
				strcpy(it[z].c,code);
				strcpy(it[z].n,name);
				it[z].p=price;
				cout<<"\nHow many "<<it[z].n<<" do you want to buy?\n";
				cin>>it[z].count;
				break;
			}
		}
		fin.close();
		cout<<"\nWant to buy more items from Fooditems section?(y/n)";
		cin>>c;
		if(c=='n'||c=='N')
		return 0;
	}
}
int bags(void)/*int departmental_store(int x) invokes this function when*/
/*customer wants to buy from this section*/
{
	char section[30],code[3],name[30],ans='y',c='y',c1='y',i[3],ch;
	float price;
	cout<<"\nWELCOME TO THE BAGS SECTON\n";
	while(c=='y'||c=='Y')
	{
		cout<<"\nHere is the Bags Menu ";
		cout<<"being displayed in the format\n";
		cout<<"\nItemcode.Name Price\n\n";
		ifstream fin("BAGS",ios::in);
		fin.seekg(0);
		while(!fin.eof())
		{
			fin>>code;
			fin>>name;
			fin>>price;
			cout<<code<<"."<<name<<" Rs "<<price<<"\n";
		}
		fin.close();
		cout<<"\nWant to buy any item?(y/n)";
		cin>>c1;
		if(c1=='n'||c1=='N')
		return 0;
		++z;
		cout<<"\nEnter item code:";
		cin>>i;
		fin.open("BAGS",ios::in);
		fin.seekg(0);
		while(fin)
		{
			fin>>code;
			fin>>name;
			fin>>price;
			if(strcmp(i,code)==0)
			{
				strcpy(it[z].c,code);
				strcpy(it[z].n,name);
				it[z].p=price;
				cout<<"\nHow many "<<it[z].n<<" do you want to buy?\n";
				cin>>it[z].count;
				break;
			}
		}
		fin.close();
		cout<<"\nWant to buy more items from Bags section?(y/n)";
		cin>>c;
		if(c=='n'||c=='N')
		return 0;
	}
}
int toys()/*int departmental_store(int x) invokes this function when*/
/*customer wants to buy from this section*/
{
	char section[30],code[3],name[30],ans='y',c='y',c1='y',i[3],ch;
	float price;
	cout<<"\nWELCOME TO THE TOYS SECTON\n";
	while(c=='y'||c=='Y')
	{
		cout<<"\nHere is the Toys Menu ";
		cout<<"being displayed in the format\n";
		cout<<"\nItemcode.Name Price\n\n";
		ifstream fin("TOYS",ios::in);
		fin.seekg(0);

		while(!fin.eof())
		{
			fin>>code;
			fin>>name;
			fin>>price;
			cout<<code<<"."<<name<<" Rs "<<price<<"\n";
		}
		fin.close();
		cout<<"\nWant to buy any item?(y/n)";
		cin>>c1;
		if(c1=='n'||c1=='N')
		return 0;
		++z;
		cout<<"\nEnter item code:";
		cin>>i;
		fin.open("TOYS",ios::in);
		fin.seekg(0);
		while(!fin.eof())
		{
			fin>>code;
			fin>>name;
			fin>>price;
			if(strcmp(i,code)==0)
			{
				strcpy(it[z].c,code);
				strcpy(it[z].n,name);
				it[z].p=price;
				cout<<"\nHow many "<<it[z].n<<" do you want to buy?\n";
				cin>>it[z].count;
				break;
			}
		}
		fin.close();
		cout<<"\nWant to buy more items from Toys section?(y/n)";
		cin>>c;
		if(c=='n'||c=='N')
		return 0;
	}
}
int watch()/*int departmental_store(int x) invokes this function when*/
/*customer wants to buy from this section*/
{
	char section[30],code[3],name[30],ans='y',c='y',c1='y',i[3],ch;
	float price;
	cout<<"\nWELCOME TO THE WRIST WATCH SECTON\n";
	while(c=='y'||c=='Y')
	{
		cout<<"\nHere is the Wrist Watch Menu ";
		cout<<"being displayed in the format\n";
		cout<<"\nItemcode.Name Price\n\n";
		ifstream fin("WATCH",ios::in);
		fin.seekg(0);
		while(!fin.eof())
		{
			fin>>code;
			fin>>name;
			fin>>price;
			cout<<code<<"."<<name<<" Rs "<<price<<"\n";
		}
		fin.close();

		cout<<"\nWant to buy any item?(y/n)";
		cin>>c1;
		if(c1=='n'||c1=='N')
		return 0;
		++z;
		cout<<"\nEnter item code:";
		cin>>i;
		fin.open("WATCH",ios::in);
		fin.seekg(0);
		while(!fin.eof())
		{
			fin>>code;
			fin>>name;
			fin>>price;
			if(strcmp(i,code)==0)
			{
				strcpy(it[z].c,code);
				strcpy(it[z].n,name);
				it[z].p=price;
				cout<<"\nHow many "<<it[z].n<<" do you want to buy?\n";
				cin>>it[z].count;
				break;
			}
		}
		fin.close();
		cout<<"\nWant to buy more items from Wrist Watch section?(y/n)";
		cin>>c;
		if(c=='n'||c=='N')
		return 0;
	}
}
int garment(void)/*int departmental_store(int x) invokes this function when*/
/*customer wants to buy from this section*/
{
	char section[30],code[3],name[30],ans='y',c='y',c1='y',i[3],ch;
	float price;
	cout<<"\nWELCOME TO THE GARMENTS SECTON\n";
	while(c=='y'||c=='Y')
	{
		cout<<"\nHere is the Garments Menu ";
		cout<<"being displayed in the format\n";
		cout<<"\nItemcode.Name Price\n\n";
		ifstream fin("GARMENT",ios::in);
		fin.seekg(0);
		while(!fin.eof())
		{
			fin>>code;
			fin>>name;
			fin>>price;
			//if(code[0]=='G')
			cout<<code<<"."<<name<<" Rs "<<price<<"\n";
		}
		fin.close();
		cout<<"\nWant to buy any item?(y/n)";
		cin>>c1;
		if(c1=='n'||c1=='N')
		return 0;
		++z;
		cout<<"\nEnter item code:";
		cin>>i;
		fin.open("GARMENT",ios::in);
		fin.seekg(0);
		while(!fin.eof())
		{
			fin>>code;
			fin>>name;
			fin>>price;
			if(strcmp(i,code)==0)
			{
				strcpy(it[z].c,code);
				strcpy(it[z].n,name);
				it[z].p=price;
				cout<<"\nHow many "<<it[z].n<<" do you want to buy?\n";
				cin>>it[z].count;
				break;
			}
		}
		fin.close();
		cout<<"\nWant to buy more items from Garments section?(y/n)";
		cin>>c;
		if(c=='n'||c=='N')
		return 0;
	}
}
int footwear(void)/*int departmental_store(int x) invokes this function when*/
/*customer wants to buy from this section*/
{
	char section[30],code[3],name[30],ans='y',c='y',c1='y',i[3],ch;
	float price;
	cout<<"\nWELCOME TO THE FOOTWEAR SECTON\n";
	while(c=='y'||c=='Y')
	{
		cout<<"\nHere is the Footwear Menu ";
		cout<<"being displayed in the format\n";
		cout<<"\nItemcode.Name Price\n\n";
		ifstream fin("FOOTWEAR",ios::in);
		fin.seekg(0);
		while(!fin.eof())
		{
			fin>>code;
			fin>>name;
			fin>>price;
			cout<<code<<"."<<name<<" Rs "<<price<<"\n";
		}
		fin.close();

		cout<<"\nWant to buy any item?(y/n)";
		cin>>c1;
		if(c1=='n'||c1=='N')
		return 0;
		++z;
		cout<<"\nEnter item code:";
		cin>>i;
		fin.open("FOOTWEAR",ios::in);
		fin.seekg(0);
		while(!fin.eof())
		{
			fin>>code;
			fin>>name;
			fin>>price;
			if(strcmp(i,code)==0)
			{
				strcpy(it[z].c,code);
				strcpy(it[z].n,name);
				it[z].p=price;
				cout<<"\nHow many "<<it[z].n<<" do you want to buy?\n";
				cin>>it[z].count;
				break;
			}
		}
		fin.close();
		cout<<"\nWant to buy more items from Footwear section?(y/n)";
		cin>>c;
		if(c=='n'||c=='N')
		return 0;
	}
}
int mobile(void)/*int departmental_store(int x) invokes this function when*/
/*customer wants to buy from this section*/
{
	char section[30],code[3],name[30],ans='y',c='y',c1='y',i[3],ch;
	float price;
	cout<<"\nWELCOME TO THE MOBILE SECTON\n";
	while(c=='y'||c=='Y')
	{
		cout<<"\nHere is the Mobile Menu ";
		cout<<"being displayed in the format\n";
		cout<<"\nItemcode.Name Price\n\n";
		ifstream fin("MOBILE",ios::in);
		fin.seekg(0);
		while(!fin.eof())
		{
			fin>>code;
			fin>>name;
			fin>>price;
			cout<<code<<"."<<name<<" Rs "<<price<<"\n";
		}
		fin.close();

		cout<<"\nWant to buy any item?(y/n)";
		cin>>c1;
		if(c1=='n'||c1=='N')
		return 0;
		++z;
		cout<<"\nEnter item code:";
		cin>>i;
		fin.open("MOBILE",ios::in);
		fin.seekg(0);

		while(!fin.eof())
		{
			fin>>code;
			fin>>name;
			fin>>price;
			if(strcmp(i,code)==0)
			{
				strcpy(it[z].c,code);
				strcpy(it[z].n,name);
				it[z].p=price;
				cout<<"\nHow many "<<it[z].n<<" do you want to buy?\n";
				cin>>it[z].count;
				break;
			}
		}
		fin.close();
		cout<<"\nWant to buy more items from Mobile section?(y/n)";
		cin>>c;
		if(c=='n'||c=='N')
		return 0;
	}
}
int laptop(void)/*int departmental_store(int x) invokes this function when*/
/*customer wants to buy from this section*/
{
	char section[30],code[3],name[30],ans='y',c='y',c1='y',i[3],ch;
	float price;
	cout<<"\nWELCOME TO THE LAPTOP SECTON\n";
	while(c=='y'||c=='Y')
	{
		cout<<"\nHere is the Laptop Menu ";
		cout<<"being displayed in the format\n";
		cout<<"\nItemcode.Name Price\n\n";
		ifstream fin("LAPTOP",ios::in);
		fin.seekg(0);
		while(!fin.eof())
		{
			fin>>code;
			fin>>name;
			fin>>price;
			cout<<code<<"."<<name<<" Rs "<<price<<"\n";
		}
		fin.close();

		cout<<"\nWant to buy any item?(y/n)";
		cin>>c1;
		if(c1=='n'||c1=='N')
		return 0;
		++z;
		cout<<"\nEnter item code:";
		cin>>i;
		fin.open("LAPTOP",ios::in);
		fin.seekg(0);

		while(!fin.eof())
		{
			fin>>code;
			fin>>name;
			fin>>price;
			if(strcmp(i,code)==0)
			{
				strcpy(it[z].c,code);
				strcpy(it[z].n,name);
				it[z].p=price;
				cout<<"\nHow many "<<it[z].n<<" do you want to buy?\n";
				cin>>it[z].count;
				break;
			}
		}
		fin.close();
		cout<<"\nWant to buy more items from Laptop section?(y/n)";
		cin>>c;
		if(c=='n'||c=='N')
		return 0;
	}
}

int departmental_store(int x)/*invokes a function according to user's choice*/
/*which he enters in main() function*/
{
	if(x==1)
	{
		homeutilities();return 0;
	}
	if(x==2)
	{
		fooditems();return 0;
	}
	if(x==3)
	{
		bags();return 0;
	}
	if(x==4)
	{
		toys();return 0;
	}
	if(x==5)
	{
		watch();return 0;
	}
	if(x==6)
	{
		garment();return 0;
	}
	if(x==7)
	{
		footwear();return 0;
	}
	if(x==8)
	{
		mobile();return 0;
	}
	if(x==9)
	{
		laptop();return 0;
	}
}
int shopping(void)/*invoked from main if someone wants to do shopping*/
{
	char ch='y',ch1='y';
	int j=0;

	cout<<"\nIf you purchase items worth more than Rs 1000\nyou will get 20% cashback\n";

	while(ch1=='y'||ch1=='Y')
	{
		cout<<"\nHERE IS THE MENU:";
		cout<<"\n1.Homeutilities";
		cout<<"\n2.Fooditems";
		cout<<"\n3.Bags";
		cout<<"\n4.Toys";
		cout<<"\n5.Wrist Watch";
		cout<<"\n6.Garment";
		cout<<"\n7.Footwear";
		cout<<"\n8.Mobiles";
		cout<<"\n9.Laptop";

		cout<<"\nWant to enter any section sir?(y/n)";
		cin>>ch;

		if(ch=='n'||ch=='N')
		{
			cout<<"\nTHANK YOU SIR,SEE YOU SOON";
			exit(0);
		}
		cout<<"\nEnter your choice:";
		cin>>j;
		departmental_store(j);
		cout<<"\nWant to do more shopping?(y/n)";
		cin>>ch1;
	}

	d.getdetails();
	cout<<"\n\n";
	cout<<"\nHere is your bill:\n";
	d.putdetails();
	cout<<"\n\n";


}

int mod()/*invoked from main if an authorized person want to do */
/*modify details of dept store.This function provides 4 options*/
/*append,modify and delete*/
{
	char p[30];
	int k;
	cout<<"\nENTER PASSWORD PLEASE\n";
	gets(p);
	if(strcmp(p,"Hesoyam")!=0)
	{
		cout<<"\nUNAUTHORIZED PERSON!!\n";
		exit(0);
	}
	cout<<"\nWHAT DO YOU WANT TO DO?\n";
	cout<<"1.Add/Append\n";
	cout<<"2.Modify existing data\n";
	cout<<"3.Delete existing data\n";
	cout<<"4.Go back to Store\n";
	cout<<"Enter Choice:";
	cin>>k;
	if(k==1)
	{
		char ch[20];
		cout<<"\nWhich file will you process:\n";
		cout<<"HOMEUTILITIES,FOODITEM,BAGS,GARMENT,MOBILE,LAPTOP,WATCH,TOYS,FOOTWEAR\n";
		gets(ch);
		cout<<"\nHere is the previous data\n";
		ifstream fin(ch,ios::in);
		char code[3];
		char name[30];
		float price;
		while(!fin.eof())
		{
			fin>>code;
			fin>>name;
			fin>>price;
			cout<<"CODE:"<<code<<"  NAME:"<<name<<"  PRICE:"<<price<<endl;
		}
		fin.close();
		cout<<"\n\nNow Append\n";
		ofstream fout(ch,ios::app|ios::out);
		char ans='y';
		while(ans=='y')
		{
			cout<<"\nEnter Product code:";
			cin>>code;
			cout<<"\nEnter Product name:";
			cin>>name;
			cout<<"\nEnter Product price:";
			cin>>price;
			cout<<"Do you want to enter more items(y/n)";
			cin>>ans;
			fout<<'\n'<<code<<'\n'<<name<<'\n'<<price<<'\n';
		}
		fout.close();
		cout<<"\nHere is the new data\n";
		fin.open(ch,ios::in);
		while(!fin.eof())
		{
			fin>>code;
			fin>>name;
			fin>>price;
			cout<<"CODE:"<<code<<"  NAME:"<<name<<"  PRICE:"<<price<<endl;
		}
		fin.close();
	}
	if(k==2)
	{
		char ch[20],c[3],o;
		long pos;
		cout<<"\nWhich file will you process:\n";
		cout<<"HOMEUTILITIES,FOODITEM,BAGS,GARMENT,MOBILE,LAPTOP,WATCH,TOYS,FOOTWEAR\n";
		gets(ch);
		cout<<"\nHere is the previous data\n";
		ifstream fin(ch,ios::in);
		char code[3];
		char name[30];
		float price;
		while(!fin.eof())
		{
			fin>>code;
			fin>>name;
			fin>>price;
			cout<<"CODE:"<<code<<"  NAME:"<<name<<"  PRICE:"<<price<<endl;
		}
		fin.close();
		cout<<"\n\n";
		cout<<"Enter the code for which you will modify corresponding details:";
		gets(c);

		cout<<"\n\n";

		fin.open(ch,ios::in);
		ofstream fo("t",ios::out|ios::app);
		while(!fin.eof())
		{
			pos=fin.tellg();
			fin>>code;
			fin>>name;
			fin>>price;
			fo<<code<<'\n'<<name<<'\n'<<price<<'\n';
			if(strcmp(c,code)==0)
			{
				cout<<"\nEnter Code: ";cin>>code;
				cout<<"\nEnter Name: ";cin>>name;
				cout<<"\nEnter Price: ";cin>>price;
				fo<<code<<'\n'<<name<<'\n'<<price<<'\n';
			}
		}
		fo.close();
		fin.close();
		cout<<"\n\n";
		cout<<"\nHere is the data after modification\n\n";
		remove(ch);
		rename("t",ch);
		fin.open(ch,ios::in);
		while(!fin.eof())
		{
			fin>>code;
			fin>>name;
			fin>>price;
			fin>>o;
			cout<<"CODE:"<<code<<"  NAME:"<<name<<"  PRICE:"<<price<<endl;
		}
		fin.close();
	}
	if(k==3)
	{
		char ch[20],c[3];
		cout<<"\nWhich file will you process:\n";
		cout<<"HOMEUTILITIES,FOODITEM,BAGS,GARMENT,MOBILE,LAPTOP,WATCH,TOYS,FOOTWEAR\n";
		gets(ch);
		cout<<"\nHere is the previous data\n";
		ifstream fin(ch,ios::in);
		char code[3];
		char name[30];
		float price;
		while(!fin.eof())
		{
			fin>>code;
			fin>>name;
			fin>>price;
			cout<<"CODE:"<<code<<"  NAME:"<<name<<"  PRICE:"<<price<<endl;
		}
		fin.close();
		cout<<"\n\n";
		cout<<"Enter the code for which you will delete corresponding details:";
		gets(c);

		ofstream fout("t",ios::app|ios::out);
		fin.open(ch,ios::in);
		while(!fin.eof())
		{
			fin>>code;
			fin>>name;
			fin>>price;
			if(strcmp(c,code)!=0)
			{
				fout<<code<<'\n'<<name<<'\n'<<price<<'\n';
			}
		}
		fout.close();
		fin.close();
		remove(ch);
		rename("t",ch);
		cout<<"\n\n";
		cout<<"\nHere is the data after deletion\n\n";
		fin.open(ch,ios::in);
		while(!fin.eof())
		{
			fin>>code;
			fin>>name;
			fin>>price;
			cout<<"CODE:"<<code<<"  NAME:"<<name<<"  PRICE:"<<price<<endl;
		}
		fin.close();
	}
	if(k==4)
	return 0;
}

void main()
{
	int q;
	char ans='n';
	while(ans=='n'||ans=='N')
	{
		/***********MAIN MENU*************/
		cout<<"\nWELCOME TO THE DEPARTMENTAL STORE\n";
		cout<<"\nWHAT DO YOU WANT TO DO?\n";
		cout<<"1.SHOPPING\n";
		cout<<"2.*MODIFY DATA*(FOR AUTHORIZED STAFF MEMBERS IN CHARGE ONLY)\n";
		cout<<"\nEnter Choice:";
		cin>>q;
		if(q==1)
		shopping();
		if(q==2)
		mod();
		/***********TO EXIT*************/
		cout<<"\n\nDO YOU WANT TO LEAVE THE STORE?(y,n)";
		cin>>ans;
	}
	cout<<"\nEnter your comments and views\n";
	fflush(stdin);//to clear input buffer
	gets(comments);
	cout<<"THANK YOU SIR,SEE YOU SOON";

}
