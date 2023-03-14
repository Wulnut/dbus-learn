CC = gcc
CFLAGS = -I /usr/include/glib-2.0 \
		 -I	/usr/lib/x86_64-linux-gnu/glib-2.0/include \
		 -I /usr/include/gio-unix-2.0 \
		 -L /lib/x86_64-linux-gnu \
		 -lglib-2.0 -lgio-2.0 -lgobject-2.0

SRCS = server.c Interface.c Linklist.c

server : $(SRCS)
	$(CC) $(SRCS) $(CFLAGS) -o server

.PHONY : clean
clean : 
	rm server