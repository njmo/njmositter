/*
 * phoneThread.h
 *
 *  Created on: Apr 10, 2017
 *      Author: njmo
 */

#ifndef PHONETHREAD_H_
#define PHONETHREAD_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/ioctl.h>

#include <thread>
#include <mutex>
#include <list>
#include <unistd.h>
#include <inc/Messages.hpp>
#include <event/queue/EventQueue.hpp>
#include <event/queue/Waiter.hpp>
#include <interface/message/RegisterUser.hpp>
#include <interface/message/NotifyRequest.hpp>
#include <interface/message/CameraRequest.hpp>
#include <interface/response/RegisterResponse.hpp>
#include <interface/response/NannyResponse.hpp>

#include <interface/message/NannyRequest.hpp>
#include <interface/response/NannyResponse.hpp>

// downloaded from https://github.com/nlohmann/json
#include <utils/json.hpp>
using nlohmann::json;

class PhoneThread : public std::thread , queue::IWaiter
{
public:
	PhoneThread(int,struct sockaddr_in*);
	void test();
	void notify(void *);
	void kill();
	virtual ~PhoneThread();
private:
	void sendNotifyRequest();
	void sendNotifyCapture(u8);

	struct sockaddr_in clientAddr;
	volatile bool isSuspended;
  volatile bool isRunning;
	std::mutex mutex;
  u32 nannyId;
	std::list<NannyResponse*> requestList;
	u32 id;
	int socket;
};

#endif /* PHONETHREAD_H_ */
