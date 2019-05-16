#include<stdio.h>
#include<string.h>
#include<stdlib.h>

 

struct student //定义结构体
{
	char   	num[20];//学号
	char   	name[9];//姓名
	char   	sex[3];//性别
	char    phone[15];//电话
	char    birth[20]; //生日
	char    szzy[20];//专业
	char    szlike[50]; //爱好
	
	student * pnext;
}student1;


struct student_cus //定义结构体
{
	char   	num[20];//学号
	char   	cusno[20];//消费编号
	char   	cusname[20];//消费名称
	float   fmony; //消费总额

	student_cus * pnext;
}student_cus1;

struct student_res//定义结构体
{
	char   	num[20];//学号
	char   	cusno[20];//课程编号
	char   	resname[20];//课程名称
	float   fvalue; //成绩

	student_res * pnext;
}student_res1;


struct student * lstallstudent =	NULL; //关于学生的链表
struct student_cus * lstallstudent_cus =	NULL;
struct student_res * lstallstudent_res =	NULL;



//菜单
int menu()
{
	int choice;
	system("cls");//清屏
	printf("                                 个人信息管理系统\n");
	printf("________________________________________________________________________________\n");
	printf("				1.创建新的学生的基本信息\n");
	printf("				2.查询所有学生基本信息\n");
	printf("________________________________________________________________________________");

	printf("				3.为某个学生创建新的消费信息\n");
	printf("				4.查询学生所有消费信息\n");
	printf("				5.查询某个学生所有消费信息\n");
	printf("				6.删除某个学生的消费信息\n");
	printf("				7.修改某个学生的消费信息\n");
	printf("________________________________________________________________________________\n");


	printf("				8.为某个学生创建新的成绩信息\n");
	printf("				9.查询学生所有成绩信息\n");
	printf("				10.查询某个学生成绩信息\n");
	printf("				11.删除某个学生成绩信息\n");
	printf("				12.修改某个学生成绩信息\n");
	printf("________________________________________________________________________________");

	printf("				0.退出系统\n");
	printf("       请选择：");

	scanf("%d",&choice);
	getchar();//消除缓存中的换行符
	return choice;
}



//创建新的是数据记录
void CreateSudent()
{
	system("cls");//清屏
	struct student *ptemp = new struct student;
	memset(ptemp,0,sizeof(struct student));//以ptemp为首地址，长度为sizeof（struct student）的内存段置为0
	if(lstallstudent ==NULL) //申请后添加到链表
	{
		lstallstudent = ptemp;
	}
	else
	{
		struct student *ptemp2 = lstallstudent;//建立新的学生信息 
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

	//初始化
	printf("请输入学号：");
	gets(ptemp->num);//输入学号

	////检查是否重复
	struct student *ptemp2 = lstallstudent;
	while(ptemp2 != NULL)
	{
		if(memcmp(ptemp2->num,ptemp->num,sizeof(ptemp->num)) == 0 && ptemp != ptemp2)//比较ptemp2和ptemp &&地址不同 
		{
			printf("学号重复，请重新输入学号：");
			gets(ptemp->num);
			ptemp2 = lstallstudent;
			continue;
		}
		ptemp2=	ptemp2->pnext;
	}


	printf("请输入姓名：");
	scanf("%s",ptemp->name);
	getchar();//消除回车

		
	char ch = '1';//先将ch初始化为1 
	printf("请选择性别（1、男   2、女）：");
	while(1)
	{
		ch=getchar();//从键盘输入选择 
		getchar();//消除回车
		if(ch=='1' ||  ch=='2')//检查输入是否有效 
			break;
		else
			printf("输入错误请重新输入：");
	}
	if(ch=='1' )
		strcpy(ptemp->sex,"男");
	else
		strcpy(ptemp->sex,"女");
	
	printf("请输入电话：");
	scanf("%s",ptemp->phone);//输入电话
	getchar();//消除回车


	printf("请输入生日：");
	scanf("%s",ptemp->birth);
	getchar();//消除回车


	printf("请输入专业：");
	scanf("%s",ptemp->szzy);
	getchar();//消除回车

	printf("请输入爱好：");
	scanf("%s",ptemp->szlike);
	getchar();//消除回车
			
	printf("创建成功！\n");
	system("pause");//任意键继续
	
}



void PintfStduent()
{
	system("cls");//清屏
	printf("________________________________________________________________________________");
	printf("学号	  姓名	  性别	电话     	生日	    专业	  爱好 \n\n");

	struct student *ptemp2 = lstallstudent;
	while(ptemp2 != NULL)
	{
		printf("%-9s%-9s%-6s%-15s%-13s%-13s%-6s \n",ptemp2->num,ptemp2->name, ptemp2->sex,ptemp2->phone,
			ptemp2->birth, ptemp2->szzy,ptemp2->szlike);
		ptemp2=	ptemp2->pnext;
	}
	
		
	printf("________________________________________________________________________________");
	system("pause");//任意键继续
}

void cus_create()
{
	system("cls");//清屏

	struct student_cus *ptemp = new struct student_cus;
	memset(ptemp,0,sizeof(struct student_cus));// 以ptemp为首地址，长度为sizeof（struct student_cus）的内存段置为0
	if(lstallstudent_cus ==NULL) //申请后添加到链表
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

	
	//初始化
	while (1)
	{
		printf("请输入学号：");
		gets(ptemp->num);//输入学号
		
		//检查是否存在
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
			printf("学号不存在");
		}
		else
		{
			break;
		}
	}


	
	
	printf("请输入消费编号：");
	scanf("%s",ptemp->cusno);
	getchar();//消除回车
	

	
	printf("请输入消费名称：");
	scanf("%s",ptemp->cusname);
	getchar();//消除回车
	
	
	printf("请输入消费总额：");
	scanf("%f",&ptemp->fmony);
	getchar();//消除回车	

	system("pause");//任意键继续

}

void cus_query()
{
	
	system("cls");//清屏
	printf("________________________________________________________________________________");
	printf("学号	  消费编号	  消费名称     	消费金额      \n\n");
	
	float fall = 0;
	struct student_cus *ptemp2 = lstallstudent_cus;
	while(ptemp2 != NULL)
	{
		printf("%-9s%-9s%-15s%.2f \n",ptemp2->num, ptemp2->cusno, ptemp2->cusname, ptemp2->fmony);
		fall += ptemp2->fmony;
		ptemp2=	ptemp2->pnext;
	}	
	
	printf("------------消费金额总金额:%.2f-------------      \n", fall);

	printf("________________________________________________________________________________");
	system("pause");//任意键继续
}

void cus_qeruyone()
{
	system("cls");//清屏
	char num[100] = {0};//设计数组来存放学号 
	
	printf("请输入学号：");
	gets(num);//输入学号
	
	//检查是否存在
	int numsfind = 0;//初始化为0 
	struct student_cus *ptemp2 = lstallstudent_cus;
	printf("学号	  消费编号	  消费名称     	消费金额      \n\n");
	float fall = 0;//记录消费总金额 
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
		printf("学号不存在");
	}
	else
	{
		printf("------------消费金额总金额:%.2f-------------      \n", fall);
	}
	
	system("pause");//任意键继续
}

void cus_delete()
{
	
	system("cls");//清屏
	char num[100] = {0};
	
	printf("请输入学号：");
	gets(num);//输入学号
	
	//检查是否存在
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
		printf("学号不存在");
	}
	else
	{
		printf("-----删除成功------\n");
	}
	
	system("pause");//任意键继续
}

void cus_uter()
{
	system("cls");//清屏
	char num[100] = {0};
	
	printf("请输入学号：");
	gets(num);//输入学号
	
	//检查是否存在
	int numsfind = 0;
	struct student_cus *ptemp2 = lstallstudent_cus;
	while(ptemp2 != NULL)
	{
		if(memcmp(ptemp2->num,num,sizeof(ptemp2->num)) == 0)
		{
			numsfind++;	
			printf("请输入需要修改的消费总额：");
			scanf("%f",&ptemp2->fmony);
			getchar();//消除回车
			break;
		
		}
		ptemp2=	ptemp2->pnext;		
		
	}
	if(numsfind == 0)
	{
		printf("学号不存在");
	}
	else
	{
		printf("------------修改成功-------------      \n");
	}
	
	system("pause");//任意键继续
}



void res_create()
{
	system("cls");//清屏
	
	struct student_res *ptemp = new struct student_res;
	memset(ptemp,0,sizeof(struct student_cus));
	if(lstallstudent_res ==NULL) //申请后添加到链表
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
	
	
	//初始化
	while (1)
	{
		printf("请输入学号：");
		gets(ptemp->num);//输入学号
		
		//检查是否存在
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
			printf("学号不存在");
		}
		else
		{
			break;
		}
	}
	
	
	
	
	printf("请输入课程编号：");
	scanf("%s",ptemp->cusno);
	getchar();//消除回车
	
	
	
	printf("请输入课程名称：");
	scanf("%s",ptemp->resname);
	getchar();//消除回车
	
	
	printf("请输入成绩：");
	scanf("%f",&ptemp->fvalue);
	getchar();//消除回车	
	
	system("pause");//任意键继续
}



void res_query()
{
	
	system("cls");//清屏
	printf("________________________________________________________________________________");
	printf("学号	  课程编号	  课程名称     	成绩      \n\n");
	
	float fall = 0;
	struct student_res *ptemp2 = lstallstudent_res;
	while(ptemp2 != NULL)
	{
		printf("%-9s%-9s%-15s%.2f \n",ptemp2->num, ptemp2->cusno, ptemp2->resname, ptemp2->fvalue);
		fall += ptemp2->fvalue;
		ptemp2=	ptemp2->pnext;
	}	
	
	printf("------------总成绩:%.2f-------------      \n", fall);
	
	printf("________________________________________________________________________________");
	system("pause");//任意键继续
}

void res_qeruyone()
{
	system("cls");//清屏
	char num[100] = {0};
	
	printf("请输入学号：");
	gets(num);//输入学号
	
	//检查是否存在
	int numsfind = 0;
	struct student_res *ptemp2 = lstallstudent_res;
	printf("学号	  课程编号	  课程名称     	成绩      \n\n");
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
		printf("学号不存在");
	}
	else
	{
		printf("------------总成绩:%.2f-------------      \n", fall);
	}
	
	system("pause");//任意键继续
}




void res_delete()
{
	
	system("cls");//清屏
	char num[100] = {0};
	
	printf("请输入学号：");
	gets(num);//输入学号
	
	//检查是否存在
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
		printf("学号不存在");
	}
	else
	{
		printf("-----删除成功------\n");
	}
	
	system("pause");//任意键继续
}

void res_uter()
{
	system("cls");//清屏
	char num[100] = {0};
	
	printf("请输入学号：");
	gets(num);//输入学号
	
	//检查是否存在
	int numsfind = 0;
	struct student_res *ptemp2 = lstallstudent_res;
	while(ptemp2 != NULL)
	{
		if(memcmp(ptemp2->num,num,sizeof(ptemp2->num)) == 0)
		{
			numsfind++;	
			printf("请输入需要修改的成绩：");
			scanf("%f",&ptemp2->fvalue);
			getchar();//消除回车
			break;
			
		}
		ptemp2=	ptemp2->pnext;		
		
	}
	if(numsfind == 0)
	{
		printf("学号不存在");
	}
	else
	{
		printf("------------修改成功-------------      \n");
	}
	
	system("pause");//任意键继续
}


int main()
{
	int sel = 0;
	while(1)
	{
		sel=menu();//获取选择
		switch(sel)
		{
		case 0:
			exit(0);
			break;
		case 1:
			CreateSudent(); //创建学生信息
			break;
		case 2:
			PintfStduent(); //输出显示学生信息
			break;

		case 3:
			cus_create(); //消费创建
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
			res_create();//成绩创建
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
