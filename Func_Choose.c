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
	printf("���������������Ӧ���֣�\n");
	printf("0.�˳�\n1.����\n2.��ʾ\n3.����\n4.���\n5.���\n6.���\n7.����\n8.���\n9.�޸�\n10.����\n11.�˷�12.N�׵�����\n13.��������\n14.������\n15.���Լʽ\n16.��С����ʽ\nϵ��Ϊ0ʱ���������룺");
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
