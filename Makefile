all : config create run

config :
	mkdir -p build
	cmake -S . -B build

create :
	make -C ./build/

run : 
	cd ./build && ./Graph

# test : 
# 	cd ./build/tests && ./tests.exe	

# install :
# 	cd ./build && sudo make install