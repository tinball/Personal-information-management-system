#include<stdio.h>
#include<string.h>
#include<stdlib.h>

 

struct student //����ṹ��
{
	char   	num[20];//ѧ��
	char   	name[9];//����
	char   	sex[3];//�Ա�
	char    phone[15];//�绰
	char    birth[20]; //����
	char    szzy[20];//רҵ
	char    szlike[50]; //����
	
	student * pnext;
}student1;


struct student_cus //����ṹ��
{
	char   	num[20];//ѧ��
	char   	cusno[20];//���ѱ��
	char   	cusname[20];//��������
	float   fmony; //�����ܶ�

	student_cus * pnext;
}student_cus1;

struct student_res//����ṹ��
{
	char   	num[20];//ѧ��
	char   	cusno[20];//�γ̱��
	char   	resname[20];//�γ�����
	float   fvalue; //�ɼ�

	student_res * pnext;
}student_res1;


struct student * lstallstudent =	NULL; //����ѧ��������
struct student_cus * lstallstudent_cus =	NULL;
struct student_res * lstallstudent_res =	NULL;



//�˵�
int menu()
{
	int choice;
	system("cls");//����
	printf("                                 ������Ϣ����ϵͳ\n");
	printf("________________________________________________________________________________\n");
	printf("				1.�����µ�ѧ���Ļ�����Ϣ\n");
	printf("				2.��ѯ����ѧ��������Ϣ\n");
	printf("________________________________________________________________________________");

	printf("				3.Ϊĳ��ѧ�������µ�������Ϣ\n");
	printf("				4.��ѯѧ������������Ϣ\n");
	printf("				5.��ѯĳ��ѧ������������Ϣ\n");
	printf("				6.ɾ��ĳ��ѧ����������Ϣ\n");
	printf("				7.�޸�ĳ��ѧ����������Ϣ\n");
	printf("________________________________________________________________________________\n");


	printf("				8.Ϊĳ��ѧ�������µĳɼ���Ϣ\n");
	printf("				9.��ѯѧ�����гɼ���Ϣ\n");
	printf("				10.��ѯĳ��ѧ���ɼ���Ϣ\n");
	printf("				11.ɾ��ĳ��ѧ���ɼ���Ϣ\n");
	printf("				12.�޸�ĳ��ѧ���ɼ���Ϣ\n");
	printf("________________________________________________________________________________");

	printf("				0.�˳�ϵͳ\n");
	printf("       ��ѡ��");

	scanf("%d",&choice);
	getchar();//���������еĻ��з�
	return choice;
}



//�����µ������ݼ�¼
void CreateSudent()
{
	system("cls");//����
	struct student *ptemp = new struct student;
	memset(ptemp,0,sizeof(struct student));//��ptempΪ�׵�ַ������Ϊsizeof��struct student�����ڴ����Ϊ0
	if(lstallstudent ==NULL) //�������ӵ�����
	{
		lstallstudent = ptemp;
	}
	else
	{
		struct student *ptemp2 = lstallstudent;//�����µ�ѧ����Ϣ 
		while(1)
		{
			if(ptemp2->pnext== NULL)
			{
				ptemp2->pnext = ptemp;
				break;
			}
			else
			{
				ptemp2 = ptemp2->pnext;
			}
		}
	}

	//��ʼ��
	printf("������ѧ�ţ�");
	gets(ptemp->num);//����ѧ��

	////����Ƿ��ظ�
	struct student *ptemp2 = lstallstudent;
	while(ptemp2 != NULL)
	{
		if(memcmp(ptemp2->num,ptemp->num,sizeof(ptemp->num)) == 0 && ptemp != ptemp2)//�Ƚ�ptemp2��ptemp &&��ַ��ͬ 
		{
			printf("ѧ���ظ�������������ѧ�ţ�");
			gets(ptemp->num);
			ptemp2 = lstallstudent;
			continue;
		}
		ptemp2=	ptemp2->pnext;
	}


	printf("������������");
	scanf("%s",ptemp->name);
	getchar();//�����س�

		
	char ch = '1';//�Ƚ�ch��ʼ��Ϊ1 
	printf("��ѡ���Ա�1����   2��Ů����");
	while(1)
	{
		ch=getchar();//�Ӽ�������ѡ�� 
		getchar();//�����س�
		if(ch=='1' ||  ch=='2')//��������Ƿ���Ч 
			break;
		else
			printf("����������������룺");
	}
	if(ch=='1' )
		strcpy(ptemp->sex,"��");
	else
		strcpy(ptemp->sex,"Ů");
	
	printf("������绰��");
	scanf("%s",ptemp->phone);//����绰
	getchar();//�����س�


	printf("���������գ�");
	scanf("%s",ptemp->birth);
	getchar();//�����س�


	printf("������רҵ��");
	scanf("%s",ptemp->szzy);
	getchar();//�����س�

	printf("�����밮�ã�");
	scanf("%s",ptemp->szlike);
	getchar();//�����س�
			
	printf("�����ɹ���\n");
	system("pause");//���������
	
}



void PintfStduent()
{
	system("cls");//����
	printf("________________________________________________________________________________");
	printf("ѧ��	  ����	  �Ա�	�绰     	����	    רҵ	  ���� \n\n");

	struct student *ptemp2 = lstallstudent;
	while(ptemp2 != NULL)
	{
		printf("%-9s%-9s%-6s%-15s%-13s%-13s%-6s \n",ptemp2->num,ptemp2->name, ptemp2->sex,ptemp2->phone,
			ptemp2->birth, ptemp2->szzy,ptemp2->szlike);
		ptemp2=	ptemp2->pnext;
	}
	
		
	printf("________________________________________________________________________________");
	system("pause");//���������
}

void cus_create()
{
	system("cls");//����

	struct student_cus *ptemp = new struct student_cus;
	memset(ptemp,0,sizeof(struct student_cus));// ��ptempΪ�׵�ַ������Ϊsizeof��struct student_cus�����ڴ����Ϊ0
	if(lstallstudent_cus ==NULL) //�������ӵ�����
	{
		lstallstudent_cus = ptemp;
	}
	else
	{
		struct student_cus *ptemp2 = lstallstudent_cus;
		while(1)
		{
			if(ptemp2->pnext== NULL)
			{
				ptemp2->pnext = ptemp;
				break;
			}
			else
			{
				ptemp2 = ptemp2->pnext;
			}
		}
	}

	
	//��ʼ��
	while (1)
	{
		printf("������ѧ�ţ�");
		gets(ptemp->num);//����ѧ��
		
		//����Ƿ����
		struct student *ptemp2 = lstallstudent;
		while(ptemp2 != NULL)
		{
			if(memcmp(ptemp2->num,ptemp->num,sizeof(ptemp->num)) == 0)
			{
				break;
			}
			ptemp2=	ptemp2->pnext;		
			
		}
		if(ptemp2 == NULL)
		{
			printf("ѧ�Ų�����");
		}
		else
		{
			break;
		}
	}


	
	
	printf("���������ѱ�ţ�");
	scanf("%s",ptemp->cusno);
	getchar();//�����س�
	

	
	printf("�������������ƣ�");
	scanf("%s",ptemp->cusname);
	getchar();//�����س�
	
	
	printf("�����������ܶ");
	scanf("%f",&ptemp->fmony);
	getchar();//�����س�	

	system("pause");//���������

}

void cus_query()
{
	
	system("cls");//����
	printf("________________________________________________________________________________");
	printf("ѧ��	  ���ѱ��	  ��������     	���ѽ��      \n\n");
	
	float fall = 0;
	struct student_cus *ptemp2 = lstallstudent_cus;
	while(ptemp2 != NULL)
	{
		printf("%-9s%-9s%-15s%.2f \n",ptemp2->num, ptemp2->cusno, ptemp2->cusname, ptemp2->fmony);
		fall += ptemp2->fmony;
		ptemp2=	ptemp2->pnext;
	}	
	
	printf("------------���ѽ���ܽ��:%.2f-------------      \n", fall);

	printf("________________________________________________________________________________");
	system("pause");//���������
}

void cus_qeruyone()
{
	system("cls");//����
	char num[100] = {0};//������������ѧ�� 
	
	printf("������ѧ�ţ�");
	gets(num);//����ѧ��
	
	//����Ƿ����
	int numsfind = 0;//��ʼ��Ϊ0 
	struct student_cus *ptemp2 = lstallstudent_cus;
	printf("ѧ��	  ���ѱ��	  ��������     	���ѽ��      \n\n");
	float fall = 0;//��¼�����ܽ�� 
	while(ptemp2 != NULL)
	{
		if(memcmp(ptemp2->num,num,sizeof(ptemp2->num)) == 0)
		{
			numsfind++;	
			
			printf("%-9s%-9s%-15s%.2f \n",ptemp2->num, ptemp2->cusno, ptemp2->cusname, ptemp2->fmony);
			fall += ptemp2->fmony;
			ptemp2=	ptemp2->pnext;
		}
		ptemp2=	ptemp2->pnext;		
		
	}
	if(numsfind == 0)
	{
		printf("ѧ�Ų�����");
	}
	else
	{
		printf("------------���ѽ���ܽ��:%.2f-------------      \n", fall);
	}
	
	system("pause");//���������
}

void cus_delete()
{
	
	system("cls");//����
	char num[100] = {0};
	
	printf("������ѧ�ţ�");
	gets(num);//����ѧ��
	
	//����Ƿ����
	int numsfind = 0;
	struct student_cus *ptemp2 = lstallstudent_cus;
	struct student_cus *plast = NULL;
	while(ptemp2 != NULL)
	{
		if(memcmp(ptemp2->num,num,sizeof(ptemp2->num)) == 0)
		{
			numsfind++;
			if(plast == NULL)
			{
				lstallstudent_cus  = ptemp2->pnext;
				delete ptemp2;
			}
			else
			{
				plast->pnext = ptemp2->pnext;
				delete ptemp2;
			}
			break;
		}
		plast = ptemp2;
		ptemp2=	ptemp2->pnext;		
		
	}
	if(numsfind == 0)
	{
		printf("ѧ�Ų�����");
	}
	else
	{
		printf("-----ɾ���ɹ�------\n");
	}
	
	system("pause");//���������
}

void cus_uter()
{
	system("cls");//����
	char num[100] = {0};
	
	printf("������ѧ�ţ�");
	gets(num);//����ѧ��
	
	//����Ƿ����
	int numsfind = 0;
	struct student_cus *ptemp2 = lstallstudent_cus;
	while(ptemp2 != NULL)
	{
		if(memcmp(ptemp2->num,num,sizeof(ptemp2->num)) == 0)
		{
			numsfind++;	
			printf("��������Ҫ�޸ĵ������ܶ");
			scanf("%f",&ptemp2->fmony);
			getchar();//�����س�
			break;
		
		}
		ptemp2=	ptemp2->pnext;		
		
	}
	if(numsfind == 0)
	{
		printf("ѧ�Ų�����");
	}
	else
	{
		printf("------------�޸ĳɹ�-------------      \n");
	}
	
	system("pause");//���������
}



void res_create()
{
	system("cls");//����
	
	struct student_res *ptemp = new struct student_res;
	memset(ptemp,0,sizeof(struct student_cus));
	if(lstallstudent_res ==NULL) //�������ӵ�����
	{
		lstallstudent_res = ptemp;
	}
	else
	{
		struct student_res *ptemp2 = lstallstudent_res;
		while(1)
		{
			if(ptemp2->pnext== NULL)
			{
				ptemp2->pnext = ptemp;
				break;
			}
			else
			{
				ptemp2 = ptemp2->pnext;
			}
		}
	}
	
	
	//��ʼ��
	while (1)
	{
		printf("������ѧ�ţ�");
		gets(ptemp->num);//����ѧ��
		
		//����Ƿ����
		struct student *ptemp2 = lstallstudent;
		while(ptemp2 != NULL)
		{
			if(memcmp(ptemp2->num,ptemp->num,sizeof(ptemp->num)) == 0)
			{
				break;
			}
			ptemp2=	ptemp2->pnext;		
			
		}
		if(ptemp2 == NULL)
		{
			printf("ѧ�Ų�����");
		}
		else
		{
			break;
		}
	}
	
	
	
	
	printf("������γ̱�ţ�");
	scanf("%s",ptemp->cusno);
	getchar();//�����س�
	
	
	
	printf("������γ����ƣ�");
	scanf("%s",ptemp->resname);
	getchar();//�����س�
	
	
	printf("������ɼ���");
	scanf("%f",&ptemp->fvalue);
	getchar();//�����س�	
	
	system("pause");//���������
}



void res_query()
{
	
	system("cls");//����
	printf("________________________________________________________________________________");
	printf("ѧ��	  �γ̱��	  �γ�����     	�ɼ�      \n\n");
	
	float fall = 0;
	struct student_res *ptemp2 = lstallstudent_res;
	while(ptemp2 != NULL)
	{
		printf("%-9s%-9s%-15s%.2f \n",ptemp2->num, ptemp2->cusno, ptemp2->resname, ptemp2->fvalue);
		fall += ptemp2->fvalue;
		ptemp2=	ptemp2->pnext;
	}	
	
	printf("------------�ܳɼ�:%.2f-------------      \n", fall);
	
	printf("________________________________________________________________________________");
	system("pause");//���������
}

void res_qeruyone()
{
	system("cls");//����
	char num[100] = {0};
	
	printf("������ѧ�ţ�");
	gets(num);//����ѧ��
	
	//����Ƿ����
	int numsfind = 0;
	struct student_res *ptemp2 = lstallstudent_res;
	printf("ѧ��	  �γ̱��	  �γ�����     	�ɼ�      \n\n");
	float fall = 0;
	while(ptemp2 != NULL)
	{
		if(memcmp(ptemp2->num,num,sizeof(ptemp2->num)) == 0)
		{
			numsfind++;	
			
			printf("%-9s%-9s%-15s%.2f \n",ptemp2->num, ptemp2->cusno, ptemp2->resname, ptemp2->fvalue);
			fall += ptemp2->fvalue;
			ptemp2=	ptemp2->pnext;
		}
		ptemp2=	ptemp2->pnext;		
		
	}
	if(numsfind == 0)
	{
		printf("ѧ�Ų�����");
	}
	else
	{
		printf("------------�ܳɼ�:%.2f-------------      \n", fall);
	}
	
	system("pause");//���������
}




void res_delete()
{
	
	system("cls");//����
	char num[100] = {0};
	
	printf("������ѧ�ţ�");
	gets(num);//����ѧ��
	
	//����Ƿ����
	int numsfind = 0;
	struct student_res *ptemp2 = lstallstudent_res;
	struct student_res *plast = NULL;
	while(ptemp2 != NULL)
	{
		if(memcmp(ptemp2->num,num,sizeof(ptemp2->num)) == 0)
		{
			numsfind++;
			if(plast == NULL)
			{
				lstallstudent_res  = ptemp2->pnext;
				delete ptemp2;
			}
			else
			{
				plast->pnext = ptemp2->pnext;
				delete ptemp2;
			}
			break;
		}
		plast = ptemp2;
		ptemp2=	ptemp2->pnext;		
		
	}
	if(numsfind == 0)
	{
		printf("ѧ�Ų�����");
	}
	else
	{
		printf("-----ɾ���ɹ�------\n");
	}
	
	system("pause");//���������
}

void res_uter()
{
	system("cls");//����
	char num[100] = {0};
	
	printf("������ѧ�ţ�");
	gets(num);//����ѧ��
	
	//����Ƿ����
	int numsfind = 0;
	struct student_res *ptemp2 = lstallstudent_res;
	while(ptemp2 != NULL)
	{
		if(memcmp(ptemp2->num,num,sizeof(ptemp2->num)) == 0)
		{
			numsfind++;	
			printf("��������Ҫ�޸ĵĳɼ���");
			scanf("%f",&ptemp2->fvalue);
			getchar();//�����س�
			break;
			
		}
		ptemp2=	ptemp2->pnext;		
		
	}
	if(numsfind == 0)
	{
		printf("ѧ�Ų�����");
	}
	else
	{
		printf("------------�޸ĳɹ�-------------      \n");
	}
	
	system("pause");//���������
}


int main()
{
	int sel = 0;
	while(1)
	{
		sel=menu();//��ȡѡ��
		switch(sel)
		{
		case 0:
			exit(0);
			break;
		case 1:
			CreateSudent(); //����ѧ����Ϣ
			break;
		case 2:
			PintfStduent(); //�����ʾѧ����Ϣ
			break;

		case 3:
			cus_create(); //���Ѵ���
			break;
		case 4:
			cus_query();
			break;
		case 5:
			cus_qeruyone();
			break;
		case 6:
			cus_delete();
			break;
		case 7:
			cus_uter(); 
			break;

		case 8:
			res_create();//�ɼ�����
			break;
		case 9:
			res_query();
			break;
		case 10:
			res_qeruyone();
			break;
		case 11:
			res_delete();
			break;
		case 12:
			res_uter();
			break;
		}
	}
	return 0;
}
