#ifndef MANAGER_INCLUDE_MANAGER_MANAGERS_TIMERMGR_H_
#define MANAGER_INCLUDE_MANAGER_MANAGERS_TIMERMGR_H_

//C system headers

//C++ system headers
#include <map>
#include <set>
//Other libraries headers

//Own components headers
#include "manager/managers/MgrBase.h"
#include "manager/time/TimerData.h"
#include "utils/time/Time.h"
//Forward declarations

class TimerMgr: public MgrBase {
public:
	int32_t init();

	void process() final;
	void deinit() final;

	void startTimer(int32_t timerid, const TimerData& data);

	void stopTimer(int32_t timerId);
	bool isActiveTimerId(int32_t timerId) const;
	void onInitEnd();

private:
	Time _elapsedTime;
	std::map<int32_t, TimerData> _timerMap;
	std::set<int32_t> _removeTimerSet;

	void removeTimersInternal();
	void onTimerTimeout(int32_t timerId, TimerData& timer);
};

extern TimerMgr* gTimerMgr;

#endif /* MANAGER_INCLUDE_MANAGER_MANAGERS_TIMERMGR_H_ */
