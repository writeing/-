 #include	<PWM.h>
//unsigned char PWM[4] = {0x3F, 0x7F, 0xBF, 0xFF};//速度分为四个等级
//unsigned int speed[4];
//P1^3,1^4为PWM输出口


void PWMInit()
{
	CCON=0;					//设置PCA控制寄存器
	CMOD=0x00;				//设置PCA工作模式器寄存器，  
	CL=0x00;				//PCA计数器低八位置0   
	CH=0x00; 				//PCA计数器高八位置0
	PCA_PWM0=0x00;	 		//设置PCA模块0的PWM寄存器
	CCAPM0=0x42;			//PWM0设置PCA工作方式为PWM方式（01000010）  
	CCAP0L=0x40;			//设置PWM0初始值与CCAP0H相同  
	CCAP0H=0x40;			// PWM0初始时为0
	CR=1;					//启动PCA定时器
	
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
//	CCON=0;				//设置PCA控制寄存器
//	CMOD=0x00;			//设置PCA工作模式器寄存器，  
//	CL=0x00;			//PCA计数器低八位置0   
//	CH=0x00; 			//PCA计数器高八位置0
//	PCA_PWM0=0x00;	 		//设置PCA模块0的PWM寄存器
//	CCAPM0=0x42;			//PWM0设置PCA工作方式为PWM方式（01000010）  
////	CCAP0L=0x8f;			//设置PWM0初始值与CCAP0H相同  
////	CCAP0H=0x8f;			// PWM0初始时为0
//	CCAP0L=0x8f;			//设置PWM0初始值与CCAP0H相同  
//	CCAP0H=0x8f;			// PWM0初始时为0
//////	CCAP0L=PWM[1];			//设置PWM0初始值与CCAP0H相同  
//////	CCAP0H=PWM[1];			// PWM0初始时为0
//	CR=1;			//启动PCA定时器
//	
//}	 

 //CL<CCAPOL时输出低,高电平接PWM输出口，占空比越大，加速

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
//			CCAP0H-=10;			//加速
//			CCAP0L-=10; 
//		} 
//	}

//} 
