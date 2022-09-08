# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/goko/Desktop/controlix/esp-idf/components/bootloader/subproject"
  "/Users/goko/Desktop/controlix/esp-idf/projects/deneme/build/bootloader"
  "/Users/goko/Desktop/controlix/esp-idf/projects/deneme/build/bootloader-prefix"
  "/Users/goko/Desktop/controlix/esp-idf/projects/deneme/build/bootloader-prefix/tmp"
  "/Users/goko/Desktop/controlix/esp-idf/projects/deneme/build/bootloader-prefix/src/bootloader-stamp"
  "/Users/goko/Desktop/controlix/esp-idf/projects/deneme/build/bootloader-prefix/src"
  "/Users/goko/Desktop/controlix/esp-idf/projects/deneme/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/goko/Desktop/controlix/esp-idf/projects/deneme/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
