if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/googletest-1.17.0)
  add_custom_target(googletest ALL
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND tar -xzvf googletest-1.17.0.tar.gz &&
            cd googletest-1.17.0 && mkdir build && cd build &&
            cmake .. && $(MAKE) &&
            cp ./lib/* ${third_party_install_dir}/lib/ &&
            mkdir -p ${third_party_install_dir}/include/googletest &&
            mkdir -p ${third_party_install_dir}/include/googlemock &&
            cp -r ../googletest/include ${third_party_install_dir}/include/googletest &&
            cp -r ../googlemock/include ${third_party_install_dir}/include/googlemock
    )
else()
  add_custom_target(googletest)
endif()
