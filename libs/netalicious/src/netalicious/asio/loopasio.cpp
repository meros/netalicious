#include "loopasio.hpp"

#include <boost/bind.hpp>

#include <iostream>

// TODO: change to method
void runTrampooline(
		boost::shared_ptr<boost::asio::io_service> myAsioIo) {
	myAsioIo->run();
}

namespace netalicious {

LoopAsio::LoopAsio()
	: myAsioIo(new boost::asio::io_service())
	, myWork(new boost::asio::io_service::work(*myAsioIo))
{
	myRunThread = boost::thread(boost::bind(runTrampooline, myAsioIo));
}

LoopAsio::~LoopAsio() {
	myAsioIo->stop();
	myRunThread.join();
}

boost::shared_ptr<boost::asio::io_service>
LoopAsio::getAsioIo() {
	return myAsioIo;
}

void LoopAsio::waitDone() {
	myWork.reset();
	myRunThread.join();
}

}
