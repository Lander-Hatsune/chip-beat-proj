//mpu6050.c

//https://www.cnblogs.com/dchipnau/p/5310088.html(��̬�ں�)

#include "Mpu6050.h"
#include "ServeSource.h"
#include "Hardware.h"
//mpu6050calibration

float mpudata[7]={0,0,0,0,0,0,0};//���ٶȡ����ٶ�����
float mpudata_int[7]={0,0,0,0,0,0,0};//�������ݣ������ٶȻ��߽Ƕ�

float offset[7]={0,0,0,0,0,0,0};//�궨�õ���offset��Ĭ��Ϊ0// done
float factor[7]={0,1,1,1,1,1,17};//�궨�õ���factor��Ĭ��Ϊ1// done

float offset_test[7]={0,0,0,0,0,0,0};
float factor_test[7]={0,0,0,0,0,0,0};

void mpu6050_Init(void)
{
	//port configuration
	IfxPort_setPinMode(SCL, IfxPort_Mode_outputOpenDrainGeneral);
	IfxPort_setPinMode(SDA, IfxPort_Mode_outputOpenDrainGeneral);
	//mpu6050 configuration
	mpu6050Configure();
}

void mpu6050Configure(void)
{
	delay_ms(100);
	mpu6050_write_register(PWR_MGMT_1, 0x00);
	mpu6050_write_register(SMPLRT_DIV, 0x07);
	mpu6050_write_register(CONFIG, 0x06);
	mpu6050_write_register(GYRO_CONFIG, 0x18);
	mpu6050_write_register(ACCEL_CONFIG, 0x01);
}//mpu6050 configuration

// i2c start singal
uint8 mpu6050Start(void)
{
	MPU6050_SDA_HIGH;
	delay_us(1);
	MPU6050_SCL_HIGH;
	delay_us(1);
	if(!MPU6050_SDA_STATE) {
		return 0;
	}
	MPU6050_SDA_LOW;
	delay_us(1);
	if(MPU6050_SDA_STATE) {
		return 0;
	}
	MPU6050_SCL_LOW;
	return 1;
}

// i2c stop signal
void mpu6050Stop(void)
{

	MPU6050_SCL_LOW;
	delay_us(1);
	MPU6050_SDA_LOW;
	delay_us(1);
	MPU6050_SCL_HIGH;
	delay_us(1);
	MPU6050_SDA_HIGH;
	delay_us(1);
}

void mpu6050_master_sendNACK(void)
{
	delay_us(1);
	MPU6050_SCL_LOW;
	delay_us(1);
	MPU6050_SDA_HIGH;//�ߵ�ƽ��Ӧ��
	delay_us(1);
	MPU6050_SCL_HIGH;
	delay_us(1);
	MPU6050_SCL_LOW;
	delay_us(1);
}

void mpu6050_master_sendACK(void)
{
	delay_us(1);
	MPU6050_SCL_LOW;
	delay_us(1);
	MPU6050_SDA_LOW;//�͵�ƽӦ��
	delay_us(1);
	MPU6050_SCL_HIGH;
	delay_us(1);
	MPU6050_SCL_LOW;
	delay_us(1);
}

uint8 mpu6050_master_waitACK(void)
{
	MPU6050_SCL_LOW;
	MPU6050_SDA_HIGH;
	delay_us(1);
	MPU6050_SCL_HIGH;
	delay_us(1);
	if (MPU6050_SDA_STATE)//��Ӧ��
	{
		MPU6050_SCL_LOW;
		delay_us(1);
		return 0;
	}
	//Ӧ��
	MPU6050_SCL_LOW;
	delay_us(1);
	return 1;
}

void mpu6050SendByte(uint8 data)
{
	uint8 i;
	MPU6050_SCL_LOW;
	for (i=0; i<8; i++)
	{
		if(data & 0x80)
		{
			MPU6050_SDA_HIGH;
		}
		else
		{
			MPU6050_SDA_LOW;
		}
		data <<= 1;
		delay_us(1);
		MPU6050_SCL_HIGH;
		delay_us(1);
		MPU6050_SCL_LOW;
		delay_us(1);
	}
}

uint8 mpu6050receiveByte(void)
{
	uint8 i;
	sint8 data = 0;
	for(i=0;i<8;i++)
	{
		MPU6050_SCL_LOW;
		MPU6050_SCL_HIGH;
		delay_us(1);
		data <<= 0x01U;
		if(MPU6050_SDA_STATE)
		{
			data |= 0x01U;
		}
		MPU6050_SCL_LOW;
		delay_us(1);
	}
	return data;
}

uint8 mpu6050_write_register(uint8 reg,uint8 data)
{
	if (!mpu6050Start())
	{
		return 0;
	}
	mpu6050SendByte(MPU6050_ID);//���ʹӻ���ַ�Ͷ�/дѡ��λ
	if (!mpu6050_master_waitACK())//�ȴ�Ӧ��
	{
		mpu6050Stop();
		return 0;
	}
	mpu6050SendByte(reg);//Ӧ������ڲ��Ĵ�����ַ
	mpu6050_master_waitACK();//�ȴ�Ӧ��
	mpu6050SendByte(data);//Ӧ�����д�������
	mpu6050_master_waitACK();//�ȴ�Ӧ��
	mpu6050Stop();
	return 1;
}


sint16 GetData(uint8 regh)
{
	uint8 data1 = 0;
	uint8 data2 = 0;

	//read first byte
	mpu6050Start();
	mpu6050SendByte(MPU6050_ID);//���ʹӻ���ַ�Ͷ�/дѡ��λ
	if (!mpu6050_master_waitACK())//�ȴ�Ӧ��
	{
		mpu6050Stop();
		return 0;
	}
	mpu6050SendByte(regh);//Ӧ������ڲ��Ĵ�����ַ
	mpu6050_master_waitACK();//�ȴ�Ӧ��
	mpu6050Start();//restart
	mpu6050SendByte(MPU6050_ID + 1);//���ʹӻ���ַ�Ͷ�/дѡ��λ
	mpu6050_master_waitACK();//�ȴ�Ӧ��
	data1=mpu6050receiveByte();//Ӧ����ȡ����
	mpu6050_master_sendNACK();//��ȡ������ɺ��ͷ�Ӧ��

	//read second byte
	mpu6050Start();//restart
	mpu6050SendByte(MPU6050_ID);//���ʹӻ���ַ�Ͷ�/дѡ��λ
	if (!mpu6050_master_waitACK())//�ȴ�Ӧ��
	{
		mpu6050Stop();
		return 0;
	}
	mpu6050SendByte(regh+1);//Ӧ������ڲ��Ĵ�����ַ
	mpu6050_master_waitACK();//�ȴ�Ӧ��
	mpu6050Start();//restart
	mpu6050SendByte(MPU6050_ID + 1);//���ʹӻ���ַ�Ͷ�/дѡ��λ
	mpu6050_master_waitACK();//�ȴ�Ӧ��
	data2=mpu6050receiveByte();//Ӧ����ȡ����
	mpu6050_master_sendNACK();//��ȡ������ɺ��ͷ�Ӧ��

	mpu6050Stop();
	return (data1<<8)|data2;
}


void MPU6050_Get_Data(void)
{
	int i;
	for(i=1;i<4;i++)
	{
		mpudata[i]=(GetData(0x3B+2*i-2)-offset[i])/factor[i];
		if (mpudata[i]<100/factor[i] && mpudata[i]>-100/factor[i])
		{
			;
			mpudata[i]=0;
		}
	}
	for(i=4;i<7;i++)
	{
		mpudata[i]=(GetData(0x3B+2*i)-offset[i])/factor[i];
		if (mpudata[i]<10/factor[i] && mpudata[i]>-10/factor[i])
		{
			;
			mpudata[i]=0;
		}
	}
}

void MPU6050_Calibrate(void)//�궨����
{
	int i;
	for(i=1;i<4;i++)
	{
		offset_test[i]=mpudata[i];
		factor_test[i]=mpudata[i];
	}
	for(i=4;i<7;i++)
	{
		offset_test[i]=mpudata[i];
		factor_test[i]=mpudata_int[i]/90;
	}
}

void MPU6050_int(float dt)//���ֺ���
{
	int i;
	for(i=1;i<7;i++)
	{
		mpudata_int[i]=mpudata_int[i]+dt*mpudata[i];
	}
}
