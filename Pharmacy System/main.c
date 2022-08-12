#include<stdio.h>
 #include<conio.h>
 #include<string.h>
 #include<ctype.h>
 // declaring the structure
 struct Medicine{
   int  Medicine_ID,Medicine_price,Quantity;
   char Medicine_Name[100], Medicine_Company[100], Medicine_Manufacturing_Date[11], Medicine_Expiry_Date[11];
  }m[100];
  // prototype of the functions
    void AddMedicine(int number,struct Medicine m[]);
    void DeleteMedicine(int number);
    void UpdateMedicine(int number);
	void PrintMedicinesInStock(int number);
	void GetMedicineInfo(int number);
	void SellMedicine(int number);
   
 main()
 {
   int i,j,choice,number=0,c;
   
   
  //declaring the first medicine in stock
   m[0].Medicine_ID=1001;
   m[0].Medicine_price=15;
   m[0].Quantity=300;
   //coping and returning the string of the first medicine
   strcpy(m[0].Medicine_Manufacturing_Date,"15-10-2018");	
   strcpy(m[0].Medicine_Expiry_Date,"15-10-2020");
   strcpy(m[0].Medicine_Name,"Panadol");
   strcpy(m[0].Medicine_Company,"Pharmatech");
 
   do{
   printf("Enter\n1) Add Medicine.\n2) Delete Medicine\n3) Update Medicine details\n4) Print All Medicines in Stock.\n5) Print info of Certain Medicine\n6) Sell Medicine\n7) Quit.\n");
   scanf("%d",&choice);
   switch(choice)
   {
    case 1:
    {
     AddMedicine(number,m);
     break;
    }
     case 2:
    {
     DeleteMedicine(number+1);
     break;
    }
      case 3:
      {
       UpdateMedicine(number+1);
       break;
      }
      case 4:
      {
       PrintMedicinesInStock(number+1);
       break;
      }
      case 5:
      {
       ++number;
       GetMedicineInfo(number+1);
       break;
      }
      case 6:
      {
       SellMedicine(number+1);
       break;
      }
      case 7:
      {
       printf( "End of run.\n" );
       break;
      }
      default: 
		printf( "none\n\n" ); 
		
		break;
   }
     printf("To Continue with other Options Enter 1 Else any other number\n");
     scanf("%d",&c);
   }while(c==1);
   
 }
  void AddMedicine(int number,struct Medicine m[])
 {
 FILE  *fptr = fopen("newfile.txt", "w");
 int i;
  char name[100];
  printf("Enter Medicine Id\n");
  scanf("%d",&(m[number].Medicine_ID));
  fflush(stdin);
  printf("Enter Medicine Name\n");
  fflush(stdin);
  gets(name);
  for (i=0;i<101;i++){
  	name[i]=tolower(name[i]);
  }
  strcpy(m[number].Medicine_Name,name);
  printf("Enter Company Name\n");
  fflush(stdin);
  gets(m[number].Medicine_Company);
  printf("Enter Manufactured Date\n");
  fflush(stdin);
  gets(m[number].Medicine_Manufacturing_Date);
  printf("Enter Expiry Date\n");
  fflush(stdin);
  gets(m[number].Medicine_Expiry_Date);
  printf("Enter Quantity\n");
  fflush(stdin);
  scanf("%d",&(m[number].Quantity));
  printf("Enter Price\n");
  fflush(stdin);
  scanf("%d",&(m[number].Medicine_price));
  
  fprintf(fptr,"  %-8s|\t %-8s|\t %-8s|\t %-8s|\t %-8s|\t %-8s|\t\t %-8s|\t\t\n\n","ID","Name","Price","Quantity","Company","Medicine Manufacturing Date","Medicine Expiry Date");
 fprintf(fptr,"************************************************************************************************************************************************\n");
	fprintf(fptr,"  %-8d|\t %-8s|\t %-8dLE| \t %-8d|\t %-8s|\t %-8s|\t\t\t\t %-8s|\t\t\t\n\n",m[number].Medicine_ID,m[number].Medicine_Name,m[number].Medicine_price,m[number].Quantity,m[number].Medicine_Company,m[number].Medicine_Manufacturing_Date,m[number].Medicine_Expiry_Date);
     fprintf(fptr,"************************************************************************************************************************************************");
	  fclose(fptr);
  
  
  printf("Medicine with id %d Added Successfully\n",m[number]. Medicine_ID);
 }
 
 void DeleteMedicine(int number)
 {
  int id,i,flag=0,num;
  printf("Enter Id to be deleted\n");
  fflush(stdin);
  scanf("%d",&id);
  for(i=0;i<number;i++)
  {
   if(m[i].Medicine_ID ==id)
   {
    flag=1;
    m[i].Medicine_ID =0;
    m[i].Medicine_price =0;
    m[i].Quantity=0;
    strcpy(m[i].Medicine_Name,"");
    strcpy(m[i].Medicine_Company,"");
    strcpy(m[i].Medicine_Manufacturing_Date,"");
    strcpy(m[i].Medicine_Expiry_Date,"");
    num=i;
    break;
   }
  }
  if(flag==1)
  {
   printf("Medicine with %d is Deleted Successfully\n",id);
  }
 }
 
 void UpdateMedicine(int number)
 {
  int id,quantity,choice,c,i;
  printf("Enter id to change Details\n");
  scanf("%d",&id);
  for(i=0;i<number;i++)
  {
   if(m[i].Medicine_ID ==id && m[i].Medicine_ID!=0)
   {
    do
    {
        printf("Enter\n1 - Change Quantity\n2 - Change Price\n3 - Change Name\n4 - Change Company\n5 - Change Manufaturing Date\n6 - Change Expiry Date\n7 - Change Info\nAny other number to exit");
        scanf("%d",&choice);
        if(choice==1)
        {
         int quantity;
         printf("Enter Quantity to be changed\n");
         fflush(stdin);
         scanf("%d",&quantity);
         m[i].Quantity=quantity;
         printf("Quantity changed Successfully\n");
        }
        if(choice==2)
        {
         int price;
         printf("Enter Price to be changed\n");
         fflush(stdin);
         scanf("%d",&price);
         m[i].Medicine_price=price;
         printf("Price changed Successfully\n");
        }
        if(choice==3)
        {
         char name[100];
         printf("Enter Name to be changed\n");
         fflush(stdin);
         gets(name);
         strcpy(m[i].Medicine_Name,name);
         printf("Medicine Name changed Successfully\n");
        }
        if(choice==4)
        {
         char company[100];
         printf("Enter company to be changed\n");
         fflush(stdin);
         gets(company);
         strcpy(m[i].Medicine_Company,company);
         printf("Company changed Successfully\n");
        }
        if(choice==5)
        {
         char mfg[11];
         printf("Enter Manufacturing date to be changed\n");
         fflush(stdin);
         gets(mfg);
         strcpy(m[i].Medicine_Manufacturing_Date,mfg);
         printf("Manufacturing Date changed Successfully\n");
        }
        if(choice==6)
        {
         char exp[11];
         printf("Enter Expiry date to be changed\n");
         fflush(stdin);
         gets(exp);
         strcpy(m[i].Medicine_Expiry_Date,exp);
         printf("Expiry Date changed Successfully\n");
        }
        if(choice==7)
        {
         break;
        }
        if(choice<=0 && choice>7)
        {
         printf("Enter valid Choice\n");
        }
        printf("Enter 1 to Change other Details Else any other number\n");
        fflush(stdin);
        scanf("%d",&c);
    }while(c==1);
    
    break;
   }
  }
 }
 
  void PrintMedicinesInStock(int number){
  int i;
  char name[20],ID[4],price[6],Quantity[15],Company[14],Medicine_Manufacturing_Date[18],Medicine_Expiry_Date[19];
  int ids , prices , quantity ; 
  if(number!=0)
  { FILE  *fptr = fopen("newfile.txt", "r");
      printf("All Available Items are\n\n");
      
      printf("  %-8s\t %-8s\t %-8s\t %-8s\t %-8s\t %-8s\t\t %-8s\t\t\n\n","ID","Name","Price","Quantity","Company","Medicine Manufacturing Date","Medicine Expiry Date");
   for(i=0;i<number;i++)
   {
    if(m[i].Medicine_ID!=0){
    
		printf("  %-8d\t %-8s\t %-8d LE\t %-8d\t %-8s\t %-8s\t %-8s\t\n\n",m[i].Medicine_ID,m[i].Medicine_Name,m[i].Medicine_price,m[i].Quantity,m[i].Medicine_Company,m[i].Medicine_Manufacturing_Date,m[i].Medicine_Expiry_Date);
      }
   }  
  }
  else{
   printf("No Items or Medicines Available\n");
  } 
 }

 void GetMedicineInfo(int number){
   int i,flag=0;
  char name[100];
  printf("Enter Name of the medicine you want to see Info\n");
  fflush(stdin);
  gets(name);
  for(i=0;i<number;i++)
  {
   if(strcmp(m[i].Medicine_Name,name)==0)
   {
    flag=1;
    printf("These are the details of Medicine\n");
    printf("Name=%s\nPrice=%d\nAvailable Quantity=%d\nCompany=%s\nMfg Date=%s\nExp Date=%s\n",m[i].Medicine_Name,m[i].Medicine_price,m[i].Quantity,m[i].Medicine_Company,m[i].Medicine_Manufacturing_Date,m[i].Medicine_Expiry_Date);  
   }
  }
  if(flag==0)
  {
   printf("Entered Name Not Found\n");
  }
 }


 void SellMedicine(int number)
 {
  int id,check_entered_number,i,quantity,flag=0;
  char name[100];
  printf("Enter 1 to use ID else any other number to use Name of Medicine\n");
  fflush(stdin);
  scanf("%d",&check_entered_number);
  if(check_entered_number==1)
  {
   printf("Enter Id to purchase Medicine\n");
   fflush(stdin);
   scanf("%d",&id);
   for(i=0;i<number;i++)
   {
    if(m[i].Medicine_ID ==id)
    {
     flag=1;
     int c;
     printf("These are the details of Medicine\n");
     printf("Name%s\nPrice=%d\nAvailable Quantity=%d\nCompany=%s\nMfg Date=%s\nExp Date=%s\n",m[i].Medicine_Name,m[i].Medicine_price,m[i].Quantity,m[i].Medicine_Company,m[i].Medicine_Manufacturing_Date,m[i].Medicine_Expiry_Date);
     
     printf("Do you want to purchase %s \nIf Yes Enter 1 else any other number\n",m[i].Medicine_Name);
     fflush(stdin);
     scanf("%d",&c);
     if(c==1)
     {
      printf("Enter Quantity to Purchase\n");
      scanf("%d",&quantity);
      if(m[i].Quantity>quantity)
      {
       printf("Total Price to be paid=%d\n",quantity*m[i].Medicine_price);
      }
      else{
       printf("Please Enter quantity below Available Quantity\n");
      }
     }
     break;
    }
   }
   if(flag==0)
   {
    printf("Entered Id Not Found\n");
   }
  }
  else
  {
   printf("Enter Name to search and Purchase\n");
   fflush(stdin);
   gets(name);
   for(i=0;i<number;i++)
   {
    if(strcmp(m[i].Medicine_Name,name)==0)
    {
     flag=1;
     int c;
     printf("These are the details of Medicine\n");
     printf("Name=%s\nPrice=%d\nAvailable Quantity=%d\nCompany=%s\nMfg Date=%s\nExp Date=%s\n",m[i].Medicine_Name,m[i].Medicine_price,m[i].Quantity,m[i].Medicine_Company,m[i].Medicine_Manufacturing_Date,m[i].Medicine_Expiry_Date);
      
     printf("Do you want to purchase %s \nIf Yes Enter 1 else any other number\n",m[i].Medicine_Name);
     fflush(stdin);
     scanf("%d",&c);
     if(c==1)
     {
      printf("Enter Quantity to Purchase\n");
      scanf("%d",&quantity);
      if(m[i].Quantity>quantity)
      {
       printf("Total Price to be paid=%d\n",quantity*m[i].Medicine_price);
      }
      else{
       printf("Please Enter quantity below Available Quantity\n");
      }
     }
     break;
    }
   }
   if(flag==0)
   {
    printf("Entered Name Not Found\n");
   }
  }
 }






	//fscanf("%s%s%s%s%s%s%s%d%d%d",&ID,&name,&price,&Quantity,&Company,&Medicine_Manufacturing_Date,&Medicine_Expiry_Date,&ids,&prices,&quantity);
    	//fprintf("%s%s%s%s%s%s%s%d%d%d",ID,name,price,Quantity,Company,Medicine_Manufacturing_Date,Medicine_Expiry_Date,ids,prices,quantity);

