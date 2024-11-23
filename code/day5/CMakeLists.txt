cmake_minimum_required(VERSION 3.16)

# Устанавливаем имя проекта
project(proj)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Включаем режим отладки
set(CMAKE_BUILD_TYPE Debug)

# Добавляем исполняемый файл
add_executable(main prog1.cpp)
