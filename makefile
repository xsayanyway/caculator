COMPILE=g++ ####！！！！！！！！！
SOURCE=$(wildcard *.cpp)
OBJECT=$(patsubst %.cpp,%.o,$(SOURCE))
TARGET=calc  ####！！！！！！！！！！
LIB=      #！！！！！！指定库的名字
LIBDIR=-L. #！！！！！！！指定库的路径
INCLUDE=-I.  ###指定头文件的路径！！！！  -I  
CFLAGS=  -std=c++11 ###编译的其他选项 如-g

$(TARGET):$(OBJECT)
	$(COMPILE) $^ -o $@ $(LIB)  $(LIBDIR) $(INCLUDE)  $(CFLAGS)
%.o:%.cpp
	$(COMPILE) -c $^ -o $@ $(INCLUDE)  $(CFLAGS)
clean:
	rm *.o 
	rm $(TARGET)