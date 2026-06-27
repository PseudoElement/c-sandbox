# How to run project:

- Changed a .c file → just `make -C build` (or cd build && make)
- Changed CMakeLists.txt → re-run `cmake -B build` first, then `make -C build`

# How to find a **linkable target name** for exteranl library(used in CMakeLists.txt target_link_libraries):

- open a project on github
- find a CMakeLists.txt file(usually in src/CMakeLists.txt)
- check a name in defined in **project(<name>)** directive
