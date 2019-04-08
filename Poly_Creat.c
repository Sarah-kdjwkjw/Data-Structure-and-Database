#include<stdio.h>
#include<string.h>
#include"��۵��ú���.c"
#define max_poly 100

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
/*************************************************************************************************************************/
Status read_coefficient(int *coefficient,char number){
if(number!='.')
		*coefficient=number-'0';
	else
		*coefficient=(int)number;
	return OK; 
}
Status read_exponent(int *exponent,char number){
	if(number!='.')
		*exponent=number-'0';
	else
		*exponent=(int)number;
	return OK;
}																			//ָ�����ַ���->���� 
/*************************************************************************************************************************/
Status monomial_store_to_polymial(char *monomial,char sign){
	int coefficient[10],exponent[10];										//�ֱ�洢ϵ����ָ�������顣ע��С���� 
	int *flag_float;														//����һ�����������ж��Ƿ�С���㣬�����λ�� 
	int i,j; 
	while(*monomial!='+'&&*monomial!='-'&&*monomial!='\n'){					//��δ��һ������ʽ�Ľ���λ�� 
		i=j=0;																//����ϵ����ָ��֮ǰ��Ӧ���������п� 
		if((*(monomial-1)=='+'||*(monomial-1)=='-')&&('9'>=*monomial>='0'||*monomial=='.')){			//ϵ���ж� 
			read_coefficient(coefficient+(i++),*monomial);
			if('z'>=*monomial>='a'||'Z'>=*monomial>='A')											//�Ա����ж� 
				if(*monomial=='^')																	//'^'�ж� 
					monomial++;
					if('9'>=*monomial>='0')															//ָ���ж� 
						read_exponent(exponent+(j++),*(monomial));
					else
						if(*monomial=='+'||*monomial=='-')
							exponent[0]=1;															//����ȱʡָ�� 
						else
							return FALSE;
		}																	//end if
		else
			return FALSE;
		monomial++;
	}																		//end while	
	return OK;
}																			//end function 
/*********************************************************************************************************************/
	Status Poly_Creat(){
		int i;
		int x_th;															//�Զ���ʽ�����x_thλ���� 
		char poly[max_poly];												//poly�����ַ�����ʽ�������ʽ 
		char monomial[20];
	//	int start,end;
		printf("����������洢�ռ䣬����1��%d :\n",n);
		scanf("%d",x_th);
		printf("���������ʽ:\n");
		gets(poly);
		if(poly==NULL){
			printf("�������\n"); 
			return ERROR;
		}
		for(i=0;poly[i]!='\n';i++){											 
			switch(poly[i]){
				case '+':monomial_store_to_polymial(&poly[i+1],'+');break;
				case '-':monomial_store_to_polymial(&poly[i+1],'-');break;
				case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':monomial_store_to_polymial(&(poly[i+1]),'+');break;
				case '0':break;
				default:return FALSE;
			}			
		}																	//�ַ��Ͷ���ʽ->����ϵ����ָ�� 	
	}																		//end Poly_Creat
/**************************************************** Appendix**************************************************************** 
