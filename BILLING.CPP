//Module of a Computer selling shop's Billing System
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>

int count=1,ch,ch1,qty,n,line=8,sk=0;
char ch2,ch3,ch4;float totalval=0;

struct product
{
 int pno;
 char pname[50];
 float price;
 char price1[10];
 char descr[100];
 int stock;
};

struct category
{
 int cid;
 char cname[50];
 product pr[10];
};

class shop
{
 float total;
 int noofcats,noofpdts[100];
 category c[10];
 public:
 shop()
 {
  noofcats=0;
  total=0;
 }
 void login();
 void inputadmn(int);
 void modifyadmn(int,char*,char*,char*,int);
 void deleteadmn(int);
 void disp();
 void fread();
 void fwrite();
 void bill();
 void billtemp();
 void dispbill();
 void aboutus();
 void contactus();
 void credits();
 void menu1();
 void updatestock(int);
 void addadmn(int);

}s ;

void shop :: contactus() // Contact Details of the Company
{
 clrscr();
 ofstream f("contact.txt");
 f<<"\nABC Computer Systems\n\nNo 233/312, Godown Street, \nOff NSC Bose Road, Parrys, \nChennai - 600001.\nPh: 044-28352866,28352434.\nMob: 9444445673.\nwww.abcsystems.com\n\nAll Rights Reserved.";
 f.close();
 char alpha;
 ifstream f1("contact.txt",ios::app);
 while(!f1.eof())
 {
  f1.get(alpha);
  cout<<alpha;
 }
  f1.close();
}

void shop :: credits() // This Project was done by
{
 clrscr();
 ofstream f("credits.txt");
 f<<"\nClass XII Computer Science Project \n\nThis Project was done by :  \n1.Karthik Prakash \n2.S.Keertivaas \n3.D.Krishanth \n4.K.M.Nitish Nambi \nof Class XII B of \nDAV Boys Senior Secondary School, Ch-86.";
 f.close();
 char alpha2;
 ifstream f1("credits.txt",ios::app);
 while(!f1.eof())
 {
  f1.get(alpha2);
  cout<<alpha2;
 }
  f1.close();
}

void shop :: login()  //User login credentials
{
 LOAD:
 struct unpw
 {
  char un[20];
  char pw[20];
 }e[3]={{"admin","admin"},{"skv123","msg"},{"username","password"}};
 clrscr();
 int ijk=0;
 char uname[20],pword[20];
 gotoxy(20,2);
 cout<<"ABC Computer systems Pvt Ltd";
 /*typedef char str[15];
 str username="admin",password="admin",uname,pword;*/
 gotoxy(18,10);
 cout<<"Username : ";
 gets(uname);
 gotoxy(18,11);
 cout<<"Password : ";
 gets(pword);
 gotoxy(18,13);
 for(int i=0;i<3;i++)
 {
  if((strcmp(uname,e[i].un)==0)&&(strcmp(pword,e[i].pw)==0))
   {
    ijk=1;
   }
 }
 if(ijk)
  {
   int kst=1;
   cout<<"Login successful..Pl wait..";
   for(long long long j=0;j<10000000;j++);
   menu1();
  }
  else
  {
   cout<<"Login failed...";
   for(long long long j=0;j<10000000;j++);
   int ch;
   cout<<"\nMenu : \n1.Retry \n2.Exit  \nGive choice : ";
   cin>>ch;
   switch(ch)
   {
    case 1:
    goto LOAD;
    break;

    case 2:
    return;
    break;

    default:cout<<"\nInvalid choice";
   }
  }

}

void shop :: menu1() // Main Menu after authentication
{
  menuretry:
  clrscr();
  int chk;
  int mpno,dpno,mstock,stno,ctno;
  char mpname[15], mprice1[10], mdesc[100];
  cout<<"\nMenu : \n1.Input products (1st time only).\n2.Modify product \n3.Delete product\n4.Update stock of product\n5.Add new product.\nGive appropriate choice : ";
  cin>>chk;
  switch(chk)
  {
   case 1:
   clrscr();
   cout<<"ABC Computer Systems Pvt. Ltd.\n";
   cout<<"\nNo of Records to enter : ";
   cin>>n;
   inputadmn(n);
   break;

   case 2:
   cout<<"\nEnter details of record to be modified : ";
   cout<<"\nEnter Product no : ";
   cin>>mpno;
   cout<<"\nEnter new product name : ";
   gets(mpname);
   cout<<"\nEnter new price : ";
   gets(mprice1);
   cout<<"\nEnter updated Description : ";
   gets(mdesc);
   cout<<"\nEnter updated stock : ";
   cin>>mstock;
   modifyadmn(mpno,mpname,mprice1,mdesc,mstock);
   break;

   case 3:
   clrscr();
   cout<<"\nEnter Product no of record to be deleted : ";
   cin>>dpno;
   deleteadmn(dpno);
   break;

   case 4:
   cout<<"Enter Product no : ";
   cin>>stno;
   updatestock(stno);
   break;

   case 5:
   cout<<"Enter Category no : ";
   cin>>ctno;
   addadmn(ctno);
   break;

   default : cout<<"\nInvalid choice. Pl try again.";
   getch();
   goto menuretry;
  }
  char mch;
  getch();
  clrscr();
  cout<<"Do you want to go to Admin menu ? : Y or N : ";
  cin>>mch;
  if(mch == 'y' || mch == 'Y')
  goto menuretry;
  else
  {
   cout<<"\nThank you for using our program. ";
   getch();
   exit(0);
  }

}

void shop :: fwrite() // Write to Data File
{
 ofstream f("sales.dat",ios::binary|ios::app);
 f.write((char*)&s,sizeof(s));
 f.close();
}

void shop :: inputadmn(int no) //To input product, category and stock as admin
{
  clrscr();
  for(int i=0;i<no;i++)
  {
   cout<<"\nEnter Category no : ";
   cin>>c[i].cid;
   cout<<"\nEnter category : ";
   gets(c[i].cname);
   noofcats++;
   cout<<"\nEnter no of products to input : "; cin>>noofpdts[i];
   for(int j=0;j<noofpdts[i];j++)
   {
    cout<<"\nProduct Details : \nProduct number : ";
    cin>>c[i].pr[j].pno;
    cout<<"\nProduct name : ";
    gets(c[i].pr[j].pname);
    cout<<"\nPrice per unit : ";
    gets(c[i].pr[j].price1);
    c[i].pr[j].price= atol(c[i].pr[j].price1);
    cout<<"\nShort description : ";
    gets(c[i].pr[j].descr);
    cout<<"\nStock : ";
    cin>>c[i].pr[j].stock;
   }
   }
  fwrite();
}

void shop :: deleteadmn(int dpno) // Delete all details for a given Product no (pno) : check
{
 int i,j,flag=0;
 fstream f("sales.dat",ios::in|ios::app);
 ofstream f1("temp.dat",ios::binary);
 while(f.read((char*)&s,sizeof(s)))
 {
  for (i=0;i<noofcats;i++)
  {
   for(j=0;j<noofpdts[i];j++)
   {
     if(c[i].pr[j].pno==dpno)
    {
     flag=1;
     for(int k=j;k<noofpdts[i];k++)
     {
      c[i].pr[k]=c[i].pr[k+1];
     }
      noofpdts[i]--;
    }
   }
  }
 }
  f1.write((char*)&s,sizeof(s));
  if(flag)
  cout<<"\nRecord found and deleted.";
  else
  cout<<"\nRecord not found.";


 f.close();
 f1.close();
 remove("sales.dat");
 rename("temp.dat","sales.dat");

}





void shop :: modifyadmn(int mpno,char mpname[10],char mprice1[10],char mdesc[100],int mstock) // Modify all details for a given Product no (pno) : check
{
 int i,j,flag=0;
 fstream f("sales.dat",ios::in | ios::app);
 ofstream f1("temp.dat",ios::binary);
 while(f.read((char*)&s,sizeof(s)))
 {
  for (i=0;i<noofcats;i++)
  {
   for(j=0;j<noofpdts[i];j++)
   {
    if(c[i].pr[j].pno==mpno)
    {
     flag=1;
     strcpy(c[i].pr[j].pname,mpname);
     strcpy(c[i].pr[j].price1,mprice1);
     c[i].pr[j].price=atol(c[i].pr[j].price1);
     strcpy(c[i].pr[j].descr,mdesc);
     c[i].pr[j].stock=mstock;
    }
   }
  }

 f1.write((char*)&s,sizeof(s));

 }

 if(flag==0)
 cout<<"\nNo such record found.";

 f.close();
 f1.close();
 remove("sales.dat");
 rename("temp.dat","sales.dat");

}

void shop :: updatestock(int stno)
{
 int stockno;
 int i,j,flag=0;
 fstream f("sales.dat",ios::in | ios::app);
 ofstream f1("temp.dat",ios::binary);
 while(f.read((char*)&s,sizeof(s)))
 {
  for (i=0;i<noofcats;i++)
  {
   for(j=0;j<noofpdts[i];j++)
   {
    if(c[i].pr[j].pno==stno)
    {
     flag = 1;
     cout<<"\nEnter stock to add : ";
     cin>>stockno;
     c[i].pr[j].stock+=stockno;
    }
   }
  }
 }
  if(flag)
  cout<<"\nStock updated. ";
  else
  cout<<"\nProduct not found.";

  f1.write((char*)&s,sizeof(s));
  f.close();
  f1.close();
  remove("sales.dat");
  rename("temp.dat","sales.dat");
}

void shop :: addadmn(int ctno) // Add a product as Admin
{
 int npno,nstock,flag=0;
 char npname[15],nprice1[10],ndesc[100];
 fstream f("sales.dat",ios::in | ios::app);
 ofstream f1("temp.dat",ios::binary);
 while(f.read((char*)&s,sizeof(s)))
 {
  for (int i=0;i<noofcats;i++)
  {
   if(c[i].cid==ctno)
   {
    flag=1;
    for(int j=i; j<noofpdts[i];j++);
    int newpdt=j;
    cout<<"\nEnter details of record to be added : ";
    cout<<"\nEnter Product no : ";
    cin>>npno;
    cout<<"\nEnter new product name : ";
    gets(npname);
    cout<<"\nEnter new price : ";
    gets(nprice1);
    cout<<"\nEnter updated Description : ";
    gets(ndesc);
    cout<<"\nEnter updated stock : ";
    cin>>nstock;
    noofpdts[i]++;
    c[i].pr[newpdt].pno=npno;
    strcpy(c[i].pr[newpdt].pname,npname);
    strcpy(c[i].pr[newpdt].price1,nprice1);
    c[i].pr[newpdt].price=atol(c[i].pr[newpdt].price1);
    strcpy(c[i].pr[newpdt].descr,ndesc);
    c[i].pr[newpdt].stock=nstock;
    cout<<"\nProduct added";
   }
  }
 }
 f1.write((char*)&s,sizeof(s));
 f.close();
 f1.close();
 remove("sales.dat");
 rename("temp.dat","sales.dat");
 if(flag==0)
 cout<<"\nCategory not found.";

}
void shop :: aboutus() // About the Company
{
 clrscr();
 ofstream f("aboutus.txt");
 f<<"About Us \n";
 f<<"\nABC computers pvt ltd. is a proven market leader \nin the supply of excellent IT products in india.\nEver since its inception in 1997 \nwe have steadily risen up the ladder \nin the industry and are today one of the leading \nIT retailers in south india. Today,we are the \nauthorised partners for the world's best IT companies \nsuch as Infosys and TCS";
 f.close();
 ifstream f1("aboutus.txt",ios::app);
 char alpha1;
 while(!f1.eof())
 {
  f1.get(alpha1);
  cout<<alpha1;
 }
  f1.close();
}

void shop :: billtemp() // Bill Printing Template
{
 ofstream f1("billing.txt");
 f1<<"\n Invoice ";
 f1<<"\n S.No    |  Product name         |       Rate       |  Quantity  |    Price   \n";
 f1<<"_____________________________________________________________________________";
 f1.close();
}


void shop :: bill() // Writes to Text file to Print the product as a Bill
{
 ofstream f1("billing.txt",ios::app);
 f1<<"\n"<<"  "<<count++<<".     |  "<<c[ch].pr[ch1].pname<<"         |       "<<(c[ch].pr[ch1].price1)<<"      |      "<<qty<<"     |     "<<c[ch].pr[ch1].price*qty;
 totalval+=(c[ch].pr[ch1].price)*qty;
 f1.close();
}

void shop :: dispbill() // Displays the Bill
{
  clrscr();
  char str;
  fstream f2("billing.txt",ios :: in);
  while(!f2.eof())
  {
    f2.get(str);
    cout<<str;
  }

  cout<<"\n\n                                                          Total :     "<<totalval;

  f2.close();
  totalval=0;
  count=1;
}


void shop :: disp() // Product Catalog Display
{
 try1:
 fstream f("sales.dat",ios::binary | ios::in | ios::out || ios::app);
 f.read((char*)&s,sizeof(s));
 ofstream f1("temp.dat",ios::binary);
 int a,i,j,var;
 billtemp();
 clrscr();
 resume:
 clrscr();
 cout<<"\nCategory Search : \n";
 for(i=0,a=0;i<noofcats;i++)
 {
  cout<<++a<<". ";
  puts(c[i].cname);
 }
 cout<<"Select preferred Category : ";
 cin>>ch;
 clrscr();
 puts(c[--ch].cname);
 cout<<"\n";
 for(j=0,var=0;j<noofpdts[ch];j++)
 {
  cout<<++var<<". ";
  puts(c[ch].pr[j].pname);
 }
 cout<<"\nSelect preferred product : ";
 cin>>ch1;ch1--;
 clrscr();
 cout<<"\n Product ID : "<<c[ch].pr[ch1].pno<<"\n Product Name : ";
 puts(c[ch].pr[ch1].pname);
 cout<<" Price : "<<c[ch].pr[ch1].price;
 cout<<"\n Specifications : \n\t";
 puts(c[ch].pr[ch1].descr);
 if(c[ch].pr[ch1].stock >= 1)
 {
  cout<<"\n Stock available : ";
  cout<<"\n Add to cart ?  Y or N : ";
  cin>>ch2;
  if(ch2 == 'Y' || ch2 == 'y')
  {
   sk++;
   try2: cout<<"Specify Qty : ";
   cin>>qty;
   if(qty<=c[ch].pr[ch1].stock)
   {
    c[ch].pr[ch1].stock -= qty;
    f1.write((char*)&s,sizeof(s));
    f.close();
    f1.close();
    remove("sales.dat");
    rename("temp.dat","sales.dat");
    f.read((char*)&s,sizeof(s));
    cout<<"\nAdded to cart ";
    bill();
    cout<<"Do you want to continue shopping ? Y or N : ";
    cin>>ch3;
    if(ch3 == 'Y' || ch3 == 'y')
    goto resume;
    else
    dispbill();
   }
   else
   {
    cout<<"\nQuantity cannot be greater than stock available. Pl try again. \n";
    goto try2;
   }
  }
  else if (ch2=='n' || ch2=='N')
  {
   if(sk==0)
   cout<<"\n Thank you for using our software";
   else
   dispbill();
  }

  else cout<<"\nInvalid choice ";


 }
  else
  {
   cout<<"\nOut of stock. Pl try other products.  ";
   getch();
   goto try1;
  }


}

void main() // Main Function
{
 int n,choice;
 mainmenu123:
 clrscr();
 cout<<"\nABC Computer Systems, Chennai - 1 ";
 cout<<"\n1.Sale\n2.Admin Login\n3.About us\n4.Contact us\n5.Credits\nSelect your action : ";
 cin>>choice;
 switch(choice)
 {
  case 1:
  s.disp();
  break;

  case 2:
  s.login();
  break;

  case 3:
  s.aboutus();
  break;

  case 4:
  s.contactus();
  break;

  case 5:
  s.credits();
  break;

  default: cout<<"\nInvalid option. Pl try again.";
  getch();
  goto mainmenu123;
 }
 getch();
 char mch;
 clrscr();
 cout<<"Do you want to go to Main menu ? : Y or N : ";
 cin>>mch;
 if(mch == 'y' || mch == 'Y')
 {
  goto mainmenu123;
  count=1;
 }
 else
 cout<<"\nThank you for using our Software.";
 getch();
}
