all: base byte

base: 
	g++ -Wall -O0 -std=c++11 BaseConverter.cpp -o baseconverter 

byte:
	g++ -Wall -O0 -std=c++11 ByteConverter.cpp -o byteconverter 
