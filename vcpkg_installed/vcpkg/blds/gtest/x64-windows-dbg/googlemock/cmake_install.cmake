# Install script for directory: C:/Users/Marco/source/repos/Coding_Challange/vcpkg_installed/vcpkg/blds/gtest/src/v1.14.0-bcf93537a8.clean/googlemock

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/Marco/source/repos/Coding_Challange/vcpkg_installed/vcpkg/pkgs/gtest_x64-windows/debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "OFF")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "gmock" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "C:/Users/Marco/source/repos/Coding_Challange/vcpkg_installed/vcpkg/blds/gtest/src/v1.14.0-bcf93537a8.clean/googlemock/include/")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "gmock" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Marco/source/repos/Coding_Challange/vcpkg_installed/vcpkg/blds/gtest/x64-windows-dbg/lib/gmock.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "gmock" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/Marco/source/repos/Coding_Challange/vcpkg_installed/vcpkg/blds/gtest/x64-windows-dbg/bin/gmock.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "gmock" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE OPTIONAL FILES "C:/Users/Marco/source/repos/Coding_Challange/vcpkg_installed/vcpkg/blds/gtest/x64-windows-dbg/bin/${CMAKE_INSTALL_CONFIG_NAME}/gmockpdb_debug_postfix-NOTFOUND.pdb")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "gmock" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "C:/Users/Marco/source/repos/Coding_Challange/vcpkg_installed/vcpkg/blds/gtest/x64-windows-dbg/googletest/generated/gmock.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "gmock" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "C:/Users/Marco/source/repos/Coding_Challange/vcpkg_installed/vcpkg/blds/gtest/src/v1.14.0-bcf93537a8.clean/googlemock/include/")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "gmock" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/manual-link" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Marco/source/repos/Coding_Challange/vcpkg_installed/vcpkg/blds/gtest/x64-windows-dbg/lib/gmock_main.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "gmock" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/Marco/source/repos/Coding_Challange/vcpkg_installed/vcpkg/blds/gtest/x64-windows-dbg/bin/gmock_main.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "gmock" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/manual-link" TYPE FILE OPTIONAL FILES "C:/Users/Marco/source/repos/Coding_Challange/vcpkg_installed/vcpkg/blds/gtest/x64-windows-dbg/bin/${CMAKE_INSTALL_CONFIG_NAME}/gmock_mainpdb_debug_postfix-NOTFOUND.pdb")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "gmock" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "C:/Users/Marco/source/repos/Coding_Challange/vcpkg_installed/vcpkg/blds/gtest/x64-windows-dbg/googletest/generated/gmock_main.pc")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/Marco/source/repos/Coding_Challange/vcpkg_installed/vcpkg/blds/gtest/x64-windows-dbg/googletest/cmake_install.cmake")

endif()

