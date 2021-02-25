#include <stdio.h>
#include <stdlib.h>

float sub_e,a,b;
char o;
float m_exp(float sub_exp, char op);
char get_op();
float get_num();
float s_exp(void);

float get_num(){
	float num;
	scanf("%f",&num);
	return num;
}
char get_op(){
	char operator;
	scanf("%c", &operator);
	return operator;
}
float m_exp(float sub_exp, char op){
	float next_num;
	char next_operator;
	float next_sub_exp;
stp1:	if(op == '+' || op == '-'){
		ungetc(op, stdin);
		return sub_exp;
	}else if(op =='\n'){
		return sub_exp;
	}else if(op == '*' || op == '/'){
		next_num = get_num();
		next_operator = get_op();
		if(op == '*'){
			next_sub_exp = sub_exp * next_num;
			return m_exp(next_sub_exp, next_operator);
		}else if(op == '/'){
			next_sub_exp = sub_exp / next_num;
			return m_exp(next_sub_exp, next_operator);
		}
	}else if(op == ' '){
		char operator;
		operator = get_op();
		return m_exp(sub_exp, operator);
  }
  else if (op=='('|| op==')'){
		goto stp1;}
    else
    exit(EXIT_FAILURE);
	
}
float s_exp(void){
	float num;
	float next;
	char operator;
	num = m_exp(1,'*');
	operator = get_op();
	while(operator == '+' || operator == '-' || operator == '*' || operator == '/' || operator == ' ' || operator=='.'|| operator=='('|| operator==')'){
		next = m_exp(1,'*');
    if (operator=='('|| operator==')')
     continue;
		else if(operator == '+'){
			num = num + next;
			operator = get_op();
		}else if(operator == '-'){
			num = num - next;
			operator = get_op();
		}else if (operator == ' '){
			operator = get_op();
		}else if(operator != '-' || operator != '+' || operator != '\n'){
			exit(EXIT_FAILURE);
			break;
		}
	}
	return num;
}

int main(){
	int repeat = 1;
	char cont;
	while(repeat == 1){
		printf("\nPlease enter an arithmetic expression: ");
		sub_e = s_exp();
		printf("%f\n", sub_e);
		printf("\nEnter One more expression: ");
		cont = get_op();
		if(cont == 'N'){
			repeat++;
		}else if(cont == 'Y'){
			continue;
		}else{	
			exit(EXIT_FAILURE);
		}
	}
	return 0;
}