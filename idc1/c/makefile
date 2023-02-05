# 开发框架头文件路径
PUBLIC = -I/home/guikai/proj/Data-Center/public

# 开发框架cpp文件名
PUBCPP = /home/guikai/proj/Data-Center/public/_public.cpp

# 编译参数
CFLAGS = -g


all:crtsurfdata

crtsurfdata: crtsurfdata.cpp
	g++ $(CFLAGS) -o crtsurfdata crtsurfdata.cpp $(PUBLIC) $(PUBCPP) -lm -lc
	cp crtsurfdata ../bin/.

clean:
	rm crtsurfdata
	rm -rf log