# Makefile for f2022, ecs36b
#
# g++ -std=c++14 test_GPS.cpp GPS.cpp -o test_GPS
#
# example: $ ./test_GPS 48.88 2.3

CC 	=	g++ -std=c++14
CFLAGS 	= 	-g -I/opt/homebrew/include
LDFLAGS = 	-L/opt/homebrew/lib -ljsoncpp -lmicrohttpd -ljsonrpccpp-common	\
		-ljsonrpccpp-server -lcurl -ljsonrpccpp-client

CLANG_ROOT = 	\
	/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk

OBJS	= 	Shadow_Thing.o GPS.o Labeled_GPS.o Person.o		\
		MT4_Thing.o Locatable.o Holdable.o Record.o JvTime.o

CLASSES	= 	Shadow_Thing.h GPS.h Labeled_GPS.h Person.h		\
		MT4_Thing.h Locatable.h Holdable.h Record.h JvTime.h	\
		mt4client.h mt4server.h

# CLINC = -I$(CLANG_ROOT)/usr/include/c++/v1 -D_MEMORY_LAYOUT_
CLINC = -D_MEMORY_LAYOUT_

# rules
all: 	test_MT4 mt4client mt4server

#
mt4client.h:		ecs36b_mt4.json
	jsonrpcstub ecs36b_mt4.json --cpp-server=mt4Server --cpp-client=mt4Client

mt4server.h:		ecs36b_mt4.json
	jsonrpcstub ecs36b_mt4.json --cpp-server=mt4Server --cpp-client=mt4Client

mt4client.o:		mt4client.h mt4client.cpp $(CLASSES)
	$(CC) -c $(CFLAGS) mt4client.cpp

mt4server.o:		mt4server.h mt4server.cpp $(CLASSES)
	$(CC) -c $(CFLAGS) mt4server.cpp

Shadow_Thing.o:		Shadow_Thing.cpp $(CLASSES)
	$(CC) -c $(CFLAGS) Shadow_Thing.cpp

Record.o:	Record.cpp $(CLASSES)
	$(CC) -c $(CFLAGS) Record.cpp

GPS.o:		GPS.cpp $(CLASSES)
	$(CC) -c $(CFLAGS) GPS.cpp

Labeled_GPS.o:	Labeled_GPS.cpp $(CLASSES)
	$(CC) -c $(CFLAGS) Labeled_GPS.cpp

JvTime.o:	JvTime.cpp $(CLASSES)
	$(CC) -c $(CFLAGS) JvTime.cpp

Person.o:	Person.cpp $(CLASSES)
	$(CC) -c $(CFLAGS) Person.cpp

MT4_Thing.o:	MT4_Thing.cpp $(CLASSES)
	$(CC) -c $(CFLAGS) MT4_Thing.cpp

Locatable.o:	Locatable.cpp $(CLASSES)
	$(CC) -c $(CFLAGS) Locatable.cpp

Holdable.o:	Holdable.cpp $(CLASSES)
	$(CC) -c $(CFLAGS) Holdable.cpp

test_MT4.o:	test_MT4.cpp $(CLASSES)
	$(CC) -c $(CFLAGS) test_MT4.cpp

mt4client:	mt4client.o $(OBJS)
	$(CC) mt4client.o $(OBJS) -o mt4client $(LDFLAGS)

mt4server:	mt4server.o $(OBJS)
	$(CC) mt4server.o $(OBJS) -o mt4server $(LDFLAGS)

test_MT4:	test_MT4.o $(OBJS)
	$(CC) test_MT4.o $(OBJS) -o test_MT4 $(LDFLAGS)

clean:
	rm -f *.o *~ core test_MT4 mt4client mt4server mt4client.h mt4server.h



