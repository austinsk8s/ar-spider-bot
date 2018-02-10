#include "terasic_os.h"
#include <pthread.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "CSpider.h"
#include "CSpiderLeg.h"
#include "CMotor.h"
#include "BtSppCommand.h"
#include "QueueCommand.h"
#include "PIO_LED.h"
#include "PIO_BUTTON.h"
#include "ADC.h"

int main(int argc, char *argv[]){

  printf("===== Group <X> Final Project =====\r\n");

  //####################################
  /*
    DO NOT TAKE THIS SECTION AWAY. SPIDER'S BEHAVIOR
    IS NOT AS EXPECTED WITHOUT THIS INITIALIZATION STEP
  */
  //####################################

  // Spider class
  CSpider Spider;
  bool bSleep = false;
    CPIO_LED LED_PIO;
    CPIO_BUTTON BUTTON_PIO;

	printf("Spider Init & Standup\r\n");
	if (!Spider.Init()){
		printf("Spilder Init failed\r\n");
	}else{
		if (!Spider.Standup())
			printf("Spilder Standup failed\r\n");
	}
	Spider.SetSpeed(50);

  //####################################

  // Uncomment to use the ADC class for reading IR sensor
  // ADC adc;

	while(1){
		if(BUTTON_PIO.GetBUTTON()==0x2)
			{
				Spider.MoveForward(5);
				Spider.Reset();
				Spider.MoveForwardDynamic(5);
				Spider.Reset();
			}
			else if (BUTTON_PIO.GetBUTTON()==0x1)
			{
				Spider.SetSpeed(10);
				Spider.MoveForwardBipod(5);
				Spider.Reset();
				Spider.SetSpeed(100);
				Spider.MoveForwardBipod(5);
				Spider.Reset();
			}
	}
	
	return 0;
}