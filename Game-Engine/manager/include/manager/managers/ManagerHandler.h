#ifndef MANAGER_INCLUDE_MANAGER_MANAGERS_MANAGERHANDLER_H_
#define MANAGER_INCLUDE_MANAGER_MANAGERS_MANAGERHANDLER_H_

//C system headers

//C++ system headers
#include <cstdint>
//Other libraries headers

//Own components headers
#include "manager/managers/MgrBase.h"
//Forward declarations
struct ManagerHandlerCfg;

class ManagerHandler {
public:

	int32_t init(const ManagerHandlerCfg& cfg);
	void deinit();

	void process();

private:
	MgrBase* _managers[MANAGERS_COUNT];

	void nullifyGlobalMgr(int32_t mgr);
};

#endif /* MANAGER_INCLUDE_MANAGER_MANAGERS_MANAGERHANDLER_H_ */
