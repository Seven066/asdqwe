cmake_minimum_required(VERSION 3.10)

set(This network)

add_library(${This}
    )

target_include_directories(${This} PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_directories(${This} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/Common-cpp
    ${CMAKE_CURRENT_LIST_DIR}/Photon-cpp
    ${CMAKE_CURRENT_LIST_DIR}/LoadBalancing-cpp
    )

target_link_libraries(${This}
    -lLoadBalancingDebug64
    -lPhotonDebug64
    -lCommonDebug64
    -lpthread
    )
