rm -rf build
cmake -G Xcode -B build \
  -DCMAKE_SYSTEM_NAME=iOS \
  -DCMAKE_OSX_ARCHITECTURES=arm64
cmake --build build --config Debug
