#include <stdio.h>
#include "FIR.h"

const double Gains[39] = {
-0.01152483856464,  -0.0225638929287, -0.002300804134165,  0.01259363093284,
-0.0003113695305127, -0.01591961043518, 0.005297252625722,  0.01846679452201,
-0.01074864266549, -0.02187510941784,   0.0192688121099,  0.02485021814652,
-0.03198920030056, -0.02754770718169,  0.05351978821001,   0.0296026126381,
-0.09977798297944, -0.03089664322888,   0.3161729116138,   0.5313543998522,
0.3161729116138, -0.03089664322888, -0.09977798297944,   0.0296026126381,
0.05351978821001, -0.02754770718169, -0.03198920030056,  0.02485021814652,
0.0192688121099, -0.02187510941784, -0.01074864266549,  0.01846679452201,
0.005297252625722, -0.01591961043518, -0.0003113695305127,  0.01259363093284,
-0.002300804134165,  -0.0225638929287, -0.01152483856464
};
#define ORDER        38                       //阶数

double Buffer[ORDER + 1];        //采样历史数据

double Fir(double Input)
{
	double Output = 0.0;        //数据输出
	int Index;                //下标索引

	//采样数据移位
	for (Index = ORDER; Index > 0; Index--)
		Buffer[Index] = Buffer[Index-1];

	Buffer[0] = Input;

	//计算输出
	for (Index = 0; Index < ORDER+1; Index++)
		Output += Gains[Index]*Buffer[Index];

	return Output;
}

