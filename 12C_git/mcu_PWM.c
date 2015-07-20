 #include	<PWM.h>
//unsigned char PWM[4] = {0x3F, 0x7F, 0xBF, 0xFF};//�ٶȷ�Ϊ�ĸ��ȼ�
//unsigned int speed[4];
//P1^3,1^4ΪPWM�����


void PWMInit()
{
	CCON=0;					//����PCA���ƼĴ���
	CMOD=0x00;				//����PCA����ģʽ���Ĵ�����  
	CL=0x00;				//PCA�������Ͱ�λ��0   
	CH=0x00; 				//PCA�������߰�λ��0
	PCA_PWM0=0x00;	 		//����PCAģ��0��PWM�Ĵ���
	CCAPM0=0x42;			//PWM0����PCA������ʽΪPWM��ʽ��01000010��  
	CCAP0L=0x40;			//����PWM0��ʼֵ��CCAP0H��ͬ  
	CCAP0H=0x40;			// PWM0��ʼʱΪ0
	CR=1;					//����PCA��ʱ��
	
}	 
void addPWM(unsigned char dat)
{
	if(CCAP0H+dat>250)
	{
		CCAP0H = 250;	
		CCAP0L = 250;
	}
	else
	{
		CCAP0H+=dat;
		CCAP0L+=dat;	
	}
}
void reducePWM(unsigned char dat)
{
	if(CCAP0H-dat<0)
	{
		CCAP0H = 10;	
		CCAP0L = 10;
	}
	else
	{
		CCAP0H-=dat;
		CCAP0L-=dat;	
	}
}
void setPWM(unsigned char dat)
{
	switch(dat)
	{
		case 1:	
			CCAP0H = 0X78;	
			CCAP0L = 0X3F;
			break;
		case 2:	
			CCAP0H = 0X7F;	
			CCAP0L = 0XBF;
			break;
		case 3:	
			CCAP0H = 0X7F;	
			CCAP0L = 0x10;
			break;
		case 4:	
			CCAP0H = 0XFF;	
			CCAP0L = 0X3F;
			break;
	}
		
}

//void PWMInit_B()
//{
//	CCON=0;				//����PCA���ƼĴ���
//	CMOD=0x00;			//����PCA����ģʽ���Ĵ�����  
//	CL=0x00;			//PCA�������Ͱ�λ��0   
//	CH=0x00; 			//PCA�������߰�λ��0
//	PCA_PWM0=0x00;	 		//����PCAģ��0��PWM�Ĵ���
//	CCAPM0=0x42;			//PWM0����PCA������ʽΪPWM��ʽ��01000010��  
////	CCAP0L=0x8f;			//����PWM0��ʼֵ��CCAP0H��ͬ  
////	CCAP0H=0x8f;			// PWM0��ʼʱΪ0
//	CCAP0L=0x8f;			//����PWM0��ʼֵ��CCAP0H��ͬ  
//	CCAP0H=0x8f;			// PWM0��ʼʱΪ0
//////	CCAP0L=PWM[1];			//����PWM0��ʼֵ��CCAP0H��ͬ  
//////	CCAP0H=PWM[1];			// PWM0��ʼʱΪ0
//	CR=1;			//����PCA��ʱ��
//	
//}	 

 //CL<CCAPOLʱ�����,�ߵ�ƽ��PWM����ڣ�ռ�ձ�Խ�󣬼���

//void main() 
//{
//	
//	PWMInit();
//	P1_3=0;
//	runfront();
//	runback();	
//	while(1) 
//	{  
//		if(P1_7==0) 
//		{  
//			delay(200); 
//			while(P1_7==0);
//			CCAP0H-=10;			//����
//			CCAP0L-=10; 
//		} 
//	}

//} 
