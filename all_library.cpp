#include"stdio.h"
#include"conio.h"
#include"string.h"
#include"stdlib.h"
#define  LIBRARIAN_MAX  2 /*����Ա����*/
int N;
int book_num_now = 0;  /*��¼��ǰ�ṹ�����ж����鼮*/ 
int login_num;
int login_ID;
char login_mima[20];
/**********����ͼ��ṹ������book*******/
struct book
{
    long num;				/*���*/
    char name[20];			/*����*/
    char writer[20];		/*����*/
    char publish[20];		/*������*/
    struct time				/*����*/
    {
        int day;
        int month;
        int year;
    }t;
    char site[10];			/*ͼ�����λ��*/ 
    int  total; 			/*ͼ��������*/ 
    int  jie;				/*��������*/
}bk[20];
/**********����ͼ��ṹ������book*******/
struct manager
{
    int manager_id;
    char managerpassword[20];

}Manager[2];
/********��������Ա��Ϣ��********/
void manage_xinxi()
{
	FILE *fp1;
    fp1 = fopen("librarian.txt","r+");
	for(int i=0;i<LIBRARIAN_MAX;i++){
		fscanf(fp1,"%d",&Manager[i].manager_id);
		fscanf(fp1,"%s",Manager[i].managerpassword);
	}
	/* 
    system("CLS");
    printf("\t\t         =====================        \n");
    printf("\t\t           ���ع���Ա��Ϣ�ɹ�              \n");
    printf("\t\t         =====================        \n\n");
    */ 
}
/********¼��ͼ����Ϣ��********/
void xinxi()
{ 
    int i;
    int book_num_updata = book_num_now; /*���ڼ�¼����鼮֮ǰ���鼮����*/
    system("CLS");
    printf("\t\t         =====================        \n");
    printf("\t\t               ¼��ͼ����Ϣ              \n");
    printf("\t\t         =====================        \n\n");
	printf("\t\t��������Ҫ¼�������:");
	scanf("%d",&N);
	book_num_now += N;
    for(i=book_num_updata;i<book_num_now;i++)
    {
		printf("\t\t�������%d����ı��:",i+1);
        scanf("%d",&bk[i].num);
        printf("\t\t�������%d���������:",i+1);
        scanf("%s",bk[i].name);
        printf("\t\t�������%d���������:",i+1);
        scanf("%s",bk[i].writer);
        printf("\t\t�������%d����ĳ�����:",i+1);
        scanf("%s",bk[i].publish);
        printf("\t\t�������%d����ĳ���ʱ��(�ö��Ÿ���):",i+1);
        scanf("%d,%d,%d",&bk[i].t.year,&bk[i].t.month,&bk[i].t.day);
        printf("\t\t�������%d��������λ��(A123):",i+1);
        scanf("%s",bk[i].site);
        printf("\t\t�������������:");
        scanf("%d",&bk[i].jie);
        printf("\t\t���������:");
        scanf("%d",&bk[i].jie);
		printf("--------------------------------------------------------------------------------\n");
    }
	system("CLS");
    printf("\t\t         =====================        \n");
    printf("\t\t               ��Ϣ¼�����              \n");
    printf("\t\t         =====================        \n");
    printf("\n\t\t             �����������...\n");
}
void xinxi_fromFILE()
{
	int book_num_updata = book_num_now; /*���ڼ�¼����鼮֮ǰ���鼮����*/
	FILE *fp1;
    fp1 = fopen("Books.txt","r+");	
    int i;
    system("CLS");
    printf("\t\t         =====================        \n");
    printf("\t\t               ¼��ͼ����Ϣ              \n");
    printf("\t\t         =====================        \n\n");
	printf("\t\t��������Ҫ¼�������:");
	scanf("%d",&N);
	book_num_now += N;
    for(i=book_num_updata;i<book_num_now;i++)
    {
    	/*
		printf("\t\t�������%d����ı��:",i+1);
        scanf("%d",&bk[i].num);
        printf("\t\t�������%d���������:",i+1);
        scanf("%s",bk[i].name);
        printf("\t\t�������%d����ĳ�����:",i+1);
        scanf("%s",bk[i].publish);
        printf("\t\t�������%d����ĳ���ʱ��(�ö��Ÿ���):",i+1);
        scanf("%d,%d,%d",&bk[i].t.year,&bk[i].t.month,&bk[i].t.day);
        printf("\t\t�����Ƿ��Ѿ�������,�ѱ���������'1'��δ����������'0':");
        scanf("%d",&bk[i].jie);
		printf("--------------------------------------------------------------------------------\n");
		*/
		fscanf(fp1,"%d",&bk[i].num);
		fscanf(fp1,"%s",bk[i].name);
		fscanf(fp1,"%s",bk[i].writer);
		fscanf(fp1,"%s",bk[i].publish);
		fscanf(fp1,"%d",&bk[i].t.year);
		fscanf(fp1,"%d",&bk[i].t.month);
		fscanf(fp1,"%d",&bk[i].t.day);
		fscanf(fp1,"%s",bk[i].site);
		fscanf(fp1,"%d",&bk[i].total);
		fscanf(fp1,"%d",&bk[i].jie);
		
    }
	system("CLS");
    printf("\t\t         =====================        \n");
    printf("\t\t               ��Ϣ¼�����              \n");
    printf("\t\t         =====================        \n");
    printf("\n\t\t             �����������...\n");
}
/******���˵�******/
int mymainmenu()
{
    int x;
	printf("\n\n\n\n");
    printf("\t\t|-------------------------------------------------------------|\n");
    printf("\t\t|                                         |\n");
    printf("\t\t|        ======================        |\n");
    printf("\t\t|           ��ӭ����ͼ�����ϵͳ          |\n");
    printf("\t\t|        ======================        |\n");
    printf("\t\t|                                         |\n");
    printf("\t\t|           1.����Աģʽ                   |\n");
    printf("\t\t|           2.�ͻ�ģʽ                     |\n");
    printf("\t\t|           3.�˳�ϵͳ                     |\n");
    printf("\t\t|--------------------------------------------------------------|\n");
    printf("\n\t\t����������ѡ��:");
    scanf("%d",&x);
    return x;
}
/**************����Ա������֤*****************/
int mimayanzheng()
{
	int  temp_id;		/*��������û������ID*/
	char temp_mima[20];/*��������û����������*/
	int flag = 0;
    printf("\n");
    printf("\t\t         ======================        \n");
    printf("\t\t            ��ӭʹ�ù���Աģʽ            \n");
    printf("\t\t         ======================        \n");
    printf("\n");
    printf("\t\t          ���������ԱID:");
    scanf("%d",&temp_id);
    printf("\t\t          ����������:");
    scanf("%s",temp_mima);
    for(int i = 0;i < 2;i++){
    	if(temp_id == Manager[i].manager_id){
    		if(strcmp(temp_mima,Manager[i].managerpassword)==0){
    			login_num = i;
				login_ID = Manager[i].manager_id;
				//login_mima = Manager[i].managerpassword;
    			strcpy(login_mima,Manager[i].managerpassword);
				return 1;
			} 
		}
		flag++;
	}
	if(flag == 2) printf("\t\tID����\n");
	return 0;
}
/**************�޸�����***********/
void xiugaimima()
{
	char temp_mima[20],temp1[20],temp2[20];/* temp_mima[20]��������û���������룬temp1[20],temp2[
20]�ֱ���������û�����������޸ĵ�����*/    
printf("\n");
    printf("\t\t         ======================        \n");
    printf("\t\t                 �޸�����                 \n");
    printf("\t\t         ======================        \n");
    printf("\n");
	printf("\t\t           ������ԭʼ����:");
	scanf("\t\t%s",temp_mima);
    while(1)
    {
	if(strcmp(temp_mima,login_mima)==0)/*�Ƚ�����*/
	{
		printf("\t           ������������:");
		scanf("%s",temp1);
		printf("\t           ��������һ��:");
		scanf("%s",temp2);
		if(strcmp(temp1,temp2)==0)/*�����������������붼��ͬ*/
		{
			printf("\t           �޸�����ɹ�!!���������,���������...");
			strcpy(Manager[login_num].managerpassword,temp1);
			getch();break;
		}
		else
		{
			printf("\t�����������벻��ͬ���޸�ʧ��!���������...");
			getch();
			break;
		}
	}
	else
	{
		printf("\t�������!�����ܽ��������޸�!���������...");
		getch();
		break;
	}
}
}	
/**************����Աģʽ****************/
int adm()
{
    int x;
	printf("\n\n\n\n");
    printf("\t\t|-------------------------------------------------------------|\n");
    printf("\t\t|                                         |\n");
    printf("\t\t|        ======================        	  |\n");
    printf("\t\t|               ����Աģʽ                |\n");
    printf("\t\t|        ======================           |\n");
    printf("\t\t|                                         |\n");
    printf("\t\t|           1.¼��ͼ����Ϣ                |\n");
    printf("\t\t|           2.�鿴ͼ����Ϣ                |\n");
    printf("\t\t|           3.�޸�ͼ����Ϣ                |\n");
    printf("\t\t|           4.�޸Ĺ�������                |\n");
    printf("\t\t|           5.���ļ���¼��ͼ����Ϣ        |\n");
    printf("\t\t|           6.�˳�ϵͳ                    |\n");
    printf("\t\t|-------------------------------------------------------------|\n");
    printf("\n\t\t����������ѡ��:");
    scanf("%d",&x);
    return x;
}
/******************�ͻ�ģʽ********************/
int peo()
{
    int x;
	printf("\n\n\n\n");
    printf("\t\t|-------------------------------------------------------------|\n");
    printf("\t\t|                                         |\n");
    printf("\t\t|        ======================           |\n");
    printf("\t\t|               ��ӭ����                  |\n");
    printf("\t\t|        ======================           |\n");
    printf("\t\t|                                         |\n");
    printf("\t\t|           1.�鿴ͼ����Ϣ                |\n");
    printf("\t\t|           2.����ͼ��                    |\n");
    printf("\t\t|           3.�˳�ϵͳ                    |\n");
    printf("\t\t|-------------------------------------------------------------|\n");
    printf("\n\t\t����������ѡ��:");
    scanf("%d",&x);
    return x;
}
/*********�鿴����ͼ��*******/
void show_all_book()
{
	int i;
	if(book_num_now==0)
		printf("\t���ݲ����ڣ�����¼������!\n\t\t�����������...");
	else
	{
		printf("\t���    ͼ������         ����             ������         ����ʱ��       λ��  ������  ������\n");
		for(i=0;i<book_num_now;i++)
		{
			printf("\t%-7d %-16s %-16s %-12s   %4d��%2d��%2d�� %-7s %-7d %-4d\n",bk[i].num,
																 				 bk[i].name,
																 				 bk[i].writer,
																 				 bk[i].publish,
																 				 bk[i].t.year,
																 				 bk[i].t.month,
																 				 bk[i].t.day, 
																 				 bk[i].site,
																 				 bk[i].total,
																 				 bk[i].jie
																 				 );
		} 
	}
}
/*********�������鿴********/
void showbook_name()
{
    int i,k=0,n;/*k��������Ƿ���ڸ���*/
    char book_name[20];
    printf("\t\t         =====================        \n");
    printf("\t\t               �������鿴                \n");
    printf("\t\t         =====================        \n");
    printf("\n\t\t��������Ҫ�鿴��ͼ������:");
    scanf("%s",book_name);
    for(i=0;i<book_num_now;i++)
        if(strcmp(book_name,bk[i].name)==0)
		{
			n=i;
			if(k==0)/* "��Ŀ"ֻ���һ��*/
			    printf("\t���    ͼ������         ����             ������         ����ʱ��       λ��  ������  ������\n");
           	printf("\t%-7d %-16s %-16s %-12s   %4d��%2d��%2d�� %-7s %-7d %-4d\n",bk[i].num,
																 				 bk[i].name,
																 				 bk[i].writer,
																 				 bk[i].publish,
																 				 bk[i].t.year,
																 				 bk[i].t.month,
																 				 bk[i].t.day, 
																 				 bk[i].site,
																 				 bk[i].total,
																 				 bk[i].jie
																 				 );
	            printf("\t\t�����������...");
			k++; /*kֵ��Ϊ�����ʾ�ҵ�ͼ��*/
		}
		if(k==0)  /*kֵΪ�����ʾδ�ҵ�ͼ��*/
			printf("\t\t�����ڸ���!�����������...");
}
/*********����Ų鿴********/
void showbook_num()
{
    int n,book_num,i,k=0;/*k��������Ƿ���ڸ���*/
    printf("\t\t         =====================        \n");
    printf("\t\t               ����Ų鿴                \n");
    printf("\t\t         =====================        \n");
    printf("\n\t\t��������Ҫ�鿴��ͼ����:");
    scanf("%d",&book_num);
    for(i=0;i<book_num_now;i++)
        if(book_num==bk[i].num)
		{
			n=i;
			if(k==0)/* "��Ŀ"ֻ���һ��*/
			    printf("\t���    ͼ������         ����             ������         ����ʱ��       λ��  ������  ������\n");
            printf("\t%-7d %-16s %-16s %-12s   %4d��%2d��%2d�� %-7s %-7d %-4d\n",bk[i].num,
																 				 bk[i].name,
																 				 bk[i].writer,
																 				 bk[i].publish,
																 				 bk[i].t.year,
																 				 bk[i].t.month,
																 				 bk[i].t.day, 
																 				 bk[i].site,
																 				 bk[i].total,
																 				 bk[i].jie
																 				 );
			k++;
			printf("\t\t�����������...");
		}
	if(k==0) /*kΪ�����ʾδ�ҵ�ͼ��*/
		printf("\t\t�����ڸ���!�����������...");    	
}
/*********��������鿴********/
void showbook_publish()
{
    int n,i,k=0;/*k��������Ƿ���ڸ���*/
    char book_publish[20];
    printf("\t\t         =====================        \n");
    printf("\t\t               ��������鿴                \n");
    printf("\t\t         =====================        \n");
    printf("\n\t\t��������Ҫ�鿴��ͼ�������:");
    scanf("%s",book_publish);
    for(i=0;i<book_num_now;i++)
        if(strcmp(book_publish,bk[i].publish)==0)
		{
			n=i;
			if(k==0)/* "��Ŀ"ֻ���һ��*/
			    printf("\t���    ͼ������         ����             ������         ����ʱ��       λ��  ������  ������\n");
            printf("\t%-7d %-16s %-16s %-12s   %4d��%2d��%2d�� %-7s %-7d %-4d\n",bk[i].num,
																 				 bk[i].name,
																 				 bk[i].writer,
																 				 bk[i].publish,
																 				 bk[i].t.year,
																 				 bk[i].t.month,
																 				 bk[i].t.day, 
																 				 bk[i].site,
																 				 bk[i].total,
																 				 bk[i].jie
																 				 );
		    if(bk[n].jie==1)
                printf("  �ѱ�����\n");
            else
                printf("  ���Խ���\n");
			k++;
			
		}
	if(k==0) /*kΪ�����ʾδ�ҵ�ͼ��*/
		printf("\t�����ڸ���!�����������...");   
	else
		printf("\t�����������..."); 	
}

/********��ʾȫ���ѽ��ĵ�ͼ��**********/
void yijieyue()
{
    int i,k=0;
	if(book_num_now==0)
		 printf("\t���ݲ����ڣ�����¼������!\n\t\t�����������...");
	else
	{
	    for(i=0;i<book_num_now;i++)
			if(bk[i].jie!=0)
			{
				if(k==0)
				    printf("\t���    ͼ������         ����             ������         ����ʱ��       λ��  ������  ������\n");
            printf("\t%-7d %-16s %-16s %-12s   %4d��%2d��%2d�� %-7s %-7d %-4d\n",bk[i].num,
																 				 bk[i].name,
																 				 bk[i].writer,
																 				 bk[i].publish,
																 				 bk[i].t.year,
																 				 bk[i].t.month,
																 				 bk[i].t.day, 
																 				 bk[i].site,
																 				 bk[i].total,
																 				 bk[i].jie
																 				 );
                k++;			
			}
            if(k==0)
				printf("\n\t\tĿǰû���κ������������������...");
	}
}
/********��ʾȫ��δ���ĵ�ͼ��********/
void weijieyue()
{
    int i,k=0;
	if(book_num_now==0)
		 printf("\t���ݲ����ڣ�����¼������!\n\t\t�����������...");
	else
	{
	    for(i=0;i<book_num_now;i++)
			if((bk[i].total-bk[i].jie)!=0)
			{
				if(k==0)
				    printf("\t���    ͼ������         ����             ������         ����ʱ��       λ��  ������  ʣ����\n");
            printf("\t%-7d %-16s %-16s %-12s   %4d��%2d��%2d�� %-7s %-7d %-4d\n",bk[i].num,
																 				 bk[i].name,
																 				 bk[i].writer,
																 				 bk[i].publish,
																 				 bk[i].t.year,
																 				 bk[i].t.month,
																 				 bk[i].t.day, 
																 				 bk[i].site,
																 				 bk[i].total,
																 				 bk[i].total-bk[i].jie
																 				 );
			    k++;
			}
			if(k==0)
               printf("\n\t���ź���Ŀǰ���е��鶼������ˡ������������...");
	}
}
/*****�鿴ͼ��˵�******/
void show()
{
    int x;
	do
	{
		 system("cls");
		 printf("\n\n\n\n");
    	 printf("\t\t|-------------------------------------------------------------|\n");
    	 printf("\t\t|                                         |\n");
    	 printf("\t\t|         =====================           |\n");
    	 printf("\t\t|              �鿴ͼ����Ϣ               |\n");
    	 printf("\t\t|         =====================           |\n");
    	 printf("\t\t|                                         |\n");
    	 printf("\t\t|           1.����������                  |\n");
    	 printf("\t\t|           2.����Ų���                  |\n");
    	 printf("\t\t|           3.�����������                |\n");
    	 printf("\t\t|           4.�鿴����δ����ͼ��          |\n");
    	 printf("\t\t|           5.�鿴�����ѽ���ͼ��          |\n");
    	 printf("\t\t|           6.�鿴����ͼ��                |\n");
    	 printf("\t\t|           7.�������˵�                  |\n");
    	 printf("\t\t|-------------------------------------------------------------|\n");
    	 printf("\n\t\t����������ѡ��:");
    	 scanf("%d",&x);
    	 switch(x)
    	 {
         	 case 1:system("cls");showbook_name();getch();break;	/*�������鿴*/
        	 case 2:system("cls");showbook_num();getch();break;		/*����Ų鿴*/
        	 case 3:system("cls");showbook_publish();getch();break;	/*��������鿴*/
       	   	 case 4:system("cls");weijieyue();getch();break;		/*�鿴δ����ͼ��*/
       	   	 case 5:system("cls");yijieyue();getch();break;			/*�鿴�ѽ���ͼ��*/
		 	 case 6:system("cls");show_all_book();getch();break;	/*�鿴����ͼ��*/	
    	 }                                    
	}while(x!=7);
}
/*********����������*******/
void jie_name()
{
	char jy[2],name[20];/*jy������ʾ�Ƿ�ȷ������*/
	int i,book_xb,k=0;/*k��������Ƿ���ڸ���*/
	printf("\t\t         ======================       \n");
    printf("\t\t                ����������               \n");
    printf("\t\t         ======================       \n");
	while(1)
	{
    printf("\n\t\t����������:");
    scanf("%s",name);
    for(i=0;i<book_num_now;i++)
        if(strcmp(bk[i].name,name)==0&&((bk[i].total-bk[i].jie)!=0))/*�ҵ�ͼ�鲢ȷ��ͼ��û�б��������¼ͼ���±�*/
		{
		    book_xb=i;
			k++;
			break;
		}
	if(k==0)
	{
		printf("\t�����ڸ��飬������Ѿ�ȫ�����!����ȷ����ͼ������!\n\t\t�����������...");
		getch();
        break;
	}
	if(k==1)
	    printf("\t���    ͼ������         ����             ������         ����ʱ��       λ��  ������  ʣ����\n");
    printf("\t%-7d %-16s %-16s %-12s   %4d��%2d��%2d�� %-7s %-7d %-4d\n",bk[book_xb].num,
																 				 bk[book_xb].name,
																 				 bk[book_xb].writer,
																 				 bk[book_xb].publish,
																 				 bk[book_xb].t.year,
																 				 bk[book_xb].t.month,
																 				 bk[book_xb].t.day, 
																 				 bk[book_xb].site,
																 				 bk[book_xb].total,
																 				 bk[book_xb].total-bk[book_xb].jie
																 				 );
    if((bk[i].total-bk[i].jie)==0)
        printf("��ȫ��������\n");
    else
        {
           printf("\t���Խ���\n\t�Ƿ���ģ�(�ǣ�'y'����'n')��");
           scanf("%s",jy);
           if(strcmp(jy,"n")==0)
           {
                printf("\t����ȡ���������������....");
                getch();
                break;
           }
           else if(strcmp(jy,"y")==0)
           {
           		bk[book_xb].jie++;
                printf("\t���ĳɹ���\n");
                printf("\t%s ʣ�� %d ��\n",bk[i].name,bk[i].total-bk[i].jie);
                printf("\t�����������...\n");
                
                //getch();
                break;
           }
           else
           {
                printf("\t�����д����������������...");
				getch();
                break;
           }           
		}
	}
}
/*********����Ž���*******/
void jie_num()
{
	long i,k=0,book_xb,book_num;/*k��������Ƿ���ڸ���*/
	char jy[2];/*jy������ʾ�Ƿ�ȷ������*/
	printf("\t\t         ======================       \n");
    printf("\t\t                ����Ž���               \n");
    printf("\t\t         ======================       \n");
    while(1)
	{
    printf("\n\t\t���������:");
    scanf("%d",&book_num);
    for(i=0;i<book_num_now;i++)
        if(bk[i].num==book_num&&((bk[i].total-bk[i].jie)!=0))
		{
			book_xb=i;
			k++;
			break;
		}
        if(k==0)
		{
			printf("\t�����ڸ��飬������Ѿ����!����ȷ����ͼ������!\n\t\t�����������...");
			getch();
            break;
		}
	printf("\t���    ͼ������         ����             ������         ����ʱ��       λ��  ������  ʣ����\n");
    printf("\t%-7d %-16s %-16s %-12s   %4d��%2d��%2d�� %-7s %-7d %-4d\n",bk[book_xb].num,
																 				 bk[book_xb].name,
																 				 bk[book_xb].writer,
																 				 bk[book_xb].publish,
																 				 bk[book_xb].t.year,
																 				 bk[book_xb].t.month,
																 				 bk[book_xb].t.day, 
																 				 bk[book_xb].site,
																 				 bk[book_xb].total,
																 				 bk[book_xb].total-bk[book_xb].jie
																 				 );
    if((bk[i].total-bk[i].jie)==0)
        printf("��ȫ��������\n");
    else
    {
        printf("���Խ���\n\t�Ƿ���ģ�(�ǣ�'y'����'n')��");
        scanf("%s",jy);
        if(strcmp(jy,"n")==0)
        {
             printf("\t����ȡ���������������....");
             getch();
             break;
        }
        else if(strcmp(jy,"y")==0)
        {
		     bk[book_xb].jie++;
		     printf("\t���ĳɹ���\n");
		     printf("\t%s ʣ�� %d ��\n",bk[i].name,bk[i].total-bk[i].jie);
		     printf("\t�����������...\n");
		     getch();
		     break;
        }
        else
        {
             printf("\t�����д����������������...");
			 getch();
             break;
        }       
    }
	}
}
/*********����ͼ��********/
void jieyue()
{
    int x;
    do
    {
    system("cls");
	printf("\n\n\n\n");
    printf("\t\t|-------------------------------------------------------------|\n");
    printf("\t\t|         =====================        |\n");
    printf("\t\t|                ����ͼ��                 |\n");
    printf("\t\t|         =====================        |\n");
    printf("\t\t|                                         |\n");
    printf("\t\t|            1.����������                 |\n");
    printf("\t\t|            2.����Ž���                 |\n");
    printf("\t\t|            3.�鿴����ͼ��               |\n");
    printf("\t\t|            4.�������˵�                 |\n");
    printf("\t\t|-------------------------------------------------------------|\n");
    printf("\t\t����������ѡ��:");
    scanf("%d",&x);
    switch(x)
    {
        case 1:system("CLS");jie_name();getch();break;/*����������*/
        case 2:system("CLS");jie_num();getch();break;/*����Ž���*/
		case 3:system("cls");show_all_book();getch();break;/*�鿴����ͼ��*/
    }
    }while(x!=4);
}
/***************���������в��Ҳ��޸���Ϣ*************/
void xiugai_name()
{
	int i,book_xb,k=0;/*book_xb������¼�±�,k�����ж��Ƿ��ҵ�����*/
	char temp[20];/*temp[20]��������û�����Ĳ��ҵ�����*/
	while(1)
	{
		system("cls");
		printf("\n");
    	printf("\t\t|         =====================        |\n");
    	printf("\t\t|             �����������޸�              |\n");
    	printf("\t\t|         =====================        |\n");
		printf("\t\t��������׼���޸ĵ�ͼ�������,����'exit'�˳�:");
    	scanf("%s",temp);
		if(strcmp(temp,"exit")==0)
		break;
		else
		{
			for(i=0;i<book_num_now;i++)
		    if(strcmp(temp,bk[i].name)==0)
			{
				book_xb=i;
			    printf("\t�������ϢΪ:\n");
			    printf("\t���    ͼ������         ����             ������         ����ʱ��       λ��  ������  ������\n");
                printf("\t%-7d %-16s %-16s %-12s   %4d��%2d��%2d�� %-7s %-7d %-4d\n",bk[book_xb].num,
																 				 bk[book_xb].name,
																 				 bk[book_xb].writer,
																 				 bk[book_xb].publish,
																 				 bk[book_xb].t.year,
																 				 bk[book_xb].t.month,
																 				 bk[book_xb].t.day, 
																 				 bk[book_xb].site,
																 				 bk[book_xb].total,
																 				 bk[book_xb].total-bk[book_xb].jie
																 				 );
				k++;
				printf("\t\t��������������Ϣ:\n");
				printf("\t\t�����뱾��ı��:");
                scanf("%d",&bk[book_xb].num);
                printf("\t\t�����뱾�������:");
                scanf("%s",bk[book_xb].name);
                printf("\t\t�����뱾�������:");
        		scanf("%s",bk[i].writer);
                printf("\t\t�����뱾��ĳ�����:");
                scanf("%s",bk[book_xb].publish);
                printf("\t\t�����뱾��ĳ���ʱ��(�ö��Ÿ���):");
                scanf("%d,%d,%d",&bk[book_xb].t.year,&bk[book_xb].t.month,&bk[book_xb].t.day);
                printf("\t\t�����뱾������λ��(A123):");
				scanf("%s",bk[i].site); 

            }
			if(k==0)
			{
				printf("\t�����������������!�����������...");
				getch();
				continue;
			}
			printf("\t��ϲ!��Ϣ�޸ĳɹ�!���������...");getch();break;
		}
	}
}
/***************����Ž��в��Ҳ��޸���Ϣ*************/
void xiugai_num()
{
	int i,book_xb,k=0;/*book_xb������¼�±�,k�����ж��Ƿ��ҵ�����*/
	long temp;/*temp��������û�����Ĳ��ҵ����*/
	do
	{
		system("cls");
	printf("\n");
    printf("\t\t|         =====================        |\n");
    printf("\t\t|             ����Ž����޸�              |\n");
    printf("\t\t|         =====================        |\n");
	printf("\t\t��������׼���޸ĵ�ͼ���ͼ���,����'0'�˳�:");
    scanf("%ld",&temp);
	if(temp==0)	break;
	else
	{
		for(i=0;i<book_num_now;i++)
		    if(temp==bk[i].num)
			{
				book_xb=i;
			    printf("\t�������ϢΪ:\n");
			    printf("\t���    ͼ������         ����             ������         ����ʱ��       λ��  ������  ������\n");
                printf("\t%-7d %-16s %-16s %-12s   %4d��%2d��%2d�� %-7s %-7d %-4d\n",bk[book_xb].num,
																 				 bk[book_xb].name,
																 				 bk[book_xb].writer,
																 				 bk[book_xb].publish,
																 				 bk[book_xb].t.year,
																 				 bk[book_xb].t.month,
																 				 bk[book_xb].t.day, 
																 				 bk[book_xb].site,
																 				 bk[book_xb].total,
																 				 bk[book_xb].total-bk[book_xb].jie
																 				 );
				k++;
		
				printf("\t\t��������������Ϣ:\n");
				printf("\t\t�����뱾��ı��:");
                scanf("%d",&bk[book_xb].num);
                printf("\t\t�����뱾�������:");
                scanf("%s",bk[book_xb].name);
                printf("\t\t�����뱾�������:");
        		scanf("%s",bk[i].writer);
                printf("\t\t�����뱾��ĳ�����:");
                scanf("%s",bk[book_xb].publish);
                printf("\t\t�����뱾��ĳ���ʱ��(�ö��Ÿ���):");
                scanf("%d,%d,%d",&bk[book_xb].t.year,&bk[book_xb].t.month,&bk[book_xb].t.day);
                printf("\t\t�����뱾������λ��(A123):");
				scanf("%s",bk[i].site); 
            }
			if(k==0)
			{
				printf("\t�����������������!�����������...");
				getch();continue;
			}
			printf("\t��ϲ!��Ϣ�޸ĳɹ�!���������...");getch();break;
	}
	}while(temp!=0);
}
/**************ɾ������ͼ��***********/
void dele_all()
{
	char queren[4];
	printf("\t����������ɾ��������Ϣ���Ƿ����?'y'������'n'����...");
	scanf("%s",queren);
	if(strcmp(queren,"y")==0)
	{
		book_num_now=0;
		printf("\tɾ���ɹ�!\n");
	}
	else
	{
		printf("\t�������û�ȡ��!���������...");
		getch();
	}
}
/******************������ɾ��************/
void dele_name()
{
	int i,book_xb,k=0;/*book_xb�������ͼ���±꣬k�ñ���Ƿ��ҵ���*/
	char queren[4],temp_name[20];/*queren[2]�������'�Ƿ�'ȷ��ɾ��,temp_name[20]������Ų���ʱ�����ͼ������*/
	printf("\t������Ҫɾ�����������,����'0'�˳�:");
	scanf("%s",temp_name);
	if(strcmp(temp_name,"0")!=0)
	{
	for(i=0;i<book_num_now;i++)
	   if(strcmp(temp_name,bk[i].name)==0)
	   {
			book_xb=i;
			printf("\t�������ϢΪ:\n");
			printf("\t���    ͼ������         ����             ������         ����ʱ��       λ��  ������  ������\n");
                printf("\t%-7d %-16s %-16s %-12s   %4d��%2d��%2d�� %-7s %-7d %-4d\n",bk[book_xb].num,
																 				 bk[book_xb].name,
																 				 bk[book_xb].writer,
																 				 bk[book_xb].publish,
																 				 bk[book_xb].t.year,
																 				 bk[book_xb].t.month,
																 				 bk[book_xb].t.day, 
																 				 bk[book_xb].site,
																 				 bk[book_xb].total,
																 				 bk[book_xb].total-bk[book_xb].jie
																 				 );
			k++;
			printf("\t�Ƿ�Ҫɾ������?��'y',��'n'");
			scanf("%s",queren);
			if(strcmp(queren,"y")==0)
			{
				if(book_xb==book_num_now-1)
					book_num_now--;
				else
				{
					for(i=0;i<book_num_now;i++)
		        		bk[book_xb+i]=bk[book_xb+i+1];
					book_num_now--;
				}
		        printf("\tɾ���ɹ�!\n");
	        }
	        else
	        	printf("\t�������û�ȡ��!���������...");
	    }
	    if(k==0)
	        printf("\tδ�ҵ�����,���ʵ�Ժ��ٲ���!,�����������....");getch();
    }	
}
/***************����Ų��Ҳ�ɾ��***********/
void dele_num()
{
	int i,book_xb,k=0,temp_num;/*book_xb�������ͼ���±꣬k�ñ���Ƿ��ҵ���,temp_num������Ų���ʱ�����ͼ������*/
	char queren[4];/*queren[2]�������'�Ƿ�'ȷ��ɾ��*/
	while(1)
	{
	printf("\t������Ҫɾ����������,����'0'�˳�:");
	scanf("%d",&temp_num);
	if(temp_num==0)
		break;
	else
	{
	for(i=0;i<book_num_now;i++)
	   if(temp_num==bk[i].num)
	   {
			book_xb=i;
			printf("�������ϢΪ:\n");
			printf("\t���    ͼ������         ����             ������         ����ʱ��       λ��  ������  ������\n");
                printf("\t%-7d %-16s %-16s %-12s   %4d��%2d��%2d�� %-7s %-7d %-4d\n",bk[book_xb].num,
																 				 bk[book_xb].name,
																 				 bk[book_xb].writer,
																 				 bk[book_xb].publish,
																 				 bk[book_xb].t.year,
																 				 bk[book_xb].t.month,
																 				 bk[book_xb].t.day, 
																 				 bk[book_xb].site,
																 				 bk[book_xb].total,
																 				 bk[book_xb].total-bk[book_xb].jie
																 				 );

			k++;
			printf("\t�Ƿ�Ҫɾ������?��'y',��'n'");
			scanf("%s",queren);
			if(strcmp(queren,"y")==0)
			{
				if(book_xb==book_num_now-1)
					book_num_now--;
				else
				{
					for(i=0;i<book_num_now;i++)
		        		bk[book_xb+i]=bk[book_xb+i+1];
					book_num_now--;
				}
		        printf("\tɾ���ɹ�!\n");
	        }
	        else
	        	printf("\t�������û�ȡ��!���������...");
	           }
	        if(k==0)
	        	printf("\tδ�ҵ�����,���ʵ�Ժ��ٲ���!,�����������....");getch();break;
       	}	
	}
}
void dele()
{
	int x;	
	do
	{
		system("cls");
		printf("\t\t|-------------------------------------------------------------|\n");
    	printf("\t\t|         =====================        |\n");
    	printf("\t\t|              ɾ��ͼ����Ϣ               |\n");
    	printf("\t\t|         =====================        |\n");
    	printf("\t\t|                                         |\n");
    	printf("\t\t|            1.������ɾ��                 |\n");
    	printf("\t\t|            2.�����ɾ��                 |\n");
    	printf("\t\t|            3.ɾ������ͼ��               |\n");
    	printf("\t\t|            4.�������˵�                 |\n");
    	printf("\t\t|-------------------------------------------------------------|\n");
		printf("\t\t����������ѡ�");
		scanf("%d",&x);
		switch(x)
		{
			case 1:system("cls");dele_name();break;
			case 2:system("cls");dele_num();break;
			case 3:system("cls");dele_all();getch();break;
		}
	}while(x!=4);
}

/***************�޸�ͼ��**************/
void xiugai()
{
    int x;
    do
    {
		system("cls");
		printf("\n\n\n\n");
   	 	printf("\t\t|-------------------------------------------------------------|\n");
   	 	printf("\t\t|         =====================        |\n");
    	printf("\t\t|               �޸�ͼ����Ϣ              |\n");
    	printf("\t\t|         =====================        |\n");
    	printf("\t\t|                                         |\n");
    	printf("\t\t|            1.����������                 |\n");
    	printf("\t\t|            2.����Ų���                 |\n");
    	printf("\t\t|            3.ɾ��ͼ��                   |\n");
    	printf("\t\t|            4.�������˵�                 |\n");
    	printf("\t\t|-------------------------------------------------------------|\n");
    	printf("\t\t����������ѡ��:");
    	scanf("%d",&x);
    	switch(x)
    	{
      	  	case 1:system("CLS");xiugai_name();break;/*�������������޸���Ϣ*/
      	  	case 2:system("CLS");xiugai_num();break;/*����Ų��Ҳ��޸���Ϣ*/
			case 3:system("cls");dele();break;							
    	}
    }while(x!=4);
}

/**************������**************/             
int main()
{
	manage_xinxi();
    int x,x2,s;/*s�����ж�������֤�Ľ��*/
    do
    {
        system("cls"); x=mymainmenu();
        switch(x)
        {
            case 1:/************���ù���Աģʽ����***********/
            	   //manage_xinxi();
				   system("cls");
                   s=mimayanzheng();/*������֤*/
				   do
				   {				    
						if(s==1)
						{
							system("cls");
							x2=adm();
							switch(x2)
							{
								case 1:system("cls");xinxi();getch();break;		/*¼����Ϣ*/
								case 2:system("cls");show();break;				/*�鿴��Ϣ*/				           
								case 3:system("cls");xiugai();break;			/*�޸���Ϣ*/
								case 4:system("cls");xiugaimima();break;		/*�޸�����*/
								case 5:system("cls");xinxi_fromFILE();getch();break;	/*���ļ���¼����Ϣ*/
							}	
						}
						else
						{
							printf("\t������󣡰����������...");
							getch();
							break;
						}
				   }while(x2!=6);break;
            case 2:/*���ÿͻ�ģʽ����*/
				  do
				  {
					  system("cls");
					  x2=peo();
					  switch(x2)
					  {
					  case 1:system("cls");show();getch();break;/*�鿴ͼ����Ϣ*/
					  case 2:system("cls");jieyue();getch();break;/*����ͼ��*/
					  }        
				  }while(x2!=3);
        }
    }while(x!=3);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tллʹ�ã�\n\t\t\t");
	getch();
	return 0; 
}


