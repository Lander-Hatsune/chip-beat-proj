//mpu6050.c

//https://www.cnblogs.com/dchipnau/p/5310088.html(姿态融合)

#include "Mpu6050.h"
#include "ServeSource.h"
#include "Hardware.h"
//mpu6050calibration

//z轴角速度offset标定，默认为0
float offset_gyro_z = -10;
//z轴角速度factor标定，默认为1
float factor_gyro_z = 18;

//其余参数offset标定
float offset_acc_x = 0;
float offset_acc_y = 0;
float offset_acc_z = 0;
float offset_gyro_x = 0;
float offset_gyro_y = 0;
//其余参数factor标定
float factor_acc_x = 1;
float factor_acc_y = 1;
float factor_acc_z = 1;
float factor_gyro_x = 1;
float factor_gyro_y = 1;

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
	MPU6050_SDA_HIGH;//高电平非应答
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
	MPU6050_SDA_LOW;//低电平应答
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
	if (MPU6050_SDA_STATE)//非应答
	{
	MPU6050_SCL_LOW;
	delay_us(1);
	return 0;
	}
	//应答
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
	mpu6050SendByte(MPU6050_ID);//发送从机地址和读/写选择位
	if (!mpu6050_master_waitACK())//等待应答
	{
		mpu6050Stop();
		return 0;
	}
	mpu6050SendByte(reg);//应答后发送内部寄存器地址
	mpu6050_master_waitACK();//等待应答
	mpu6050SendByte(data);//应答后发送写入的数据
	mpu6050_master_waitACK();//等待应答
	mpu6050Stop();
	return 1;
}

uint8 mpu6050_read_register(uint8 reg)
{
	sint8 data = 0;
	if (!mpu6050Start())
	{
		return 0;
	}
	mpu6050SendByte(MPU6050_ID);//发送从机地址和读/写选择位
	if (!mpu6050_master_waitACK())//等待应答
	{
		mpu6050Stop();
		return 0;
	}
	mpu6050SendByte(reg);//应答后发送内部寄存器地址
	mpu6050_master_waitACK();//等待应答
	mpu6050Start();//restart
	mpu6050SendByte(MPU6050_ID + 1);//应答后发送内部寄存器地址和读/写选择位
	mpu6050_master_waitACK();//等待应答
	data = mpu6050receiveByte();//应答后读取数据
	mpu6050_master_sendNACK();//读取数据完成后发送非应答
	mpu6050Stop();
	return data;
}



sint16 GetData(uint8 reg)
{
	uint8 H,L;
	H = mpu6050_read_register(reg);
	L = mpu6050_read_register(reg + 1);
	return (H << 8) | L;
}

//fetch required data
float MPU6050_Get_Data(unsigned id)
{
    switch(id)
    {
        case 1: return (GetData(ACCEL_XOUT_H) + offset_acc_x)/factor_acc_x;
        case 2: return (GetData(ACCEL_YOUT_H) + offset_acc_y)/factor_acc_y;
        case 3: return (GetData(ACCEL_ZOUT_H) + offset_acc_z)/factor_acc_z;
        case 4: return (GetData(GYRO_XOUT_H) + offset_gyro_x)/factor_gyro_x;
        case 5: return (GetData(GYRO_YOUT_H) + offset_gyro_y)/factor_gyro_y;
        case 6: {
        	float gyro = 0;
			gyro = (GetData(GYRO_ZOUT_H) - offset_gyro_z)/factor_gyro_z;
			if (gyro< 10/factor_gyro_z && gyro > -(10/factor_gyro_z)) {
			gyro = 0;
        }
		return gyro;
      }
   }
    return 0;
}
