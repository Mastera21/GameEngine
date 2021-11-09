#include "manager/time/TimerClient.h"

//C system headers

//C++ system headers
#include <iostream>
//Other libraries headers

//Own components headers
#include "manager/managers/TimerMgr.h"

void TimerClient::startTimer(int64_t interval, int32_t timerId, TimerType timerType){

	if(!gTimerMgr){
		return;
	}

	constexpr auto minTimerInterval = 20;//ms

	if(interval < minTimerInterval){
		std::cerr<<"Timer with Id: "<<timerId << " requesed internal: "<<interval <<
					", which is lower than the minnimum one: "<<minTimerInterval<<"\n";
		return;
	}

	const TimerData data(interval, interval, this, timerType);
	gTimerMgr->startTimer(timerId, data);
}
void TimerClient::stopTimer(int32_t timerId){
	if(!gTimerMgr){
		return;
	}

	gTimerMgr->stopTimer(timerId);
}
bool TimerClient::isActiveTimerId(int32_t timerId) const{
	return gTimerMgr->isActiveTimerId(timerId);
}
