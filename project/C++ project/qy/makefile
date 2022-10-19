CC = g++
src1 = $(wildcard ./manager/*.cpp)
src2 = $(wildcard ./service/*.cpp)
src3 = $(wildcard ./*.cpp)
obj1 = $(patsubst %.cpp,%.o,$(src1))
obj2 = $(patsubst %.cpp,%.o,$(src2))
obj3 = $(patsubst %.cpp,%.o,$(src3))
BIN = qy


all:$(obj1) $(obj2) $(obj3)
	$(CC) $^ -o $(BIN) && ./$(BIN)
#	gcc $(obj) -o $(target)

#编译 src下的.c文件 为.o文件	
%.o:./service%.cpp
	$(CC) -c $< -o $@

#编译 src下的.c文件 为.o文件	
%.o:./service%.cpp
	$(CC) -c $< -o $@	
	
#编译 当前文件下的main.c文件
%.o:%.cpp
	$(CC) -c $< -o $@
	
clean:
	rm -rf $(BIN) $(obj1) $(obj2) $(obj3) 
	rm -rf *~ *.h.gch

