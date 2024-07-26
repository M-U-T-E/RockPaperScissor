prepare:
	rmdir /Q /S build
	mkdir build
deploy:
	rmdir /Q /S build
	mkdir build
	cd build
	cmake -G "MinGW Makefiles" .
	cmake --build . --config Release
