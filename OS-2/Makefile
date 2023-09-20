obj-m += q3.o 

all:
	gcc q2.c -o q2
	sudo ./q2
	python3 q2.py
	make -C /lib/modules/6.2.0-32-generic/build M=$(PWD) modules
clean:
	make -C /lib/modules/6.2.0-32-generic/build M=$(PWD) clean
	rm q2
	rm data.txt