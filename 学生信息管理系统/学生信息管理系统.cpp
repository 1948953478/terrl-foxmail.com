#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct date  
					{
						int year;
						int month;
						int day;
					};
typedef struct student
{	
					char no[9];				//ѧ���ṹ��
					char name[9];			
					char sex[3];			
					struct  date birthday;
					int score[4];				
}student;
student st[30];
void menu();
int input();
void output(int n);
void namearrange(int n);
void scorearrange(int n);
void scoreout(int n);
void information(int n);
void average(int n);
void sex(int n);
void file(int n);
int main()
{
	menu();
	return 0;
}
void menu()
{
	int num,n;
	input();
	n=input();
	printf("��ѡ��˵�\n");
	printf("1.��ʾԭʼѧ����Ϣ��\n");
	printf("2.��������������\n");
	printf("3.��ʾ���ֵܷݼ������ѧ����Ϣ\n");
    printf("4.��ѧ��ؼ������ѧ����Ϣ��ƽ������\n");
	printf("5.���ſ�ƽ������\n");
	printf("6.��Ůѧ��������������\n");
	printf("7.���ļ���ʽ��ʾ�����ѧ����Ϣ��\n");
	printf("8.�˳�\n");
	scanf("%d",&num);
	switch(num)
	{
	case 1:
		output(n);
		break;
	case 2:
		namearrange(n);
		break;
	case 3:
		scoreout(n);
		break;
	case 4:
		information(n);
		break;
	case 5:
		average(n);
		break;
	case 6:
		sex(n);
		break;
	case 7:
		file(n);
		break;
	case 8:
		return;
	default :
		printf("����1~7��ѡ��\n");
		menu();
	}
}

int input()
{
	int n,i=0;
	FILE *fp;
	fp=fopen("D:\\studf.txt","r");
	if(fp==0)                                       //����
	{
		printf("file error!\n");
		exit(1);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%s%s%s%d%d%d%d%d%d%d",st[i].no,st[i].name,st[i].sex,&st[i].birthday.year,&st[i].birthday.month,&st[i].birthday.day,&st[i].score[0],&st[i].score[1],&st[i].score[2],&st[i].score[3]);
		i++;
	}
	fclose(fp);
	n=i;
	return n;
}
void output(int n)
{
	int i;
	printf("ѧ��\t����\t�Ա�\t\t����    \t��ѧ\tӢ��\tC����\t�ܷ�\n");  //���
	for(i=0;i<n;i++)
	{
		printf("%s\t%s\t%s\t   %d��%d��%d�� \t%d\t%d\t%d\t%d\n",st[i].no,st[i].name,st[i].sex,st[i].birthday.year,st[i].birthday.month,st[i].birthday.day,st[i].score[0],st[i].score[1],st[i].score[2],st[i].score[3]);
	}
}
void namearrange(int n)
{
	int i,k;
	student t;
	for (i=0;i<n-1;i++)
	{

		for (k=n-1;k>i;k--)
		{
			if(strcmp(st[k].name,st[k-1].name)<0)      //����+ð��
			{
				t=st[k-1];
                st[k-1]=st[k];
				st[k]=t;
			}
		}
	}
}
void scorearrange(int n)
{
	int i,k,index;
	student t;
	for (i=0;i<=n;i++)
	{
		index=i;
		for (k=i+1;k<=n-1;k++)
		{
			if (st[k].score[3]>st[index].score[3])     //ѡ������
				index=k;
			if (index!=i)
			{
				t=st[index];
                st[index]=st[i];
				st[i]=t;
			}
		}
	} 
	
}
void scoreout(int n)
{
	scorearrange(n);
	int i;
	printf("ѧ��\t����\t�Ա�\t\t����    \t��ѧ\tӢ��\tC����\t�ܷ�\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t%s\t%s\t   %d��%d��%d�� \t%d\t%d\t%d\t%d\n",st[i].no,st[i].name,st[i].sex,st[i].birthday.year,st[i].birthday.month,st[i].birthday.day,st[i].score[0],st[i].score[1],st[i].score[2],st[i].score[3]);
	}
}
void information(int n)
{
	int i,flag=0,item;
	double m;
	printf("��ѡ���Ӳ˵�\n");
	printf("1.��ѧ�Ų�ѯ\n");
	printf("2.��������ѯ\n");
	printf("3.�������˵�\n");
	printf("4.�˳�\n");
	scanf("%d",&item);
	switch(item)
	{                               //��Ϣ
		char st1[10];
	case 1:
		printf("���������ѯѧ�ţ��磺01��\n");
		scanf("%s",&st1);
		for(i=0;i<n;i++)
		{
			if(strcmp(st[i].no,st1)==0)
			{
				flag=1;
				m=st[i].score[3]/3.0;
				printf("ѧ��:%s ����:%s �Ա�:%s ����:%d��%d��%d�� ��ѧ:%d Ӣ��:%d C����:%d �ܷ�:%d ƽ���֣�%.2f\n",st[i].no,st[i].name,st[i].sex,st[i].birthday.year,st[i].birthday.month,st[i].birthday.day,st[i].score[0],st[i].score[1],st[i].score[2],st[i].score[3],m);
			}
		}
			if(flag==0)
				printf("��ѧ�Ų����ڣ�\n");
				break;
	case 2:
		printf("���������ѯѧ������\n");
		scanf("%s",&st1);
		for(i=0;i<n;i++)
		{
			if(strcmp(st[i].name,st1)==0)
			break;
		}
		if(strcmp(st[i].name,st1)==0)
		{
			m=st[i].score[3]/3.0;
			printf("ѧ��:%s ����:%s �Ա�:%s ����:%d��%d��%d�� ��ѧ:%d Ӣ��:%d C����:%d �ܷ�:%d ƽ���֣�%.2f\n",st[i].no,st[i].name,st[i].sex,st[i].birthday.year,st[i].birthday.month,st[i].birthday.day,st[i].score[0],st[i].score[1],st[i].score[2],st[i].score[3],m);
		}
		else
			printf("�����������ڣ�\n");
			break;
	case 3:
		menu();
		break;
	case 4:
		return;
	default :
		printf("����1~4��ѡ��\n");
		information(n);
	}
}
void average(int n)	
{
	double a=0,b=0,c=0,h,j,k;
		int i,m;
		for(i=0;i<n;i++)
		{
			a+=st[i].score[0];
			b+=st[i].score[1];
			c+=st[i].score[2];
		}
		h=a/n;
		j=b/n;
		k=c/n;                                                  //����ƽ����
		printf("�������ѯ��Ŀ����\n");
		printf("1.��ѧ\n");
	    printf("2.Ӣ��\n");
	    printf("3.C����\n");
		scanf("%d",&m);
		switch(m)
		{
		case 1:
			printf("%.2f\n",h);
			break;
		case 2:
			printf("%.2f\n",j);
			break;
		case 3:
			printf("%.2f\n",k);
			break;
		}
}
void sex(int n)
{
	int i,j=0,k=0;
	for(i=0;i<n;i++)
	{
		if(strcmp(st[i].sex,"m")==0)
			j++; 
		else
			k++;
	}                                  //������
	printf("������%d\n",j);
	printf("Ů����%d\n",k);
	printf("��������%d\n",n);
}
void file(int n)
{
	int i;
	scorearrange(n);
	FILE *f;
	f=fopen("D:\\student arrange.txt","w");
	if(!f)
	{
		printf("file error!\n");
		exit(1);
	}
	for(i=0;i<n;i++)
	{
		fprintf(f,"%s %s %s %d %d %d %d %d %d %d\n",st[i].no,st[i].name,st[i].sex,st[i].birthday.year,st[i].birthday.month,st[i].birthday.day,st[i].score[0],st[i].score[1],st[i].score[2],st[i].score[3]);
	}
	fclose(f);
	f=fopen("D:\\student arrange.txt","r");
	if(!f)
	{
		printf("file error!\n");
		exit(1);
	}
	printf("ѧ��\t����\t�Ա�\t\t����    \t��ѧ\tӢ��\tC����\t�ܷ�\n");
	for(i=0;i<n;i++)
	{
		fscanf(f,"%s%s%s%d%d%d%d%d%d%d",st[i].no,st[i].name,st[i].sex,&st[i].birthday.year,&st[i].birthday.month,&st[i].birthday.day,&st[i].score[0],&st[i].score[1],&st[i].score[2],&st[i].score[3]);
	    
	    printf("%s\t%s\t%s\t   %d��%d��%d�� \t%d\t%d\t%d\t%d\n",st[i].no,st[i].name,st[i].sex,st[i].birthday.year,st[i].birthday.month,st[i].birthday.day,st[i].score[0],st[i].score[1],st[i].score[2],st[i].score[3]);
	}
	fclose(f);
}



