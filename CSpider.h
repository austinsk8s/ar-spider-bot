/*
 * CSpider.h
 *
 *  Created on: 2014/7/26
 *      Author: Richard
 */

#ifndef CSPIDER_H_
#define CSPIDER_H_

#include "CSpiderLeg.h"

class CSpider {
protected:

	typedef enum{
		LEG_RF,
		LEG_RM,
		LEG_RB,
		LEG_LF,
		LEG_LM,
		LEG_LB,
		LEG_NUM
	}LEG_ID;

	typedef enum{
		TRIPOD1,    //RF LM RB
		TRIPOD2,	//LF RM LB
		TRIPOD_NUM
	}TRIPOD_ID;
	
	typedef enum{
		BIPOD1,		//RF LB
		BIPOD2,		//LF RB
		BIPOD_NUM
	}BIPOD_ID;

	CSpiderLeg *m_szLeg[LEG_NUM];
	static bool m_bDebugDump;
	bool m_bAbort;


public:
	CSpider();
	virtual ~CSpider();

	bool IsReady(void);
//	bool WaitReady(float fTimeoutSecond);
	bool WaitReady(uint32_t Timeout);
	uint32_t ReadyTime(void);
	void SetFootY(uint8_t Leg,float Angle);
	void MoveTripod(TRIPOD_ID Tripod,CSpiderLeg::JOINT_ID Joint,float AngleF,float AngleM,float AngleB);
	void MoveBipod(BIPOD_ID Bipod,CSpiderLeg::JOINT_ID Joint,float AngleF,float AngleB);
	//Action
	bool Init(void);
	void Reset(void);
	void LiftMidLegs(void);
	bool Standup(void);
	void TiltRight(void);
	void TiltLeft(void);
	void TiltForward(void);
	void TiltBackward(void);
	void TiltNone(void);
	void BodyForward(void);
	void BodyBackward(void);
	void BodyNone(void);
	void BodyUpDown(uint8_t Repeat_Num);
	void MoveForward(uint8_t Repeat_Num);
	void MoveForwardDynamic(uint8_t Repeat_Num);
	void MoveForwardBipod(uint8_t Repeat_Num);
	void MoveBackward(uint8_t Repeat_Num);
	void MoveParallelR(uint8_t Repeat_Num);
	void MoveParallelL(uint8_t Repeat_Num);
	void Stomp(uint8_t Repeat_Num);
	void RotatelRight(uint8_t Repeat_Num);
	void RotatelLeft(uint8_t Repeat_Num);
	void SetSpeed(int Speed);
	void DEMO_Dance(uint8_t Repeat_Num);
	void ByeBye(uint8_t Repeat_Num);
	void DEMO_Rollover(void);
	void Abort(void);
	void Sleep(void);
	void WakeUp(void);

	void SetLegsBase();
	void Extend();
	void Fold();
	void Grab();

	void SetJointPosition(int leg, int joint, int position);


};

#endif /* CSPIDER_H_ */
