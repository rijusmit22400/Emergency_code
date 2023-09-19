obj-m += q3.o 

all::
	make -C /lib/modules/6.2.0-32-generic/build M=$(PWD) modules
clean:
	make -C /lib/modules/6.2.0-32-generic/build M=$(PWD) clean
