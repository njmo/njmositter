/*
 * EventMain.hpp
 *
 *  Created on: Jun 7, 2017
 *      Author: njmo
 */

#ifndef APPLICATION_EVENT_EVENTMAIN_HPP_
#define APPLICATION_EVENT_EVENTMAIN_HPP_
#include "EventHandler.hpp"
#include <event/queue/EventQueue.hpp>
#include <thread>

namespace event {

class EventMain : public std::thread {
public:
	EventMain()
		:std::thread(&EventMain::mainLoop, this),
		 eventHandler(),
		 suspended(true),
		 stopped(false)
	{

	};

	void mainLoop();
	bool isSuspended() { return suspended; }
	void suspend() { suspended = true; nannyLogInfo("Going to sleep"); }
	void kill(){ stopped = true; nannyLogInfo("received kill command");}
	void wakeUp() { suspended = false; }
	bool isRunning() { return !stopped; }
	virtual ~EventMain();
private:
	EventHandler eventHandler;
	bool suspended;
	bool stopped;
};

} /* namespace event */

#endif /* APPLICATION_EVENT_EVENTMAIN_HPP_ */
