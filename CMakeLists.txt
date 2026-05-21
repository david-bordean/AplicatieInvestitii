cmake_minimum_required(VERSION 3.16)
project(portofoliu CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(portofoliu
    main.cpp
    Actiune.cpp
    Crypto.cpp
    InstrumentFinanciar.cpp
    Investitor.cpp
    Obligatiune.cpp
    Piata.cpp

)

# Copiaza fisierele .in langa executabil dupa fiecare build
foreach(IN_FILE actiuni.in crypto.in obligatiuni.in)
    add_custom_command(TARGET portofoliu POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${CMAKE_SOURCE_DIR}/${IN_FILE}"
            "$<TARGET_FILE_DIR:portofoliu>/${IN_FILE}"
        COMMENT "Copiez ${IN_FILE} -> $<TARGET_FILE_DIR:portofoliu>"
    )
endforeach()
