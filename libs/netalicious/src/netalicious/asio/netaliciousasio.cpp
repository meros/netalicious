#include "netaliciousasio.hpp"

#include <netalicious/asio/loopasio.hpp>
#include <netalicious/asio/eggclockasio.hpp>
#include <netalicious/asio/tcpacceptorasio.hpp>
#include <netalicious/asio/tcpconnectorasio.hpp>
#include <netalicious/asio/ipaddressv4asio.hpp>
#include <netalicious/asio/ipresolverasio.hpp>

namespace netalicious {

NetaliciousAsio::~NetaliciousAsio() {

}

boost::shared_ptr<Loop>
NetaliciousAsio::createLoop() {
	return boost::shared_ptr<Loop>(new LoopAsio());
}

boost::shared_ptr<EggClock>
NetaliciousAsio::createEggclock(
		boost::shared_ptr<Loop> aLoop) {
	boost::shared_ptr<LoopAsio> loopAsio =
			boost::static_pointer_cast<LoopAsio>(aLoop);

	return boost::shared_ptr<EggClock>(new EggClockAsio(loopAsio));
}

boost::shared_ptr<TcpAcceptor>
NetaliciousAsio::createTcpAcceptor(
		boost::shared_ptr<Loop> aLoop) {
	boost::shared_ptr<LoopAsio> loopAsio =
			boost::static_pointer_cast<LoopAsio>(aLoop);

	return boost::shared_ptr<TcpAcceptor> (new TcpAcceptorAsio(loopAsio));
}

boost::shared_ptr<TcpConnector>
NetaliciousAsio::createTcpConnector(
			boost::shared_ptr<Loop> aLoop) {
	boost::shared_ptr<LoopAsio> loopAsio =
			boost::static_pointer_cast<LoopAsio>(aLoop);

	return boost::shared_ptr<TcpConnector> (new TcpConnectorAsio(loopAsio));
}

boost::shared_ptr<IpResolver>
NetaliciousAsio::createIpResolver(
			boost::shared_ptr<Loop> aLoop) {
	boost::shared_ptr<LoopAsio> loopAsio =
			boost::static_pointer_cast<LoopAsio>(aLoop);

	return boost::shared_ptr<IpResolver> (new IpResolverAsio(loopAsio));
}

boost::shared_ptr<IpAddress>
NetaliciousAsio::createIpAddress(
		uint8_t aOctets[4]) {
	boost::shared_ptr<IpAddressV4Asio> addr(new IpAddressV4Asio);

	boost::asio::ip::address_v4::bytes_type bytes;
	bytes[0] = aOctets[0];
	bytes[1] = aOctets[1];
	bytes[2] = aOctets[2];
	bytes[3] = aOctets[3];

	addr->myAddress = boost::asio::ip::address_v4(bytes);

	return addr;
}



}
