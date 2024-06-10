debug:
	cmake --build build/Debug --config Debug
	./build/Debug/SpaceInvaders.exe

release:
	cmake --build build/Release --config Release
	./build/Release/SpaceInvaders.exe

install:
	cmake --install build/Release --config Release

init-debug:
	cmake -S . -B build/Debug -G "Ninja" -DCMAKE_BUILD_TYPE=Debug

init-release:
	cmake -S . -B build/Release -G "Ninja" -DCMAKE_BUILD_TYPE=Release