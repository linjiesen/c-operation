#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
 void master(); //定义管理人员管理系统 
 void initial_room(); //初始化80个房间信息 
 void data(); //更新删除系统
 void book();//订房
 void ruzhu();//入住
 void tuifang();//退房
 void search();//查询
int i=0,t=0;
 struct Room    //定义房间的结构体
{
	 int dank;
	 int price;
	 int num;
	 int state;
};
struct Guest   //定义顾客的结构体
{
	char name[20];
	char ID[20];
	int room_num;
	int day;
	int change;
	int prepaid;
};
void set_name(struct Guest *cs, char *n)
{
 strcpy(cs->name,n);//把从src地址开始且含有NULL结束符的字符串复制到以dest开始的地址空间
}
void set_ID(struct Guest *cs, char *p)
{
 strcpy(cs->ID,p);
}
void set_room_num(struct Guest *cs, int n)
{
 cs->room_num=n;
}
void set_day(struct Guest *cs, int d)
{
 cs->day=d;
}
void set_prepaid(struct Guest *cs, int p)
{
 cs->prepaid=p;
}
char *get_name(struct Guest *cs)
{
 return cs->name;
}
char *get_ID(struct Guest *cs)
{
 return cs->ID;
}
int  get_room_num(struct Guest *cs)
{
 return cs->room_num;
}
int  get_day(struct Guest *cs)
{
 return cs->day;
}
int  get_prepaid(struct Guest *cs)
{
 return cs->prepaid;
}
struct Room room[80];
struct Guest *guest[80];
int main(void)
{ initial_room();
	int a,b,d;


	cout<<"               ********************************           "<<endl;
    cout<<"               欢迎来到宾馆管理系统!!!           			"<<endl;
	cout<<"               ********************************           "<<endl;
	cout<<"    进入系统请选择1，退出请选择2!"<<endl;
    cin>>a;
	if(a==1)
cout<<"欢迎进入系统管理系统!!!"<<endl;
while(d=1)
{	cout<<"进入信息管理选择项目：1.登记并打印客户信息;2.查询信息;3.更新（增加删除）;4.退房结算;5.管理!"<<endl;
cout<<"请做出相应的选择，谢谢!"	;
cin>>b;
if((b>5)||(b<1))
cout<<"输入有误，请重试！"<<endl;
else
{switch(b)
{
case 1: book();  break;
case 2: search(); break;
case 3: data(); break;
case 4: tuifang(); break;
case 5: master();break;}
 cout<<"继续使用本系统请按1,退出请按2"<<endl;
  fflush(stdin);
  cin>>d;
  
 }
	cout<<endl;
}
return 0;}
void GGuest(struct Guest *cs)
{
 cout<<"请您输入顾客的姓名"<<endl;
 cin>>cs->name;
 cout<<"请您输入顾客的身份证号码"<<endl;
 cin>>cs->ID;
 cs->prepaid = cs->change = cs->day = 0;
}
void book()
{ int room_,day;
guest[i] = (struct Guest*)malloc(sizeof(struct Guest));//分配一个 大小为结构体stu的大小的空间
GGuest(guest[i]);
cout<<"请选择您所需要的房间的类型："<<endl;
cout<<"1.单人间 60/天 2.双人间 70/天 3.标准间 80/天 4.总统套房 500/天"<<endl;
cin>>room_;
cout<<"请输入住宿的天数："<<endl;
cin>>day;
set_day(guest[i],day);
switch(room_)
{
	int n;
case 1: cout<<"住房的总费用："<<day*60;
	for(n=0;n<20;n++)
	{
		if(room[n].state==0)
		{
			cout<<"住宿的房间为"<<room[n].num;
			room[n].state=2;
			set_room_num(guest[i],room[n].num);
			break;
		}
	}
	break;
case 2: cout<<"住房的总费用："<<day*70;
	for(n=20;n<40;n++)
	{
		if(room[n].state==0)
		{
			cout<<"住宿的房间为"<<room[n].num;
			room[n].state=2;
			set_room_num(guest[i],room[n].num);
			break;
		}
	}
	break;
case 3: cout<<"住房的总费用："<<day*80;
	for(n=40;n<60;n++)
	{
		if(room[n].state==0)
		{
			cout<<"住宿的房间为"<<room[n].num;
			room[n].state=2;
			set_room_num(guest[i],room[n].num);
			break;
		}
	}
	break;
case 4: cout<<"住房的总费用："<<day*60;
	for(n=60;n<80;n++)
	{
		if(room[n].state==0)
		{
			cout<<"住宿的房间为"<<room[n].num;
			room[n].state=2;
			set_room_num(guest[i],room[n].num);
			break;
		}
	}
	break;
}
i++;t++;
}
void tuifang()  //退房
{
	char name2[10],id2[19];
 int standard,j,room_num,day1,day2,day;
cout<<"请输入要退房的顾客姓名和身份证号码:"<<endl;
cin>>name2>>id2;
cout<<"请输入该顾客实住天数:"<<endl; 
 cin>>day2; 
 for(j=0;j<i;j++)
 {
  if((strcmp(get_name(guest[j]),name2)==0)&&(strcmp(get_ID(guest[j]),id2)==0))
  {
   char account;
   room_num=get_room_num(guest[j]);
   standard=room_num/100; 
   day1=get_day(guest[j]);
   day=day1-day2;
switch(standard)
{
case 1:
 cout<<"顾客的房间号是"<<room_num<<"为单人间,每天60元"<<endl;
cout<<"该顾客预付了房费"<<get_prepaid(guest[j])<<"元"<<"实际消费"<<day2*60<<"元整!"<<endl;
 if(day>0)
    cout<<"请退给该顾客"<<day*60<<"元整!"<<endl; 
    if(day<0)
     cout<<"请补收该顾客住房费"<<-day*60<<"元整!"<<endl;;
    break; 
case 2:
	 cout<<"顾客的房间号是"<<room_num<<"为双人间,每天70元"<<endl;
cout<<"该顾客预付了房费"<<get_prepaid(guest[j])<<"元"<<"实际消费"<<day2*60<<"元整!"<<endl;
   if(day>0)
    cout<<"请退给该顾客"<<day*70<<"元整!"<<endl; 
    if(day<0)
     cout<<"请补收该顾客住房费"<<-day*70<<"元整!"<<endl;;
    break; 
case 3:
	 cout<<"顾客的房间号是"<<room_num<<"为标准间,每天80元"<<endl;
cout<<"该顾客预付了房费"<<get_prepaid(guest[j])<<"元"<<"实际消费"<<day2*60<<"元整!"<<endl;
 if(day>0)
    cout<<"请退给该顾客"<<day*80<<"元整!"<<endl; 
    if(day<0)
     cout<<"请补收该顾客住房费"<<-day*80<<"元整!"<<endl;
    break; 
case 4:
	 cout<<"顾客的房间号是"<<room_num<<"为总统套房,每天500元"<<endl;
cout<<"该顾客预付了房费"<<get_prepaid(guest[j])<<"元"<<"实际消费"<<day2*60<<"元整!"<<endl;
    
    if(day>0)
    cout<<"请退给该顾客"<<day*500<<"元整!"<<endl; 
    if(day<0)
     cout<<"请补收该顾客住房费"<<-day*500<<"元整!"<<endl;;
    break; 
}

  cout<<"退房核算清楚,请按1: "<<endl;
   fflush(stdin);//用来清空输入缓存，以便不影响后面输入的东西
   cin>>&account;

   if(account=='1')
   {
    int k;
    for(k=0;k<80;k++)
    {
     if(room[k].num==get_room_num(guest[j])) 
      room[k].state=0;
    }
    i--;
    for(;j<i;j++)
    {
    guest[j]=guest[j+1];
    }
    free(guest[i]);
    cout<<"欢迎下次光临！"<<endl;
   }
  }
 } 
};
void search()   //查找信息
{
int a;
cout<<"请选择查询的项目：1.房间信息 2.顾客信息查询 "<<endl;
fflush(stdin);//用来清空输入缓存，以便不影响后面输入的东西
cin>>a;
if(1==a)
{
	int j,k=0;
cout<<"下列房间没人住："<<endl;
  for(j=0;j<80;j++)
  {if(room[j].state==0)
   {
    if(k%10==0)
       cout<<room[j].num;//这里出现了一点问题 自己无法调试
		printf("%d\t",room[j].num);//为什么在这里cout不能循环输出？？？？
    k++;
   }
}

cout<<"下列房间已经有人住："<<endl;
 for(j=0;j<80;j++)
  {
   if(room[j].state==2)
   {
    if(k%10==0)
   cout<<room[j].num;
    k++;
   }
  }
 }
else if(a==2)
{int j,m;
  fflush(stdin);
char name3[10];
cout<<"请选择：1.姓名查找 2.身份证号码查找"<<endl;
  fflush(stdin);
cin>>m;
if(1==m)
{ cout<<"输入客户的姓名"<<endl;
cin>>name3;
for(j=0;j<i;j++)
   {
    if(strcmp(get_name(guest[j]),name3)==0)
    {
     cout<<name3<<"的住房信息如下:"<<endl;
     cout<<"房间号为:"<<get_room_num(guest[j])<<endl;
     cout<<"预付房费为:"<<get_prepaid(guest[j])<<endl;
    }
   }
  }
 if(m==2)
{
	char id3[20];
	int j;
	cout<<"请输入客户的身份证号码："<<endl;
	cin>>id3;
 for(j=0;j<i;j++)
   {
    if(strcmp(get_ID(guest[j]),id3)==0)
    {
     cout<<get_name(guest[j])<<"的住房信息如下:"<<endl;
     cout<<"房间号为:"<<get_room_num(guest[j])<<endl;
    cout<<"预付房费为:"<<get_prepaid(guest[j])<<endl;
    }
   }
  }
 }
};
void data()
{ char name4[20],id4[20];
  int j,o,p;
cout<<"请选择1.修改信息 2.删除信息"	;
cin>>o;
if(o==1) 
{cout<<"请输入您的姓名和身份证号码："<<endl;
cin>>name4[20]>>id4[20];
for(j=0;j<i;j++)
 {
  if((strcmp(get_name(guest[j]),name4)==0)&&(strcmp(get_ID(guest[j]),id4)==0))
  { cout<<"请核实您的信息！"<<endl;
  cout<<"请输入您想要修改的内容！"<<endl;
  cout<<"姓名"<<"身份证号码"<<endl;
  cin>>name4[20]>>id4[20];
  cout<<"您已经修改成功";}}}
else
{cout<<"请输入您的姓名和身份证号码："<<endl;

 cin>>name4[20]>>id4[20];
 for(j=0;j<i;j++)
	{ if((strcmp(get_name(guest[j]),name4)==0)&&(strcmp(get_ID(guest[j]),id4)==0))
  { cout<<"请核实您的信息！"<<endl;
  cout<<"请确认您是否要删除！！"<<endl;
   cin>>p;
   if(1==p)
   {cout<<"您已经删除成功";}}}}}


void initial_room() //对80个房间进行初始化,分为4个类型，查询网上资料
{
 int j,k=101;
 for(j=0;j<20;j++)
 {
  room[j].num=k++;
  room[j].dank=1;
  room[j].price=60;
  room[j].state=0;
 }
 k=201;
 for(j=20;j<40;j++)
 {
  room[j].num=k++;
  room[j].dank=2;
  room[j].price=70;
  room[j].state=0;
 }
 k=301;
 for(j=40;j<60;j++)
 {
  room[j].num=k++;
  room[j].dank=3;
  room[j].price=80;
  room[j].state=0;
 }
 k=401;
 for(j=60;j<80;j++)
 {
  room[j].num=k++;
  room[j].dank=4;
  room[j].price=500;
  room[j].state=0;
 }
}

void master()
{int password,u,zonge;
	cout<<"请输入管理密码！！！：";
cin>>password;
if(password==520)
{	
	cout<<"今天来住宿的人数为："<<t<<endl; 
}

else cout<<"非法操作！！！！！！！！！！！！！！！！！！！！！！！！！！";}
