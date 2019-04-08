#include<stdio.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
Status ope_call(int *operation){
	printf("请输入意向操作对应数字：\n");
	printf("0.退出\n1.创建\n2.显示\n3.复制\n4.求和\n5.求差\n6.求积\n7.销毁\n8.清空\n9.修改\n10.求商\n11.乘方12.N阶导函数\n13.不定积分\n14.定积分\n15.最大公约式\n16.最小公倍式\n系数为0时将结束输入：");
	scanf("%d",*operation);
	switch(*operation){
		case 0:Exit();break;
		case 1:Creat();break;
		case 2:Print();break;
		case 3:Copy();break;
		case 4:Add();break;
		case 5:Minus();break;
		case 6:Multiply();break;
		case 7:Destroy();break;
		case 8:Clear();break;
		case 9:Modify();break;
		case 10:Division();break;
		case 11:Power();break;
		case 12:Differential();break;
		case 13:Indefinite_Integral();break;
		case 14:Definite_Integral();break;
		case 15:GC_Divisor();break;
		case 16:LC_Multiple();break; 
		default :
			printf("The input is invalid!");return(ERROR);
	}																		//end switch 																				//end switch
}																			//end Ope_Call
/****************************************************Appendix******************************************************************************/ 
