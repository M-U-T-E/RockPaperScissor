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
pkgdeb:# build and package for Debian
	rm -rf build
	mkdir build
	cmake -S . -B build -DCPACK_LINUX_GEN_NAME="DEB"
	cmake --build build --config Release
	cd build && cpack -C Release
pkgrpm:# build and package for Redhat
	rm -rf build
	mkdir build
	cmake -S . -B build -DCPACK_LINUX_GEN_NAME="RPM"
	cmake --build build --config Release
	cd build && cpack -C Release
pkgwin:# build and package for Windows (using mingw and NSIS with Env var plugin)
	rmdir /Q /S build
	mkdir build
	cmake -S . -B build  -G "MinGW Makefiles" -DCPACK_LINUX_GEN_NAME=NSIS
	cmake --build build --config Release -DCPACK_LINUX_GEN_NAME=NSIS
	cd build && cpack -C Release