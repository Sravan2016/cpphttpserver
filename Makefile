all: run

helloworld: 
	g++ -L /home/sravan/Documents/javafromc/ -L/usr/lib/ main.o -o server  -lm -lpq

hello_world: 
	g++ -std=c++17 -o server \
	-L /usr/lib/postgresql/12/lib/ \
	-L /home/sravan/Documents/javafromc/ \
	-I /usr/include/postgresql/ \
	-I /usr/lib/jvm/java-8-openjdk-amd64/include/linux/ \
	-I /home/sravan/Documents/javafromc/include/ \
	connection_context.cpp epoll_loop.cpp http_server.cpp postgresql.cpp main.cpp \
	-lm -lpq  \

run: ./server
	

clean:
	rm -f server
