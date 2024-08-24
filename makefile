compile:
	gcc mainDriver.c sll_list.c -o sll -Wall

clean:
	rm sll
	rm -f $(TARGET)
	rm -rf bin

