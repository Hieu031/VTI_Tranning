
#include "ADC.h"

/* Function to start ADC Conversion */

void Adc_StartGroupConversion(Adc_GroupType Group)
{
		if(Group == 1)
		{
			/* Write code to start ADC */
			/* ... */
		}
}

/* Function API to read ADC group */
Std_ReturnType Adc_ReadGroup( Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr)
{
	unsigned int ADCValue;
	
	if(Group == 1)
	{
		ADCValue = SomeRegister;
		*DataBufferPtr = ADCValue; /* Write back ADC value */
	}
}

 