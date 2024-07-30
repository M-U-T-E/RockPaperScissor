wprepare:
	rmdir /Q /S build
	mkdir build
prepare:
	rm -rf build
	mkdir build
compile:
	cmake -S . -B build
	cmake --build build --config Release
