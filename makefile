wprepare:
	rmdir /Q /S build
	mkdir build
prepare:
	rm -rf build
	mkdir build
compile:
	cd build
	cmake -S . -B build
	cmake --build build --config Release
	cd ..
pkgdeb:
	rm -rf build
	mkdir build
	cmake -S . -B build -DCPACK_LINUX_GEN_NAME="DEB"
	cmake --build build --config Release
	cd build && cpack -C Release
	
pkgrpm:
	rm -rf build
	mkdir build
	cmake -S . -B build -DCPACK_LINUX_GEN_NAME="RPM"
	cmake --build build --config Release
	cd build && cpack -C Release
	