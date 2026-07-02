cmake -G Ninja -B build-clangd \
  -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
  -DCMAKE_OSX_ARCHITECTURES=arm64
ln build-clangd/compile_commands.json .
