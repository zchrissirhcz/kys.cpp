add_executable(kys
  kys.cpp
  Engine.cpp
  TitleScene.cpp
  Application.cpp
)

target_link_libraries(kys PRIVATE
  fmt::fmt
  mlcc
)
target_include_directories(kys PUBLIC
  ${CMAKE_SOURCE_DIR}/src
)