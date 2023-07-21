# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/flose/Data/Coding/FTXUI/ftxui-starter/cmake-build-debug/_deps/ftxui-src"
  "/home/flose/Data/Coding/FTXUI/ftxui-starter/cmake-build-debug/_deps/ftxui-build"
  "/home/flose/Data/Coding/FTXUI/ftxui-starter/cmake-build-debug/_deps/ftxui-subbuild/ftxui-populate-prefix"
  "/home/flose/Data/Coding/FTXUI/ftxui-starter/cmake-build-debug/_deps/ftxui-subbuild/ftxui-populate-prefix/tmp"
  "/home/flose/Data/Coding/FTXUI/ftxui-starter/cmake-build-debug/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp"
  "/home/flose/Data/Coding/FTXUI/ftxui-starter/cmake-build-debug/_deps/ftxui-subbuild/ftxui-populate-prefix/src"
  "/home/flose/Data/Coding/FTXUI/ftxui-starter/cmake-build-debug/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/flose/Data/Coding/FTXUI/ftxui-starter/cmake-build-debug/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/flose/Data/Coding/FTXUI/ftxui-starter/cmake-build-debug/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
