#test compile and run
CXX=g++
CXXSTD=-std=gnu++17

FILE=main.cpp
BIN=test

RUN_LINUX=./test #and powershell
RUN_WINDOWS=test.exe

DELETE_LINUX=rm test*

linux_and_powershell:
	$(CXX) $(FILE) -o $(BIN) $(CXXSTD)
	$(RUN_LINUX)
	$(DELETE_LINUX)

windows:
	$(CXX) $(FILE) -o $(BIN) $(CXXSTD)
	$(RUN_WINDOWS)