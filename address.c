#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000

struct  Addr{
	char name[MAX];
	char phone[MAX];
	char id[MAX];
	char age[MAX];
	int exist; //To determine whether it was deleted
	char tmp[MAX];
}p[MAX];

int count=0;
int insert=MAX+1; 

void menu();
int confirm(char* id_tmp);

void List();
void Find();                                                   
void Insert();
void Delete();
void Update();
void Sort();
void Write();

int main()
{
	menu();	
	char choose;	 
	scanf(" %c",&choose);
	//print menu
	while(1)
	{
		switch(choose)
		{
			case 'l':
				List();
				break;
			case 'f':
				Find();
				break;
			case 'i':
				Insert();
				break;
			case 'd':
				Delete();
				break;
			case 'u':
				Update();
				break;			
	   		case 's':
				Sort();
				break;
			case 'w':
				Write();
				break;
			case 'e': 
				exit(1);
			default:
				printf("again....\n");
				break;	 
		}
		printf("please input command: ");	
		scanf(" %c",&choose);
	}
	return 0;
}

void Insert()
{
	char *delim = ",";
	int boolen,index=0;
	static int i=0;
	char *pch,remaining[MAX];
	fgets(remaining,MAX,stdin);
	if(remaining[strlen(remaining) - 1] == '\n')
    		remaining[strlen(remaining) - 1] = '\0';
	
	pch = strtok(remaining,delim);
	while(pch != NULL)
	{
		strcpy(p[index].tmp,pch);
		pch = strtok(NULL,delim);
		index++;
	}
	strcpy(p[i].id,p[0].tmp);
	strcpy(p[i].name,p[1].tmp);
	strcpy(p[i].phone,p[2].tmp);
	strcpy(p[i].age,p[3].tmp);
	//input end
		
	boolen=confirm(p[i].id);

	if(boolen && !p[i].exist) //the situation of, repeat 
	{
		printf("Insert error! studentID is exists!\n");
	}
	else
	{
		p[i].exist=1;
		printf("%s,%s,%s,%s\n",p[i].id,p[i].name,p[i].phone,p[i].age);		
		i++;
		count++;		
	}
}
void Delete()
{
	char *delim = ",";
	int i,index=0;
	char temp[MAX];
	char *pch,remaining[MAX];	
	fgets(remaining,MAX,stdin);
	if(remaining[strlen(remaining) - 1] == '\n')
    		remaining[strlen(remaining) - 1] = '\0';
	
	pch = strtok(remaining,delim);
	while(pch != NULL)
	{
		strcpy(p[index++].tmp,pch);
		pch = strtok(NULL,delim);
	}
	strcpy(temp,p[0].tmp);
	//input end
	
	for(i=0;i<count;i++)
	{
		if(strcmp(temp,p[i].id)==0)
		{
			p[i].exist=0;
			printf("%s,%s,%s,%s\n",p[i].id,p[i].name,p[i].phone,p[i].age);
			return;
		}
	}
	printf("Delete error! studentID not exists!\n");	
}
void List()
{
	int i;
	printf("id\t\tname\t\tphone\t\t\tage\n");
	printf("--------------------------------------------------------------------\n");
	for(i=0;i<count;i++)
	{
		if(p[i].exist==1)
		{
			printf("%s\t%s\t\t%s\t\t%s\n",p[i].id,p[i].name,p[i].phone,p[i].age);
		}	
	}	
}
void Find()
{
	char *delim = ",";
		
	int i,index=0;
	char target[MAX];
	int print_down[count];
	char *pch,remaining[MAX];	
	fgets(remaining,MAX,stdin);
	if(remaining[strlen(remaining) - 1] == '\n')
    		remaining[strlen(remaining) - 1] = '\0';
	
	pch = strtok(remaining,delim);
	while(pch != NULL)
	{
		strcpy(p[index++].tmp,pch);
		pch = strtok(NULL,delim);
	}
	strcpy(target,p[0].tmp);	
	//input end
	printf("\n");
	for(i=0;i<count;i++) //initialization
		print_down[i]=0;
	
	
	for(i=0;i<count;i++)	//find the same of <ID>
	{
		if(strstr(p[i].id,target) && (!print_down[i]) && p[i].exist)
		{
			printf("%s,%s,%s,%s\n",p[i].id,p[i].name,p[i].phone,p[i].age);
			print_down[i]=1;
		}
	}
	for(i=0;i<count;i++)	//find the same of <NAME>
	{
		if(strstr(p[i].name,target) && (!print_down[i]) && p[i].exist)
		{
			printf("%s,%s,%s,%s\n",p[i].id,p[i].name,p[i].phone,p[i].age);	
			print_down[i]=1;	
		}
	}
	for(i=0;i<count;i++)	//find the same of <Phone>
	{
		if(strstr(p[i].phone,target) && (!print_down[i]) && p[i].exist)
		{
			printf("%s,%s,%s,%s\n",p[i].id,p[i].name,p[i].phone,p[i].age);	
			print_down[i]=1;	
		}
	}
	
}
void Update()
{
	char *delim = ",";

	int index=0;
	char old_id[MAX],id[MAX],name[MAX],phone[MAX],age[MAX];
	char *pch,remaining[MAX];
	fgets(remaining,MAX,stdin);
	if(remaining[strlen(remaining) - 1] == '\n')
    	remaining[strlen(remaining) - 1] = '\0';
	
	pch = strtok(remaining,delim);
	while(pch != NULL)
	{
		strcpy(p[index++].tmp,pch);
		pch = strtok(NULL,delim);
	}
	strcpy(old_id,p[0].tmp);
	strcpy(id,p[1].tmp);
	strcpy(name,p[2].tmp);
	strcpy(phone,p[3].tmp);
	strcpy(age,p[4].tmp);
	//input end
	if(confirm(old_id))
	{	
		strcpy(p[insert].id,id);		
		strcpy(p[insert].name,name);
		strcpy(p[insert].phone,phone);
		strcpy(p[insert].age,age);	
		printf("%s,%s,%s,%s\n",p[insert].id,p[insert].name,p[insert].phone,p[insert].age);	
	}
	else
		printf("Update error! studentID not exists!\n");
}
void Sort()
{
	char *delim = ",";
	
	int i,j,min,index=0;
	char cmp[5];
	char *pch,remaining[MAX];	
	fgets(remaining,MAX,stdin);
	if(remaining[strlen(remaining) - 1] == '\n')
    	remaining[strlen(remaining) - 1] = '\0';
	
	pch = strtok(remaining,delim);
	while(pch != NULL)
	{
		strcpy(p[index++].tmp,pch);
		pch = strtok(NULL,delim);
	}
	strcpy(cmp,p[0].tmp);
	//input end
	if(strcmp(cmp,"id")==0)
	{
		for(i=0;i<count-1;i++)
		{
			min=i;
			for(j=i+1;j<count;j++)
			{
				if(strcmp(p[min].id,p[j].id)>0)
				{
					min=j;
				}			
			}
			if(min!=i)
			{
				struct Addr temp;			
				temp = p[i];
				p[i] = p[min];
				p[min] = temp;
			}
		}
	}
	if(strcmp(cmp,"name")==0)
	{
		for(i=0;i<count-1;i++)
		{
			min=i;
			for(j=i+1;j<count;j++)
			{
				if(strcmp(p[min].name,p[j].name)>0)
				{
					min=j;
				}			
			}
			if(min!=i)
			{
				struct Addr temp;			
				temp = p[i];
				p[i] = p[min];
				p[min] = temp;
			}
		}
	}
	if(strcmp(cmp,"phone")==0)
	{
		for(i=0;i<count-1;i++)
		{
			min=i;
			for(j=i+1;j<count;j++)
			{
				if(strcmp(p[min].phone,p[j].phone)>0)
				{
					min=j;
				}			
			}
			if(min!=i)
			{
				struct Addr temp;			
				temp = p[i];
				p[i] = p[min];
				p[min] = temp;
			}
		}
	}
	if(strcmp(cmp,"age")==0)
	{		
		for(i=0;i<count-1;i++)
		{
			min=i;
			for(j=i+1;j<count;j++)
			{
				if(strlen(p[min].age)>strlen(p[j].age))
				{
					min=j;
				}
				else if(strlen(p[min].age) == strlen(p[j].age))
				{
					if(strcmp(p[min].age,p[j].age)>0)
					{
						min = j;
					}
				}			
			}
			if(min!=i)
			{
				struct Addr temp;			
				temp = p[i];
				p[i] = p[min];
				p[min] = temp;
			}
		}
	}
}
void Write()
{
	char *delim = ",";
	
	int index=0;
	char filename[MAX];
	char *pch,remaining[MAX];	
	fgets(remaining,MAX,stdin);
	if(remaining[strlen(remaining) - 1] == '\n')
    	remaining[strlen(remaining) - 1] = '\0';
	
	pch = strtok(remaining,delim);
	while(pch != NULL)
	{
		strcpy(p[index++].tmp,pch);
		pch = strtok(NULL,delim);
	}
	strcpy(filename,p[0].tmp);
	//input end
	FILE *fout;
	fout=fopen(filename,"w+");
	if(fout==NULL)
	{
		printf("Fail to open file %s !!\n",filename);
		return;
	}
	int i;
	fprintf(fout,"id\t\tname\t\tphone\t\t\tage\n");
	fprintf(fout,"--------------------------------------------------------------------\n");
	for(i=0;i<count;i++)
	{
		if(p[i].exist==1)
		{
			fprintf(fout,"%s\t%s\t\t%s\t\t%s\n",p[i].id,p[i].name,p[i].phone,p[i].age);	
		}	
	}	
	printf("Writing file successful!\n");
	fclose(fout);
}
void menu()
{
	printf("Main menu\n");
	printf("(l) list\n");
	printf("(f) find\n");
	printf("(u) Update\n");	
	printf("(i) insert\n");
	printf("(d) delete\n");
	printf("(s) Sort\n");	
	printf("(w) Write\n");	
	printf("(e) exit\n\n");
	printf("<hint> if U want to insert,you must be input <ID,Name,Phone,Age> in order.\n");
	printf("<hint> if U want to delete,you just need to enter the ID value of the guy.\n\n");
	printf("Please input command: "); 
}
int confirm(char* id_tmp)
{
	int i,repeat=0;
	for(i=0;i<count;i++)
	{
		if(strcmp(id_tmp,p[i].id)==0)
		{
			insert=i; //insert is the repeat point 
			repeat=1;		
			break;	
		}
	}	
	return repeat;
}
