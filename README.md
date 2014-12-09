netalicious
===========

What is this?
-------------
netalicious is a simple (as in easy to use) network lib that is still based on a modern asynchronous model that should be able to scale well. That said, the design does not aim for best in class performance, target audience is hobby projects that want an easy to use cross platform event driven network library.

In scope:
* Basic accepting/connecting tcp sockets.
* Basic protocol handling.

Goals:
* Dead simple application code.
* Thin api between application and implementation, helpers are implemented in headers using same thin api.
* Sane but balanced model for handling resources/memory etc. Professional quality but not micro optimized.

Antigoals:
* Templates as micro-optimization
* Best in class performance (choosing an interface/implementation pattern is in itself a cost)

Current status
--------------
This project is still in it's infancy, much is lacking.

As of now this is available:

* Loop - working
* EggClock - working
* TcpAcceptor - able to bind/accept/close
* TcpChannel - able to read/write/close
* ReadableBuffer - working, needs utilities for ease of use
* TcpConnector - basic functionaly with hardcoded address
* TODO: SslChannel

Design decisions and random thoughts
------------------------------------
Very light weight error mechanism - connect either returns ok channel or not - when did you really take care of all potential errors correctly anyway? When did you really recover from exotic error states? So, few potential return values, less code, better code. 

Never return null pointers, always wrap in optional if empty result is an option. Clear semantic signal on what user can expect and needs to take care of.

Build
-----
To build this, you need maker, another project of mine. Clone maker in a folder next to netalicious and it should work:

* /workspace/netalicious
* /workspace/maker

Then use cmake as usual using netalicious as root source folder. I recommend building out of source.
